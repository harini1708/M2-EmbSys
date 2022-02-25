# DETECTION OF OBJECTS USING ULTRASONIC SENSOR

## Description
An ultrasonic sensor is an instrument that measures the distance to an object using ultrasonic sound waves. An ultrasonic sensor uses a transducer to send and receive ultrasonic pulses that relay back information about an object's proximity. Ultrasonic sensors are used primarily as proximity sensors which means, an object passing within the preset range will be detected and generates an output signal. The sensor determines the distance to a target by measuring time lapses between the sending and receiving of the ultrasonic pulse.

## Features
Components Used:

•	Atmega328 Microcontroller

•	HC-SR04 (Ultrasonic) sensor

•	LCD display

•	Switches

•	Power Supply


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

| ID  |  Description                                      | Status     | 
| ----|  -----------------------------------------        |----------  |
|HLR1 |Ultrasonic sensors used to detect the objects      |            |
|HLR2 |Microcontroller that controls the entire setup     |            |
|HLR3 |Souce code used for execution of system            |            |
|HLR4 |LCD that displays the output(measured distance)    |            |

### Low Level Requirement

| ID  |  Description                                      | Status     | 
| ----|  -----------------------------------------        |----------  |
|LLR1 |Power Supply (5V DC)                               |            |
|LLR2 |Measuring angle of 30 degrees                      |            |
|LLR3 |Trigger Input Pulse width: 10uS TTL pulse          |            |

