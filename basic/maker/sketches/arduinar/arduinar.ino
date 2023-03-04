/*
 * Arduinar Targeting System
 * 
 * learnelectronics
 * 27 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */


//-----------------------------------------------------------------------------------------
//                                    LIBRARIES
//-----------------------------------------------------------------------------------------


#include <SPI.h>                                                          //serial lib for oled
#include <Wire.h>                                                         //I2C ??
#include <Adafruit_GFX.h>                                                 //grafix library for oled
#include <Adafruit_SH1106.h>                                              //oled driver
#include <Servo.h>                                                        //servo driver
#include <NewPing.h>                                                      //sonar driver


//-----------------------------------------------------------------------------------------
//                                    DEFINES
//-----------------------------------------------------------------------------------------
#define OLED_MOSI      9                                                  //oled Din digital pin 9
#define OLED_CLK      10                                                  //oled CLK digital pin 10
#define OLED_DC       11                                                  //oled DC digital pin 11
#define OLED_CS       12                                                  //oled CD digital pin 12
#define OLED_RESET    13                                                  //oled reset digital pin 13
#define TRIGGER_PIN    5                                                  //sonar trigger digital pin 5
#define ECHO_PIN       4                                                  //sonar echo digital pin 5
#define MAX_DISTANCE  200                                                 //sonar max distance in cm

//-----------------------------------------------------------------------------------------
//                                    LIBRARY CALLS
//-----------------------------------------------------------------------------------------
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS); //set up oled soft spi
Servo myservo;                                                              //set up servo
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);                         //set up sonar

//-----------------------------------------------------------------------------------------
//                                    VARIABLES
//-----------------------------------------------------------------------------------------
int pos = 0;                                                                //servo pos in degrees


//-----------------------------------------------------------------------------------------
//                                    SETUP
//-----------------------------------------------------------------------------------------
void setup()   {                
  Serial.begin(9600);                                                       //serial comms
  

  display.begin(SH1106_SWITCHCAPVCC);                                       //oled start

  display.display();                                                        //splash screen stuff
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(" Arduinar");
  display.setTextSize(1);
  display.println("  SONAR Targeting &");
  display.println("  Tracking System");
  display.display();
  delay(2000);
  myservo.attach(A2);                                                       //attach servo to A2

}



//-----------------------------------------------------------------------------------------
//                                    MAIN LOOP
//-----------------------------------------------------------------------------------------
void loop() {

byte echo = 0;                                                            //variable to store echo cm
display.clearDisplay();                                                   //clear display




display.drawRect(0, 0, 128, 64, WHITE);                                   //draw screen layout
display.drawCircle(64, 64, 64, WHITE);
display.drawCircle(64, 64, 48, WHITE);
display.drawCircle(64, 64, 32, WHITE);
display.drawCircle(64, 64, 16, WHITE);
display.drawCircle(64, 64, 8, WHITE);

display.display();                                                        //show layout


  for (pos = 0; pos <= 180; pos += 1) {                                   //sweep right
    // in steps of 1 degree
    myservo.write(pos);                                                   //move servo to "pos" degrees
    echo = sonar.ping_cm();                                               //send & receive sonar
    Serial.println(echo);                                                 //print for debuging
    if(echo>0 && echo<10){                                                //if echo is in range
          int l =map(pos,0,180,0,128);                                    //map degrees to screen width
          display.drawLine(64, 64, l, 0, WHITE);                          //draw line from btm ctr to mapped point
          display.display();                                              //show line
          display.drawLine(64, 64, l, 0, BLACK);                          //clear line
          display.drawRect(0, 0, 128, 64, WHITE);                         //redraw screen layout
          display.drawCircle(64, 64, 64, WHITE);
          display.drawCircle(64, 64, 48, WHITE);
          display.drawCircle(64, 64, 32, WHITE);
          display.drawCircle(64, 64, 16, WHITE);
          display.drawCircle(64, 64, 8, WHITE);
          display.display();                                              //show redrawn layout        
    }
        delay(15);                                                        //wait                 
  }
  for (pos = 180; pos >= 0; pos -= 1) {                                   //sweep left
    myservo.write(pos);
    echo = sonar.ping_cm();
    Serial.println(echo);
    if(echo>0 && echo<10){
          int l =map(pos,0,180,0,128);
          display.drawLine(64, 64, l, 0, WHITE);
          display.display();
          display.drawLine(64, 64, l, 0, BLACK);
          display.drawRect(0, 0, 128, 64, WHITE);
          display.drawCircle(64, 64, 64, WHITE);
          display.drawCircle(64, 64, 48, WHITE);
          display.drawCircle(64, 64, 32, WHITE);
          display.drawCircle(64, 64, 16, WHITE);
          display.drawCircle(64, 64, 8, WHITE);
          display.display();        
    }             
      delay(15);                     
  }
  
}

