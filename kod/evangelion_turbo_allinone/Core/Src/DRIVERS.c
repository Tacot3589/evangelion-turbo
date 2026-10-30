/*
 * start_module.c
 *
 *  Created on: Oct 23, 2026
 *      Author: szymo
 */


#include "DRIVERS.h"
#include "main.h"
#include "MY_INCLUDES.h"

uint8_t BUFFER[20];

uint8_t DRIVERS_INIT(SPI_HandleTypeDef *hspi)
{
    const struct {
        uint8_t reg;
        uint8_t value;
    } config[] = {
        // TOFF=00; pozostałe pola IC1: PWM z pinów, ustawienia domyślne
        { DRV_REG_IC1_CONTROL, 0x11u },

        // ITRIP_REP=1, TSD_MODE=1, OTW_REP=1,
        // OCP_TRETRY=00, OCP_MODE=10, DIS_CPUV=0
        { DRV_REG_IC2_CONTROL, 0xE2u },

        // ITRIP_LVL=11 (7 A); pozostałe pola IC4 = 0
        { DRV_REG_IC4_CONTROL, 0x0Cu }
    };

    GPIO_TypeDef *csPort[2] = {
        DRV_CS_1_GPIO_Port,
        DRV_CS_2_GPIO_Port
    };
    uint16_t csPin[2] = {
        DRV_CS_1_Pin,
        DRV_CS_2_Pin
    };

    uint16_t tx, rx;
    uint8_t driver, i;

    // Oba CS nieaktywne
    HAL_GPIO_WritePin(csPort[0], csPin[0], GPIO_PIN_SET);
    HAL_GPIO_WritePin(csPort[1], csPin[1], GPIO_PIN_SET);

    for (driver = 0; driver < 2; driver++) {
        for (i = 0; i < 3; i++) {
            tx = DRV_CMD_WRITE(config[i].reg, config[i].value);
            rx = 0;

            HAL_GPIO_WritePin(csPort[driver], csPin[driver], GPIO_PIN_RESET);

            HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(
                hspi, (uint8_t *)&tx, (uint8_t *)&rx, 1, 10);

            HAL_GPIO_WritePin(csPort[driver], csPin[driver], GPIO_PIN_SET);

            if (status != HAL_OK) {
                return 1;
            }

            HAL_Delay(1); // wymagane nSCS-high to min. 500 ns
        }
    }

    return 0;
}


Velocity_t SET_MOTORS(int16_t L, int16_t R)
{
	Velocity_t M = (Velocity_t){L, R};
	int16_t magnitude, velocity;

	if(SWITCH_MOTORS)
	{
		int16_t temp=M.R;
		M.R=M.L;
		M.L=temp;
	}

	Motors.Requested = M;
	M = ACCELERATION_COMPENSATION(M);
	M = CURRENT_COMPENSATION(M);
	M = TEMPERATURE_COMPENSATION(M);

	if(M.L > 1000)
		M.L = 1000;
	else if(M.L < -1000)
		M.L = -1000;

	if(M.R > 1000)
		M.R = 1000;
	else if(M.R < -1000)
		M.R = -1000;

	if(REVERSE_RIGHT_MOTOR)
		M.R = - M.R;

	if(REVERSE_LEFT_MOTOR)
		M.L = - M.L;

	if(M.L == 0)
	{
		TIM4->CCR1 = 0;
		TIM4->CCR2 = 0;
	}
	else
	{
	    magnitude = M.L;
	    if (magnitude < 0) magnitude = -magnitude;
	    velocity = REAL_MIN_PWM + magnitude * (REAL_MAX_PWM - REAL_MIN_PWM) / 1000;
	    if(M.L > 0)
	    {
			TIM4->CCR1 = velocity;
			TIM4->CCR2 = 0;
			Motors.Set.L = velocity;
	    }
	    else
	    {
	    	TIM4->CCR1 = 0;
	    	TIM4->CCR2 = velocity;
	    	Motors.Set.L = velocity;
	    }
	}

	if(M.R == 0)
	{
		TIM8->CCR1 = 0;
		TIM8->CCR3 = 0;
	}
	else
	{
	    magnitude = M.R;
	    if (magnitude < 0) magnitude = -magnitude;
	    velocity = REAL_MIN_PWM + magnitude * (REAL_MAX_PWM - REAL_MIN_PWM) / 1000;
	    if(M.R > 0)
	    {
	    	TIM8->CCR1 = velocity;
	    	TIM8->CCR3 = 0;
	    	Motors.Set.R = velocity;
	    }
	    else
	    {
	    	TIM8->CCR1 = 0;
	    	TIM8->CCR3 = velocity;
	    	Motors.Set.R = -velocity;
	    }
	}

	return Motors.Set;
}



