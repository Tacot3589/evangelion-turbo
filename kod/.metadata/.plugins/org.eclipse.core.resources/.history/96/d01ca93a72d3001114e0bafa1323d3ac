/*
 * start_module.h
 *
 *  Created on: Oct 23, 2026
 *      Author: szymo
 */

#ifndef WATCHDOG_AND_INTERFACE_H_
#define WATCHDOG_AND_INTERFACE_H_

#include <stdint.h>
#include "main.h"
//======================================= PRIVATE FUNCTIONS
static void MENU_CHANGE(JoystickMode_t *Change);


//======================================= PRIVATE DEFINES
extern LidarSensors_t Lunas;
extern LinesSensors_t Lines;
extern Evangelion_t Eva;
extern MotorsSettingsInfo_t Motors;
extern uint8_t lastSeen;
extern JoystickMode_t JoystickState;

//======================================= PUBLIC FUNCTIONS
void WATCHDOG(void);
void OLED_INFO(void);

#endif /* INC_START_MODULE_H_ */
