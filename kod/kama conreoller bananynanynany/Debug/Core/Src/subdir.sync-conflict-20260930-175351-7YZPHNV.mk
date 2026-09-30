################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Accelerometer.c \
../Core/Src/adc.c \
../Core/Src/baby_hiroshima.c \
../Core/Src/dma.c \
../Core/Src/fdcan.c \
../Core/Src/fonts.c \
../Core/Src/gpio.c \
../Core/Src/hiroshima.c \
../Core/Src/i2c.c \
../Core/Src/interrupts.c \
../Core/Src/main.c \
../Core/Src/mega_sumo.c \
../Core/Src/micromause.c \
../Core/Src/robot_data.c \
../Core/Src/ssd1306.c \
../Core/Src/stm32g4xx_hal_msp.c \
../Core/Src/stm32g4xx_it.c \
../Core/Src/sumo.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g4xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/Accelerometer.o \
./Core/Src/adc.o \
./Core/Src/baby_hiroshima.o \
./Core/Src/dma.o \
./Core/Src/fdcan.o \
./Core/Src/fonts.o \
./Core/Src/gpio.o \
./Core/Src/hiroshima.o \
./Core/Src/i2c.o \
./Core/Src/interrupts.o \
./Core/Src/main.o \
./Core/Src/mega_sumo.o \
./Core/Src/micromause.o \
./Core/Src/robot_data.o \
./Core/Src/ssd1306.o \
./Core/Src/stm32g4xx_hal_msp.o \
./Core/Src/stm32g4xx_it.o \
./Core/Src/sumo.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g4xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/Accelerometer.d \
./Core/Src/adc.d \
./Core/Src/baby_hiroshima.d \
./Core/Src/dma.d \
./Core/Src/fdcan.d \
./Core/Src/fonts.d \
./Core/Src/gpio.d \
./Core/Src/hiroshima.d \
./Core/Src/i2c.d \
./Core/Src/interrupts.d \
./Core/Src/main.d \
./Core/Src/mega_sumo.d \
./Core/Src/micromause.d \
./Core/Src/robot_data.d \
./Core/Src/ssd1306.d \
./Core/Src/stm32g4xx_hal_msp.d \
./Core/Src/stm32g4xx_it.d \
./Core/Src/sumo.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g4xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-4 "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Accelerometer.cyclo ./Core/Src/Accelerometer.d ./Core/Src/Accelerometer.o ./Core/Src/Accelerometer.su ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/baby_hiroshima.cyclo ./Core/Src/baby_hiroshima.d ./Core/Src/baby_hiroshima.o ./Core/Src/baby_hiroshima.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/fdcan.cyclo ./Core/Src/fdcan.d ./Core/Src/fdcan.o ./Core/Src/fdcan.su ./Core/Src/fonts.cyclo ./Core/Src/fonts.d ./Core/Src/fonts.o ./Core/Src/fonts.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/hiroshima.cyclo ./Core/Src/hiroshima.d ./Core/Src/hiroshima.o ./Core/Src/hiroshima.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/interrupts.cyclo ./Core/Src/interrupts.d ./Core/Src/interrupts.o ./Core/Src/interrupts.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mega_sumo.cyclo ./Core/Src/mega_sumo.d ./Core/Src/mega_sumo.o ./Core/Src/mega_sumo.su ./Core/Src/micromause.cyclo ./Core/Src/micromause.d ./Core/Src/micromause.o ./Core/Src/micromause.su ./Core/Src/robot_data.cyclo ./Core/Src/robot_data.d ./Core/Src/robot_data.o ./Core/Src/robot_data.su ./Core/Src/ssd1306.cyclo ./Core/Src/ssd1306.d ./Core/Src/ssd1306.o ./Core/Src/ssd1306.su ./Core/Src/stm32g4xx_hal_msp.cyclo ./Core/Src/stm32g4xx_hal_msp.d ./Core/Src/stm32g4xx_hal_msp.o ./Core/Src/stm32g4xx_hal_msp.su ./Core/Src/stm32g4xx_it.cyclo ./Core/Src/stm32g4xx_it.d ./Core/Src/stm32g4xx_it.o ./Core/Src/stm32g4xx_it.su ./Core/Src/sumo.cyclo ./Core/Src/sumo.d ./Core/Src/sumo.o ./Core/Src/sumo.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32g4xx.cyclo ./Core/Src/system_stm32g4xx.d ./Core/Src/system_stm32g4xx.o ./Core/Src/system_stm32g4xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

