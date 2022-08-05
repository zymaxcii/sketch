// rtc.ino
// using DS1307 with 2 servos

// http://samsneatprojectblogcode.blogspot.com/


// CODE BY SAM BASKIN HIES 2018
// If you're trying to figure this out and I'm graduated then don't hesitate to email me at samsonbaskin@gmail.com or call 404-680-1281


#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

RTC_DS1307 RTC;

int yearLast = 17;
int daysOfWeek;
int wait1 = 200;
int daylightSavings = 0;     // 0 if between November and March, 1 if between March and November
int wait2 = 500;
float w = 0;
int sCount = 0;
int tune = 0;

Servo remus;
Servo spin;

int monthCode[12] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
// char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void setup ()
{
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  remus.attach(9);

  // remus.attach(9);
  remus.write(100);
  delay(500);
  remus.detach();
  // char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


  // IMPORTANT: INSTRUCTIONS FOR RESETTNG TIME AND ADJUSTING FOR DAYLIGHT SAVINGS
  // If it just went between daylight savings or not daylight savings, you can also follow the below instructions.
  // STEP 1: Uncomment the line below to reset time.
  // STEP 2: After uploading, re-comment the line and upload again.
  // Otherwise the time will reset every time you start the sketch.
  // RTC.adjust(DateTime(__DATE__, __TIME__)); 
  //^^^^^^^^^^THIS IS THE LINE YOU SHOULD COMMENT/UNCOMMENT(like the one above this line, not THIS line. You troll.)^^^^^^^^

  if (! RTC.isrunning())
  {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled


    // Allows for precise time setting
    // RTC.setHours(15);
    // RTC.setMinutes(7);
    // RTC.setSeconds(5)
  }
}


void loop ()
{
  printTime1();   // Calls printTime1 method to prints timestamp

  /*
   * SET BELL TIMES HERE
  */
  //CHECK TIME SECTION
  // Use -1 as an input if you want any hour
  // FORMAT: checkTime(hour, minute, second).      ring(How many times you want it to ring)
  // No need for "== true" because checkTime is a boolean method

  // IF NOT THURS

  if (daysOfWeek != 5 && daysOfWeek != 1 && daysOfWeek != 7)
  {
    if (checkTime(8, 29, 45))
    {
      ring(1);
    }
    if (checkTime(9, 39, 45))
    {
      ring(1);
    }
    if (checkTime(9, 44, 45))
    {
      ring(1);
    }
  }
 
  if (daysOfWeek == 5)
  {
    if (checkTime(8, 19, 45))
    {
      ring(1);
    }
    if (checkTime(9, 29, 45))
    {
      ring(1);
    }
    if (checkTime(9, 29, 45))
    {
      ring(1);
    }
  }


// STANDARD DAY
  if (daysOfWeek != 7 && daysOfWeek != 1)
  {
    if (checkTime(10, 24, 45))
    {
      ring(1);
    }
    if (checkTime(10, 29, 45))
    {
      ring(1);
    }
    if (checkTime(11, 39, 45))
    {
      ring(1);
    }
    if (checkTime(11, 44, 45))
    {
      ring(1);
    }
    if (checkTime(12, 54, 45))
    {
      ring(1);
    }
    if (checkTime(13, 44, 45))
    {
      ring(1);
    }
    if (checkTime(14, 59, 45))
    {
      ring(1);
    }
    if (checkTime(16, 59, 45))
    {
      ring(1);
    }
  }

  // ROBOTICS STUFF
  if (daysOfWeek == 5 || daysOfWeek == 3)
  {
    if (checkTime(15, 14, 45))
    {
      ring(1);
    }
    if (checkTime(16, 49, 45))
    {
      ring(1);
    }
  }

  if(Serial.available() > sCount)
  {
    ring(1);
    sCount++;
  }
  delay(1000);
}


// CONTROLS SERVO TO RING BELL
void ring(int n)
{
  for (int i = 0; i < n; i++)
  {
    remus.attach(9);
    delay(500);
    remus.write(140);
    delay(600);
    remus.write(100);
    delay(500);
    remus.detach();
  }
}


// PRINTS TIME
void printTime1()
{
  // int daysOfWeek
  DateTime now = RTC.now();
  int dayOWeek = int(yearLast / 4) + now.day() + monthCode[now.month()-1] + 6 + 17;
  if (now.month() == 1 || now.month() == 2)
  {
    daysOfWeek = (dayOWeek % 7) + 1;
  }
  else
  {
    daysOfWeek = dayOWeek % 7;
  }

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second() + tune, DEC);
 
  Serial.println(daysOfWeek);
  Serial.println();
}


// CHECKS TO SEE IF RING TIME IS EQUAL TO CURRENT TIME
boolean checkTime(int h , int m, int s)
{
  boolean ho = false;
  boolean mi = false;
  boolean se = false;

  DateTime now = RTC.now();

  if (now.hour() == h || h == -1)
  {
    ho = true;
  }

  if (now.minute() == m || m == -1)
  {
    mi = true;
  }
  
  if (now.second() == (s) || s == -1)     // + tune corrects the clock's slightly off time which results from uploading
  {
    se = true;
  }

  if (ho && mi && se)
  {
    return true;
  }

  else
  {
    return false;
  }
}
