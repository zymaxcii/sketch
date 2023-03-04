/*
 * Digital Spirit Level v0.5
 * 
 * learnelectronics
 * 10 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */
//---------------------------------------------------------------------------------------------------------------
//                                                 LIBRARIES
//---------------------------------------------------------------------------------------------------------------

#include <Wire.h>                                 //wire library for oled
#include <Adafruit_SSD1306.h>                     //oled driver

//---------------------------------------------------------------------------------------------------------------
//                                                  DEFINES
//---------------------------------------------------------------------------------------------------------------

#define OLED_RESET 4                              //used by adafruit library

//---------------------------------------------------------------------------------------------------------------
//                                              LIBRARY OBJECTS
//---------------------------------------------------------------------------------------------------------------

Adafruit_SSD1306 display(OLED_RESET);             //create instance of oled called display

//---------------------------------------------------------------------------------------------------------------
//                                                  VARIABLES
//---------------------------------------------------------------------------------------------------------------

float x0;                                         //initial reading of x (0 point)
float y0;                                         //initial reading of y (0 point)
float xnow;                                       //current reading of x
float ynow;                                       //current reading of y


//---------------------------------------------------------------------------------------------------------------
//                                                    SETUP
//---------------------------------------------------------------------------------------------------------------

void setup()   {                

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);      //start oled @ hex addy 0x3C
  display.display();                              //clear display
  display.clearDisplay();                         //clear display
  delay(1000);                                    //wait 1 sec to get 0 reading
  x0 = analogRead(A0);                            //get 0 reading of x
  y0 = analogRead(A1);                            //get 0 reading of y
  delay(1000);                                    //wait 1 sec before beginning

}

//---------------------------------------------------------------------------------------------------------------
//                                                  MAIN LOOP
//---------------------------------------------------------------------------------------------------------------

void loop() {

  xnow = analogRead(A0);                          //get current value of x
  ynow = analogRead(A1);                          //get current value of y

  display.setTextSize(1);                         //set text size
  display.setTextColor(WHITE);                    //set text color
  display.setCursor(0,0);                         //set cursor to upper left
  display.println("    Digital Level");           //print the header to buffer
  display.setCursor(0,40);                        //drop down a few lines

  if(xnow<x0-5){                                  //if current x is less than 0 point x
    display.print("-------<<[ ]---------");       //print <x indication to buffer
  }
  else if(xnow>x0+5){                             //if current x is greater than 0 point x
    display.print("---------[ ]>>-------");       //print >x indication to buffer
  }
  else{                                           //if it aint greater than or less than it must be equal
    display.print("---------[X]---------");       //print level indication to bufer
  }
  delay(500);                                     //wait 1/2 sec to make it more stable
  display.display();                              //show whats in the buffer
  display.clearDisplay();                         //clear screen & buffer
}



