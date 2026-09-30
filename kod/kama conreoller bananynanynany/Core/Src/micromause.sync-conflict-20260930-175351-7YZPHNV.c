/*
 * micromause.c
 *
 *  Created on: Mar 12, 2026
 *      Author: SKYNET
 */


#include "main.h"
#include "accelerometer.h"

#define ROTATING 			1
#define IDLE				2
#define DRIVING_STRAIGHT 	3
#define IDLE_AFTER_FINISH	4

// Stałe regulatora (wymagają dostrojenia do Twojego robota)
#define KP_ROTATION 		0.5f      	// Moc obrotu w stosunku do błędu
#define KP_STRAIGHT			0.5f
#define MIN_PWM 			(active_PARAM_config->Mouse_Rotate_Velocity_Min)       		// Minimalna moc, przy której silniki jeszcze ruszają
#define MAX_PWM 			(active_PARAM_config->Mouse_Rotate_Velocity_Max)        	// Maksymalna dopuszczalna moc obrotu
#define DRIVE_PWM			(active_PARAM_config->Mouse_Drive_Velocity)
#define SLOWDOWN			(active_PARAM_config->Mouse_Slow_Factor)
#define ANGLE_THRESHOLD 	2.0f 	 	// Dopuszczalny błąd (np. +/- 1 stopień)

extern uint16_t 	FRONT_LEFT_Distance, FRONT_LEFT_Return, FRONT_LEFT_Temperature;
extern uint16_t 	FRONT_RIGHT_Distance, FRONT_RIGHT_Return, FRONT_RIGHT_Temperature;
extern uint16_t 	ANGLE_LEFT_Distance, ANGLE_LEFT_Return, ANGLE_LEFT_Temperature;
extern uint16_t 	ANGLE_RIGHT_Distance, ANGLE_RIGHT_Return, ANGLE_RIGHT_Temperature;

extern uint8_t		Module_Switch		[];

extern float 	Angle;
float 			Target_Angle;
uint16_t 		Target_Distance;
uint8_t 		Motion_Status = IDLE;

extern uint16_t DUPA;
int16_t 		traveled;
uint16_t 		current_sensor_val;
static uint16_t start_distance = 0;
//#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

uint8_t target_reached(float error);
uint8_t rotate_robot(float angle_to_add);
uint8_t reverse_time(uint16_t time_ms);
uint8_t drive_distance(uint16_t target_dist_cm);
uint8_t wait_before_start(uint16_t time_ms);
float normalize_angle(float angle);
static inline int16_t limit(int16_t amt, int16_t low, int16_t high);
uint8_t Execute_Move_And_Turn(uint16_t distance, float angle, uint16_t wait_time);
void Mouse_State_Machine(void);


uint16_t Phase = 0;
uint16_t seq_timer = 0; // Pause for stabilization timer

//float error = 0;
void MazeScan(void)
{

}

void MICRO_mause(void)
{
	static uint16_t time = 150;
	static uint8_t 	step = 0;

	switch (step)
	{
	case 0:
		if (Execute_Move_And_Turn(65, 90.0f, time))
			step = 1;
		break;
	case 1:
		if (Execute_Move_And_Turn(22, 90.0f, time))
			step = 2;
		break;
	case 2:
		if (Execute_Move_And_Turn(70, -90.0f, time))
			step = 3;
		break;
	case 3:
		if (Execute_Move_And_Turn(80, -90.0f, time))
			step = 5;
		break;
	case 4:
		if (reverse_time(time))
			step = 5;
		break;

	case 5:
		if (Execute_Move_And_Turn(55, 90.0f, time))
			step = 6;
		break;
	case 6:
		if (Execute_Move_And_Turn(60, -90.0f, time))
			step = 7;
		break;
	case 7:
		if (Execute_Move_And_Turn(80, -90.0f, time))
			step = 8;
		break;
	}

	Mouse_State_Machine();
	MOTOR_DRIVER_TransmitData();
}

typedef enum
{
    STEP_IDLE = 0,
    STEP_MOVE,
    STEP_WAIT_AFTER_MOVE,
	STEP_START_TURN,
    STEP_TURN,
    STEP_WAIT_AFTER_TURN,
    STEP_DONE
} MotionStep_t;


