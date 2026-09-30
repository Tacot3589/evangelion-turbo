/*
 * Accelerometer.c
 *
 *  Created on: Feb 5, 2025
 *      Author: SKYNET
 */
#include "main.h"
#include "Accelerometer.h"
#include "i2c.h"
#include "math.h"
#include "stdlib.h"
#include <float.h>

#define I2C hi2c2

uint8_t I2C_ADDR;
uint8_t I2C_RX [10];
uint8_t I2C_TX [10];
uint8_t I2C_ACC [10];
uint8_t I2C_GYRO [10];
uint8_t I2C_ACCE [10];

float A_X, A_Y, A_Z;
float AX, AY;
float E_X, E_Y, E_Z;
float G_X, G_Y, G_Z;
float Vx, Vy, V;
volatile float Angle;
volatile float Total_Angle;
float Distance_Travelled;
float dt = 0.00104;

float pitch = 0;
float roll = 0;
float acc_pitch;
float acc_roll;
float gx;
float gy;

float AX_Correction, AY_Correction, AZ_Correction;
float GX_Correction, GY_Correction, GZ_Correction;
float EX_Correction, EY_Correction, EZ_Correction;
float GX_Noise, GY_Noise, GZ_Noise;

extern uint16_t DUPA;

int compare_int16_opt(const void *a, const void *b);
int16_t MedianFilter(int16_t newData, uint8_t channel);


void ACC_Init(void)
{
	  I2C_ADDR =  0x6B << 1;

	  // Who I Am?
	  HAL_I2C_Mem_Read(&I2C, I2C_ADDR, 0x0F, 1, I2C_RX, 1, HAL_MAX_DELAY); // Response should be 0x73

	  // Enable config register access;
	  I2C_TX[0] = 0x01;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x01, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);

	  I2C_TX[0] = 0x44; // Auto Increment
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x12, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, 100);

	  // Set Gyroscope range 4000 DPS frequency to 960Hz
//	  I2C_TX[0] = 0x47;
	  I2C_TX[0] = 0x4D;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x15, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);
	  I2C_TX[0] = 0x9F;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x11, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);

	  // Set Accelerometer 16g frequency 960Hz
	  I2C_TX[0] = 0x03;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x17, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);
	  I2C_TX[0] = 0x9F;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x10, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);

	  // Set Accelerometer 320g range
	  I2C_TX[0] = 0x94;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x4E, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);

	  // Disable config register access;
	  I2C_TX[0] = 0x00;
	  HAL_I2C_Mem_Write(&I2C, I2C_ADDR, 0x01, I2C_MEMADD_SIZE_8BIT, I2C_TX, 1, HAL_MAX_DELAY);


//	  I2C_TX[0] = 0x0F;
	  HAL_I2C_Mem_Read_IT(&I2C, I2C_ADDR, 0x28, I2C_MEMADD_SIZE_8BIT, I2C_ACC, 6);
}

void Acc_ReadACC(void)
{
	I2C_TX[0] = 0x0F;
	HAL_I2C_Mem_Read_IT(&I2C, I2C_ADDR, 0x28, I2C_MEMADD_SIZE_8BIT, I2C_ACC, 6);
}
void Acc_ReadACC_320G(void)
{
	I2C_TX[0] = 0x0F;
	HAL_I2C_Mem_Read_IT(&I2C, I2C_ADDR, 0x34, I2C_MEMADD_SIZE_8BIT, I2C_ACCE, 6);
}
void Acc_ReadGYRO(void)
{
	I2C_TX[0] = 0x0F;
	HAL_I2C_Mem_Read_IT(&I2C, I2C_ADDR, 0x22, I2C_MEMADD_SIZE_8BIT, I2C_GYRO, 6);
}

