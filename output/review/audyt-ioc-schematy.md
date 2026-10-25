# Audyt konfiguracji STM32CubeMX względem schematów

Data: 2026-10-24. Wynik: przypisania pinów driverów są poprawne, ale konfiguracja SPI i ADC wymaga poprawek. Sprawdzenie statyczne; bez programowania płytki, pomiarów oscyloskopem i odczytu Option Bytes. Nie zmieniono pliku .ioc ani kodu aplikacji.

## Zakres i źródła

Podstawą są bieżące pliki [MCU.SchDoc](D:/tech/robotyka/robots/evangelion-turbo/altiumik/evangelion_turbo_allinone_PCB/MCU.SchDoc), [MotorDriver8873S.SchDoc](D:/tech/robotyka/robots/evangelion-turbo/altiumik/evangelion_turbo_allinone_PCB/MotorDriver8873S.SchDoc), [PCB.SchDoc](D:/tech/robotyka/robots/evangelion-turbo/altiumik/evangelion_turbo_allinone_PCB/PCB.SchDoc) oraz [evangelion_turbo_allinone.ioc](D:/tech/robotyka/robots/evangelion-turbo/kod/evangelion_turbo_allinone/evangelion_turbo_allinone.ioc). Odczytano rekordy komponentów, pinów, przewodów, portów i etykiet bezpośrednio z binarnych SchDoc. Dodatkowo sprawdzono arkusze IMU, OledAndLed, Interface, Sensor_connectors i MCU_2 oraz wygenerowane main.c, stm32g4xx_hal_msp.c i stm32g4xx_it.c.

Eksport PDF obejrzano pomocniczo. Jest nieaktualny względem źródeł: np. C74 ma w PDF 100 nF, w SchDoc 47 nF; szyna drivera nazywa się w PDF 5v, w SchDoc 5v_DVDD; C21/C22 mają odpowiednio 6,8 pF i 10 pF. Dlatego wnioski o bieżącym projekcie oparto na SchDoc.

## 1. Problemy wymagające poprawy

### 1.1. SPI2: prędkość, faza i rozmiar danych

.ioc:432-437 ustawia preskaler /4, czyli 42,5 MHz przy PCLK1=170 MHz. W main.c:797-810 konfiguracja zawiera dodatkowo wartości domyślne niewpisane jawnie w .ioc: SPI_DATASIZE_4BIT, SPI_POLARITY_LOW, SPI_PHASE_1EDGE, NSS_SOFT, MSB first.

