//LED driver libaray for NEO pixels by adafruit or any LED that uses the
//WS2812 intelligent LED's
//this libraries assume the following:
// you are using a pic32
// you are using pin RD4 which is located on PORTD and the TRISDbits are set to
// output mode
// you are using the following performance setting macro:
// SYSTEMConfigPerformance(80000000); as well as config settings for the pic
// are set for the 80MHZ
// if you wish to change the port pin change the PORTDINV commands to the
// apropriate port and the bit mask to the correct vale
#include "LED_driver.h"

//////////////////////////////////////////////////////////////
//This function sets the timing of the NRZ protcol
// inputs:
//  int * ledArray - pass a pointer to an array of integers (32-bits wide)
//  although only 24 bits are used the format for the color schem are as follows
//  (G7,G6,G5,G4,G3,G2,G1,G0,R7,R6,R5,R4,R3,R2,R1,R0,B7,B6,B5,B4,B3,B2,B1,B0)
//  int lengthArray - length of the ledArray
//////////////////////////////////////////////////////////////
int refreshLEDS(int * ledArray, int lengthArray)
{
	unsigned int count = 0; //location variable
	int currentPixel = 0;  //current pixel information
	int i = 0;    //counter variable
	int j = 0;

	for (count = 0; count<lengthArray; count++) //string control
	{
		currentPixel = ledArray[count]; //get current pixel settings
		for (i = 23; i >= 0; i--)           //iterate through the current pixel information
		{
			PORTESET = 0b1;     //code below will convert pixel info to NRZ serial data on portd pin 0
			if (currentPixel & (0x000001) << i)
			{
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				PORTECLR = 0b1;
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
			}//delay for logic one
			else
			{
				//__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
				//__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				PORTECLR = 0b1;
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
				__asm__("nop");
			}//delay for logic zero
		}//end of bit data
	}//end for string count loop
	for (j = 0; j<100; j++);
	return 1;
}
/*This function is a simple delay. Given input "time",
* the function will do that many "nop" operations*/
void delay_LED(int time)
{
	int counter = 0, scalar = 0;

	if (time <= 0)
	{
		scalar = 1;
	}
	else if (time > 5)
	{
		scalar = 5;
	}
	else
	{
		scalar = time;
	}

	for (counter = 0; counter < (400000 / scalar); counter++)
	{
		__asm__("nop");
	}
}
/*This function will change the color of the center LED in the middle of the eye only.
This is at ring[] index 0*/
void changeColorCenter(int newColor)
{
	ring[0] = newColor;
}
/*This function assumes that the small ring is connected to the board first.
* Meaning that the small ring's dataIn is connected to the Cerebot board
* and the dataOut connects to the dataIn of the medium sized ring. Therefore,
* the first 12 elements of the "ring" array correspond to the 12 LEDs of the
* small ring.
*
* This function will change the color of all the LEDs on the small ring to
* whatever "newColor" is.
*  */
void changeColorSmallRing(int newColor)
{
	int i = 0;
	for (i = 1; i<13; i++)
	{
		ring[i] = newColor;
	}
}
/*This function assumes that the medium ring is connected to the small ring
* first. Meaning that the medium ring's dataIn is connected to the small ring's
* dataOut and the dataOut connects to the dataIn of the large sized ring.
* Therefore, the first elements ranging from indeces 12-27 of the "ring" array
* correspond to the 16 LEDs of the small ring.
*
* This function will change the color of all the LEDs on the medium ring to
* whatever "newColor" is.
*  */
void changeColorMediumRing(int newColor)
{
	int i = 0;
	for (i = 13; i<29; i++)
	{
		ring[i] = newColor;
	}
}
/*This function assumes that the large ring is connected to the medium ring
* first. Meaning that the large ring's dataIn is connected to the medium ring's
* dataOut and the dataOut connects to nothing.
* Therefore, the first elements ranging from indeces 28-51 of the "ring" array
* correspond to the 24 LEDs of the small ring.
*
* This function will change the color of all the LEDs on the large ring to
* whatever "newColor" is.
*  */
void changeColorLargeRing(int newColor)
{
	int i = 0;
	for (i = 29; i<53; i++)
	{
		ring[i] = newColor;
	}
}
/*Since the "ring" variable is global, passing in a location and color will
*allow to change the color at any one specific LED. User will need to know that
*the indeces correspond as follows:
*small ring: 0-11
*medium ring: 12-27
*large ring: 28-51
*/
void changeColorAt(int newColor, int loc)
{
	ring[loc] = newColor;
}
/*This function will go through the whole ring array and set the color pattern
to color1, color2, color3 repeating in that order*/
void changeTriColor(int newColor1, int newColor2, int newColor3)
{
	int i = 0;
	int color = 0;
	for (i = 0; i<53; i++)
	{
		if ((i % 3) == 0)
		{
			color = newColor1;
		}
		else if ((i % 3) == 1)
		{
			color = newColor2;
		}
		else
		{
			color = newColor3;
		}

		ring[i] = color;
	}
}
/*This function does the same thing as changeTriColor but will only do so
*for the small ring */
void changeTriColorSmall(int newColor1, int newColor2, int newColor3)
{
	int i = 0;
	int color = 0;
	for (i = 1; i<13; i++)
	{
		if ((i % 3) == 0)
		{
			color = newColor1;
		}
		else if ((i % 3) == 1)
		{
			color = newColor2;
		}
		else
		{
			color = newColor3;
		}

		ring[i] = color;
	}
}
/*This function does the same thing as changeTriColor but will only do so
*for the medium ring */
void changeTriColorMed(int newColor1, int newColor2, int newColor3)
{
	int i = 0;
	int color = 0;
	for (i = 13; i<29; i++)
	{
		if ((i % 3) == 0)
		{
			color = newColor1;
		}
		else if ((i % 3) == 1)
		{
			color = newColor2;
		}
		else
		{
			color = newColor3;
		}

		ring[i] = color;
	}
}
/*This function does the same thing as changeTriColor but will only do so
*for the small ring */
void changeTriColorLarge(int newColor1, int newColor2, int newColor3)
{
	int i = 0;
	int color = 0;
	for (i = 29; i<53; i++)
	{
		if ((i % 3) == 0)
		{
			color = newColor1;
		}
		else if ((i % 3) == 1)
		{
			color = newColor2;
		}
		else
		{
			color = newColor3;
		}

		ring[i] = color;
	}
}
/*This function takes in the color modifier from the USB/UART buffer
and then assigns various color variables to be passed into pattern functions.
Could be seen as a setter.*/
void setColorPattern(int colorChoice)
{
	//preset colors
	int red = 0x000F00,
		blue = 0x00000F,
		orange = 0x0F0600,
		green = 0x0F0000,
		purple = 0x000F0F,
		yellow = 0x171400,
		white = 0x0F0F0F;

	switch (colorChoice % 5)
	{
	case 0:
		LED_Color1 = red;
		LED_Color2 = blue;
		LED_Color3 = orange;
		break;
	case 1:
		LED_Color1 = yellow;
		LED_Color2 = blue;
		LED_Color3 = red;
		break;
	case 2:
		LED_Color1 = green;
		LED_Color2 = purple;
		LED_Color3 = white;
		break;
	case 3:
		LED_Color1 = purple;
		LED_Color2 = white;
		LED_Color3 = orange;
		break;
	case 4:
		LED_Color1 = blue;
		LED_Color2 = purple;
		LED_Color3 = red;
		break;
	}
}

