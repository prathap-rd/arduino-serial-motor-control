# Arduino Serial Controlled DC Motor (L298N)

## Problem Statement
Control a two-wheel DC motor robot using serial commands
with direction and speed control via Arduino and L298N.

## Hardware Used
- Arduino Uno
- L298N Motor Driver
- DC Motors
- External Power Supply

## Control Commands
- F → Forward
- B → Backward
- L → Left
- R → Right
- S → Stop

## Features
- Serial-based motor control
- PWM speed control
- Modular motor control functions
- Safe motor stop logic

## How It Works
The Arduino reads single-character commands from the serial monitor.
Based on the command, motor direction pins are set and speed is controlled
using PWM on the enable pins of the L298N driver.

## How to Run
1. Connect the L298N module to Arduino as per wiring diagram
2. Upload the code
3. Open Serial Monitor at 9600 baud
4. Send commands (F, B, L, R, S)

## Status
Tested and working on real hardware
