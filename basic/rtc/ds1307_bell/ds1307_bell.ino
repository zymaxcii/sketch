// ds1307_bell.ino

// rtcBell.ino
// using DS1307 RTC

// http://samsneatprojectblogcode.blogspot.com/

#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

RTC_DS1307 RTC;

int wait1 = 200;
int wait2 = 500;
int tune = 7;

Servo remus;
Servo spin;


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
  remus.write(100);
  delay(500);
  remus.detach();
 
  // Uncomment the line below to reset time
  // After uploading, re-comment the line and upload again
  // Otherwise the time will reset every time you start the sketch
  // RTC.adjust(DateTime(__DATE__, __TIME__));
 
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
  printTime1();   // Calls printTime1 method to print timestamp

  /*
  * SET BELL TIMES HERE
  */
  // CHECK TIME SECTION
  // Use -1 as an input if you want any hour
  // FORMAT: checkTime(hour, minute, second).      ring(How many times you want it to ring)
  // No need for "== true" because checkTime is a boolean method


  if (checkTime(13, 0, 20))
  {
    ring(1);
  }

  if (checkTime(9, 31, 50))
  {
    ring(1);
  }
  delay(1000);
}


// Control servo to ring bell
void ring(int n)
{
  for (int i = 0; i < n; i++)
  {
    remus.attach(9);
    remus.write(122);
    delay(300);
    remus.write(100);
    delay(500);
    remus.detach();
  }
}


// print time
void printTime1()
{
  DateTime now = RTC.now();
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
  Serial.print(now.second() + tune, DEC);
  Serial.println();
}


// check to see if ring time is equal to current time
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
  
  // tune corrects the clock's slightly off time which results from uploading
  if (now.second() == (s+tune) || s == -1)  
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
