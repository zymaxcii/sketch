/*
 * Arduino Sound Meter
 * 
 * learnelectronics
 * 14 April 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0119@gmail
 */


 //--------------------------------------------------------------------------------------------
 //                                          LIBRARIES
 //--------------------------------------------------------------------------------------------
 
#include <SPI.h>                                          //SPI Library for OLED
#include <Adafruit_GFX.h>                                 //Graphics library for OLED
#include <Adafruit_SH1106.h>                              //OLED Driver

//--------------------------------------------------------------------------------------------
 //                                           DEFINES
 //--------------------------------------------------------------------------------------------
 
#define OLED_MOSI   9                                     //SoftSPI MOSI on D9
#define OLED_CLK   10                                     //SoftSPI CLK on D10
#define OLED_DC    11                                     //SoftSPI DC on D11
#define OLED_CS    12                                     //SoftSPI CS on D12
#define OLED_RESET 13                                     //OLED Reset in d13

//--------------------------------------------------------------------------------------------
 //                                        LIBRARY CALLS
 //--------------------------------------------------------------------------------------------
 
                                                          //Create instance of OLED called display
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//--------------------------------------------------------------------------------------------
 //                                       GLOBAL VARIABLES
 //--------------------------------------------------------------------------------------------
 
const int sampleWindow = 50;                              // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

 //--------------------------------------------------------------------------------------------
 //                                            SETUP
 //--------------------------------------------------------------------------------------------
 
void setup() 
{
   Serial.begin(9600);                                    //Serial comms for debugging
   display.begin(SH1106_SWITCHCAPVCC);                    //OLED display start
   display.display();                                     //show buffer
   display.clearDisplay();                                //clear buffer
   display.setTextSize(1);                                //Set text size to 1 (1-6)
   display.setTextColor(WHITE);                           //Set text color to WHITE (no choice lol)
   display.setCursor(0,0);                                //cursor to upper left corner
   display.println(" Arduino Sound Meter");               //write title
   display.display();                                     //show title
   delay(2000);                                           //wait 2 seconds
}
 
//--------------------------------------------------------------------------------------------
 //                                         MAIN LOOP
 //--------------------------------------------------------------------------------------------
  
void loop() 
{
   unsigned long startMillis= millis();                   // Start of sample window
   float peakToPeak = 0;                                  // peak-to-peak level
 
   unsigned int signalMax = 0;                            //minimum value
   unsigned int signalMin = 1024;                         //maximum value
 
                                                          // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);                             //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;                           // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;                    // max - min = peak-peak amplitude
   float db = map(peakToPeak,20,900,49.5,90);             //calibrate for deciBels
   display.setCursor(0,0);                                //cursor to upper left
   display.setTextSize(2);                                //set text size to 2
   display.print(db);                                     //write calibrated deciBels
   display.print(" dB");                                  //write units


    for(int x =5;x<114;x=x+6){                            //draw scale
      display.drawLine(x, 32, x, 27, WHITE);
    }
   display.drawRoundRect(0, 32, 120, 20, 6, WHITE);       //draw outline of bar graph
   int r = map(db,0,120,1,120);                           //set bar graph for width of screen
   display.fillRoundRect(1, 33, r, 18, 6, WHITE);         //draw bar graph with a width of r
   display.display();                                     //show all that we just wrote & drew
   display.clearDisplay();                                //clear the display
}
