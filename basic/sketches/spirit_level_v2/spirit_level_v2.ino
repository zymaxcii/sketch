/*
 * Digital Spirit Level v1
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
int xplot;                                        //difference from center x axis
int yplot;                                        //difference from center y axis


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

  display.drawCircle(64, 32, 10, WHITE);          //draw the bullseye that marks center (xcenter,ycenter,radius,color)

  if(xnow>x0+5){                                  //if tilted left (5 unit buffer zone)
    xplot = (xnow-x0)+64;                         //difference is current-0 offset by center point
  }

  else if(xnow<x0-5){                             //if tilted right (5 unit buffer zone)
    xplot = 64-(x0-xnow);                         //difference is center point offset by 0-current
  }

  else{                                           //otherwise x axis is centered
    xplot = 64;                                   // center point
  }


if(ynow>y0+5){
    yplot = (ynow-y0)+32;
  }

  else if(ynow<y0-5){
    yplot = 32-(y0-ynow);
  }

  else{
    yplot = 32;
  }

  display.fillCircle(xplot, yplot, 8, WHITE);     //draw filled dot (xcenter,ycenter,radius,color)
  
  delay(500);                                     //wait 1/2 sec to make it more stable
  display.display();                              //show whats in the buffer
  display.clearDisplay();                         //clear screen & buffer
}



