# DESCRIPTION

This case study is regarding Digital clock with alarm using RTC(Real Time Clock).Digital clock works in 24 hour mode and the time is displayed on the LCD.The RTC chip is configured using 8051 Microcontroller.The microcontroller continuously reads the data from RTC and displays the time and date on LCD.In this digital clock, we can set alarm and time instantly anytime using the keypad.

# FEATURES

This digital clock contains several components like Microcontroller,LCD,Buzzer,Relay,RTC(Real time clock),Push buttons.Microcontroller controls all the other components.In controlling,several push buttons are used .They consist of alarm set,reset button and each perform different sets of work.RTC varies the time continuous and delays
## LCD: 
LCD is the output device.It displays the time,date,month and year
## Microcontroller:
All the components are controlled by the microcontroller that has been programmed and the output genereated is displayed on the LCD
## RTC(REAL TIME CLOCK):
Real-time clock is a clock function used by systems that measure time even when the main device (such as MCU) is powered off.RTC is the main block of the system. Real time clock is to provide precise time and date.
## Buzzer:
Generates sound as the alarm rings
## Relay:
A relay is an electrically operated switch. It consists of a set of input terminals for a single or multiple control signals, and a set of operating contact terminals.
 ## Power Supply
 Provides power supply to the controller

# HIGH LEVEL REQUIREMENTS
| ID  |  Description                                      | Status     | 
| ----|  -----------------------------------------        |----------  |
| HLR1| LCD Diplay that displays the output               | Implemented|
| HLR2| Real Time clock to provide precise time and date  | Implemented|
| HLR3| Microcontroller that controls all other units     | Implemented|
| HLR4| Power supply for controller                       | Implemented|


# LOW LEVEL REQUIREMENTS
| ID  |  Description                                      | Status     | 
| ----|  -----------------------------------------        |----------  |
| LLR1| Buzzer to generate sound as alarm rings           | Implemented|
| LLR2| Light Emitting Diode                              | Implemented|
| LLR3| Relay that acts as a switch                       | Implemented|  
| LLR4| Push Buttons used to set time and alarm           | Implemented|  