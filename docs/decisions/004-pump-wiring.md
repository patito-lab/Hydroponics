# 004: Pump wiring

**Date:** 1Aug26
**Status:** Accepted

## Context

Wiring for the peristaltic pump control

## Options considered

prebuilt control, direct drive, DIY

## Decision

Motors will be driven directly from a 12v power supply. MOSFET will be used to switch on & off from MCU. Flyback diode across the pump is used to prevent current from frying the MOSFET.

Resistors used around the gate so that transistor will turn off when input voltage from the MCU is dropped.

Capacitor is used from positive to ground to shunt motor noise to ground and reducing voltage sag when the MOSFET activates.

## Why

Covered in decision above.
