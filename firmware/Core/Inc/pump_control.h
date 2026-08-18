/*
 * pump_control.h
 *
 *  Created on: Aug 16, 2026
 *      Author: graytongiesman
 */

#ifndef INC_PUMP_CONTROL_H_
#define INC_PUMP_CONTROL_H_

#include <stdbool.h>
#include <stdint.h>

// one entry per dosing bottle, named by content rather than pump number
// so callers don't need to track which pump is wired to what. mapping to
// pump/GPIO is internal to pump_control.c. Same A-D bottle ordering as
// level_check.h's bot1-4 float switches (see docs/Hydroponics_Pinout_v1.xlsx,
// "Assignments by subsystem").
typedef enum {
    DOSE_CAL_NITRATE = 0, // Pump 1 / Bottle A
    DOSE_NUTRIENT,         // Pump 2 / Bottle B (Masterblend + Epsom)
    DOSE_PH_DOWN,           // Pump 3 / Bottle C
    DOSE_PH_UP,              // Pump 4 / Bottle D
    DOSE_CONTENT_COUNT
} dose_content_t;

void pump_control_init(void);

// non-blocking: call once per main-loop pass. turns off any pump whose
// dose duration has elapsed.
void pump_control_update(void);

// starts dosing `content` for `duration_ms`. returns false and does not
// start if that pump is already running or duration_ms is 0.
bool pump_dose_start(dose_content_t content, uint32_t duration_ms);

// stops a pump immediately, ignoring remaining duration.
void pump_stop(dose_content_t content);

bool pump_is_busy(dose_content_t content);

#endif /* INC_PUMP_CONTROL_H_ */