/*This function will have alternating colors flashing.
The Center, and Medium ring will be assigned the same color
The Small and Large ring will be assigned the same color*/
void AlternatingFlash(void)
{
	if (patternCounter == 0)
	{
		changeColorCenter(LED_Color1);
		changeColorMediumRing(LED_Color1);

		changeColorSmallRing(LED_Color2);
		changeColorLargeRing(LED_Color2);
		patternCounter = 1;
	}
	else
	{
		changeColorCenter(LED_Color2);
		changeColorMediumRing(LED_Color2);

		changeColorSmallRing(LED_Color1);
		changeColorLargeRing(LED_Color1);
		patternCounter = 0;
	}
}

/*This function will use the TriColor function to alternate three colors all
through the ring[] array and have the colors rotate clockwise for the small
and large rings while the medium ring will rotate counter clockwise*/
void Hypnotize(void)
{
	changeColorCenter(0x0F0F0F);    //white

	if (patternCounter == 0)
	{
		changeTriColorSmall(LED_Color1, LED_Color2, LED_Color3);
		changeTriColorMed(LED_Color1, LED_Color2, LED_Color3);
		//changeTriColorLarge(LED_Color2,LED_Color2,LED_Color3);
		patternCounter = 1;
	}
	else if (patternCounter == 1)
	{
		changeTriColorSmall(LED_Color2, LED_Color3, LED_Color1);
		changeTriColorMed(LED_Color3, LED_Color1, LED_Color2);
		//changeTriColorLarge(LED_Color2,LED_Color3,LED_Color2);
		patternCounter = 2;
	}
	else
	{
		changeTriColorSmall(LED_Color3, LED_Color1, LED_Color2);
		changeTriColorMed(LED_Color2, LED_Color3, LED_Color1);
		//changeTriColorLarge(LED_Color3,LED_Color2,LED_Color2);
		patternCounter = 0;
	}
}
/*This function will sets all the LEDs to LED_Color1 except for the first
in the ring[] array. This LED will be set to LED_Color2 and will move through
individual LEDs to the end of the array and back*/
void Spiral(void)
{
	changeColorCenter(LED_Color1);
	changeColorSmallRing(LED_Color1);
	changeColorMediumRing(LED_Color1);
	changeColorLargeRing(LED_Color1);

	ring[indexCounter] = LED_Color2;

	if (patternCounter == 0)
	{
		if (0<indexCounter && indexCounter < 13)
		{
			if (indexCounter == 12)
			{
				indexCounter = 28;
			}
			else
			{
				indexCounter++;
			}
		}
		else if (12<indexCounter && indexCounter < 29)
		{
			if (indexCounter == 13)
			{
				indexCounter = 29;
			}
			else
			{
				indexCounter--;
			}
		}
		else
		{
			indexCounter++;
		}
	}
	else
	{
		if (0<indexCounter && indexCounter < 13)
		{
			indexCounter--;
		}
		else if (12<indexCounter && indexCounter < 29)
		{
			if (indexCounter == 28)
			{
				indexCounter = 12;
			}
			else
			{
				indexCounter++;
			}
		}
		else
		{
			if (indexCounter == 29)
			{
				indexCounter = 13;
			}
			else
			{
				indexCounter--;
			}
		}
	}

	if (indexCounter == 0)
	{
		indexCounter = 1;
		patternCounter = 0; //up
	}
	else if (indexCounter == 53)
	{
		patternCounter = 1; //down
	};
}
