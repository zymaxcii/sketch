// tm1637-rtc.ino
// https://mytectutor.com/tm1637-4-digit-7-segment-display-with-arduino-digital-clock-example/


#include "RTClib.h"
#include <TM1637Display.h>
// Define the connections pins:
#define CLK 9
#define DIO 8
// Create rtc and display object:
RTC_DS3231 rtc;

TM1637Display display = TM1637Display(CLK, DIO);
const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Wait for console opening:
  delay(3000);
  // Check if RTC is
connected correctly:
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  // Check if the RTC lost power and if so, set the time:
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // The following line sets the RTC to the date & time this sketch was compiled:
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
  display.setBrightness(0x0a);  // Set the
display brightness 
  display.setSegments(blank);//clear display
}
void loop() {
  
  DateTime now = rtc.now(); // Get current date and time
  int displaytime = (now.hour() * 100) + now.minute(); // Create time format to display
  Serial.println(displaytime); // Print displaytime to the Serial Monitor: 

    //create blinking center colon
    int a=now.second()%2;
    if(a==0){display.setColon(false);}
    else{display.setColon(true);}
    
    display.showNumberDec(displaytime, true); //Display the current time in 24 hour format with leading zeros enabled and a center colon:
}
