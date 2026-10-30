/*
 * start_module.h
 *
 *  Created on: Oct 23, 2026
 *      Author: szymo
 */

#ifndef INC_START_MODULE_H_
#define INC_START_MODULE_H_

#include <stdint.h>

void Received_RC5_Frame(uint8_t Addres, uint8_t Command);
void Received_SIRC_Frame(uint8_t Addres, uint8_t Command);
uint8_t LED_GREEN_Control(uint8_t Command, uint8_t Data);
uint8_t LED_RED_Control(uint8_t Command, uint8_t Data);
uint8_t LED_BLUE_Control(uint8_t Command, uint8_t Data);

typedef enum {
	STARTUP,
	PPROGRAMMED,
	READY,
	RC5_START,
	SIRC_START,
	STOP
} StartMod_state_t;

//======================================= PRIVATE DEFINES
#define RISING 		1
#define FALLING		2
#define TIMEOUT		3

#define RC5				1
#define SIRC			2
#define UNKNOWN			0
#define SAVED_STATUS 	5

#define RC5_Short   889      // 889 us
#define RC5_Long    1778     // 1778 us
#define SIRC_Short  600      // 600 us
#define SIRC_Long   1200     // 1200 us
#define Margin      300

// Led Commands
#define ON			2
#define OFF			3
#define BLINK_SLOW	4
#define BLINK_FAST	5
#define TICK		6

//======================================= PUBLIC FUNCTIONS
uint8_t StartModule_Started(void);
uint8_t StartModule_Startup(void);
void StartMod_OnRisingExti(void);
void StartMod_OnFallingExti(void);
void InterruptStartModLeds(void);
void InterruptStartMod(uint8_t Edge);
uint8_t StartModule_GetDohyoID(void);

#endif /* INC_START_MODULE_H_ */
