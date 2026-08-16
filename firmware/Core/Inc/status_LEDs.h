/*
 * status_LEDs.h
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */

#ifndef STATUS_LEDS_H
#define STATUS_LEDS_H

void status_leds_init(void);

//set up system state LED
typedef enum {
    SYS_OFF = 0,
    SYS_OK,
    SYS_FAULT
} sys_state_t;

void sys_leds_set(sys_state_t state);

//set up tank level state LED (red/yellow/green)
typedef enum {
    TANK_OFF = 0,
    TANK_LOW,
    TANK_REFILL,
	TANK_FULL,
} tank_state_t;

void tank_leds_set(tank_state_t state);

// shared state for the 4 bottle LEDs (red/green)
typedef enum {
    BOT_OFF = 0,
    BOT_EMPTY,
    BOT_FULL
} bottle_state_t;

void bot1_leds_set(bottle_state_t state);
void bot2_leds_set(bottle_state_t state);
void bot3_leds_set(bottle_state_t state);
void bot4_leds_set(bottle_state_t state);

#endif /* STATUS_LEDS_H */
