/*
 * robot_data.c
 *
 *  Created on: Aug 7, 2025
 *      Author: SKYNET
 */

#include "robot_data.h"
#include "main.h"
#include "stdio.h"

// -------------------------------------------- HIROSHIMA ------------------------------------------------

const ADC_config HIROSHIMA_ADC =
{
    .ADC_sensor1A = 9,
	.ADC_sensor1B = 10,
	.ADC_sensor2A = 8,
	.ADC_sensor2B = 11,
	.ADC_sensor3A = 2,
	.ADC_sensor3B = 3,
	.ADC_sensor4A = 6,
	.ADC_sensor4B = 7,
	.BatteryVoltage = 12,
	.Number_of_sensors = 4,
};

const IO_config HIROSHIMA_IO =
{
	.Number_of_TFmini = 4,
	.Left_motor = 1, 				// CAN Motor 1 or 2
	.Right_motor = 2,				// CAN Motor 1 or 2
	.Reverse_left_motor = 1,		// Forward 0, Reverse 1
	.Reverse_right_motor = 0,		// Forward 0, Reverse 1
};

const PARAM_config HIROSHIMA_PARAM =
{
    .Front_distance_range = 100,	// distance in cm
	.Angle_distance_range = 80,		// distance in cm
	.Side_distance_range = 0,		// distance in cm
	.Ring_threshold_value = 3000,	// ADC raw value 0-4096

	.Attack_velocity = 50, 			// range -100 to 100	// default is 50
	.Search_velocity = 25, 			// range -100 to 100	// default is 25
	.Reverse_velocity = -25,		// range -100 to 100
	.Rush_velocity = 50, 			// range -100 to 100
	.Rotation_velocity = 25,		// range -100 to 100
	.Return_time = 500, 			// time set in ms.
	.Rush_Time = 250,				// time for fast speed drive toward ring edge in ms

	.Mouse_Drive_Velocity 		= 30,
	.Mouse_Slow_Factor			= 20,
	.Mouse_Rotate_Velocity_Max 	= 16,
	.Mouse_Rotate_Velocity_Min	= 4,

};
// -------------------------------------------- HIROSHIMKA ------------------------------------------------

const ADC_config HIROSHIMKA_ADC =
{
    .ADC_sensor1A = 9,
	.ADC_sensor1B = 10,
	.ADC_sensor2A = 8,
	.ADC_sensor2B = 11,
	.ADC_sensor3A = 2,
	.ADC_sensor3B = 3,
	.ADC_sensor4A = 6,
	.ADC_sensor4B = 7,
	.BatteryVoltage = 12,
	.Number_of_sensors = 4,
};

const IO_config HIROSHIMKA_IO =
{
	.Number_of_TFmini = 4,
	.Left_motor = 1, 				// CAN Motor 1 or 2
	.Right_motor = 2,				// CAN Motor 1 or 2
	.Reverse_left_motor = 1,		// Forward 0, Reverse 1
	.Reverse_right_motor = 0,		// Forward 0, Reverse 1
};

const PARAM_config HIROSHIMKA_PARAM =
{
    .Front_distance_range = 100,	// distance in cm
	.Angle_distance_range = 80,		// distance in cm
	.Side_distance_range = 0,		// distance in cm
	.Ring_threshold_value = 3000,	// ADC raw value 0-4096

	.Attack_velocity = 30, 			// range -100 to 100	// default is 85
	.Search_velocity = 25, 			// range -100 to 100	// default is 60
	.Reverse_velocity = -25,		// range -100 to 100
	.Rush_velocity = 20, 			// range -100 to 100	//80
	.Rotation_velocity = 20,		// range -100 to 100	// default 60
	.Return_time = 500, 			// time set in ms.
	.Rush_Time = 250,				// time for fast speed drive toward ring edge in ms

	.Mouse_Drive_Velocity 		= 30,
	.Mouse_Slow_Factor			= 20,
	.Mouse_Rotate_Velocity_Max 	= 20,
	.Mouse_Rotate_Velocity_Min	= 4,

};

// -------------------------------------------- BABY HIROSHIMA ------------------------------------------------
const ADC_config BABY_HIROSHIMA_ADC =
{
	.ADC_sensor1A = 9,
	.ADC_sensor1B = 10,
	.ADC_sensor2A = 8,
	.ADC_sensor2B = 11,
	.ADC_sensor3A = 2,
	.ADC_sensor3A = 3,
	.ADC_sensor3B = 5,
	.ADC_sensor4A = 6,
	.ADC_sensor4B = 7,
	.BatteryVoltage = 12,
	.Number_of_sensors = 2,
};

const IO_config BABY_HIROSHIMA_IO =
{
	.Number_of_TFmini = 2,
	.Left_motor = 1, 				// CAN Motor 1 or 2
	.Right_motor = 2,				// CAN Motor 1 or 2
	.Reverse_left_motor = 1,		// Forward 0, Reverse 1
	.Reverse_right_motor = 0,		// Forward 0, Reverse 1
};