uint8_t Execute_Move_And_Turn(uint16_t distance, float angle, uint16_t wait_time)
{
    static MotionStep_t step = STEP_IDLE;
    static uint16_t timer = 0;

    uint8_t done = 0;

    switch (step)
    {
        case STEP_IDLE:
            if (Motion_Status == IDLE)
            {
            	Target_Distance = distance;
                drive_distance(distance);
                step = STEP_MOVE;
            }
            break;

        case STEP_MOVE:
            if (Motion_Status == IDLE_AFTER_FINISH)
            {
                timer = 0;
                step = STEP_WAIT_AFTER_MOVE;
            }
            break;

        case STEP_WAIT_AFTER_MOVE:
            if (++timer >= wait_time)
            {
                step = STEP_START_TURN;
            }
            break;

        case STEP_START_TURN:
            if (Motion_Status == IDLE)
            {
            	Target_Angle = angle;
                rotate_robot(angle);
                step = STEP_TURN;
            }
            break;

        case STEP_TURN:
            if (Motion_Status == IDLE_AFTER_FINISH)
            {
                timer = 0;
                step = STEP_WAIT_AFTER_TURN;
            }
            break;

        case STEP_WAIT_AFTER_TURN:
            if (++timer >= wait_time)
            {
                step = STEP_DONE;
            }
            break;

        case STEP_DONE:
            done = 1;
            step = STEP_IDLE;
            break;
    }

    return done;
}


void Mouse_State_Machine(void)
{
	static uint8_t cnt = 0;
	switch (Motion_Status)
	{

		case IDLE:
			// W tym stanie robot nic nie robi.
			MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);
		break;

		case ROTATING:
			// Wywołujemy Twoją funkcję obrotu.
			if (rotate_robot(Target_Angle))
				Motion_Status = IDLE_AFTER_FINISH;

		break;

		case DRIVING_STRAIGHT:
			// Wywołujemy funkcję jazdy na dystans.
			if (drive_distance(Target_Distance))
				Motion_Status = IDLE_AFTER_FINISH;

		break;

		case IDLE_AFTER_FINISH:
			// W tym stanie robot nic nie robi.
			MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);
			cnt++;
			if (cnt >= 10)
			{
				Motion_Status = IDLE;
				cnt = 0;
			}

		break;
	}
	MOTOR_DRIVER_TransmitData();
}

uint8_t drive_distance(uint16_t target_dist_cm)
{
    static float heading_target;
//    static uint16_t start_distance = 0;

    float angle_error = 0;
    uint8_t Done = 0;

    current_sensor_val = (FRONT_LEFT_Distance + FRONT_RIGHT_Distance) / 2;

    // 2. Inicialization
    if (Motion_Status == IDLE)
    {
        heading_target = Angle;
        start_distance = current_sensor_val;
        if (start_distance < target_dist_cm)
//        	start_distance = target_dist_cm + 10;
        	start_distance = target_dist_cm + 2;
        Motion_Status = DRIVING_STRAIGHT;
    }

    // 3. Distance Traveled Calculation
    traveled = (int16_t)start_distance - (int16_t)current_sensor_val;
    if (traveled < 0) traveled = 0;

    // 4. Stop Condition
    int16_t dist_error = (int16_t)target_dist_cm - traveled;

    if (dist_error <= 0)
    {
        MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);
        Motion_Status = IDLE_AFTER_FINISH;
        Done = 1;
        return Done;
    }

    // 5. IMU heading correction
    angle_error = heading_target - Angle;
    if (angle_error > 180.0f)  angle_error -= 360.0f;
    if (angle_error < -180.0f) angle_error += 360.0f;

    int16_t correction = (int16_t)(angle_error * KP_STRAIGHT);

    // 6. Select motor power
    int16_t power = DRIVE_PWM;

    // Simple slow down before target
    if (dist_error < 15) {
        power = DRIVE_PWM - SLOWDOWN;
    }

    // 7. Overspeed limiation with correction
    int16_t left_p  = limit(power - correction, -DRIVE_PWM, DRIVE_PWM);
    int16_t right_p = limit(power + correction, -DRIVE_PWM, DRIVE_PWM);

    MOTOR_DRIVER_SetDuty(LEFT_MOTOR, left_p);
    MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, right_p);

    return Done;
}
uint8_t wait_before_start(uint16_t time_ms)
{
	static uint16_t timer;
	uint8_t done = 0;
	timer++;

    MOTOR_DRIVER_SetDuty(LEFT_MOTOR, 0);
    MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, 0);

    if (timer > time_ms)
    {
    	timer = 0;
    	done = 1;
    }

    return done;
}

uint8_t reverse_time(uint16_t time_ms)
{
	static uint16_t timer;
	uint8_t done = 0;
	timer++;

    MOTOR_DRIVER_SetDuty(LEFT_MOTOR, MOUSE_VELOCITY_REVERSE);
    MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, MOUSE_VELOCITY_REVERSE);

    if (timer > time_ms)
    {
    	timer = 0;
    	done = 1;
    }

    return done;
}

