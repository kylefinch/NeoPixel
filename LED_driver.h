/* 
 * File:   LED_driver.h
 * Author: lowell
 * Modified by: Kyle Vandelac on 4/18/14
 * Created on February 28, 2014, 10:51 PM
 */
#include <p32xxxx.h>

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H


int ring[52];
int refreshLEDS(int * ledArray, int lengthArray);
void changeColorSmallRing(int newColor);
void changeColorMediumRing(int newColor);
void changeColorLargeRing(int newColor);
void changeColorAt(int newColor, int loc);
void changeTriColor(int ring[], int newColor1, int newColor2, int newColor3);
void delay_LED(int time);

#endif	/* LED_DRIVER_H */

