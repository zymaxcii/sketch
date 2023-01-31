// ds3231_sqwInt.ino

// https://github.com/DuranioMakes/DS3231_RTC_SQW_1Hz_Interrupt
// https://www.youtube.com/watch?v=2xZ15ntJy20


/*
This sketch is a modified version of the DS3231 example sketch avaiable as part of the Adafruit RTClib library. This sketch has been modified to use the SQW output pin of the DS3231 as an external
interrupt signal connected to pin 2 of the Arduino. This sketch configures the SQW pin of the DS3231 to output a 1Hz squarewave to trigger the Arduino to read new date and time info from the DS3231.

Link to the Adafruit DS3231 Imlementation Guide: https://cdn-learn.adafruit.com/downloads/pdf/adafruit-ds3231-precision-rtc-breakout.pdf
Link to the Adafruit RTClib library: https://github.com/adafruit/RTClib
Link to the original Adafruit ds3231 example sketch: https://github.com/adafruit/RTClib/blob/master/examples/ds3231/ds3231.ino
*/


#include "RTClib.h"

const byte SQWinput = 2;   // Interrut pin

volatile int EDGE;         // falling 1Hz clock edge

// Setup the Real Time Clock DS3231
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void setup()
{
  Serial.begin(9600);
 
  if (! rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
    // set explicit date & time
    // January 21, 2014 at 3am you would call
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // or set explicit date & time
  // January 21, 2014 at 3am you would call
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  
  // Configure SQW pin to output a 1Hz squarewave
  rtc.writeSqwPinMode(DS3231_SquareWave1Hz);
  
  pinMode(SQWinput, INPUT);
  // Enable internal pull-up resistor, since SQW pin is an Open Drain output
  digitalWrite (SQWinput, HIGH); 
  
  attachInterrupt(digitalPinToInterrupt(SQWinput), Isr, FALLING);
   // Initialize EDGE to 1
   // isr will make EDGE equal to zero when triggered by a falling clock edge on SQW
   EDGE = 1;
}


// Interrupt Service Routine
void Isr()
{
    EDGE = 0;
}


void loop ()
{
  if (EDGE == 0)
  {
    displayTime();
    EDGE = 1;
  }
}


void displayTime()
{
  DateTime now = rtc.now();
  
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  Serial.print(" since midnight 1/1/1970 = ");
  Serial.print(now.unixtime());
  Serial.print("s = ");
  Serial.print(now.unixtime() / 86400L);
  Serial.println("d");

  // calculate a date which is 7 days, 12 hours, 30 minutes, 6 seconds into the future
  DateTime future (now + TimeSpan(7,12,30,6));

  Serial.print(" now + 7d + 12h + 30m + 6s: ");
  Serial.print(future.year(), DEC);
  Serial.print('/');
  Serial.print(future.month(), DEC);
  Serial.print('/');
  Serial.print(future.day(), DEC);
  Serial.print(' ');
  Serial.print(future.hour(), DEC);
  Serial.print(':');
  Serial.print(future.minute(), DEC);
  Serial.print(':');
  Serial.print(future.second(), DEC);
  Serial.println();

  Serial.print("Temperature: ");
  Serial.print(rtc.getTemperature());
  Serial.println(" C");

  Serial.println();
  // delay(3000);
}
