// rtc_1302b.ino

/*
 A simple program designed to setup and demonstrate the DS1302 RTC library and 
 DS1302 Real Time Clock Module - BKAA100056
     
 The program uses the DS1302 RTC library to initialise the DS1302 chipset 
 and then read the time from it every second
      
 modified 03 March 2019
 by Sebastian Karam - Flux Workshop
      
 The DS1302 RTC library created by Matt Sparks
 https://github.com/msparks/arduino-ds1302
*/ 

#include "DS1302.h" // include the DS1302 RTC library
     
const int ResetPin = 2;  // reset Pin
const int DataPin = 3;   // data Pin
const int ClockPin = 4;  // clock Pin
     
DS1302 rtc(ResetPin, DataPin, ClockPin);   // create a DS1302 object
     
String dayAsString(const Time::Day day)
{ 
  // function that converts the day ouptput into a string
  switch (day)
  {
        case Time::kSunday: return "Sunday";
        case Time::kMonday: return "Monday";
        case Time::kTuesday: return "Tuesday";
        case Time::kWednesday: return "Wednesday";
        case Time::kThursday: return "Thursday";
        case Time::kFriday: return "Friday";
        case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}
     
char * readTime()
{ 
  // reads time from chip and returns it in a character array
  Time t = rtc.time();     // get the time and date from the chip

  // obtain text for the day of the week
  const String day = dayAsString(t.day);

  // initialise a character array to hold the date text
  static char CurrentTime[50];

  // format the time into the character array
  snprintf(CurrentTime, sizeof(CurrentTime), "%s %04d-%02d-%02d %02d:%02d:%02d", day.c_str(), t.yr, t.mon, t.date, t.hr, t.min, t.sec); 
  
  // return current time
  return CurrentTime;
}
     
     
void setup()
{
  Serial.begin(9600);
  
  rtc.writeProtect(false);     // turn off write protection
  rtc.halt(false);             // clear the clock halt flag

  // create a new time object with set date
  // comment out if no need to set time
  // Time t(2021, 11, 30, 19, 28, 00, Time::kTuesday);    // kFriday
  // rtc.time(t); // send the time to the chipset
}

     
// Loop and print time every second
void loop()
{
  char * timearray = readTime();      // obtain the time from readtime()
  Serial.println(timearray);          // print the time to the serial monitor
  delay(1000);                        // pause before looping
}
