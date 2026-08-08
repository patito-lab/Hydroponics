# 007: Indicator LEDs

**Date:** 8Aug26
**Status:** Accepted

## Context

Want LEDs to reflect tank and dosing bottle liquid levels. Want overall status indication

## Options considered

Screen, simple LEDs, multicolor LEDs

## Decision

3 LEDs for main tank (red, yellow, green), 2 LEDs for each dosing bottle (red, green), 2 LEDs for system (red, green)

Indicator       Pin     CN10
System green	  PC6	    4
System red   	  PC8	    2
Tank green	    PB12	  16
Tank yellow	    PB13	  30
Tank red	      PB14	  28
Bottle 1 green	PB15	  26
Bottle 1 red	  PB1	    24
Bottle 2 green	PB2	    22
Bottle 2 red	  PB10	  25
Bottle 3 green	PB4	    27
Bottle 3 red	  PB5	    29
Bottle 4 green	PB6	    17
Bottle 4 red	  PC7	    19

Red & Yellow LED's are lower voltage so they go GPIO -> 220 R -> LED -> ground
Green LED's are higher voltage so they go +5v -> 270 R -> LED -> GPIO

This means the green LED GPIO need to be configured opposite in the code.

## Why

This gives the cleanest visual, and I already had colored LED's on hand and I didn't want to have to buy multicolored ones. A display is more complicated (SPI driven), may use in a future version. Refill indicator is important for the main tank so I have notice, high and low will throw system errors.

For the dosing bottles, they are small so only 1 switch fits. This limits to red & green. 