const PARAM_config BABY_HIROSHIMA_PARAM =
{
    .Front_distance_range = 80,		// distance in cm
	.Angle_distance_range = 80,		// distance in cm
	.Side_distance_range = 0,		// distance in cm
	.Ring_threshold_value = 3000,	// ADC raw value 0-4096

	.Attack_velocity = 60, 			// range -100 to 100
	.Search_velocity = 20, 			// range -100 to 100
	.Reverse_velocity = -15,		// range -100 to 100
	.Rush_velocity = 20, 			// range -100 to 100
	.Rotation_velocity = 25,		// range -100 to 100
	.Return_time = 500, 			// time set in ms.
	.Rush_Time = 250,				// time for fast speed drive toward ring edge in ms

	.Mouse_Drive_Velocity 		= 15,
	.Mouse_Slow_Factor			= 8,
	.Mouse_Rotate_Velocity_Max 	= 20,
	.Mouse_Rotate_Velocity_Min	= 4,


};

// -------------------------------------------- BABY HIROSHIMKA K ------------------------------------------------
const ADC_config BABY_HIROSHIMKA_ADC =
{
	.ADC_sensor1A = 9,
	.ADC_sensor1B = 10,
	.ADC_sensor2A = 8,
	.ADC_sensor2B = 11,
	.ADC_sensor3A = 2,
	.ADC_sensor3A = 3,
	.ADC_sensor3B = 5,
	.ADC_sensor4A = 6,
	.ADC_sensor4B = 7,
	.BatteryVoltage = 12,
	.Number_of_sensors = 2,
};

const IO_config BABY_HIROSHIMKA_IO =
{
	.Number_of_TFmini = 2,
	.Left_motor = 1, 				// CAN Motor 1 or 2
	.Right_motor = 2,				// CAN Motor 1 or 2
	.Reverse_left_motor = 1,		// Forward 0, Reverse 1
	.Reverse_right_motor = 0,		// Forward 0, Reverse 1
};

const PARAM_config BABY_HIROSHIMKA_PARAM =
{
    .Front_distance_range = 80,		// distance in cm
	.Angle_distance_range = 80,		// distance in cm
	.Side_distance_range = 0,		// distance in cm
	.Ring_threshold_value = 3000,	// ADC raw value 0-4096

	.Attack_velocity = 60, 			// range -100 to 100
	.Search_velocity = 20, 			// range -100 to 100
	.Reverse_velocity = -15,		// range -100 to 100
	.Rush_velocity = 20, 			// range -100 to 100
	.Rotation_velocity = 25,		// range -100 to 100
	.Return_time = 500, 			// time set in ms.
	.Rush_Time = 250,				// time for fast speed drive toward ring edge in ms

	.Mouse_Drive_Velocity 		= 15,
	.Mouse_Slow_Factor			= 8,
	.Mouse_Rotate_Velocity_Max 	= 20,
	.Mouse_Rotate_Velocity_Min	= 4,
};
// -------------------------------------------- KAMA ------------------------------------------------
const ADC_config KAMA_ADC =
{
	.ADC_sensor1A 		= 9,
	.ADC_sensor1B 		= 10,
	.ADC_sensor2A 		= 8,
	.ADC_sensor2B 		= 11,
	.ADC_sensor3A 		= 2,
	.ADC_sensor3A 		= 3,
	.ADC_sensor3B 		= 5,
	.ADC_sensor4A 		= 6,
	.ADC_sensor4B 		= 7,
	.BatteryVoltage 	= 12,
	.Number_of_sensors 	= 2,
};

const IO_config KAMA_IO =
{
	.Number_of_TFmini 		= 2,
	.Left_motor 			= 1, 	// CAN Motor 1 or 2
	.Right_motor 			= 2,	// CAN Motor 1 or 2
	.Reverse_left_motor 	= 0,	// Forward 0, Reverse 1 <- this one bugged
	.Reverse_right_motor 	= 1,	// Forward 0, Reverse 1
};

const PARAM_config KAMA_PARAM =
{
    .Front_distance_range 	= 80,	// distance in cm
	.Angle_distance_range 	= 80,	// distance in cm
	.Side_distance_range 	= 0,	// distance in cm
	.Ring_threshold_value 	= 3000,	// ADC raw value 0-4096

	.Attack_velocity 	= 20, 		// range -100 to 100 	// 85
	.Search_velocity 	= 10, 		// range -100 to 100	// 40
	.Reverse_velocity 	= -10,		// range -100 to 100	//-20
	.Rush_velocity 		= 10, 		// range -100 to 100	// 20
	.Rotation_velocity 	= 25,		// range -100 to 100	// 25
	.Return_time 		= 500, 		// time set in ms.
	.Rush_Time = 250,				// time for fast speed drive toward ring edge in ms

	.Mouse_Drive_Velocity 		= 45,	//45
	.Mouse_Slow_Factor			= 30,	//30
	.Mouse_Rotate_Velocity_Max 	= 10,	//20
	.Mouse_Rotate_Velocity_Min	= 5,	//5

};
// -------------------------------------------- BABY KAMA ------------------------------------------------
const ADC_config BABY_KAMA_ADC =
{
	.ADC_sensor1A 		= 9,
	.ADC_sensor1B 		= 10,
	.ADC_sensor2A 		= 8,
	.ADC_sensor2B 		= 11,
	.ADC_sensor3A 		= 2,
	.ADC_sensor3A 		= 3,
	.ADC_sensor3B 		= 5,
	.ADC_sensor4A 		= 6,
	.ADC_sensor4B 		= 7,
	.BatteryVoltage 	= 12,
	.Number_of_sensors 	= 2,
};

