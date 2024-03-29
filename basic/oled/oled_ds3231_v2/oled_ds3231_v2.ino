// oled_ds3231_v2.ino
// status: compile ok, upload ok, working now

// https://www.youtube.com/watch?v=ai4xqzTVGUM
// https://github.com/jarzebski/Arduino-DS3231

#include <Wire.h>
#include "DS3231.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int pause=1000;

DS3231 myClock;
RTCDateTime dt;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1// Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
Serial.begin(9600);
    myClock.begin();
  // Set sketch compiling time
    // clock.setDateTime(__DATE__, __TIME__);
 
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display(); //display initial Adafruit logo
    delay(2000); 

  // Clear the buffer
  display.clearDisplay(); 
  display.display();

}

String DayOfTheWeek(uint8_t Day){
  String DayText;
  if (Day==1)  DayText="Monday";
  if (Day==2)  DayText="Tuesday";
  if (Day==3)  DayText="Wednesday";
  if (Day==4)  DayText="Thursday";
  if (Day==5)  DayText="Friday";
  if (Day==6)  DayText="Saturday";
  if (Day==7)  DayText="Sunday";
  return DayText;
}



String DayMonthYear(uint8_t Day,uint8_t Month,uint16_t Year){
  String DayMonthYearText;
  if (Month==1)  DayMonthYearText="JAN ";
  if (Month==2)  DayMonthYearText="FEB ";
  if (Month==3)  DayMonthYearText="MAR ";
  if (Month==4)  DayMonthYearText="APR ";
  if (Month==5)  DayMonthYearText="MAY ";
  if (Month==6)  DayMonthYearText="JUN ";
  if (Month==7)  DayMonthYearText="JUL ";
  if (Month==8)  DayMonthYearText="AUG ";
  if (Month==9)  DayMonthYearText="SEP ";
  if (Month==10)  DayMonthYearText="OCT ";
  if (Month==11)  DayMonthYearText="NOV ";
  if (Month==12)  DayMonthYearText="DEC ";

  DayMonthYearText=DayMonthYearText+Day;
  if (Day==1)DayMonthYearText=DayMonthYearText+"st ";
  if (Day==2)DayMonthYearText=DayMonthYearText+"nd ";
  if (Day>2)DayMonthYearText=DayMonthYearText+"th ";

  DayMonthYearText=DayMonthYearText+Year;
  
  return DayMonthYearText;
}

String AddLeadingZero(uint8_t x){
  String AddLeadingZeroText;
  if(x<10) AddLeadingZeroText="0"; 
  else AddLeadingZeroText=""; 
  AddLeadingZeroText=AddLeadingZeroText+x;
  return AddLeadingZeroText;
}

String CurrentTime(uint8_t h, uint8_t i ){
  String CurrentTimeText="";
  CurrentTimeText=CurrentTimeText + AddLeadingZero(h) +":"+AddLeadingZero(i);
  return CurrentTimeText;
}

void loop() {
  dt = myClock.getDateTime();

  display.fillRect(0,0,128,16,SSD1306_WHITE);
  display.fillRect(0,16,128,28,SSD1306_WHITE);
  display.fillRect(0,28,128,46,SSD1306_BLACK);
  display.fillRect(0,54,128,64,SSD1306_WHITE);

    display.setCursor(1,1); 
    display.setTextSize(2);
    display.setTextColor(SSD1306_BLACK); 
    display.println(DayOfTheWeek(dt.dayOfWeek));

  display.setCursor(1,18); 
  display.setTextSize(1);
  display.setTextColor(SSD1306_BLACK); 
  display.println(DayMonthYear(dt.day,dt.month,dt.year));

    display.setCursor(0,31); 
    display.setTextSize(3);  
    display.setTextColor(SSD1306_WHITE); 
    display.println(CurrentTime(dt.hour,dt.minute));

     display.setCursor(88,31); 
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE); 
  display.println(":");

  display.setCursor(102,35); 
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE); 
  display.println(AddLeadingZero(dt.second));

    display.setCursor(12,55); 
  display.setTextSize(1);
  display.setTextColor(SSD1306_BLACK); 
  display.println("Tempreture : ");

  myClock.forceConversion();
  display.setCursor(75,55); 
  display.setTextSize(1);
display.setTextColor(SSD1306_BLACK); 
display.print(myClock.readTemperature());
display.setCursor(105,53); 
display.setTextSize(1);
display.print("o");


  display.display();
  delay(1000);
}
