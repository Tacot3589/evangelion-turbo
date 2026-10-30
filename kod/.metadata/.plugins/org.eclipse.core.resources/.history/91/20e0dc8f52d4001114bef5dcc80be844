#ifndef ATCK_MODES_H_
#define ATCK_MODES_H_

#include <stdint.h>
#include "main.h"

#define GO_TO_LINE_TASK_SPEED                    30
#define AFTER_TASK_ALIGMENT_SPEED                30
#define AFTER_TASK_ROTATION_TIME                 50
#define STARTING_TASK_GO_TIME                    100

#define SEARCH_STRAIGHT_ATTACK_SPEED             30
#define ATTACK_STRAIGHT_ATTACK_SPEED             80

#define CURVE_ATTACK_ONE_SEE_ATTACK_SPEED_FASTER 60
#define CURVE_ATTACK_SEARCH_SPEED_FASTER         50
#define CURVE_ATTACK_SEARCH_SPEED_SLOWER         25

#define LINE_COMEBACK_TIME                       300
#define LINE_COMEBACK_VELOCITY                   30

#define FOLLOW_LINER_FASTER                      40
#define FOLLOW_LINER_SLOWER                      30
#define MAX_MOTOR_ACCELERATION_FOR_LINE_FOLLOWING 20

extern LidarSensors_t Lunas;
extern LinesSensors_t Lines;
extern Evangelion_t Eva;
extern MotorsSettingsInfo_t Motors;
extern uint8_t lastSeen;

void STRAIGHT_ATTACK(void);
void CURVE_ATTACK(void);
void FOLLOWLINER_ATTACK(void);
void FOLLOW_ATTACKER_ATTACK(void);
void STRAIGHT_SIMPLEST_ATTACK(void);

#endif /* ATCK_MODES_H_ */
