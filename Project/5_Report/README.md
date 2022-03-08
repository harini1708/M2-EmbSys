# DETECTION OF OBJECTS USING ULTRASONIC SENSOR

## Description
An ultrasonic sensor is an instrument that measures the distance to an object using ultrasonic sound waves. An ultrasonic sensor uses a transducer to send and receive ultrasonic pulses that relay back information about an object's proximity. Ultrasonic sensors are used primarily as proximity sensors which means, an object passing within the preset range will be detected and generates an output signal. The sensor determines the distance to a target by measuring time lapses between the sending and receiving of the ultrasonic pulse.

## Features
Components Used:

•	Atmega328 Microcontroller: It controls the entire setup

•	HC-SR04 (Ultrasonic) sensor: Used to measure the distance to an object using ultrasonic sound waves

•	LCD display: Measured distance is displayed in the LCD

•	Switches: Used to On/off 

•	Power Supply: Provides power supply for the controller


## SWOT ANALYSIS

### Strengths

•	The distance of an obstacle can be measured using Low-cost Ultrasonic sensor

•	Not highly affected by dust, dirt, or high-moisture environments, color of objects

•	This sensors module includes ultrasonic transmitter,ultrasonic receiver and control circuit

•	These sensors can be useful for blind people


### Weaknesses
       
•	Sensing accuracy can be affected by soft materials.

•	Ultrasonic sensors have a limited detection range

### Opportunities

•	Ultrasonic sensors can be useful for making smart glasses for the blind with some added specifications.

•	These can be useful in parking assistance systems in vehicles with high power ultrasonic transmitter

•	 Can be used as burglar alarm with some suitable additional software for homes and offices, etc..

### Threats

•	Battery Backup is a major challenge

•	Ultrasonic sensors must view a surface (particularly a hard level surface) opposite to get adequate sound reverberation



## 4W’s and 1H:

### WHAT
The setup consists of a microcontroller that is connected to the ultrasonic sensor and displays the measured distance in the LCD.

### WHEN
It can be used whenever the range (or distance) has to be detected using ultrasonic sensor

### WHERE 
It is used wherever the distance has to be sensed using the ultrasonic sensor

### WHO
It can be used by blind people (with some additional specifications) which reduces their dependency on others.

### HOW
The sensor used in this project is Ultrasonic sensor that detects the opposite objects and send this information to the microcontroller and the output is generated in the LCD.

## Details Requirements

### High Level Requirement

| ID  |  Description                                      | 
| ----|  -----------------------------------------        |
|HLR1 |Ultrasonic sensors used to detect the objects      | 
|HLR2 |Microcontroller that controls the entire setup     | 
|HLR3 |Souce code used for execution of system            |
|HLR4 |LCD that displays the output(measured distance)    | 

### Low Level Requirement

| ID  |  Description                                      | 
| ----|  -----------------------------------------        |
|LLR1 |Power Supply (5V DC)                               |            
|LLR2 |Measuring angle of 30 degrees                      |            
|LLR3 |Trigger Input Pulse width: 10uS TTL pulse          |            

## Block Diagram

![Blockdiagram](https://user-images.githubusercontent.com/73392962/157188453-10ba544c-0400-4bb6-a71e-689fda9b5f60.png)


## Behavioural Diagram

![Behavioral_diagram](https://user-images.githubusercontent.com/73392962/157188414-305b1068-26d8-48f4-bfd1-f7446040169f.png)


## Conclusion
The aim of the project was to design and implement an ultrasonic distance meter. The device can detect the target and calculate the distance of the target. The ultrasonic distance meter is a low cost device and a simple device for distance measurement. This device calculates the distance with suitable accuracy and resolution. It is a useful for non-contact measurement of distance. The device has its application in many fields such as car backing system, automation and robotics, detecting the depth of the snow, water level of the tank, production line. This device will also have its application in civil and mechanical field for precise and small measurements. For calculating the distance using this device, the target whose distance is to be measured should always be perpendicular to the plane of propagation of the ultrasonic waves. Hence the orientation of the target is a limitation of this system. The ultrasonic detection range also depends on the size and position of the target. The bigger is the target, stronger will be the reflected signal and more accurate will be the distance calculated. 
