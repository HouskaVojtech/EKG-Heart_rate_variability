# EKG-Heart_rate_variability
Simple Arduino program to measure heart rate, heart rate variability etc. 
The data can be used to measure fittnes or recovery after a workout for optimal training.

# Hardware
It uses Atmel Atmega328 chip with arduino bootloader.

EKG front end is AD8232.

# Limits
The circuit should be put on a pcb isntead of a breadboard and closed into a metal box to reduce surrounding electrical noise. Currently, it is picking up a powergrid 50hz signal.

# Safety!
The circuit above should run only on battery to prevent any power surges that migh occur.

# Future Work
I plan to implement the EKG with ESP32 and front end that allows
