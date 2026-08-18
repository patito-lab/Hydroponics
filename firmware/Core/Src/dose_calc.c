/*
 * dose_calc.c
 *
 *  Created on: Aug 16, 2026
 *      Author: graytongiesman
 */
#include "dose_calc.h"

// bench characterization durations
static const uint32_t test_duration_ms[DOSE_CONTENT_COUNT] = {
    [DOSE_CAL_NITRATE] = 500,
    [DOSE_NUTRIENT]    = 500,
    [DOSE_PH_DOWN]     = 500,
    [DOSE_PH_UP]       = 500,
};

uint32_t dose_calc_duration_ms(dose_content_t content)
{
    return test_duration_ms[content];
}