DRV8873 wymaga SCLK nie szybszego niż 10 MHz, CPOL=0 i próbkowania na drugim, opadającym zboczu (SPI mode 1). Transakcja zawiera dokładnie 16 taktów przy aktywnym CS, a pomiędzy transakcjami CS musi być wysoki przez co najmniej 500 ns. Źródło: [TI DRV8873, sekcje 6.6 i 7.5.1.2](https://www.ti.com/lit/ds/symlink/drv8873.pdf).

Proponowane ustawienia CubeMX:

| Parametr | Ustawienie |
|---|---|
| Mode | Full-Duplex Master |
| Prescaler | /32 = 5,3125 MHz; /64 = 2,65625 MHz na pierwsze uruchomienie |
| Clock polarity | Low |
| Clock phase | 2 Edge |
| Data size | 16 Bits |
| First bit | MSB First |
| NSS | Software |
| NSS pulse | Disable; przy NSS_SOFT zewnętrznym CS i tak steruje GPIO |
| SCK/MOSI GPIO | AF push-pull; dobrać szybkość zboczy do obciążenia, np. High na początek i sprawdzić przebiegi |

/16 nadal daje za dużo: 10,625 MHz. Alternatywnie można użyć 8-bitowego SPI i dwóch bajtów przy nieprzerwanym CS=0. Konfiguracja 4-bitowa wymagałaby świadomej obsługi czterech nibble; nie odpowiada typowej obsłudze ramki 16-bitowej. Nie ma obecnie kodu realizującego takie transakcje.

### 1.2. Oba chip-selecty startują w stanie aktywnym

PA10 i PA3 mają właściwe funkcje GPIO_Output, ale nie mają ustawionego stanu początkowego High. main.c:1176 potwierdza GPIO_PIN_RESET dla obu CS. Powoduje to jednoczesne wybranie obu driverów na wspólnej magistrali; podczas transferu oba mogą odpowiadać na MISO.

Ustawić GPIO output level = High dla PA10 i PA3. Transakcja wybiera tylko jeden driver; drugi pozostaje z CS=1.

Próba podniesienia CS w main.c:147-148 wykonuje się przed MX_GPIO_Init(), przed włączeniem zegara portu A w tej funkcji, a później jest nadpisywana stanem Low. Zmiana musi znaleźć się w konfiguracji stanów początkowych. Użycie DRV_CS_1_GPIO_Port dla drugiego CS jest obecnie funkcjonalnie poprawne, ponieważ oba są na GPIOA, ale nazwa powinna być DRV_CS_2_GPIO_Port.

### 1.3. PA0 i PA1 błędnie wybrane jako para różnicowa

.ioc:170 i :173: IN1-Differential. Tymczasem PA0 jest sygnałem CURRENT drivera B względem GND, a PA1 niezależnym sygnałem czujnika ADC3. Ustawić dwa wejścia single-ended: ADC1_IN1 na PA0 oraz ADC1_IN2 na PA1.

W aktualnej sekwencji ADC kanału 1 nie ma, więc kod nie wykonuje teraz błędnego pomiaru różnicowego prądu: w ogóle nie mierzy tego prądu. Błąd wybranego trybu trzeba usunąć przed dodaniem kanału.

### 1.4. ADC ma 11 przypisanych wejść, ale tylko 2 zaprogramowane konwersje

ADC1 ma wyłącznie kanał 12 (PB1, czujnik ADC7), ADC2 wyłącznie kanał 3 (PA6, czujnik ADC1). Scan jest wyłączony, liczba konwersji wynosi 1 dla każdego ADC. Nie ma skonfigurowanych kanałów prądu ani napięcia baterii w sekwencji regularnej; nie ma również ich konfiguracji injected. Samo przypisanie analogowego pinu nie dodaje go do sekwencji.

Jeśli mają być mierzone wszystkie wejścia, proponowany podział przy zachowaniu obecnych peryferiów:

| ADC | Kanały regularne | Liczba |
|---|---|---:|
| ADC1 | IN1 (prąd B), IN2 (ADC3), IN11 (prąd A), IN12 (ADC7), IN15 (ADC6) | 5 |
| ADC2 | IN3 (ADC1), IN4 (ADC2), IN5 (ADC5), IN12 (ADC8), IN13 (ADC4), IN17 (bateria) | 6 |

Kolejność rang można dobrać do aplikacji. Włączyć scan i, dla automatycznego zbierania całej sekwencji, odpowiednio skonfigurować DMA/wyzwalanie. Alternatywą jest świadome przełączanie pojedynczego kanału przez HAL_ADC_ConfigChannel w aplikacji. W przejrzanej inicjalizacji takiej obsługi nie ma.

Zegar przetwornika wynosi 170 MHz / 4 = 42,5 MHz; nie należy utożsamiać RCC.ADC12Freq_Value=170 MHz z zegarem samej konwersji. Sampling time 2,5 cyklu to około 59 ns. To ustawienie wymaga sprawdzenia impedancji źródeł i błędu ustalania, szczególnie dzielnika baterii. Dłuższy sampling time, np. 24,5 lub 47,5 cyklu, jest punktem startowym do weryfikacji, nie gwarancją dokładności. W firmware potrzebne są kalibracja ADC i uruchomienie pomiarów; nie znajdują się w obecnym main.c.

## 2. Pełna mapa połączeń driverów

| Sygnał | MCU / pin obudowy | Konfiguracja .ioc | Połączenie z DRV8873S |
|---|---|---|---|
| SCLK | PB13 / 26 | SPI2_SCK | oba drivery, pin 5 |
| MISO | PB14 / 27 | SPI2_MISO | oba SDO, pin 3 |
| MOSI | PB15 / 28 | SPI2_MOSI | oba SDI, pin 4 |
| CS A | PA10 / 32 | GPIO_Output | SPI_CS_1 -> nSCS A, pin 6 |
| CS B | PA3 / 11 | GPIO_Output | SPI_CS_2 -> nSCS B, pin 6 |
| A1 | PA11 / 33 | TIM4_CH1, AF10 | DIR -> R11 -> PH/IN2, pin 8 |
| A2 | PA12 / 34 | TIM4_CH2, AF10 | PWM -> R10 -> EN/IN1, pin 7 |
| B1 | PB9 / 47 | TIM8_CH3, AF10 | DIR -> R11 -> PH/IN2, pin 8 |
| B2 | PB6 / 44 | TIM8_CH1, AF5 | PWM -> R10 -> EN/IN1, pin 7 |
| Prąd A | PB12 / 25 | ADC1_IN11, single-ended | połączone IPROPI1/IPROPI2 |
| Prąd B | PA0 / 8 | ADC1_IN1, obecnie differential | połączone IPROPI1/IPROPI2 |

Mapowanie fizycznych pinów i funkcji alternatywnych jest poprawne. Oznaczenia A1/B1 nie oznaczają IN1: prowadzą do IN2. W szczególności TIM8_CH1 steruje B2, a TIM8_CH3 steruje B1.

Oba timery PWM mają PSC=16, ARR=999 i pracują przy 170 MHz: fPWM=10 kHz. Tryb PWM1, dodatnia polaryzacja, początkowe CCR=0 są poprawne. Brak komplementarnych wyjść i dead-time w MCU nie jest błędem dla wejść logicznych tego zintegrowanego mostka. Nie ma sprzętowego połączenia nFAULT do wejścia break.

Domyślny tryb drivera to PWM/IN1-IN2. Dwa kanały PWM mogą więc zostać. Jeśli zamiarem jest PH/EN, trzeba ustawić MODE przez SPI i traktować A1/B1 jako kierunek, A2/B2 jako PWM. Same nazwy DIR/PWM na schemacie nie wybierają trybu układu. Źródło: [TI, tabela 2 i sekcja 7.3.1](https://www.ti.com/lit/ds/symlink/drv8873.pdf).

nSLEEP jest połączony z DVDD, DISABLE z GND, a nFAULT tylko podciągnięty przez R13 do DVDD; żaden z tych sygnałów nie dochodzi do MCU. Brak GPIO dla nich w .ioc jest zgodny ze schematem. Diagnostykę trzeba odczytywać przez SPI; przerwania nFAULT nie da się dodać samą zmianą konfiguracji.

R8 i R9, oba 330 ohm, są połączone równolegle na wspólnym CURRENT: rezystancja przeliczeniowa wynosi 165 ohm. Nie używać 330 ohm w przeliczeniu prądu. Dla typowego stosunku lustra 1100:1 daje to około 0,15 V/A w fazie przewodzenia mierzonego tranzystora; próbki podczas PWM zależą od fazy i wymagają odpowiedniej synchronizacji/interpretacji. Źródło współczynnika: [TI, sekcja 7.3.3](https://www.ti.com/lit/ds/symlink/drv8873.pdf).

## 3. Pozostałe piny analogowe

Nazwy ADC1...ADC8 w tej tabeli oznaczają porty schematu czujników, a nie numery peryferiów STM32.

| Port schematu | Pin MCU | Funkcja | Stan sekwencji obecnie |
|---|---|---|---|
| ADC1 | PA6 | ADC2_IN3 | jedyny kanał ADC2 |
| ADC2 | PA7 | ADC2_IN4 | pominięty |
| ADC3 | PA1 | ADC1_IN2 | pominięty; zły tryb różnicowy |
| ADC4 | PA5 | ADC2_IN13 | pominięty |
| ADC5 | PC4 | ADC2_IN5 | pominięty |
| ADC6 | PB0 | ADC1_IN15 | pominięty |
| ADC7 | PB1 | ADC1_IN12 | jedyny kanał ADC1 |
| ADC8 | PB2 | ADC2_IN12 | pominięty |
| Battery Voltage | PA4 | ADC2_IN17 | pominięty |

## 4. I2C, UART, joystick i debug

| Obwód | Piny i funkcje | Ocena |
|---|---|---|
| IMU | PB7 SDA, PB8 SCL, I2C1 AF4 | właściwe piny; szybkość zależy od wariantu IMU |
| OLED | PA8 SDA, PA9 SCL, I2C2 AF4 | właściwe piny; Fast-mode Plus wymaga korekty dla SSD1306 |
| DIST1 RX | PA2, LPUART1_TX w half-duplex | wybór fizycznej linii poprawny; zalecany receive-only |
| DIST2 RX | PB4, USART2_RX | poprawnie |
| Wspólny TX czujników | PB3, USART2_TX | poprawnie, wspólna linia TX do czterech złączy |
| DIST3 RX | PB10, USART3_TX w half-duplex, MODE_RX | poprawnie |
| DIST4 RX | PC10, UART4_TX w half-duplex, MODE_RX | poprawnie |
| JOY1 | PC15 | input/no pull, zewnętrzny pull-up |
| JOY2 | PC14 | input/no pull, zewnętrzny pull-up |
| JOY3 | PC13 | input/no pull, zewnętrzny pull-up |
| JOY4 | PC6 | input/no pull, zewnętrzny pull-up |
| JOY5 + NRST | PG10 | zależne od Option Bytes; patrz niżej |
| LED red | PC11 | GPIO output, zgodne z START_MOD_LED_1 |
| LED blue | PA15 | GPIO output, zgodne z START_MOD_LED_2 |
| LED green | PB5 | GPIO output, zgodne z START_MOD_LED_3 |
| IR start | PB11 | EXTI11, oba zbocza, IRQ włączone, zgodne z obsługą |
| SWD | PA13 SWDIO, PA14 SWCLK | Serial Wire poprawne; PA15/PB3/PB4 pozostają do innych funkcji |
| HSE | PF0, PF1 | rezonator 32 MHz, poprawny tryb crystal |

I2C1 i I2C2 mają Fast-mode Plus, Timing=0x4052060F przy 170 MHz. Ustawienie jest przeznaczone dla szybkiej magistrali, około 1 MHz; dokładny okres zależy też od filtrów i zboczy. Nie jest to konfiguracja 400 kHz. Obie magistrale są AF open-drain i mają zewnętrzne pull-upy 4,7 kohm; GPIO_NOPULL jest poprawne.

IMU.SchDoc dopuszcza LSM6DSV320XTR/LSM6DSOX, natomiast komentarz main.c wskazuje LSM6DSOX. Dla [LSM6DSOX](https://www.st.com/resource/en/datasheet/lsm6dsox.pdf) limit I2C wynosi 400 kHz. [LSM6DSV320X](https://www.st.com.cn/resource/en/datasheet/lsm6dsv320x.pdf) dopuszcza 1 MHz. Bez identyfikacji zamontowanego układu nie można uznać I2C1 za jednoznacznie błędne dla obu wariantów. Ustawienie 400 kHz jest wspólne dla obu; należy przeliczyć Timing w CubeMX. Przy 1 MHz trzeba ponadto sprawdzić czas narastania dla pull-upów 4,7 kohm.

Dla OLED obsługiwanego biblioteką SSD1306 zalecane I2C2 Fast Mode 400 kHz: dokumentacja SSD1306 podaje minimalny okres 2,5 us. Schemat opisuje panel tylko jako oled flex 0.96, dlatego model kontrolera wynika tu z użytego firmware. Źródło: [dokument producenta Solomon Systech, tabela 13-6](https://gabotronics.com/download/datasheets/ssd1306.pdf).

PG10 ma jednocześnie etykiety JOY5 i NRST. GPIO_Input w .ioc nie ustawia Option Bytes. JOY5 wymaga NRST_MODE=2; w ustawieniu resetu naciśnięcie tego kierunku joysticka resetuje MCU. Po przełączeniu na GPIO złącze PROG traci sprzętowy reset, choć SWD pozostaje dostępne. Nie odczytano Option Bytes płytki, więc jest to warunek do weryfikacji, nie stwierdzenie aktualnego ustawienia sprzętu. Dla PB8/I2C_SCL sprawdzić także bootowanie sterowane Option Bytes, aby podciągnięta SCL nie wybierała bootloadera, jeśli włączono wybór BOOT0 z pinu. Źródło: [ST RM0440, sekcje 9.3.15-16](https://www.st.com/resource/en/reference_manual/dm00355726-stm32g4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf).

Half-duplex na fizycznych pinach TX jest prawidłowym sposobem odbioru na PA2/PB10/PC10. Nie należy przenosić tych sygnałów na inne piny RX. Dla LPUART1 aktualny main.c ustawia jednak TX_RX oraz 209700 baud; UART4/USART2/USART3 mają 115200 baud. Ustawić LPUART1 receive-only i jawny baud zgodny z czujnikiem. Jeśli cztery czujniki są takie same, rozbieżność prędkości jest szczególnie podejrzana. Schemat złączy nie określa protokołu ani modelu czujnika, więc samej liczby 209700 nie uznaję za dowiedziony błąd prędkości.

Nie ma DMA ani IRQ dla UART-ów; odbiór pollingiem jest możliwy, odbiór przez HAL_UART_Receive_IT/DMA wymaga dodatkowej konfiguracji. Wspólny TX oznacza rozsyłanie tych samych danych do wszystkich czujników.

## 5. Zegary, timery, DMA, NVIC i ustawienia projektu

STM32G431CBU6 / UFQFPN48 zgadza się z IC1. HSE 32 MHz / PLLM 8 * PLLN 85 / PLLR 2 = 170 MHz. AHB/APB1/APB2 bez dzielenia. Kod włącza Voltage Scale 1 Boost i ustawia FLASH_LATENCY_4. Nie ma potrzeby zmiany tych ustawień wynikającej z połączeń na schemacie. [ST, dokumentacja MCU](https://www.st.com/resource/en/datasheet/stm32g431cb.pdf).

| Timer | PSC | ARR | Wynik |
|---|---:|---:|---|
| TIM4 | 16 | 999 | PWM 10 kHz |
| TIM8 | 16 | 999 | PWM 10 kHz |
| TIM15 | 169 | 999 | 1 kHz |
| TIM16 | 1699 | 999 | 100 Hz |
| TIM17 | 1699 | 3999 | 25 Hz |
| TIM6 | 1699 | 4999 | 20 Hz |
| TIM7 | 169 | 65534 | tick 1 us, przepełnienie co 65,535 ms |

TIM7 ARR=65534 oznacza 65535 taktów. Jeśli celem jest pełny zakres licznika 16-bitowego, użyć ARR=65535 (65536 taktów); obecna wartość nie jest automatycznie błędem bez wymagania aplikacji. Komentarze przy HAL_TIM_Base_Start_IT dla TIM15/16/17 są zamienione, ale konfiguracja oraz identyfikacja timerów w callbacku odpowiadają tabeli.

DMA1_Channel1: I2C1_RX, peripheral-to-memory, byte, memory increment, normal. DMA1_Channel2: I2C2_TX, memory-to-peripheral, byte, memory increment, normal. Nie ma konfliktu kanałów. Kierunki zgadzają się z odczytem IMU i zapisem OLED. Tryb normal jest odpowiedni dla osobnych transakcji I2C; brak DMA dla kierunku przeciwnego nie blokuje operacji pollingiem.

Przerwania DMA, I2C_EV, EXTI15_10 oraz używanych timerów są włączone i mają procedury obsługi. Brak I2C1_ER/I2C2_ER: przy pracy DMA warto je włączyć, aby błędy magistrali trafiały do HAL_I2C_ER_IRQHandler. To zalecenie odporności obsługi, nie błąd połączenia. Większość IRQ ma priorytet 0, SysTick 15; przy rozwijaniu obsługi silników warto dobrać priorytety i nie blokować w ISR funkcjami zależnymi od SysTick. Brak SPI IRQ/DMA nie przeszkadza w transakcjach blokujących.

SYS Serial Wire, wyłączone dead-battery signals, brak LSE przy użyciu PC14/PC15 jako joysticka są spójne. Wartości wyświetlane dla niewłączonych bloków, np. RCC.USBFreq_Value, nie oznaczają działającego USB i nie stanowią tu samodzielnej usterki. Ustawienia generowania HAL, toolchain, heap/stack i optymalizacji nie mają bezpośredniej sprzeczności ze schematami; ich wystarczalność wymaga odrębnej analizy programu.

## 6. Uwagi do obecnego programu, poza .ioc

Po starcie main.c uruchamia PWM i ustawia TIM4 CCR1=0, CCR2=800 oraz TIM8 CCR1=0, CCR3=800. Oznacza to 80% wysterowania na różnych wejściach mostków: A na IN1, B na IN2. W domyślnym trybie PWM kierunki elektryczne są przeciwne; dla lustrzanego montażu silników może to być zamierzone. Ten fragment nie sprawdza zgody modułu startowego przed ustawieniem wypełnienia. Napisy DRIVER A/B w sekwencji inicjalizacji nie wykonują konfiguracji SPI driverów.

## 7. Kolejność dalszych działań

1. Poprawić SPI2 i stany początkowe obu CS, wygenerować kod i sprawdzić jego zgodność z ustawieniami.
2. Poprawić single-ended PA0/PA1 i rzeczywiste sekwencje ADC.
3. Uzgodnić tryb PWM/PH-EN w aplikacji; zachować podaną mapę kanałów timerów.
4. Dobrać I2C do rzeczywistego IMU/OLED oraz tryb i baud LPUART1 do czujnika.
5. Odczytać Option Bytes i sprawdzić PG10/BOOT0 względem zamierzonego użycia.
6. Na sprzęcie sprawdzić osobne odczyty rejestrów każdego DRV, 16 taktów SPI na ramkę, stany CS, PWM oraz pomiary ADC. Wynik tego audytu nie zastępuje tych pomiarów.
