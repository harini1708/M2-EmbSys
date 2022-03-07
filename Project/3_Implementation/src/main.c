/**
 * @file main.c
 * @author Harini
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif  

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


#define lcd_port PORTD          // Connected the lcd on port D
#define lcd_data_dir  DDRD      // Defining the direction of the pins(input or output)
#define rs PD0                  // Behavior of the LCD we have connected RS pin of LCD to port D pin 0
#define en PD1                  // Connected Enable pin of LCD to port D pin 1

#define US_PORT PORTC           // connected the Ultrasonic sensor on port C. to use the ultrasonic we need two pins of the ultrasonic to be connected on port C
#define	US_PIN	PINC            // we need to initialize the pin resistor when we want to take input.
#define US_DDR 	DDRC            //  data-direction-resistor (DDR) to set the direction of data flow

#define US_TRIG_POS	PC0         // the trigger pin of ultrasonic sound sensor is connected to port C pin 0
#define US_ECHO_POS	PC1         // the echo pin of the ultrasonic sound sensor is connected to port C pin 1

#define led1 PC2                //  Connected four of the LEDs to port C and one LED to port D. The first LED is connected to port C pin 2
#define led2 PC3                
#define led3 PC4
#define led4 PC5
#define led5 PD2

#define US_ERROR		-1   // Defining two more variables two know if the ultrasonic sensor is working or not
#define	US_NO_OBSTACLE	-2

int distance, previous_distance;


void UltrasonicInit();
void UltrasonicTrigger();

void lcd_command( unsigned char );

void UltrasonicInit()
{
	
	US_DDR|=(1<<US_TRIG_POS);
}

void UltrasonicTrigger() // this function will generate ultrasonic sound wave for 15 microseconds
{   
	//Send a 10uS pulse on trigger line
	
	US_PORT|=(1<<US_TRIG_POS);	//high
	
	_delay_us(15);				//wait 15uS
	
	US_PORT&=~(1<<US_TRIG_POS);	//low
}

uint16_t GetPulseWidth()
{
	// this function will be used to measure the pulse duration. When the ultra sound echo back after hitting an object
	// the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it.
	
	uint32_t i,result;

	for(i=0;i<700000;i++)
	{
		if(!(US_PIN & (1<<US_ECHO_POS)))
		continue;	//Line is still low, so wait
		else
		break;		//High edge detected, so break.
	}

	if(i==700000)
	return US_ERROR;	//Indicates time out
	
	TCCR1A=0X00;
	TCCR1B=(1<<CS11);	// This line sets the resolution of the timer. Maximum of how much value it should count.
	TCNT1=0x00;			// This line start the counter to start counting time

	for(i=0;i<700000;i++)                // the 700000 value is used randomly to denote a very small amount of time
	{
		if(US_PIN & (1<<US_ECHO_POS))
		{
			if(TCNT1 > 70000)
             break; 
             else
              continue;   // if the TCNT1 value gets higher than 70000 it means there is not object in the range of the sensor
		}
		else
		break;
	}

	if(i==700000)
	return US_NO_OBSTACLE;	//Indicates time out

	//Falling edge found

	result=TCNT1;          

	//Stop Timer
	TCCR1B=0x00;

	if(result > 70000)
	return US_NO_OBSTACLE;	//No obstacle
	else
	return (result>>1);
}


void initialize (void)
{
	lcd_data_dir = 0xFF;     // sets the LCD pins connected on the microcontroller as output
	_delay_ms(15);           // to show data on the LCD we need to send commands first then the data
	lcd_command(0x02);       // this command returns the cursor to the first row and first column position
	lcd_command(0x28);       
	lcd_command(0x0c);
	lcd_command(0x06);
	lcd_command(0x01);
	_delay_ms(2);
}

void lcd_command( unsigned char cmnd )
{
	lcd_port = (lcd_port & 0x0F) | (cmnd & 0xF0);  // Writes the command on the data pins of the lcd connected to the microcontroller portD pin 4 to 7
	lcd_port &= ~ (1<<rs);
	lcd_port |= (1<<en);
	_delay_us(1);
	lcd_port &= ~ (1<<en);
	_delay_us(200);// delay of 200 microseconds
	lcd_port = (lcd_port & 0x0F) | (cmnd << 4);
	lcd_port |= (1<<en);
	_delay_us(1);
	lcd_port &= ~ (1<<en);
	_delay_ms(2);
}

void lcd_clear()
{
	lcd_command (0x01);   // clears the LCD screen
	_delay_ms(2);         // waits for two milliseconds
	lcd_command (0x80);   // this line sets the cursor to the row 1 column 1
}


void lcd_print (char *str)  // this function is used to display the string on the LCD screen
{

	int i;
	for(i=0; str[i]!=0; i++)
	{
		// we cannot send the whole string to the LCD . we need to send character by character
		
		lcd_port = (lcd_port & 0x0F) | (str[i] & 0xF0);
		lcd_port |= (1<<rs);
		lcd_port|= (1<<en);
		_delay_us(1);
		lcd_port &= ~ (1<<en);
		_delay_us(200);
		lcd_port = (lcd_port & 0x0F) | (str[i] << 4);
		lcd_port |= (1<<en);
		_delay_us(1);
		lcd_port &= ~ (1<<en);
		_delay_ms(2);
	}
}



void lcd_setCursor(unsigned char x, unsigned char y){    //  used to set cursor
	unsigned char adr[] = {0x80, 0xC0};    
	lcd_command(adr[y-1] + x-1);
	_delay_us(100);
}

int main()
{
	initialize();           // Initializing the LCD

	char numberString[4];   // we re defining an array of character. It will be utilized later to store integer to be displayed on the LCD screen

	while(1) {
		
		uint16_t r;
		
		_delay_ms(100);	//Let the LCD Module start
                    
		UltrasonicInit();
        DDRC |= (1 << led1) | (1 << led2) | ( 1 << led3) | ( 1 << led4);    // setting all the leds as output
		DDRD |= (1 << led5);                                                 // setting the fifth led as output separately since it is on another port
	
		while(1)
		{
			
			UltrasonicTrigger();               // calling the ultrasonic sound wave generator function
			r=GetPulseWidth();                 //Measure the width of pulse        

			if(r==US_ERROR)                // if microcontroller doesn't get any pulse then it will set the US_ERROR variable to -1
			
			{
				lcd_setCursor(1, 1);      //lcd_setCursor(column, row)
				lcd_print("Error!");      //displays the error if any error is found
			}
			else
			{
				
				distance=(r*0.034/2.0);	// Formula to find the distance (in centimeters)
				
				
				if (distance != previous_distance)    // the LCD screen only need to be cleared if the distance is changed otherwise it is not required
				{
					lcd_clear();
				}
				
				lcd_setCursor(1, 1);      // set the row and column to display the data
				lcd_print("Distance = ");
				lcd_setCursor(12, 1);      //lcd_setCursor(column, row)
				itoa(distance, numberString, 10);    // converts integer into array of character
				lcd_print(numberString);
				lcd_setCursor(14, 1);      //set the row to 1 and and column to 14 to display the data
				lcd_print(" cm");
				
				previous_distance = distance;
				_delay_ms(30);
			}
		}
		
	}
}