uint8_t Acc_Cal(void)
{
    static uint16_t i = 0;

    // ===== SUMS =====
    static float sum_Ax = 0, sum_Ay = 0, sum_Az = 0;
    static float sum_Gx = 0, sum_Gy = 0, sum_Gz = 0;

    // ===== MIN/MAX GYRO =====
    static float min_Gx = FLT_MAX, min_Gy = FLT_MAX, min_Gz = FLT_MAX;
    static float max_Gx = -FLT_MAX, max_Gy = -FLT_MAX, max_Gz = -FLT_MAX;

    uint8_t done = 0;

    // ===== DATA AQUISITION =====
    sum_Ax += A_X;
    sum_Ay += A_Y;
    sum_Az += A_Z;

    sum_Gx += G_X;
    sum_Gy += G_Y;
    sum_Gz += G_Z;

    // ===== MIN/MAX GYRO =====
    if (G_X < min_Gx) min_Gx = G_X;
    if (G_Y < min_Gy) min_Gy = G_Y;
    if (G_Z < min_Gz) min_Gz = G_Z;

    if (G_X > max_Gx) max_Gx = G_X;
    if (G_Y > max_Gy) max_Gy = G_Y;
    if (G_Z > max_Gz) max_Gz = G_Z;

    i++;

    if (i >= 1000)
    {
        // ===== GYRO BIAS =====
        GX_Correction = sum_Gx / 1000.0f;
        GY_Correction = sum_Gy / 1000.0f;
        GZ_Correction = sum_Gz / 1000.0f;

        // ===== ACC BIAS =====
        AX_Correction = sum_Ax / 1000.0f;
        AY_Correction = sum_Ay / 1000.0f;
        AZ_Correction = (sum_Az / 1000.0f) - 1.0f; // gravity

        // ===== SZUM GYRO =====
        GX_Noise = (max_Gx - min_Gx) / 2 * 1.8;
        GY_Noise = (max_Gy - min_Gy) / 2 * 1.8;
        GZ_Noise = (max_Gz - min_Gz) / 2 * 1.8;

        done = 1;

        // ===== RESET =====
        i = 0;

        sum_Ax = sum_Ay = sum_Az = 0;
        sum_Gx = sum_Gy = sum_Gz = 0;

        min_Gx = min_Gy = min_Gz = FLT_MAX;
        max_Gx = max_Gy = max_Gz = -FLT_MAX;
    }

    return done;
}

void Acc_Calc(void)
{
//	float Buff;
	#define M_PI 3.14159265358979323846f

	int16_t BufferData[9];
 //   float pitch_rad = pitch * (M_PI / 180.0f);
//    float roll_rad  = roll  * (M_PI / 180.0f);

	BufferData[0] = (I2C_ACC[1] << 8 | I2C_ACC[0]);
	BufferData[1] = (I2C_ACC[3] << 8 | I2C_ACC[2]);
	BufferData[2] = (I2C_ACC[5] << 8 | I2C_ACC[4]);
	BufferData[3] = (I2C_ACCE[1] << 8 | I2C_ACCE[0]);
	BufferData[4] = (I2C_ACCE[3] << 8 | I2C_ACCE[2]);
	BufferData[5] = (I2C_ACCE[5] << 8 | I2C_ACCE[4]);
	BufferData[6] = (I2C_GYRO[1] << 8 | I2C_GYRO[0]);
	BufferData[7] = (I2C_GYRO[3] << 8 | I2C_GYRO[2]);
	BufferData[8] = (I2C_GYRO[5] << 8 | I2C_GYRO[4]);

	for (int i = 0; i < 9; i++)
	{
		BufferData[i] = MedianFilter(BufferData[i], i);
	}

  	A_X = (float)BufferData[0] / 32768.0 * 8.0;
  	A_X = -(A_X - AX_Correction);
    A_Y = (float)BufferData[1] / 32768.0 * 8.0;
    A_Y = A_Y + AX_Correction;
    A_Z = (float)BufferData[2] / 32768.0 * 8.0;

    G_X = (float)BufferData[6] / 32768.0 * 4000.0;
    G_X = G_X - GX_Correction;
    G_Y = (float)BufferData[7] / 32768.0 * 4000.0;
    G_Y = G_Y + GX_Correction;
    G_Z = (float)BufferData[8] / 32768.0 * 4000.0;
    G_Z = G_Z - GZ_Correction;

    if (G_X < GX_Noise && G_X > -GX_Noise)
    	G_X = 0;
    if (G_Y < GY_Noise && G_Y > -GY_Noise)
    	G_Y = 0;
    if (G_Z < GZ_Noise && G_Z > -GZ_Noise)
    	G_Z = 0;

   G_X = G_X * 0.9;
   G_Y = G_Y * 0.9;
   G_Z = G_Z * 0.9;

//
    acc_pitch = atan2f(-A_X, sqrtf(A_Y * A_Y + A_Z * A_Z));
    acc_roll  = atan2f(A_Y, A_Z);

//    pitch = 0.998f * (pitch + G_Y * dt) + 0.002f * acc_pitch;
//    roll  = 0.998f * (roll + G_X * dt) + 0.002f * acc_roll;
    pitch = pitch + G_Y * dt;
    roll  = roll + G_X * dt;

    gx = -sinf(pitch);
    gy = cosf(pitch) * sinf(roll);

    AX = A_X - gx;
    AY = A_Y - gy;



  	E_X = (float)BufferData[3] / 32768.0 * 320.0;
    E_Y = (float)BufferData[4] / 32768.0 * 320.0;
    E_Z = (float)BufferData[5] / 32768.0 * 320.0;

    Angle = Angle + (G_Z / 1000.0);
    Total_Angle = Total_Angle + (G_Z / 1000.0);
    Angle = fmod(Angle, 360.0);
    if (Angle < 0)
    	Angle = Angle + 360.0;

    if (AX < 0.01 && AX > -0.01)
    	AX = 0;
    if (AY < 0.01 && AY > -0.01)
    {
	   AY = 0;
    }

 //   Acc_Velocity();
//    Acc_Position();
}