const IO_config BABY_KAMA_IO =
{
	.Number_of_TFmini 		= 2,
	.Left_motor 			= 1, 	// CAN Motor 1 or 2
	.Right_motor 			= 2,	// CAN Motor 1 or 2
	.Reverse_left_motor 	= 0,	// Forward 0, Reverse 1
	.Reverse_right_motor 	= 0,	// Forward 0, Reverse 1
};

const PARAM_config BABY_KAMA_PARAM =
{
    .Front_distance_range 	= 80,	// distance in cm
	.Angle_distance_range 	= 80,	// distance in cm
	.Side_distance_range 	= 0,	// distance in cm
	.Ring_threshold_value 	= 3000,	// ADC raw value 0-4096

	.Attack_velocity 	= 60, 		// range -100 to 100 	// 85
	.Search_velocity 	= 40, 		// range -100 to 100	// 40
	.Reverse_velocity 	= -40,		// range -100 to 100	//-20
	.Rush_velocity 		= 50, 		// range -100 to 100	// 20
	.Rotation_velocity 	= 50,		// range -100 to 100	// 25
	.Return_time 		= 500, 		// time set in ms.
	.Rush_Time = 250,				// time for fast speed drive toward ring edge in ms

	.Mouse_Drive_Velocity 		= 45,	//45
	.Mouse_Slow_Factor			= 30,	//30
	.Mouse_Rotate_Velocity_Max 	= 40,	//20
	.Mouse_Rotate_Velocity_Min	= 5,	//5

};

// --------------------------------------------SELECTION------------------------------------------------

// global pointer
const ADC_config* active_ADC_config;
const IO_config* active_IO_config;
const PARAM_config* active_PARAM_config;

extern uint16_t ADC_readout[];

uint8_t SelectRobot(void)
{
	uint8_t Feedback;
    // select based on ADC hardware PIN.
   if (ADC_readout[13] > 80 && ADC_readout[13] < 120)
    {
    	active_ADC_config = 	&BABY_HIROSHIMA_ADC;
       	active_IO_config = 		&BABY_HIROSHIMA_IO;
       	active_PARAM_config =	&BABY_HIROSHIMA_PARAM;
    	Feedback = BABY_HIROSHIMA;
    }

    else if (ADC_readout[13] > 20 && ADC_readout[13] < 60)
    {
       	active_ADC_config = 	&HIROSHIMA_ADC;
       	active_IO_config = 		&HIROSHIMA_IO;
       	active_PARAM_config = 	&HIROSHIMA_PARAM;
       	Feedback = HIROSHIMA;
    }

   if (ADC_readout[13] > 1290 && ADC_readout[13] < 1330)
    {
    	active_ADC_config = 	&HIROSHIMKA_ADC;
       	active_IO_config = 		&HIROSHIMKA_IO;
       	active_PARAM_config = 	&HIROSHIMKA_PARAM;
    	Feedback = HIROSHIMKA;
    }

   if (ADC_readout[13] > 160 && ADC_readout[13] < 200)
    {
    	active_ADC_config = 	&BABY_HIROSHIMKA_ADC;
       	active_IO_config = 		&BABY_HIROSHIMKA_IO;
       	active_PARAM_config = 	&BABY_HIROSHIMKA_PARAM;
    	Feedback = BABY_HIROSHIMKA;
    }

/*   if (ADC_readout[13] > 850 && ADC_readout[13] < 890)
     {
     	active_ADC_config = 	&BABY_KAMA_ADC;
     	active_IO_config = 		&BABY_KAMA_IO;
     	active_PARAM_config = 	&BABY_KAMA_PARAM;
     	Feedback = BABY_KAMA;
     }*/

   if (ADC_readout[13] > 850 && ADC_readout[13] < 890)
     {
     	active_ADC_config = 	&KAMA_ADC;
     	active_IO_config = 		&KAMA_IO;
     	active_PARAM_config = 	&KAMA_PARAM;
     	Feedback = KAMA;
     }

   // tests for KAMA
   if (ADC_readout[13] > 660 && ADC_readout[13] < 700)
    {
    	active_ADC_config = &KAMA_ADC;
       	active_IO_config = &KAMA_IO;
       	active_PARAM_config = &KAMA_PARAM;
    	Feedback = KAMA;
    }

   if (ADC_readout[13] > 290 && ADC_readout[13] < 330)
    {
    	active_ADC_config = &KAMA_ADC;
       	active_IO_config = &KAMA_IO;
       	active_PARAM_config = &KAMA_PARAM;
    	Feedback = KAMA;
    }


    return Feedback;
}
