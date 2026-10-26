/*
 * start_module.h
 *
 *  Created on: Oct 23, 2026
 *      Author: szymo
 */

#ifndef INC_TFLUNA_H_
#define INC_TFLUNA_H_

#include <stdint.h>
#include "main.h"

//======================================= PRIVATE FUNCTIONS
static uint8_t BUFFER_CONTAINS(const uint8_t *buffer, const uint8_t *pattern);
static uint16_t GET_MEDIAN(uint16_t *Array, uint8_t Array_Filtering_size);

//======================================= DEFINES
#define MAX_DISTANCE 75
#define MIN_DISTANCE 5
#define CLOSE_DISTANCE 5
#define MAX_RETRIES_INIT 5

//filtering
#define MIN_AMP_TRESCHOLD 200
#define LIDARS_FILTERING_ARRAY_SIZE_FRONT 11
#define LIDARS_FILTERING_ARRAY_SIZE_BACK 11
#define MIN_LIDAR_AMP_DIST_AMP 300
#define MIN_LIDAR_AMP_DIST 5


//======================================= PUBLIC FUNCTIONS
uint8_t TFLUNAs_INIT(LineSensors_t *Lunas);
void TFLUNAs_DMA_CALLBACK(LineSensors_t *Lunas, UART_HandleTypeDef *huart);
uint16_t TFLUNA_AMP(uint8_t UART_NO);
uint16_t TFLUNA_DIST(uint8_t UART_NO);
uint16_t TFLUNA_TEMP(uint8_t UART_NO);


//======================================= PRIVATE STATIC
static const uint8_t CMD_DISABLE_OUTPUT[5] = { 0x5A, 0x05, 0x07, 0x00, 0x66};
static const uint8_t CMD_ENABLE_OUTPUT[5] = { 0x5A, 0x05, 0x07, 0x01, 0x67};
static const uint8_t CMD_SET_250HZ[6] = {0x5A, 0x06, 0x03, 0xFA, 0x00, 0x5D};


#endif /* INC_START_MODULE_H_ */
