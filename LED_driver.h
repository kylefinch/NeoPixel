/*
 * File:   LED_driver.h
 * Author: lowell
 * Modified by: Kyle Finch on 4/18/14
 * Created on February 28, 2014, 10:51 PM
 */
#include <p32xxxx.h>

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H


int ring[53];
int LED_Color1, LED_Color2, LED_Color3, patternState, indexCounter;

int refreshLEDS(int * ledArray, int lengthArray);
void changeColorCenter(int newColor);
void changeColorSmallRing(int newColor);
void changeColorMediumRing(int newColor);
void changeColorLargeRing(int newColor);
void changeColorAt(int newColor, int loc);
void changeTriColor(int newColor1, int newColor2, int newColor3);
void changeTriColorSmall(int newColor1, int newColor2, int newColor3);
void changeTriColorMed(int newColor1, int newColor2, int newColor3);
void changeTriColorLarge(int newColor1, int newColor2, int newColor3);
void delay_LED(int time);
void setColorPattern(int colorChoice);
void AlternatingFlash(void);
void Hypnotize(void);
void Spiral(void);
void Focus(void);
//int HSVtoRGB(int hsv);

#endif	/* LED_DRIVER_H */

