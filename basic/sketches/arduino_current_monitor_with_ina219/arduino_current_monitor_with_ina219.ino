/**********************************************
* Arduino Current Monitoring
* with INA219 Module
* by learnelectronics
* 30 JAN 2017
*
* www.youtube.com/c/learnelectronics
**********************************************/


#include <Wire.h>                                   // Include the Wire lib as we are using I2C
#include <INA219.h>                                 // We need the INA219 lib to use the sensor
#include <Adafruit_GFX.h>                           // grafix lib for the OLED
#include <Adafruit_SSD1306.h>                       // I2C OLED lib

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);               //OLED lib call

INA219 monitor;                                     //INA219 lib call


void setup()
{
 
   monitor.begin();                                 // start the ina219
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);       // start the oled @ address 0x3c
   display.display();                               // show buffer
   display.clearDisplay();                          // clear display
}

void loop()
{

  display.setTextSize(1);                           //set text size to 1
  display.setTextColor(WHITE);                      //set color to white
  display.setCursor(0,0);                           //set cursor to upper left

  display.print("shunt current: ");                 //print string to oled
  display.setCursor(0,10);                          //drop down to next line
  display.print(monitor.shuntCurrent() * 1000, 4);  //print current to the oled
  display.setCursor(47,10);                         //move 47 pixels right
  display.println(" mA");                           //print scale we are using
  
  display.display();                                //show what is in the buffer
  delay(1000);                                      //wait one second
  display.clearDisplay();                           //clear the display
}


