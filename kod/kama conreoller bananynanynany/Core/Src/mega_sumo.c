/*
 * mega_sumo.c
 *
 *  Created on: Apr 2, 2025
 *      Author: SKYNET
 */


/*
 * sumo.c
 *
 *  Created on: Apr 2, 2025
 *      Author: SKYNET
 */
#include "main.h"

extern uint16_t 	ADC_readout			[];

extern uint16_t 	FRONT_LEFT_Distance, FRONT_LEFT_Return, FRONT_LEFT_Temperature;
extern uint16_t 	FRONT_RIGHT_Distance, FRONT_RIGHT_Return, FRONT_RIGHT_Temperature;
extern uint16_t 	ANGLE_LEFT_Distance, ANGLE_LEFT_Return, ANGLE_LEFT_Temperature;
extern uint16_t 	ANGLE_RIGHT_Distance, ANGLE_RIGHT_Return, ANGLE_RIGHT_Temperature;

extern uint16_t 	ADC_threshold_HI;
extern uint16_t		ADC_threshold_LO;
extern uint16_t		Line_Color_Threshold;

extern uint8_t 		LastEnemyLocation; // taken from sumo

extern uint8_t		Module_Switch		[];

uint8_t MEGA_StartParameters(void);

void MEGA_Battle(void)
{
	static uint8_t	Ring_Status;
	static uint8_t	Enemy_Status;
	static uint16_t Reverse_Timer;
	static uint16_t Battle_Timer;
	static uint8_t	SumoBattleInit;
	if(SumoBattleInit == 0)
	{
//		SumoBattleInit = MEGA_StartParameters();
	//	SumoBattleInit = 1;
		MOTOR_DRIVER_SetDuty(BOTH_MOTORS, MEGA_VELOCITY_ATTACK);
	}


	// Rush forward after start - for a bit
	else if(SumoBattleInit == 1)
	{
		Battle_Timer++;

		MOTOR_DRIVER_SetDuty(BOTH_MOTORS, MEGA_VELOCITY_ATTACK);
		MOTOR_DRIVER_TransmitData();
		if (Battle_Timer == 110)
			SumoBattleInit = 2;
	}

	else if (SumoBattleInit == 2)
	{
//	MovingAverage(ADC_readout_A[SIDE_LEFT], ADC_readout_A[ANGLE_LEFT], ADC_readout_A[SIDE_RIGHT], ADC_readout_A[ANGLE_RIGHT]);
		Ring_Status = RingStatus(NBR_OF_LINE_SENS);
		Enemy_Status = EnemyLocation(NBR_OF_DISTANCE_SENS);

	 // =====================================ROBOT INSIDE OF RING AREA==================

		if (Ring_Status == ON_RING)
		{
			// Standard battle
			if (Module_Switch[0] == 0)
			{
				// Both Front detect
				if (Enemy_Status == ENEMY_FRONT)
					MOTOR_DRIVER_SetDuty(BOTH_MOTORS, SUMO_VELOCITY_ATTACK);

				else if (Enemy_Status == ENEMY_FRONT_LEFT)
				{
					MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MEGA_VELOCITY_SEARCH/3);
					MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MEGA_VELOCITY_SEARCH);
					LastEnemyLocation = ENEMY_LEFT;
				}

				else if (Enemy_Status == ENEMY_FRONT_RIGHT)
				{
					MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MEGA_VELOCITY_SEARCH/3);
					MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MEGA_VELOCITY_SEARCH);
					LastEnemyLocation = ENEMY_RIGHT;
				}

				// ------------------------------------------ANGLE SENSORS -----------------------------------

				else if (Enemy_Status == ENEMY_LEFT)
				{
					MOTOR_DRIVER_SetDuty(LEFT_MOTOR, 0);
					MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MEGA_VELOCITY_SEARCH);
					LastEnemyLocation = ENEMY_LEFT;
				}

				else if (Enemy_Status == ENEMY_RIGHT)
				{
					MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, 0);
					MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MEGA_VELOCITY_SEARCH);
					LastEnemyLocation = ENEMY_RIGHT;
				}

				else if (Reverse_Timer == 0)
				{
					if (LastEnemyLocation == UNKNOWN)
						MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);

					if (LastEnemyLocation == ENEMY_RIGHT)
					{
						MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, -MEGA_VELOCITY_SEARCH);
						MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MEGA_VELOCITY_SEARCH);
					}
					if (LastEnemyLocation == ENEMY_LEFT)
					{
						MOTOR_DRIVER_SetDuty(LEFT_MOTOR, -MEGA_VELOCITY_SEARCH);
						MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MEGA_VELOCITY_SEARCH);
					}
				}
			}
			// Capture the flag mode
			else if (Module_Switch[0] == 1)
			{
				if (FRONT_LEFT_Distance <= TFMINI_MAX_RANGE && FRONT_RIGHT_Distance <= TFMINI_MAX_RANGE && FRONT_LEFT_Return < TFMINI_STRENGTH_THRESHOLD && FRONT_RIGHT_Return < TFMINI_STRENGTH_THRESHOLD && FRONT_LEFT_Distance != 0 && FRONT_RIGHT_Distance != 0)
					MOTOR_DRIVER_SetDuty(BOTH_MOTORS, MEGA_VELOCITY_ATTACK);

				else if (FRONT_LEFT_Distance <= TFMINI_MAX_RANGE && FRONT_LEFT_Return < TFMINI_STRENGTH_THRESHOLD && FRONT_LEFT_Distance != 0)
				{
					MOTOR_DRIVER_SetDuty(LEFT_MOTOR, 0);
					MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MEGA_VELOCITY_SEARCH);
					LastEnemyLocation = ENEMY_LEFT;
				}

				else if (FRONT_RIGHT_Distance <= TFMINI_MAX_RANGE && FRONT_RIGHT_Return < TFMINI_STRENGTH_THRESHOLD && FRONT_RIGHT_Distance != 0)
				{
					MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, 0);
					MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MEGA_VELOCITY_SEARCH);
					LastEnemyLocation = ENEMY_RIGHT;
				}
				else if (Reverse_Timer == 0)
				{
					if (LastEnemyLocation == UNKNOWN)
						MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);

					if (LastEnemyLocation == ENEMY_RIGHT)
					{
						MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, -MEGA_VELOCITY_SEARCH);
						MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MEGA_VELOCITY_SEARCH);
					}
					if (LastEnemyLocation == ENEMY_LEFT)
					{
						MOTOR_DRIVER_SetDuty(LEFT_MOTOR, -MEGA_VELOCITY_SEARCH);
						MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MEGA_VELOCITY_SEARCH);
					}
				}
			}
		}
		//====================================================| OUTSIDE RING AREA |===================================================
		else if (Ring_Status == FRONT_RIGHT_OUT)
		{
			MOTOR_DRIVER_SetDuty(BOTH_MOTORS, MEGA_VELOCITY_REVERSE);
			//---- ROTATE
			LastEnemyLocation = ENEMY_LEFT;
			Reverse_Timer = 1;
		}
		else if (Ring_Status == FRONT_LEFT_OUT)
		{
			MOTOR_DRIVER_SetDuty(BOTH_MOTORS, MEGA_VELOCITY_REVERSE);
			//---- ROTATE
			LastEnemyLocation = ENEMY_RIGHT;
			Reverse_Timer = 1;
		}

		if (Reverse_Timer > 0)
			Reverse_Timer = (Reverse_Timer + 1) % MEGA_RETURN_TIME;

	}
}

uint8_t MEGA_StartParameters(void)
{
//	static uint16_t Delay_Timer;
	uint8_t ready = 1;
//	if(LINE_CAL_TYPE == 2 || Autocal == 1 )
	if(LINE_CAL_TYPE == 3)
	{
		if(ADC_readout[ADC_CHANNEL_LEFT_LINE_B] < Line_Color_Threshold)
		{
			ADC_threshold_HI = Line_Color_Threshold;
			ADC_threshold_LO = 0;
		}
		else
		{
			ADC_threshold_HI = 4096;
			ADC_threshold_LO = Line_Color_Threshold;
		}
	}
	ready = 0;

	return ready;
}

void MEGA_PreStartParameters(void)
{
	if (FRONT_LEFT_Distance < 10)
		LastEnemyLocation = ENEMY_LEFT;
	if (FRONT_RIGHT_Distance < 10)
		LastEnemyLocation = ENEMY_RIGHT;
}
