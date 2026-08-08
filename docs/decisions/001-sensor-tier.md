# 001: Sensor tier, DFRobot for V1, Atlas Scientific for V2

**Date:** 28Jul26
**Status:** Accepted

## Context

Need to validate the dosing and control loop logic before committing to precision sensor hardware.

## Options considered

- Atlas Scientific pH/EC from the start: higher accuracy, higher cost.
- DFRobot pH/EC to start: lower cost, adequate for validating firmware logic.

## Decision

Start with DFRobot pH/EC sensors for V1. Upgrade to Atlas Scientific once the control loop is proven.

## Why

DFRobot sensors are roughly a third of the cost of Atlas Scientific and let the firmware and control logic get debugged cheaply before spending on precision hardware that isn't the bottleneck at this stage.
