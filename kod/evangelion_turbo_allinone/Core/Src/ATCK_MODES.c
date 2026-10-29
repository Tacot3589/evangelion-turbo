#include "ATCK_MODES.h"
#include "DRIVERS.h"
#include "MY_INCLUDES.h"
#include "TFLUNA.h"

#include <stdint.h>

/* The TF-Luna driver uses UINT16_MAX when it has no valid distance. */
static uint8_t LidarDistanceWithin(uint16_t distance, uint16_t limit)
{
    return (distance != UINT16_MAX) && (distance <= limit);
}

static int16_t ScaleSpeed90(int16_t speed)
{
    return (int16_t)(((int32_t)speed * 9) / 10);
}

void STRAIGHT_ATTACK(void)
{
    static uint16_t comeBackLinerTimer = UINT16_MAX;
    static uint16_t goForwardLineAttention = UINT16_MAX;
    static uint8_t backLineOutGoDirection = LEFT;

    if (comeBackLinerTimer < LINE_COMEBACK_TIME)
    {
        comeBackLinerTimer++;
        SET_MOTORS(-LINE_COMEBACK_VELOCITY, -LINE_COMEBACK_VELOCITY);

        if (Lines.BackLeft.Dohyo == OUT)
        {
            comeBackLinerTimer = UINT16_MAX;
            goForwardLineAttention = 0;
            backLineOutGoDirection = RIGHT;
        }
        else if (Lines.BackRight.Dohyo == OUT)
        {
            comeBackLinerTimer = UINT16_MAX;
            goForwardLineAttention = 0;
            backLineOutGoDirection = LEFT;
        }
    }
    else if (goForwardLineAttention < LINE_COMEBACK_TIME)
    {
        goForwardLineAttention++;
        if (backLineOutGoDirection == LEFT)
            SET_MOTORS(ScaleSpeed90(LINE_COMEBACK_VELOCITY), LINE_COMEBACK_VELOCITY);
        else
            SET_MOTORS(LINE_COMEBACK_VELOCITY, ScaleSpeed90(LINE_COMEBACK_VELOCITY));
    }
    else if (Lines.FrontLeft.Dohyo == OUT || Lines.FrontRight.Dohyo == OUT)
    {
        comeBackLinerTimer = 0;
        SET_MOTORS(-LINE_COMEBACK_VELOCITY, -LINE_COMEBACK_VELOCITY);
    }
    else if (LidarDistanceWithin(Lunas.FrontLeft.Dist, MIN_DISTANCE) &&
             LidarDistanceWithin(Lunas.FrontRight.Dist, MIN_DISTANCE))
    {
        SET_MOTORS(100, 100);
    }
    else if (LidarDistanceWithin(Lunas.FrontLeft.Dist, MAX_DISTANCE) &&
             LidarDistanceWithin(Lunas.FrontRight.Dist, MAX_DISTANCE))
    {
        SET_MOTORS(ATTACK_STRAIGHT_ATTACK_SPEED, ATTACK_STRAIGHT_ATTACK_SPEED);
    }
    else if (LidarDistanceWithin(Lunas.FrontLeft.Dist, MAX_DISTANCE))
    {
        SET_MOTORS(ScaleSpeed90(ATTACK_STRAIGHT_ATTACK_SPEED), ATTACK_STRAIGHT_ATTACK_SPEED);
    }
    else if (LidarDistanceWithin(Lunas.FrontRight.Dist, MAX_DISTANCE))
    {
        SET_MOTORS(ATTACK_STRAIGHT_ATTACK_SPEED, ScaleSpeed90(ATTACK_STRAIGHT_ATTACK_SPEED));
    }
    else if (lastSeen == LEFT)
    {
        SET_MOTORS(-SEARCH_STRAIGHT_ATTACK_SPEED / 3, SEARCH_STRAIGHT_ATTACK_SPEED);
    }
    else if (lastSeen == RIGHT)
    {
        SET_MOTORS(SEARCH_STRAIGHT_ATTACK_SPEED, -SEARCH_STRAIGHT_ATTACK_SPEED / 3);
    }
    else
    {
        SET_MOTORS(SEARCH_STRAIGHT_ATTACK_SPEED, 0);
    }
}

