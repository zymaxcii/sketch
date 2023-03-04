/*
 * Arduino Tounchscreen Radio
 * with Si4703, 2.8" TFT LCD 
 * For Arduino Mega
 * 
 * learnelectronics
 * 11 APRIL 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */

#include <Adafruit_GFX.h>                 //graphix library for drawing
#include <Adafruit_TFTLCD.h>              //LCD library to drive screen
#include "TouchScreen.h"                  //library for tounchscreen
#include <Wire.h>                         //I2C library
#include <radio.h>                        //Radio library
#include <si4703.h>                       //si4703 library


#define YP A3                             // touchscreen - must be an analog pin, use "An" notation!
#define XM A2                             // touchscreen - must be an analog pin, use "An" notation!
#define YM 9                              // touchscreen - can be a digital pin
#define XP 8                              // touchscreen - can be a digital pin

#define TS_MINX 150                       //touchscreen - min x value
#define TS_MINY 120                       //touchscreen - min y value
#define TS_MAXX 920                       //touchscreen - max x value
#define TS_MAXY 940                       //touchscreen - max y value

SI4703 radio;                             //create instance of SI4703 called radio
                                          //create instance of touchscreen called ts
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3                         //LCD Control Pins
#define LCD_CD A2                         //LCD Control Pins
#define LCD_WR A1                         //LCD Control Pins
#define LCD_RD A0                         //LCD Control Pins
                                          // optional
#define LCD_RESET A4                       //LCD Control Pins

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

                                          //create instance of TFTLCD called tft
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


int station=10350;                        //var to hold station
int volume = 5;                           //var to hold volume
int horz;                                 //var to hold x touch
int vert;                                 //var to hold y touch
String rdsname="XXXX";                    //var to hold RDS name data
String rdstext="No Data";                 //var to hold RDS Text data
String rdstime="12:12";                   //var to hold RDS Time data
  
void setup(void) {
  Serial.begin(9600);                    //serial comms for debug
  tft.reset();                           //reset the screen
  tft.begin(0x9341);                     //start screen using chip identifier hex

  tft.setRotation(1);                    //set rotation for wide screen
  tft.fillScreen(BLACK);                 //fill screen with black (ersatz clear)
  tft.setCursor(0, 0); 
  tft.setTextColor(WHITE);               //set text color white
  tft.setTextSize(2);                    //set text size to 2 (1-6)
  tft.println("     Arduino FM Radio");  //print header to screen
  
   tft.drawRoundRect(10, 20, 300, 200, 6, WHITE); //draw screen outline
   tft.fillRoundRect(20, 30, 160, 50, 6, RED);    //draw station box
   tft.fillRoundRect(20, 90, 110, 50, 6, BLUE);   //draw volume box
   tft.fillRoundRect(135, 90, 50, 50, 6, BLUE);   //draw mute box
   tft.fillRoundRect(20, 150,280, 50, 6, YELLOW); //draw RDS box
   tft.fillRoundRect(190, 30, 50, 50, 6, RED);    //draw station up buton
   tft.fillRoundRect(250, 30, 50, 50, 6, RED);    //draw station down buton
   tft.fillRoundRect(190, 90, 50, 50, 6, BLUE);   //draw volume up buton
   tft.fillRoundRect(250, 90, 50, 50, 6, BLUE);   //draw volume down buton
   tft.fillTriangle(215, 30, 192, 67, 235, 67,WHITE); //draw up triangle for station
   tft.fillTriangle(275, 67, 252, 30, 295, 30,WHITE); //draw down triangle for station
   tft.fillTriangle(215, 90, 192, 127, 235, 127,WHITE); //draw up triangle for volume
   tft.fillTriangle(275, 127, 252, 90, 295, 90,WHITE);  //draw down triangle for volume
   tft.setCursor(152, 105);                             //put cursor in mute box
   tft.setTextSize(3);                                  //set text size 3
   tft.println("X");                                    //write a bog ol x in mute box

  volume = constrain(volume, 1, 15);
  radio.init();                                        //initialize radio

  radio.setBandFrequency(RADIO_BAND_FM, station);      //set band and freq
  radio.setVolume(volume);                              //set volume
  radio.setMono(false);                                 //set stereo
  radio.setMute(false);                                 //set sound on
}

void think(){                                           //logic for buttons
  if(horz>650 && horz<789){           //station up
    if(vert>297 && vert<359){
      station=station+20;
      tft.fillRoundRect(20, 30, 160, 50, 6, RED);
      radio.setFrequency(station);
    }
  }
  if(horz>650 && horz<770){           //station down
    if(vert>148 && vert<234){
      station=station-20;
      tft.fillRoundRect(20, 30, 160, 50, 6, RED);
      radio.setFrequency(station);
    }
  }
if(horz>538 && horz<588){           //volume up
    if(vert>302 && vert<390){
      volume++;
      tft.fillRoundRect(20, 90, 110, 50, 6, BLUE);
      radio.setVolume(volume);
    }
  }
  if(horz>436 && horz<627){           //volume down
    if(vert>136 && vert<234){
      volume--;
      tft.fillRoundRect(20, 90, 110, 50, 6, BLUE);
      radio.setVolume(volume);
    }
  }
  /*
  if(horz>478 && horz<605){           //mute
    if(vert>293 && vert<538){
      volume=0;
      tft.fillRoundRect(135, 90, 50, 50, 6, BLUE);
      radio.setVolume(volume);
    }
  }
  */
}

void loop(void) {
                                    //screen updates 
 tft.setCursor(22, 40);
 tft.setTextColor(WHITE);
 tft.setTextSize(2);
 tft.print("Station:");
 tft.setTextColor(WHITE);
 tft.print(station);                //write station
 tft.setCursor(22, 110);
 tft.setTextColor(WHITE);
 tft.setTextSize(2);
 tft.print("Volume:");
 tft.setTextColor(WHITE);
 tft.print(volume);                 //write volume
 tft.setTextColor(BLACK);
 tft.setCursor(22, 160);
 tft.setTextSize(1);
 tft.print(rdstime);                //write RDS data
tft.setCursor(22, 170);
 tft.print(rdsname);
tft.setCursor(22, 180);
 tft.print(rdstext);
                                    //look for a touch
                                    //since we are sharing pins between display & touch
                                    //we must change directions everytime we look for a touch
   digitalWrite(13, HIGH);
   TSPoint p = ts.getPoint();       //get touch
   digitalWrite(13, LOW);
   pinMode(XM, OUTPUT);
   pinMode(YP, OUTPUT);
   
   if (p.z > ts.pressureThreshhold) { //if touch is above threshold
     
     horz=p.x;                        //send touch values to variables
     vert=p.y;
     think();                         //call think function
  }

}
