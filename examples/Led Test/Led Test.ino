//include the library
#include "LedControlMS.h"

/*
Configuring the LEDMatrix:
5V is connected to VCC
GND is connected to GND
Digital 2 is conneted to DIN (Data IN)
Digital 3 is connected to CLK (CLocK)
Digital 4 is connected to CS (LOAD)
There is only one MAX7219 display module.
*/

#define NBR_MTX 1	//This defines how many matrices are attached
LedControl lc = LedControl(2, 3, 4, NBR_MTX);
/* wait time between updates of the display */
unsigned long delaytime = 100;

void setup()
{ // initalizes and sets up the initial values. Declaring function setup.
	//The display module is in power-saving mode on startup.
  	//Do a wakeup call
	Serial.begin(9600);		 // setting data rate as 9600 bits per second for serial data communication to computer
	Serial.println("Setup"); //prints data to serial port as human-readable text
	letterCounter = 0;
	for (int i = 0; i < NBR_MTX; i++)
	{
		lc.shutdown(i, false); //keep the screen on
		lc.setIntensity(i, 8); // set brightness to medium values
		lc.clearDisplay(i);	 //clear the display
	}
}

void loop()
{
	//Turn each led on in turn
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			lc.setLed(0, i, k, true);
			delay(delaytime);
		}
	}
	//Turn each led off in turn
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			lc.setLed(0, i, k, false);
			delay(delaytime);
		}
	}
}