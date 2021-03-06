// https://docs.google.com/document/d/e/2PACX-1vQfgD6z_DbvsePnDIoKMtx1W0B9DcW_LGmpeIDGWZ-LcOoxHtGY3uwuHJ_CMIp_dZ_EWIudq8zKWOny/pub


// A quick demo of how to use my DS1302-library to

// quickly send time and date information over a serial link

// I assume you know how to connect the DS1302.

// DS1302:  CE pin    -> Arduino Digital 2

// I/O pin   -> Arduino Digital 3

// SCLK pin  -> Arduino Digital 4

 

#include <DS1302.h>

 

// Init the DS1302

DS1302 rtc(2, 3, 4);

 

/* The setup() function is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. This function will only run once, after each power up or reset of the Arduino board. */

 

void setup()

{

  // Set the clock to run-mode, and disable the write protection

  rtc.halt(false);

  rtc.writeProtect(false);

 

  // Setup Serial connection

  Serial.begin(9600);

 

  // The following lines can be commented out to use the values already stored in DS1302

  rtc.setDOW(FRIDAY);        // Set Day-of-Week to FRIDAY

  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)

  rtc.setDate(6, 8, 2010);   // Set the date to August 6th, 2010

}

 

/* The loop() function executes the program repeatedly until Specified. */

 

void loop()

{

  // Send Day-of-Week

  Serial.print(rtc.getDOWStr());

  Serial.print(" ");

 

  // Send date

  Serial.print(rtc.getDateStr());

  Serial.print(" -- ");

 

  // Send time

  Serial.println(rtc.getTimeStr());

 

  // Wait one second before repeating :)

  delay (1000);

}


