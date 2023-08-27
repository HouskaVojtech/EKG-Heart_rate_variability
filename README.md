# EKG-Heart_rate_variability
Simple Arduino program to measure heart rate, heart rate variability etc. 
The data can be used to measure fittnes or recovery after a workout for optimal training. The measurement has to be performed seated due to the design's limitations.

# Hardware
It uses Atmel Atmega328 chip with arduino bootloader.
EKG front end is AD8232.
![cricuit](https://github.com/HouskaVojtech/EKG-Heart_rate_variability/blob/main/ekg_circuit.jpg?raw=true)

# Limitations
The circuit should be put on a pcb isntead of a breadboard and closed into a metal box to reduce surrounding electrical noise. Currently, it is picking up a powergrid 50hz signal.

On top of that there is a noise from muscles. If you flex your left pectoralis muscles, where the electrodes are placed, electrical activity produced by them will disrupt the measurement.   

# Safety!
The circuit above should run on battery power only to prevent potential power surges, which could pose a danger.

# Future Work
I plan to implement the EKG with ESP32 and EKG front end like ADS1298. ESP32 can be connected to a phone via bluetooth or wifi network to display and store collected data. ADS1298 EKG front end with more leads to better deal with noise and maybe track the data while performing an exercise. 
