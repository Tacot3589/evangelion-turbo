/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32h5xx_hal.h"

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

void HAL_LPTIM_MspPostInit(LPTIM_HandleTypeDef *hlptim);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DRV_CS2_Pin GPIO_PIN_13
#define DRV_CS2_GPIO_Port GPIOC
#define JOY1_Pin GPIO_PIN_14
#define JOY1_GPIO_Port GPIOC
#define JOY2_Pin GPIO_PIN_15
#define JOY2_GPIO_Port GPIOC
#define JOY3_Pin GPIO_PIN_0
#define JOY3_GPIO_Port GPIOC
#define JOY4_Pin GPIO_PIN_1
#define JOY4_GPIO_Port GPIOC
#define JOY5_Pin GPIO_PIN_2
#define JOY5_GPIO_Port GPIOC
#define FAN_PWM_Pin GPIO_PIN_2
#define FAN_PWM_GPIO_Port GPIOB
#define START_MOD_LED_1_Pin GPIO_PIN_10
#define START_MOD_LED_1_GPIO_Port GPIOB
#define START_MOD_LED_2_Pin GPIO_PIN_11
#define START_MOD_LED_2_GPIO_Port GPIOB
#define START_MOD_LED_3_Pin GPIO_PIN_12
#define START_MOD_LED_3_GPIO_Port GPIOB
#define ENKODERKI_CS2_Pin GPIO_PIN_11
#define ENKODERKI_CS2_GPIO_Port GPIOD
#define ENKODERKI_CS1_Pin GPIO_PIN_12
#define ENKODERKI_CS1_GPIO_Port GPIOD
#define IMU_INTERRUPT_Pin GPIO_PIN_8
#define IMU_INTERRUPT_GPIO_Port GPIOC
#define IMU_SDA_Pin GPIO_PIN_9
#define IMU_SDA_GPIO_Port GPIOC
#define IMU_SCL_Pin GPIO_PIN_8
#define IMU_SCL_GPIO_Port GPIOA
#define START_MOD_IR2_Pin GPIO_PIN_11
#define START_MOD_IR2_GPIO_Port GPIOA
#define START_MOD_IR1_Pin GPIO_PIN_12
#define START_MOD_IR1_GPIO_Port GPIOA
#define DRV_CS1_Pin GPIO_PIN_0
#define DRV_CS1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
