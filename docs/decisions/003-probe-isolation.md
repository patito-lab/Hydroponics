# 003: Probe isolation

**Date:** 8Aug26
**Status:** Accepted

## Context

Using DFRobot pH and EC sensors. Both pass current to read and output low-level analog signals.

## Options considered

I didn't consider too many fancy options, just what would be simple and effective

## Decision

pH and EC (along with temp sensor) will go on the right end of the tank. Pumps will live near the dosing bottles underneath the system. Board will live on the front of the system. Motors are driven directly off of a 12v power supply. Software will only read 1 sensor at a time.

## Why

pH and EC probes output low-level analog signals. If they share ground or power with switching loads like pump motors, noise could get into the readings and shows up as drift or instability. Keeping the wiring separate mitigates this. Analog sensors will be near eachother to maintain point accuracy, but separated slightly (about 2 inches) to reduce potential grounding. In the code, sensors will be read sequentially, so their measuring current don't interfere with eachother. 