uint8_t rotate_robot(float angle_to_add)
{
    static float error = 0;
    static float Target;
    static uint16_t Timeout;
    uint8_t Done = 0;

    if (Motion_Status == IDLE)
    {
    	Target = normalize_angle(Angle + angle_to_add);
        Motion_Status = ROTATING;
        Timeout = 0;
    }

    error = Target - Angle;
    if (error > 180.0f)  error -= 360.0f;
    if (error < -180.0f) error += 360.0f;


    if (target_reached(error))
    {
    	MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);
        Motion_Status = IDLE_AFTER_FINISH;
        Done = 1;
    }

    else if (Timeout > 5000)
    {
    	MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);
        Motion_Status = IDLE_AFTER_FINISH;
        Done = 1;
    }

    else {
        // 4. Regulator Proporcjonalny (P)
        int8_t Power = error * KP_ROTATION;

        if (Power > 0 && Power < MIN_PWM)
        	Power = MIN_PWM;
        if (Power < 0 && Power > -MIN_PWM)
        	Power = -MIN_PWM;

        if (Power > MAX_PWM)
        	Power = MAX_PWM;
        if (Power < -MAX_PWM)
        	Power = -MAX_PWM;

        MOTOR_DRIVER_SetDuty(LEFT_MOTOR, Power);
        MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, -Power);
        Timeout ++;
    }

    return Done;
}

uint8_t target_reached(float error)
{

    static uint8_t cnt = 0;
    uint8_t feedback = 0;

    if (error >= -ANGLE_THRESHOLD && error <= ANGLE_THRESHOLD)
    {
        cnt++;
        if (cnt >= 100)
        {
            cnt = 100;
            feedback = 1;
        }
    }
    else
    	cnt = 0;

    return feedback;
}

float normalize_angle(float angle)
{
    while (angle >= 360.0f) angle -= 360.0f;
    while (angle < 0.0f) angle += 360.0f;
    return angle;
}

static inline int16_t limit(int16_t amt, int16_t low, int16_t high)
{
    if (amt < low) return low;
    if (amt > high) return high;
    return amt;
}

/*
uint8_t Rotate(int8_t rotate) {
    float Target = Angle + (float)rotate;
    float last_error = 0;
    float error_diff = 0;
    float KD_ROTATION = 12.0f; // <--- Dobierz tę wartość (zacznij od 1.0 - 3.0)

    // 1. Normalizacja Targetu do 0-360
    if (Target < 0.0f) Target += 360.0f;
    if (Target >= 360.0f) Target -= 360.0f;

    // Oblicz błąd początkowy dla pierwszej iteracji
    float error = Target - Angle;
    if (error > 180.0f) error -= 360.0f;
    if (error < -180.0f) error += 360.0f;
    last_error = error;

    // Główna pętla regulacji
    while (error > ANGLE_THRESHOLD || error < -ANGLE_THRESHOLD) {
        // 2. Aktualizacja błędu
        error = Target - Angle;

        // 3. Korekta "najkrótszej drogi"
        if (error > 180.0f) error -= 360.0f;
        if (error < -180.0f) error += 360.0f;

        // 4. Obliczenie członu D (Różniczkowego)
        // Patrzymy jak szybko zmienia się błąd.
        // Jeśli robot pędzi do celu, error_diff będzie miało przeciwny znak do error
        error_diff = (error - last_error);
        last_error = error;

        // 5. Sumaryczna moc (P + D)
        // Człon D działa jak hamulec - im szybciej się obracasz, tym bardziej "odejmuje" mocy
        int power = (int)(error * KP_ROTATION + error_diff * KD_ROTATION);

        // 6. Limity i martwa strefa
        if (power > MAX_PWM) power = MAX_PWM;
        if (power < -MAX_PWM) power = -MAX_PWM;

        // Martwa strefa (tylko jeśli błąd jest wciąż duży)
        if (power > 0 && power < MIN_PWM) power = MIN_PWM;
        if (power < 0 && power > -MIN_PWM) power = -MIN_PWM;

        // 7. Sterowanie silnikami
        MOTOR_DRIVER_SetDuty(LEFT_MOTOR, -power);
        MOTOR_DRIVER_SetDuty(RIGHT_MOTOR, power);
        MOTOR_DRIVER_TransmitData();

        HAL_Delay(3); // Stały czas pętli jest ważny dla członu D
    }

    // 8. Zatrzymanie z hamowaniem
    MOTOR_DRIVER_SetDuty(BOTH_MOTORS, 0);
    MOTOR_DRIVER_TransmitData();

    return 1;
}
*/
void Start_Rotate(int8_t rotate_by)
{
    float target = Angle + (float)rotate_by;

    // Normalizacja do 0-360
    if (target < 0.0f)
    	target += 360.0f;

    if (target >= 360.0f)
    	target -= 360.0f;

//    target_angle = target;
//    last_error = 0; // Resetujemy człon D
//    Motion_Status = ROTATING;
}




