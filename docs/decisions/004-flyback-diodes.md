# 004: Flyback diodes on pump/relay drivers

**Date:**
**Status:** Accepted

## Context

[fill in: which loads this applies to, e.g. peristaltic pump motors, relay coils]

## Options considered

[fill in: if any alternative protection was considered, e.g. TVS diode, snubber]

## Decision

A flyback (freewheeling) diode is placed across each inductive load (pump motor, relay coil) driven by the MCU or its driver transistor/MOSFET.

## Why

When current through an inductive load is switched off, the collapsing magnetic field generates a voltage spike (back-EMF) in the opposite polarity, which can exceed the breakdown voltage of the driving transistor and destroy it. A diode across the load gives that current a path to dissipate safely instead of spiking back through the driver.
