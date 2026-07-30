# Kitchen Hydroponics Controller

STM32-based closed-loop nutrient dosing and sensor monitoring system for a four-site window planter (basil, cilantro, parsley, chives).

## Status

V1: planning and design complete, hardware ordered, firmware not yet started.

## System overview

MCU: STM32 (Cortex-M)
Sensors: DFRobot pH/EC for V1, Atlas Scientific pH/EC for V2 (see `docs/decisions/001-sensor-tier.md`)
Reservoir: slim DWC window planter, ~30" x 6" x 8" interior, four 3" net pot sites
Dosing: peristaltic pumps for calcium nitrate and phosphate-sulfate lines, kept hydraulically separate (see `docs/decisions/002-precipitation-separation.md`)

(block diagram to add once wiring is finalized)

## Repo layout

- `firmware/` - STM32CubeIDE project (control loop, sensor drivers, dosing logic)
- `docs/decisions/` - engineering decision records
- `hardware/` - BOM, wiring notes, physical build

## Bill of materials

See `hardware/README.md` for a summary, or the full spreadsheet in `hardware/`.

## Decision log

See `docs/decisions/` for the reasoning behind specific engineering choices: sensor tier, dosing line separation, probe isolation, driver protection, reservoir material.