void Acc_Position(void)
{
	Distance_Travelled = Distance_Travelled - Vx * dt;
}
void Acc_Velocity(void)
{
//	static float Vx;
//	static float Vy;
	static uint8_t Timer;

	Vx = Vx + AX * 9.80665f * dt;
	Vy = Vy + AY * 9.80665f * dt;

	if (AX == 0 && AY == 0)
	{
		if (Timer >= 100)
		{
			Vx = 0;
			Vy = 0;
		}
	}
	else if (Timer > 0)
		Timer = 0;

	Timer++;
	Timer = Timer % 200;

}
/*
int16_t MedianFilter(int16_t newData)
{
    static int16_t buffer[9];
    static uint8_t currentIndex = 0;
    static uint8_t samples_count = 0;
    int16_t sorted_buffer[9];

    // add new data
    buffer[currentIndex] = newData;
    // write data to cyclic buffer
    currentIndex = (currentIndex + 1) % 9;

    // Wait till buffer is fully filled
    if (samples_count < 9)
        samples_count++;

    // Copy data to temporary buffer
    for (int i = 0; i < samples_count; i++)
    {
        sorted_buffer[i] = buffer[i];
    }
    // Sort data
    qsort(sorted_buffer, samples_count, sizeof(int16_t), compare_int16);

    return sorted_buffer[4];
}
*/
int16_t MedianFilter(int16_t newData, uint8_t channel)
{
    static int16_t circular_buffer[9][9];
    static int16_t sorted_buffer[9][9];
    static uint8_t currentIndex[9];
    static uint8_t samples_count[9];

    int16_t oldValue;
    int8_t old_value_index;

    if (channel < 9)
    {
    	// Buffer not full - initialization
    	if (samples_count[channel] < 9)
    	{
    		circular_buffer[channel][samples_count[channel]] = newData;
    		sorted_buffer[channel][samples_count[channel]] = newData;
    		samples_count[channel]++;

    		qsort(sorted_buffer[channel], samples_count[channel], sizeof(int16_t), compare_int16_opt);
    	}
    	// Long term operation
    	else
    	{
    	// Find oldest element and replace with new one;
    		oldValue = circular_buffer[channel][currentIndex[channel]];
    		circular_buffer[channel][currentIndex[channel]] = newData;

        // Copy data to circular buffer
    		currentIndex[channel] = (currentIndex[channel] + 1) % 9;

    	// Calculate only if new data is different than old data
    		if (newData != oldValue)
    		{
    		// Find oldes value and replace
    			old_value_index = -1;
    			for (int i = 0; i < 9; i++)
    			{
    				if (sorted_buffer[channel][i] == oldValue)
    				{
    					sorted_buffer[channel][i] = newData;
    					old_value_index = i;
    					break;
    				}
    			}
    			// If oldes value not found
    			if(old_value_index == -1)
    				qsort(sorted_buffer[channel], 9, sizeof(int16_t), compare_int16_opt);

    			else
    			{
    			// Sort array with new element
    				int i = old_value_index;
    				while (i > 0 && sorted_buffer[channel][i] < sorted_buffer[channel][i - 1])
    				{
    					int16_t temp = sorted_buffer[channel][i];
    					sorted_buffer[channel][i] = sorted_buffer[channel][i - 1];
    					sorted_buffer[channel][i - 1] = temp;
    					i--;
    				}
    				while (i < 9 - 1 && sorted_buffer[channel][i] > sorted_buffer[channel][i + 1])
    				{
    					int16_t temp = sorted_buffer[channel][i];
    					sorted_buffer[channel][i] = sorted_buffer[channel][i + 1];
    					sorted_buffer[channel][i + 1] = temp;
    					i++;
    				}
    			}
    		}
    	}
    }
    return sorted_buffer[channel][4];
}

int compare_int16_opt(const void *a, const void *b)
{
    int16_t val1 = *(const int16_t *)a;
    int16_t val2 = *(const int16_t *)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}
/*
void UpdateOrientation(OrientationState *state,
                       float acc_x, float acc_y, float acc_z,
                       float gyro_x, float gyro_y, float gyro_z,
                       float dt)
{
	// calculate from accelerometer;
    float roll_acc = atan2(acc_y, acc_z) * 180.0 / M_PI;
    float pitch_acc = atan2(-acc_x, sqrt(acc_y * acc_y + acc_z * acc_z)) * 180.0 / M_PI;

    // Add Gyro
    // Roll
    state->roll = ALPHA * (state->roll + gyro_x * dt) + (1.0 - ALPHA) * roll_acc;

    // Pitch
    state->pitch = ALPHA * (state->pitch + gyro_y * dt) + (1.0 - ALPHA) * pitch_acc;
}
*/
