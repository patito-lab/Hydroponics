/*
 * status_LEDs.h
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */

#ifndef STATUS_LEDS_H
#define STATUS_LEDS_H

typedef enum {
    SYS_OFF = 0,
    SYS_OK,
    SYS_FAULT
} sys_state_t;

void status_leds_init(void);
void status_leds_set(sys_state_t state);

#endif /* STATUS_LEDS_H */