static Velocity_t ACCELERATION_COMPENSATION(Velocity_t M)
{
	M.L = Acceleration_Time_Compensation_L(M.L);
	M.R = Acceleration_Time_Compensation_R(M.R);
	return M;
}

static Velocity_t TEMPERATURE_COMPENSATION(Velocity_t M)
{
	if(Motors.DRV_OTW.L == true)
		M.L = M.L/2;
	if(Motors.DRV_OTW.R == true)
		M.R = M.R/2;
	return M;
}

static Velocity_t CURRENT_COMPENSATION(Velocity_t M)
{
	if(Motors.DRV_Current.L >= 10000)
		M.L = M.L/2;
	if(Motors.DRV_Current.L >= 10000)
		M.R = M.R/2;
	return M;
}


int16_t Acceleration_Time_Compensation_L(int16_t Duty)
{
    static int16_t current_duty = 0;
    static int16_t start_duty = 0;
    static int16_t target_duty = 0;
    static int16_t ramp_delta = 0;
    uint16_t t_ms;
    t_ms = __HAL_TIM_GET_COUNTER(&htim1) / 10;

    if(MAX_ACCELERATION_MS == 0)
    {
        return Duty;
    }
    else if (Duty <= current_duty)
    {
    	HAL_TIM_Base_Stop(&htim1);
    	return current_duty = start_duty = target_duty = Duty;
    }
    else if(target_duty != Duty)
    {
        current_duty = start_duty + (int32_t)ramp_delta * t_ms / MAX_ACCELERATION_MS;

        start_duty = current_duty;
        target_duty = Duty;
        ramp_delta = target_duty - start_duty;

        __HAL_TIM_SET_COUNTER(&htim1, 0);
        HAL_TIM_Base_Start(&htim1);

        return current_duty;
    }

    if(t_ms >= MAX_ACCELERATION_MS)
    {
        HAL_TIM_Base_Stop(&htim1);
        current_duty = target_duty;
        return current_duty;
    }

    current_duty = start_duty + (int32_t)ramp_delta * t_ms / MAX_ACCELERATION_MS;

    return current_duty;
}


int16_t Acceleration_Time_Compensation_R(int16_t Duty)
{
    static int16_t current_duty = 0;
    static int16_t start_duty = 0;
    static int16_t target_duty = 0;
    static int16_t ramp_delta = 0;
    uint16_t t_ms;
    t_ms = __HAL_TIM_GET_COUNTER(&htim2) / 10;

    if(MAX_ACCELERATION_MS == 0)
    {
        return Duty;
    }
    else if (Duty <= current_duty)
    {
    	HAL_TIM_Base_Stop(&htim2);
    	return current_duty = start_duty = target_duty = Duty;
    }
    else if(target_duty != Duty)
    {
        current_duty = start_duty + (int32_t)ramp_delta * t_ms / MAX_ACCELERATION_MS;

        start_duty = current_duty;
        target_duty = Duty;
        ramp_delta = target_duty - start_duty;

        __HAL_TIM_SET_COUNTER(&htim2, 0);
        HAL_TIM_Base_Start(&htim2);

        return current_duty;
    }

    if(t_ms >= MAX_ACCELERATION_MS)
    {
        HAL_TIM_Base_Stop(&htim2);
        current_duty = target_duty;
        return current_duty;
    }

    current_duty = start_duty + (int32_t)ramp_delta * t_ms / MAX_ACCELERATION_MS;

    return current_duty;
}
