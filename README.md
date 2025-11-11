# Arduino Stopwatch

## Overview
This project is a simple Arduino-based stopwatch that measures the time between two button presses using `millis()` and Timer0. It demonstrates basic input handling, timer configuration, and serial output.

## Hardware Setup
| Component | Pin | Description |
|------------|-----|-------------|
| Push Button | D2 | Input to start and stop the timer |
| GND | — | Connected to button for active LOW input |

## How It Works
- When powered on, the program waits for a button press and release to start timing.  
- The first press records the start time using `millis()`.  
- The second press records the end time.  
- The difference between the two is displayed in seconds on the Serial Monitor.

## Example Output
