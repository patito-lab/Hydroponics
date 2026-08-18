/*
 * dose_calc.h
 *
 *  Created on: Aug 16, 2026
 *      Author: graytongiesman
 */

#ifndef INC_DOSE_CALC_H_
#define INC_DOSE_CALC_H_

#include <stdint.h>
#include "pump_control.h"

// placeholder: returns a fixed bench-test duration per pump, for
// characterizing dispense rate (run the pump for this long, measure
// dispensed volume in a graduated cylinder, compute mL/s).
//
// once the sensor module lands this will take a pH/EC reading and a
// target setpoint and return the duration needed to close the gap
// instead - signature will change accordingly.
uint32_t dose_calc_duration_ms(dose_content_t content);

#endif /* INC_DOSE_CALC_H_ */
