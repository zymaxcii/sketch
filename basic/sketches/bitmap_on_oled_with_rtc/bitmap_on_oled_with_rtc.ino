/*
 * Bitmap on OLED w/ RTC
 * 
 * learnelectronics
 * 
 * 5 FEB 2017
 * 
 * www.youtube.com/c/learnelectronics
 */

#include <SPI.h>                                                            //include SPI lib for OLED
#include <Wire.h>                                                           //include wire lib for RTC
#include <DS3231.h>                                                         //include ds3231 RTC lib
#include <Adafruit_GFX.h>                                                   //include GFX lib
#include <Adafruit_SH1106.h>                                                //include sh1106 OLED lib

                                                                            // If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);//set up display
DS3231 Clock;                                                              //set up clock

bool Century=false;                                                        //clock variables
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

byte year, month, date, DoW, hour, minute, second;
                                                                          //our custom bitmap
const unsigned char PROGMEM myclock32 [] = {
0x00, 0x07, 0xE0, 0x00, 0x00, 0x3C, 0x3C, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x03, 0x01, 0x80, 0xC0,
0x06, 0x01, 0x80, 0x60, 0x0C, 0x01, 0x80, 0x30, 0x18, 0x01, 0x80, 0x18, 0x10, 0x01, 0x80, 0x08,
0x20, 0x01, 0x80, 0x04, 0x20, 0x01, 0x80, 0x06, 0x40, 0x01, 0x80, 0x02, 0x40, 0x01, 0x80, 0x02,
0xC0, 0x01, 0x80, 0x03, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
0x80, 0x01, 0xC0, 0x01, 0x80, 0x00, 0x40, 0x01, 0x80, 0x00, 0x20, 0x01, 0xC0, 0x00, 0x30, 0x03,
0x40, 0x00, 0x18, 0x02, 0x40, 0x00, 0x0C, 0x02, 0x60, 0x00, 0x04, 0x06, 0x20, 0x00, 0x00, 0x04,
0x10, 0x00, 0x00, 0x0C, 0x18, 0x00, 0x00, 0x18, 0x0C, 0x00, 0x00, 0x10, 0x06, 0x00, 0x00, 0x60,
0x03, 0x00, 0x00, 0xC0, 0x00, 0xC0, 0x03, 0x80, 0x00, 0x38, 0x1E, 0x00, 0x00, 0x0F, 0xF0, 0x00
};


void setup()   {                
   Wire.begin();                                                          //start I2C
  Serial.begin(9600);                                                     //start serial
  display.begin(SH1106_SWITCHCAPVCC);                                     //activate display
  display.display();                                                      //show buffer
  delay(2000);                                                            //pause
  display.clearDisplay();                                                 //clear display
       

}


void loop() {

 int second,minute,hour,date,month,year,temperature;                      //populate clock variables
  second=Clock.getSecond();
  minute=Clock.getMinute();
  hour=Clock.getHour(h12, PM);
  date=Clock.getDate();
  month=Clock.getMonth(Century);
  year=Clock.getYear();
  
  temperature=Clock.getTemperature();
 display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  display.print(hour,DEC);                                                //print time to OLED (decimal)
  display.print(':');
  display.print(minute,DEC);
  display.print(':');
  display.println(second,DEC);
  
  display.print(month,DEC);                                              //print date to oled (decimal)
  display.print("/");
  display.print(date,DEC);
  display.print("/");
  display.print("20");
  display.println(year,DEC);

  //display.drawbitmap syntax (x pos, y pos, name of bitmap, x size, y size, color)
  
   display.drawBitmap(96, 0, myclock32, 32, 32, WHITE);                 //print our custom clock bitmap
  display.print((temperature)*1.8+32);                                  //print temp converted to F
  display.print("F");
  display.display();                                                    //show whats in the buffer
  display.clearDisplay();                                               //clear the buffer
 
 
  
}


