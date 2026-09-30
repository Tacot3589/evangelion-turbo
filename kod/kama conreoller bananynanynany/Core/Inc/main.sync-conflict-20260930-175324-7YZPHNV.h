/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "robot_data.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

uint8_t RingStatus(uint8_t sensors);
uint8_t EnemyLocation(uint8_t Nbr_of_Sensors);

void MOTOR_DRIVER_SetDuty(uint8_t Motor, int8_t Duty);
void MOTOR_DRIVER_TransmitData(void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STARTMOD_Pin GPIO_PIN_13
#define STARTMOD_GPIO_Port GPIOC
#define START_Pin GPIO_PIN_14
#define START_GPIO_Port GPIOC
#define SW1_Pin GPIO_PIN_15
#define SW1_GPIO_Port GPIOC
#define BATT_VOLTAGE_Pin GPIO_PIN_12
#define BATT_VOLTAGE_GPIO_Port GPIOB
#define EN_5V_Pin GPIO_PIN_13
#define EN_5V_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOC
#define Motor_KILL_Pin GPIO_PIN_10
#define Motor_KILL_GPIO_Port GPIOA
#define Power_EN_Pin GPIO_PIN_15
#define Power_EN_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_5
#define SW2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define UNKNOWN				0

// ADC_Channels
#define ADC_CHANNEL_BATTERY_VOLTAGE		(active_ADC_config->BatteryVoltage)
// ADC 1
#define ADC_CHANNEL_LEFT_LINE_A			(active_ADC_config->ADC_sensor1A)
#define ADC_CHANNEL_LEFT_LINE_B			(active_ADC_config->ADC_sensor1B)
// ADC 2
#define ADC_CHANNEL_RIGHT_LINE_A		(active_ADC_config->ADC_sensor2A)
#define ADC_CHANNEL_RIGHT_LINE_B		(active_ADC_config->ADC_sensor2B)
// ADC 3
#define ADC_CHANNEL_REAR_RIGHT_LINE_A	(active_ADC_config->ADC_sensor3A)
#define ADC_CHANNEL_REAR_RIGHT_LINE_B	(active_ADC_config->ADC_sensor3B)
//ADC 4
#define ADC_CHANNEL_REAR_LEFT_LINE_A	(active_ADC_config->ADC_sensor4A)
#define ADC_CHANNEL_REAR_LEFT_LINE_B	(active_ADC_config->ADC_sensor4B)

// SENORS CONFIGURATION
#define TFMINI_MAX_RANGE			(active_PARAM_config->Front_distance_range)		// centimeters  Range 0-1200
#define TFMINI_STRENGTH_THRESHOLD	5000	// amount of light reflected back to sensor 0-65536 lower is darker opponent
#define ANALOG_DETECTION_VALUE		2000	// analog sensor value range 0-4096
#define LINE_LOW					3400	// Low ADC Ring value 0-4096
#define LINE_HI						4096	// High ADC Ring value 0-4096
#define NBR_OF_LINE_SENS			(active_ADC_config->Number_of_sensors)
#define NBR_OF_DISTANCE_SENS		(active_IO_config->Number_of_TFmini)

#define IMU							hi2c2
#define OLED						hi2c1

#define TF_FRONT_LEFT				huart3
#define TF_FRONT_RIGHT				hlpuart1
#define TF_ANGLE_LEFT				huart2
#define TF_ANGLE_RIGHT				huart1
#define DMA_FRONT_LEFT				hdma_usart3_rx
#define DMA_FRONT_RIGHT				hdma_lpuart1_rx
#define DMA_ANGLE_LEFT				hdma_usart2_rx
#define DMA_ANGLE_RIGHT				hdma_usart1_rx
#define TF_FR						0		// 0 - LPUART
#define TF_FL						3		// 1 - UART1
#define TF_AR						1		// 2 - UART2
#define TF_AL						2		// 3 - UART3

// MOTOR DRIVER CONFIGURATION
#define MOTOR_MAX_TEMP					100		// C degree
#define FET_MAX_TEMP					95		// C degree
#define SUMO_MOTOR_MAX_CURRENT			15		// A // 15A
#define SUMO_MOTOR_MAX_CONSTANT_CURRENT	10		// A // 10A
#define MEGA_MOTOR_MAX_CURRENT			55		// A
#define MEGA_MOTOR_MAX_CONSTANT_CURRENT	50		// A
#define RAMP_STEP						1		// Max allowed instantaneous duty change; 100 is 1ms ramp. 1 is 100ms ramp

// START SETTING
#define MODULE 	1
#define BUTTON	2
#define DEFAULT 0

#define SUMO_START_DELAY	2900	// Start delay in mili-seconds;
#define MOTOR_TIMEOUT		250 	//
#define	INIT				0
#define SYNCED				1
#define DESYNCED			2
#define ERROR				10

// MOTOR VELOCITY CONFIG
#define SUMO_VELOCITY_SEARCH		(active_PARAM_config->Search_velocity)	//20		// Search velocity as Duty 0-100% //25 // 			25
#define SUMO_VELOCITY_ATTACK		(active_PARAM_config->Attack_velocity)	//35		// Attack velocity as Duty 0-100% // 30				40
#define SUMO_VELOCITY_REVERSE		(active_PARAM_config->Reverse_velocity)	//-20		// Reverse velocity as Duty 0-100%	-100-0 //-15
#define SUMO_VELOCITY_RUSH			(active_PARAM_config->Reverse_velocity)	//60		// Fist movement off the ring edge					60					//8		// 1/10th of Velocity Rush
#define SUMO_VELOCITY_ROTATE		(active_PARAM_config->Rotation_velocity)	//21		// Search velocity as Duty 0-100% //25				25
#define SUMO_RETURN_TIME			(active_PARAM_config->Return_time)	//500
#define MOUSE_VELOCITY_REVERSE		(active_PARAM_config->Reverse_velocity)
#define INCREMENT

// Robo Rave PID
#define PD_MAX_SPEED 100
#define KP 1.0
#define KD 0.0

#define MEGA_VELOCITY_SEARCH		100		// Search velocity as Duty 0-100% //25
#define MEGA_VELOCITY_ATTACK		100		// Attack velocity as Duty 0-100% // 30
#define MEGA_VELOCITY_REVERSE		-100	// Reverse velocity as Duty 0-100%	-100-0 //-15
#define MEGA_VELOCITY_RUSH			20		// Fist movement off the ring edge
#define MEGA_RETURN_TIME			70

#define ROTATE_TIME 				100
#define ROBO_RAVE_ROTATION			540		// 540 degree

#define LEFT_MOTOR				(active_IO_config->Left_motor)
#define RIGHT_MOTOR				(active_IO_config->Right_motor)
#define BOTH_MOTORS				3
#define MOTOR_REVERSED_LEFT		(active_IO_config->Reverse_left_motor)		// 1 - revese motor 0 - not reversed
#define MOTOR_REVERSED_RIGHT	(active_IO_config->Reverse_right_motor)		// 1 - revese motor 0 - not reversed

// Line sensors status
#define ON_RING			0
#define FRONT_LEFT_OUT	1
#define FRONT_RIGHT_OUT	2
#define FRONT_OUT		3
#define REAR_LEFT_OUT	4
#define REAR_RIGHT_OUT	5
#define REAR_OUT		6
#define OFF_RING		7

// Opponent Status
#define ENEMY_FRONT			1
#define ENEMY_FRONT_LEFT	2
#define ENEMY_FRONT_RIGHT	3
#define ENEMY_LEFT			4
#define ENEMY_RIGHT			5
#define ENEMY_LOST			6

#define LINE_CAL_TYPE	3  		// Method of Line sensors calibration:
								// 0 - auto detection of line position
								// 1 - both sensors on line at beginning
								// 2 - one sensor on line, other at ring
								// 3 - both sensor on ring

#define SENS 0.1				// Line sensor calibration sensitive (Higher sensitive -> Wider range for single color calibration

// Robot Selection
#define HIROSHIMA				1
#define HIROSHIMKA				2
#define BABY_HIROSHIMA			3
#define BABY_HIROSHIMKA			4
#define KAMA					5
#define BABY_KAMA				6
#define SPARE_1					7
#define SPARE_2					8



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
