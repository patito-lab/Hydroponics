# 003: Probe isolation

**Date:**
**Status:** Accepted

## Context

[fill in: what symptom or risk prompted this, e.g. noisy pH/EC readings]

## Options considered

[fill in: e.g. shared ground plane vs. isolated analog front end, isolation amplifier vs. layout-only separation]

## Decision

[fill in: what was actually implemented]

## Why

pH and EC probes output low-level analog signals. If they share ground or power with switching loads like pump motor drivers or relay coils, PWM and inductive switching noise couples into the readings and shows up as drift or instability that has nothing to do with the actual solution chemistry. Keeping the analog sensor front end isolated (separate ground/power domain, or physical isolation) from the switching side of the circuit avoids this.
