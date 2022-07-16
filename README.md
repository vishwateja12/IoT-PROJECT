# Roller Coaster/ Downhill Race Team 8

## Method 
The project aims to show Conservation of energy at different heights using Internet of Things. A car is released from top of the inclined plane. Distances and velocities are measured using Ultrasonic sensor HRSC04 during the downfall of the car. The motion of the car is controlled using motor, L298N H-bridge and ESP 8266. The car is pulled up and down the incline plane as needed using motors. The project uses Blynk as dashboard to give inputs and display outputs to the hardware setup. 

## Read me for controlling motor
File esp8266_carcontrol.ino has the code for controlling motor using ESP8266, H-bridge L298N.

- Firstly, Include the necessary libraries.
- Define the motor pins
- Define the necessary variables.

## Setting up Blynk and wifi details 
- After creating new project in Blynk, an authorization token will be generated and sent to email address. Enter that authorization token.
- Then, enter the wifi details - username and password which will be used for controlling the motors.

- After setting up Blynk details, define motor pins as OUTPUT pins, we connect to Blynk Server using Blynk.begin()
- Define the virtual pins used in the dashboard.
- Write function for working of pulley.

## Smart pulley
- Checks if the input is HIGH for rotating the motors in one direction. If no, checks the other direction. If both the inputs are LOW, then the motion of car stops. 
- Necessary functions like turnDir1() , turnDir2() and Stop() are written for giving instructions to motor.
- Blynk.run() is constantly being called in a loop to check if there are new inputs. 

## Ultrasonic sensor

* Control is with blink just connect the sensor with respective pins vcc-3v3 gnd-gnd echo-D5 and trig-D18 and just push the code and connect it with a 4.5v or minimum of 3.7v it will work and take readings respectively and shown in Blynk dashboard we created.
* We used hc.dist inbuilt function to get the distance and made the 100 milli distance difference and we found ds/dt so we got the velocity and we found the k.e and p.e and t.e of the body and shown it on blynk.
