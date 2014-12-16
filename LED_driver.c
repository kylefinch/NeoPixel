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
        int i =0;    //counter variable
        int j = 0;

      for(count = 0;count<lengthArray;count++) //string control
      {
          currentPixel = ledArray[count]; //get current pixel settings
          for(i=23;i>=0;i--)           //iterate through the current pixel information
          {
              PORTCSET = 0b100;     //code below will convert pixel info to NRZ serial data on portd pin 0
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
                 PORTCCLR = 0b100;
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
                PORTCCLR = 0b100;
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
    int counter = 0, scalar = 0;

    if(time <= 0)
    {
        scalar = 1;
    }
    else if(time > 70)
    {
        scalar = 100000;
    }
    else
    {
        scalar = time;
    }

    for(counter = 0; counter < (400000/scalar); counter++)
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
    for (i=1; i<13; i++)
    {
        ring[i] = newColor;//newColor;
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
void changeTriColor(int newColor1, int newColor2, int newColor3)
{
     int i = 0;
     int color = 0;
    for (i=0; i<53; i++)
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

    switch (colorChoice % 4)
    {
        case 0:
            LED_Color1 = red;
            LED_Color2 = white;
            LED_Color3 = blue;
            break;
        case 1:
            LED_Color1 = yellow;
            LED_Color2 = blue;
            LED_Color3 = red;
            break;
        case 2:
            LED_Color1 = blue;
            LED_Color2 = purple;
            LED_Color3 = green;
            break;
        case 3:
            LED_Color1 = purple;
            LED_Color2 = white;
            LED_Color3 = orange;
            break;
       default:
            LED_Color1 = blue;
            LED_Color2 = green;
            LED_Color3 = red;
            break;
    }
}

/*This function will have alternating colors flashing.
 The Center, and Medium ring will be assigned the same color
 The Small and Large ring will be assigned the same color*/
void AlternatingFlash(void)
{
    if(patternState == 0)
    {
        changeColorCenter(LED_Color1);
        changeColorMediumRing(LED_Color1);

        changeColorSmallRing(LED_Color2);
        changeColorLargeRing(LED_Color2);
        patternState = 1;
    }
    else
    {
        changeColorCenter(LED_Color2);
        changeColorMediumRing(LED_Color2);

        changeColorSmallRing(LED_Color1);
        changeColorLargeRing(LED_Color1);
        patternState = 0;
    }
}

/*This function will use the TriColor function to alternate three colors all
 through the ring[] array and have the colors rotate clockwise for the small
 and large rings while the medium ring will rotate counter clockwise*/
void Hypnotize(void)
{
    changeColorCenter(LED_Color1);

    if(patternState == 0)
    {
        changeTriColorSmall(LED_Color1,LED_Color2,LED_Color3);
        changeTriColorMed(LED_Color1,LED_Color2,LED_Color3);
        changeTriColorLarge(LED_Color1,LED_Color2,LED_Color3);
        patternState = 1;
    }
    else if(patternState == 1)
    {
        changeTriColorSmall(LED_Color2,LED_Color3,LED_Color1);
        changeTriColorMed(LED_Color2,LED_Color3,LED_Color1);
        changeTriColorLarge(LED_Color2,LED_Color3,LED_Color1);
        patternState = 2;
    }
    else
    {
        changeTriColorSmall(LED_Color3,LED_Color1,LED_Color2);
        changeTriColorMed(LED_Color3,LED_Color1,LED_Color1);
        changeTriColorLarge(LED_Color3,LED_Color1,LED_Color2);
        patternState = 0;
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

    if(patternState == 0)
    {
        if(0<=indexCounter && indexCounter < 13)
        {
            indexCounter = (indexCounter == 12) ? 28 : indexCounter +1;
        }
        else if(12<indexCounter && indexCounter < 29)
        {
            indexCounter = (indexCounter == 13) ? 29 : indexCounter -1;
        }
        else
        {
            indexCounter++;
        }
    }
    else
    {
        if(0<indexCounter && indexCounter < 13)
        {
            indexCounter--;
        }
        else if(12<indexCounter && indexCounter < 29)
        {
            indexCounter = (indexCounter == 28) ? 12 : indexCounter +1;
        }
        else
        {
            indexCounter = (indexCounter == 29) ? 13 : indexCounter -1;
        }
    }

    patternState = (indexCounter == 0) ? 0 : ((indexCounter == 53) ? 1 : patternState);
}

void Focus(void)
{

    switch (indexCounter%5)
    {
        case 0:
            changeColorCenter(LED_Color3);
            changeColorSmallRing(LED_Color3);
            changeColorMediumRing(LED_Color3);
            changeColorLargeRing(LED_Color3);
            patternState = 0;
            indexCounter++;
            break;
        case 1:
            changeColorCenter(LED_Color2);
            changeColorSmallRing(LED_Color3);
            changeColorMediumRing(LED_Color3);
            changeColorLargeRing(LED_Color3);
            indexCounter = (patternState == 0) ? indexCounter +1 : indexCounter -1;
            break;
        case 2:
            changeColorCenter(LED_Color2);
            changeColorSmallRing(LED_Color2);
            changeColorMediumRing(LED_Color3);
            changeColorLargeRing(LED_Color3);
            indexCounter = (patternState == 0) ? indexCounter +1 : indexCounter -1;
            break;
        case 3:
            changeColorCenter(LED_Color2);
            changeColorSmallRing(LED_Color2);
            changeColorMediumRing(LED_Color2);
            changeColorLargeRing(LED_Color3);
            indexCounter = (patternState == 0) ? indexCounter +1 : indexCounter -1;
            break;
        default:
            changeColorCenter(LED_Color2);
            changeColorSmallRing(LED_Color2);
            changeColorMediumRing(LED_Color2);
            changeColorLargeRing(LED_Color2);
            patternState = 1;
            indexCounter--;
            break;
    }

}
/*int HSVtoRGB(int hsv)
{
    //mask of h s and v values
    int h = (hsv & (0xFF << 16)) >> 16,
        s =((hsv & (0xFF << 8)) >> 8),
        v = ((hsv & 0xFF)),
        X = 0, R,G,B, rgb;
    float C = 0.0,
        M = 0.0,
        r = 0,
        g = 0,
        b = 0,
        S = 0.0,
        V = 0.0;

    S = ((float)s)/((float)100);
    V = ((float)v)/((float)100);

    C = S * V;
    M = V - C;
   // X = (1/(abs(((h/60)%2)-1)));
    X = h/60;

    if (h >= 0 && h < 60)
    {
        r = C + M;
        g = (double)X + M;
        b = 0 + M;
    }else if (h >= 60 && h < 120)
    {
        r = (double)X + M;
        g = C + M;
        b = 0 + M;
    }else if (h >= 120 && h < 180)
    {
        r = 0 + M;
        g = C + M;
        b = (double)X + M;
    }else if (h >= 180 && h < 240)
    {
        r = 0 + M;
        g = (double)X + M;
        b = C + M;
    }else if (h >= 240 && h < 300)
    {
        r = (double)X + M;
        g = 0 + M;
        b = C + M;
    }else// h > 300 && h < 360
    {
        r = C + M;
        g = 0 + M;
        b = (double)X + M;
    }
    R = r*255;
    G = g*255 ;
    B = b*255;
    
    R = (int)R;
    G = (int)G;
    B = (int)B;

    R = R<<8;
    G = G<<16;
    B = B;

    rgb =  G | R | B;


    return rgb;
}*/

