/*
 * 7 Segment 4 Digit Display Example
 * 
 * learnelectronics
 * 5 May 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * TM1637 Libray can be downloaded from: https://github.com/avishorp/TM1637
 */

 
#include <DS3231.h>                                           //RTC Library
#include <Wire.h>                                             //I2C Library
#include <TM1637Display.h>                                    //TM1637 Library

#define CLK 2                                                 //display clock on digital 2
#define DIO 3                                                 //display data on digital 3

DS3231 Clock;                                                 //create instance of DS3131 called Clock
TM1637Display display(CLK, DIO);                              //create instance of 7/4 display called display

byte year, month, date, DoW, hour, minute, second;            //global variables for DS3231

void setup() {

  Wire.begin();                                               //start I2C
  Serial.begin(9600);                                         //start serial comms for debug
  display.setBrightness(0x0f);                                //set max brightness
}

void loop() {

Clock.getTime(year, month, date, DoW, hour, minute, second);  //get time from DS3231

String myTime = String(hour)+String(minute);                  //convert the hour and minutes ints to a string
int myTimeInt = myTime.toInt();                               //convert the string to a single integer
//Serial.print(myTimeInt);                                    //print to serial for debug
display.showNumberDecEx(myTimeInt, (0x80 >> 1), true,4,0);    //show time on display with colon on
delay(1000);                                                  //wait one ssecond
display.showNumberDec(myTimeInt, true, 4, 0);                 //show time with colon off
delay(1000);                                                  //wait one second

}
