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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define START_MOD_IR1_Pin GPIO_PIN_14
#define START_MOD_IR1_GPIO_Port GPIOC
#define VBAT_Pin GPIO_PIN_4
#define VBAT_GPIO_Port GPIOA
#define START_LED_RED_Pin GPIO_PIN_1
#define START_LED_RED_GPIO_Port GPIOB
#define START_LED_GREEN_Pin GPIO_PIN_2
#define START_LED_GREEN_GPIO_Port GPIOB
#define START_LED_BLUE_Pin GPIO_PIN_10
#define START_LED_BLUE_GPIO_Port GPIOB
#define START_MOD_IR3_Pin GPIO_PIN_11
#define START_MOD_IR3_GPIO_Port GPIOB
#define JOY5_Pin GPIO_PIN_11
#define JOY5_GPIO_Port GPIOD
#define JOY4_Pin GPIO_PIN_12
#define JOY4_GPIO_Port GPIOD
#define JOY3_Pin GPIO_PIN_6
#define JOY3_GPIO_Port GPIOC
#define JOY2_Pin GPIO_PIN_7
#define JOY2_GPIO_Port GPIOC
#define JOY1_Pin GPIO_PIN_8
#define JOY1_GPIO_Port GPIOC
#define OLED_SDA_Pin GPIO_PIN_9
#define OLED_SDA_GPIO_Port GPIOC
#define OLED_SCL_Pin GPIO_PIN_8
#define OLED_SCL_GPIO_Port GPIOA
#define CAN_EN_Pin GPIO_PIN_10
#define CAN_EN_GPIO_Port GPIOA
#define CAN_RX_Pin GPIO_PIN_11
#define CAN_RX_GPIO_Port GPIOA
#define CAN_TX_Pin GPIO_PIN_12
#define CAN_TX_GPIO_Port GPIOA
#define BUZZ_PWM_Pin GPIO_PIN_4
#define BUZZ_PWM_GPIO_Port GPIOB
#define OLED_SCLB8_Pin GPIO_PIN_8
#define OLED_SCLB8_GPIO_Port GPIOB
#define OLED_SDAB9_Pin GPIO_PIN_9
#define OLED_SDAB9_GPIO_Port GPIOB
#define START_MOD_IR_2_Pin GPIO_PIN_0
#define START_MOD_IR_2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
