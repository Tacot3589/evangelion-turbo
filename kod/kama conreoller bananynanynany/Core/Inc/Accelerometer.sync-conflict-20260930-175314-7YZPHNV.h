/*
 * Accelerometer.h
 *
 *  Created on: Feb 5, 2025
 *      Author: SKYNET
 */

#ifndef INC_ACCELEROMETER_H_
#define INC_ACCELEROMETER_H_

void ACC_Init(void);
void Acc_ReadAndCalc(void);

void Acc_ReadACC(void);
void Acc_ReadACC_320G(void);
void Acc_ReadGYRO(void);
void Acc_Calc(void);
void Acc_Position(void);
void Acc_Velocity(void);
uint8_t Acc_Cal(void);




#endif /* INC_ACCELEROMETER_H_ */