void CURVE_ATTACK(void)
{
    static uint16_t comeBackLinerTimer = UINT16_MAX;
    static uint16_t goForwardLineAttention = UINT16_MAX;
    static uint8_t backLineOutGoDirection = LEFT;

    if (comeBackLinerTimer < LINE_COMEBACK_TIME)
    {
        comeBackLinerTimer++;
        SET_MOTORS(-SEARCH_STRAIGHT_ATTACK_SPEED, -SEARCH_STRAIGHT_ATTACK_SPEED);

        if (Lines.BackLeft.Dohyo == OUT)
        {
            comeBackLinerTimer = UINT16_MAX;
            goForwardLineAttention = 0;
            backLineOutGoDirection = RIGHT;
        }
        else if (Lines.BackRight.Dohyo == OUT)
        {
            comeBackLinerTimer = UINT16_MAX;
            goForwardLineAttention = 0;
            backLineOutGoDirection = LEFT;
        }
    }
    else if (goForwardLineAttention < LINE_COMEBACK_TIME)
    {
        goForwardLineAttention++;
        if (backLineOutGoDirection == LEFT)
            SET_MOTORS(ScaleSpeed90(LINE_COMEBACK_VELOCITY), LINE_COMEBACK_VELOCITY);
        else
            SET_MOTORS(LINE_COMEBACK_VELOCITY, ScaleSpeed90(LINE_COMEBACK_VELOCITY));
    }
    else if (Lines.FrontLeft.Dohyo == OUT || Lines.FrontRight.Dohyo == OUT)
    {
        comeBackLinerTimer = 0;
        SET_MOTORS(-LINE_COMEBACK_VELOCITY, -LINE_COMEBACK_VELOCITY);
    }
    else if (LidarDistanceWithin(Lunas.FrontLeft.Dist, MIN_DISTANCE) &&
             LidarDistanceWithin(Lunas.FrontRight.Dist, MIN_DISTANCE))
    {
        SET_MOTORS(100, 100);
    }
    else if (LidarDistanceWithin(Lunas.FrontLeft.Dist, MAX_DISTANCE) &&
             LidarDistanceWithin(Lunas.FrontRight.Dist, MAX_DISTANCE))
    {
        SET_MOTORS(ATTACK_STRAIGHT_ATTACK_SPEED, ATTACK_STRAIGHT_ATTACK_SPEED);
    }
    else if (LidarDistanceWithin(Lunas.FrontLeft.Dist, MAX_DISTANCE))
    {
        SET_MOTORS(CURVE_ATTACK_ONE_SEE_ATTACK_SPEED_FASTER / 2,
                   CURVE_ATTACK_ONE_SEE_ATTACK_SPEED_FASTER);
    }
    else if (LidarDistanceWithin(Lunas.FrontRight.Dist, MAX_DISTANCE))
    {
        SET_MOTORS(CURVE_ATTACK_ONE_SEE_ATTACK_SPEED_FASTER,
                   CURVE_ATTACK_ONE_SEE_ATTACK_SPEED_FASTER / 2);
    }
    else if (lastSeen == LEFT)
    {
        SET_MOTORS(CURVE_ATTACK_SEARCH_SPEED_SLOWER, CURVE_ATTACK_SEARCH_SPEED_FASTER);
    }
    else if (lastSeen == RIGHT)
    {
        SET_MOTORS(CURVE_ATTACK_SEARCH_SPEED_FASTER, CURVE_ATTACK_SEARCH_SPEED_SLOWER);
    }
    else
    {
        SET_MOTORS(CURVE_ATTACK_SEARCH_SPEED_FASTER, 0);
    }
}

void FOLLOWLINER_ATTACK(void)
{
    LineState_t front;
    LineState_t back;
    int16_t inside;
    int16_t outside;

    if (Lines.FrontLeft.Dohyo == OUT && Lines.FrontRight.Dohyo == OUT)
    {
        SET_MOTORS((lastSeen == LEFT) ? 100 : -100,
                   (lastSeen == LEFT) ? -100 : 100);
        return;
    }

    /* lastSeen is the existing LEFT/RIGHT direction state in main.c. */
    if (lastSeen == LEFT)
    {
        front = Lines.FrontLeft.Dohyo;
        back = Lines.BackLeft.Dohyo;
    }
    else
    {
        front = Lines.FrontRight.Dohyo;
        back = Lines.BackRight.Dohyo;
    }

    if (front == OUT && back == OUT)
    {
        outside = FOLLOW_LINER_FASTER;
        inside = ScaleSpeed90(FOLLOW_LINER_SLOWER);
    }
    else if (front == OUT && back == IN)
    {
        outside = FOLLOW_LINER_FASTER;
        inside = 10;
    }
    else if (front == IN && back == OUT)
    {
        outside = FOLLOW_LINER_SLOWER;
        inside = FOLLOW_LINER_FASTER;
    }
    else
    {
        outside = FOLLOW_LINER_SLOWER;
        inside = FOLLOW_LINER_FASTER;
    }

    if (lastSeen == LEFT)
        SET_MOTORS(outside, inside);
    else
        SET_MOTORS(inside, outside);
}

void FOLLOW_ATTACKER_ATTACK(void)
{
    typedef enum
    {
        FOLLOW_LINE,
        ATTACK
    } AttackStage_t;

    static AttackStage_t stage = FOLLOW_LINE;

    /* MAX_DISTANCE is the configured valid range for the TF-Luna sensors. */
    if (lastSeen == LEFT &&
        LidarDistanceWithin(Lunas.BackLeft.Dist, MAX_DISTANCE))
    {
        stage = ATTACK;
        lastSeen = LEFT;
    }
    else if (lastSeen == RIGHT &&
             LidarDistanceWithin(Lunas.BackRight.Dist, MAX_DISTANCE))
    {
        stage = ATTACK;
        lastSeen = RIGHT;
    }

    if (stage == FOLLOW_LINE)
        FOLLOWLINER_ATTACK();
    else
        CURVE_ATTACK();
}
