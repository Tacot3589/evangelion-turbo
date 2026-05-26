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
#define START_MOD_IR2_Pin GPIO_PIN_14
#define START_MOD_IR2_GPIO_Port GPIOC
#define LINE_4B_Pin GPIO_PIN_0
#define LINE_4B_GPIO_Port GPIOC
#define LINE_4A_Pin GPIO_PIN_1
#define LINE_4A_GPIO_Port GPIOC
#define LINE_3B_Pin GPIO_PIN_2
#define LINE_3B_GPIO_Port GPIOC
#define LINE_3A_Pin GPIO_PIN_3
#define LINE_3A_GPIO_Port GPIOC
#define LUNA2_TX_Pin GPIO_PIN_0
#define LUNA2_TX_GPIO_Port GPIOA
#define LUNA2_RX_Pin GPIO_PIN_1
#define LUNA2_RX_GPIO_Port GPIOA
#define LUNA3_TX_Pin GPIO_PIN_2
#define LUNA3_TX_GPIO_Port GPIOA
#define LUNA3_RX_Pin GPIO_PIN_3
#define LUNA3_RX_GPIO_Port GPIOA
#define VBAT_IN_Pin GPIO_PIN_4
#define VBAT_IN_GPIO_Port GPIOA
#define LINE_2B_Pin GPIO_PIN_5
#define LINE_2B_GPIO_Port GPIOA
#define LINE_2A_Pin GPIO_PIN_6
#define LINE_2A_GPIO_Port GPIOA
#define LINE_1B_Pin GPIO_PIN_7
#define LINE_1B_GPIO_Port GPIOA
#define LINE_1A_Pin GPIO_PIN_5
#define LINE_1A_GPIO_Port GPIOC
#define START_LED_RED_Pin GPIO_PIN_1
#define START_LED_RED_GPIO_Port GPIOB
#define START_LED_GREEN_Pin GPIO_PIN_2
#define START_LED_GREEN_GPIO_Port GPIOB
#define START_LED_BLUE_Pin GPIO_PIN_10
#define START_LED_BLUE_GPIO_Port GPIOB
#define START_MOD_IR2B11_Pin GPIO_PIN_11
#define START_MOD_IR2B11_GPIO_Port GPIOB
#define LUNA1_RX_Pin GPIO_PIN_12
#define LUNA1_RX_GPIO_Port GPIOB
#define LUNA1_TX_Pin GPIO_PIN_13
#define LUNA1_TX_GPIO_Port GPIOB
#define LUNA4_TX_Pin GPIO_PIN_14
#define LUNA4_TX_GPIO_Port GPIOB
#define LUNA4_RX_Pin GPIO_PIN_15
#define LUNA4_RX_GPIO_Port GPIOB
#define JOY_CENTER_Pin GPIO_PIN_11
#define JOY_CENTER_GPIO_Port GPIOD
#define JOY_RIGHT_Pin GPIO_PIN_12
#define JOY_RIGHT_GPIO_Port GPIOD
#define JOY_LEFT_Pin GPIO_PIN_6
#define JOY_LEFT_GPIO_Port GPIOC
#define JOY_DOWN_Pin GPIO_PIN_7
#define JOY_DOWN_GPIO_Port GPIOC
#define JOY_UP_Pin GPIO_PIN_8
#define JOY_UP_GPIO_Port GPIOC
#define OLED_SDA_Pin GPIO_PIN_9
#define OLED_SDA_GPIO_Port GPIOC
#define OLED_SCL_Pin GPIO_PIN_8
#define OLED_SCL_GPIO_Port GPIOA
#define DR1_ENABLE_Pin GPIO_PIN_10
#define DR1_ENABLE_GPIO_Port GPIOA
#define DR2_ENABLE_Pin GPIO_PIN_10
#define DR2_ENABLE_GPIO_Port GPIOC
#define FAN_PWM_Pin GPIO_PIN_3
#define FAN_PWM_GPIO_Port GPIOB
#define BUZZ_PWM_Pin GPIO_PIN_4
#define BUZZ_PWM_GPIO_Port GPIOB
#define IMU_INT_LOL_3_Pin GPIO_PIN_5
#define IMU_INT_LOL_3_GPIO_Port GPIOB
#define IMU_I2C_LOL_2_Pin GPIO_PIN_6
#define IMU_I2C_LOL_2_GPIO_Port GPIOB
#define IMU_I2C_LOL_1_Pin GPIO_PIN_7
#define IMU_I2C_LOL_1_GPIO_Port GPIOB
#define EPROM_SCL_Pin GPIO_PIN_8
#define EPROM_SCL_GPIO_Port GPIOB
#define EPROM_SDA_Pin GPIO_PIN_9
#define EPROM_SDA_GPIO_Port GPIOB
#define START_MOD_IR2E0_Pin GPIO_PIN_0
#define START_MOD_IR2E0_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
