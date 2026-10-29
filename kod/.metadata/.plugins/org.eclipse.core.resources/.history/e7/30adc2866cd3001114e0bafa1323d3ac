/*
 * start_module.h
 *
 *  Created on: Oct 23, 2026
 *      Author: szymo
 */

#ifndef ADC_READOUT_H_
#define ADC_READOUT_H_

#include <stdint.h>
#include "main.h"
#include "TFLUNA.h"

//======================================= PRIVATE FUNCTIONS


//======================================= PRIVATE DEFINES
#define WHITE_LINE_TRESCHOLD 3700 //white is less
#define R1 470
#define R2 47
#define BATTERY_VOLTAGE_COMPENSATION 1
#define BATTERY_ADC_CHANNEL 3
#define REFERENCE_VOLTAGE 3.3f
#define BATTERY_CONST  ((REFERENCE_VOLTAGE / 4095.0f * ((R1) + (R2)) / (R2)) * (BATTERY_VOLTAGE_COMPENSATION) * 100.0f)
#define BATTERY_ADC_VOLTAGE_FILTRATION_ARRAY_SIZE 15
#define MCU_TEMP_FILTRATION_ARRAY_SIZE 15
#define DRV_CURRENT_FILTRATION_ARRAY_SIZE 5
#define DRV8873_CURERNT_CONST  ((REFERENCE_VOLTAGE * 1100.0f * 1000.0f) / (4095.0f * DRV8873_IPROPI_RESISTOR))
#define DRV8873_IPROPI_RESISTOR 330/2

//======================================= PUBLIC FUNCTIONS
uint8_t ADC_READOUT_INIT(ADC_HandleTypeDef *hadc, volatile uint16_t *Array, uint16_t Size);
void ADC_REDOUT_INFO_GETTHEMALL(Evangelion_t *Eva, MotorsSettingsInfo_t *Motors, LinesSensors_t  *Lines, volatile uint16_t *A1, volatile uint16_t *A2);

#endif /* INC_START_MODULE_H_ */
