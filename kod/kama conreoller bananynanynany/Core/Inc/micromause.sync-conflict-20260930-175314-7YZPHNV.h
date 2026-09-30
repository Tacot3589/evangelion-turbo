/*
 * micromause.h
 *
 *  Created on: Mar 12, 2026
 *      Author: SKYNET
 */

#ifndef INC_MICROMAUSE_H_
#define INC_MICROMAUSE_H_


#endif /* INC_MICROMAUSE_H_ */

#include "main.h"

void MazeScan(void);
void MazeSolve(void);
void MICRO_mause(void);

uint8_t rotate_robot(float angle_to_add);
uint8_t Turn_to_Angle(int16_t target);
uint8_t Motion_Control(uint8_t Status);

void Start_Rotate(int8_t rotate_by);
