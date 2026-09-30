/*
 * robot_data.h
 *
 *  Created on: Aug 6, 2025
 *      Author: SKYNET
 */

#ifndef INC_ROBOT_DATA_H_
#define INC_ROBOT_DATA_H_

#include <stdint.h>

// old define structure
typedef struct {
    uint8_t		ADC_sensor1A;
    uint8_t	    ADC_sensor1B;
    uint8_t		ADC_sensor2A;
    uint8_t	    ADC_sensor2B;
    uint8_t		ADC_sensor3A;
    uint8_t	    ADC_sensor3B;
    uint8_t		ADC_sensor4A;
    uint8_t	    ADC_sensor4B;
    uint8_t	    BatteryVoltage;
    uint8_t		Number_of_sensors;

} ADC_config;

typedef struct {
    uint8_t		Number_of_TFmini;
    uint8_t		Left_motor;
    uint8_t		Right_motor;
    uint8_t		Reverse_left_motor;
    uint8_t		Reverse_right_motor;

} IO_config;

typedef struct {
    uint16_t	Front_distance_range;
    uint16_t	Angle_distance_range;
    uint16_t	Side_distance_range;
    uint16_t	Ring_threshold_value;

	int8_t		Attack_velocity;
	int8_t		Search_velocity;
	int8_t		Reverse_velocity;
	int8_t		Rush_velocity;
	int8_t		Rotation_velocity;
	uint16_t	Return_time;
	uint16_t	Rush_Time;

	int8_t		Mouse_Drive_Velocity ;
	int8_t		Mouse_Rotate_Velocity_Max;
	int8_t		Mouse_Rotate_Velocity_Min;
	int8_t		Mouse_Slow_Factor;


} PARAM_config;

// global pointer
extern const ADC_config* 	active_ADC_config;
extern const IO_config* 	active_IO_config;
extern const PARAM_config* 	active_PARAM_config;

// Select Function
uint8_t SelectRobot(void);



#endif /* INC_ROBOT_DATA_H_ */
