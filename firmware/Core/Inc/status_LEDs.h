/*
 * status_LEDs.h
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */

#ifndef STATUS_LEDS_H
#define STATUS_LEDS_H

//set up system state LED
typedef enum {
    SYS_OFF = 0,
    SYS_OK,
    SYS_FAULT
} sys_state_t;

void status_leds_init(void);
void status_leds_set(sys_state_t state);

//set up tank level state LED
typedef enum {
    TANK_OFF = 0,
    TANK_LOW,
    TANK_REFILL,
	TANK_FULL,
} tank_state_t;

void status_leds_init(void);
void status_leds_set(tank_state_t state);

// set up bottle 1 state LED
typedef enum {
    BOT1_OFF = 0,
    BOT1_LOW,
    BOT1_FULL
} bot1_state_t;

void status_leds_init(void);
void status_leds_set(bot1_state_t state);

// set up bottle 2 state LED
typedef enum {
    BOT2_OFF = 0,
    BOT2_LOW,
    BOT2_FULL
} bot2_state_t;

void status_leds_init(void);
void status_leds_set(bot2_state_t state);

// set up bottle 3 state LED
typedef enum {
    BOT3_OFF = 0,
    BOT3_LOW,
    BOT3_FULL
} bot3_state_t;

void status_leds_init(void);
void status_leds_set(bot3_state_t state);

// set up bottle 4 state LED
typedef enum {
    BOT4_OFF = 0,
    BOT4_LOW,
    BOT4_FULL
} bot4_state_t;

void status_leds_init(void);
void status_leds_set(bot4_state_t state);

#endif /* STATUS_LEDS_H */
