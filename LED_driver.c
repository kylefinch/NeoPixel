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
    { unsigned int count = 0; //location variable
       int currentPixel = 0;  //current pixel information
       int i =0;    //counter variable
       int j = 0;
      for(count = 0;count<lengthArray;count++) //string control
         {

        currentPixel = ledArray[count]; //get current pixel settings
            for(i=23;i>=0;i--)           //iterate through the current pixel information
            {PORTDSET = 0b10000;     //code below will convert pixel info to NRZ serial data on portd pin 4
             if(currentPixel & (0x000001)<<i)
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
                 PORTDCLR = 0b10000;
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
                }//delay for logic one

            else
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
                PORTDCLR = 0b10000;
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
      for(j=0;j<100;j++);
      return 1;
}
/*This function is a simple delay. Given input "time", 
 * the function will do that many "nop" operations*/
void delay_LED(int time)
{
    int counter = 0;

    for(counter = 0; counter < time; counter++)
    {
        __asm__("nop");
    }
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
    for (i=1; i<13; i++)
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
    for (i=13; i<29; i++)
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
    for (i=29; i<53; i++)
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
void changeTriColor(int ring[],int newColor1, int newColor2, int newColor3)
{
    int i = 0;
    int color = 0;
    for (i=1; i<53; i++)
    {
        if((i%3) == 0)
        {
            color = newColor1;
        }
        else if((i%3) == 1)
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
    for (i=1; i<13; i++)
    {
        if((i%3) == 0)
        {
            color = newColor1;
        }
        else if((i%3) == 1)
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
    for (i=13; i<29; i++)
    {
        if((i%3) == 0)
        {
            color = newColor1;
        }
        else if((i%3) == 1)
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
    for (i=29; i<53; i++)
    {
        if((i%3) == 0)
        {
            color = newColor1;
        }
        else if((i%3) == 1)
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
