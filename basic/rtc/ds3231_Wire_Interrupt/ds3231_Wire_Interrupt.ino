// ds3231_Wire_Interrupt.ino
// Why setInterrupt in loop() instead of setup()?
// https://forum.arduino.cc/t/which-library-is-best-for-ds3231-rtc/980510/6

// DS3231_RTC.ino - for DS3231 real time clock - set time and alarm every minute
// interrupt on alarm - connect INT/SQW to pin 2

// Arduino Nano connections
// GND - GND
// VCC - 5V
// SDA - A4
// SCL - A5

// My standard hardware setup
// ds3231 rtc module:
// A4 RTC module, pin SDA
// A5 RTC module, pin SCL
// INT/SQW D2
// VCC
// GND


#include "Wire.h"

#define DS3231_I2C_ADDRESS 0x68

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}


// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}


void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  // setDS3231time(30,13,19, 7, 20,1,17);
}


// set time
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte
                    dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);                   // set next input to start at seconds register
  Wire.write(decToBcd(second));    // set seconds
  Wire.write(decToBcd(minute));    // set minutes
  Wire.write(decToBcd(hour));      // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month));     // set month
  Wire.write(decToBcd(year));      // set year (0 to 99)
  Wire.endTransmission();
}


// set alarm time
void setDS3231alarm(byte second, byte minute, byte hour, byte dayOfMonth)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(7);                    // set next input to start at seconds register
  Wire.write(decToBcd(second));     // set seconds
  Wire.write(decToBcd(minute));     // set minutes
  Wire.write(decToBcd(hour));       // set hours
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.endTransmission();
}


// read time or alarm
void readDS3231time(int alarm, byte *second, byte *minute, byte *hour, byte                           *dayOfWeek, byte *dayOfMonth, byte *month, byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  if (!alarm) Wire.write(0);         // set DS3231 register pointer to 00h
  else  Wire.write(0x07);
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}


// display current time
void displayTime()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(0, &second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,  &year);
  // send it to the serial monitor
  Serial.print("Time  ");
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  
  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  Serial.print(" Day of week: ");
  
  switch(dayOfWeek)
  {
  case 1:
    Serial.println("Sunday");
    break;
  case 2:
    Serial.println("Monday");
    break;
  case 3:
    Serial.println("Tuesday");
    break;
  case 4:
    Serial.println("Wednesday");
    break;
  case 5:
    Serial.println("Thursday");
    break;
  case 6:
    Serial.println("Friday");
    break;
  case 7:
    Serial.println("Saturday");
    break;
  }
}


// display alarm time
void displayAlarmTime()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(1, &second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,  &year);
  // send it to the serial monitor
  Serial.print("Alarm ");
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  Serial.println();
   }

// write/read status register
void writeDS3231controlStatus(int value)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x0F); 
  Wire.write(value); 
  Wire.endTransmission();
}


int readDS3231controlStatus(void)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x0F); 
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 1);
  return Wire.read();
}


// write read control register
void writeDS3231controlRegister(int value)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x0E); 
  Wire.write(value); 
  Wire.endTransmission();
}

int readDS3231controlRegister(void)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x0E); 
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 1);
  return Wire.read();
}


// alarm interuupt routine
volatile int interrupt=0;
void alarmTimer()          
{                   
   interrupt=1;  // set interrupt indicator
}


void loop()
{
  static int setAlarm = 1;              // set alarm on first call to loop()
  
  if (setAlarm)
  {
    Serial.println("\n\nresetting alarm for 1 minute");
    setAlarm=0;
    writeDS3231controlRegister(4 | 1);  // enable INTCN and A1E
    writeDS3231controlStatus(0);
    byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
    
    readDS3231time(0, &second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,  &year);
    minute+=1;       // alarm in one minute - A1F should go high
    if(minute>60)    // if minute overflow reset
    {
      hour+=1; minute-=60; }  // need to allow for 24 hour overflow etc etc!!
    setDS3231alarm(second, minute, hour,  dayOfMonth);
    
    // set up for alarm 1 to interrupt on pin 2
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2),alarmTimer,FALLING); 
  }    
  
  displayAlarmTime(); // display the alarm data on the Serial Monitor,
  displayTime();      // display the real-time clock data on the Serial Monitor,
  
  Serial.print("DS3231 control  register ");
  Serial.println(readDS3231controlRegister(), HEX);
  Serial.print("DS3231 control status register ");
  Serial.println(readDS3231controlStatus(), HEX);
  
  if(readDS3231controlStatus()&1) 
     { Serial.println("\nAlarm gone off!!"); setAlarm=1; }
  if(interrupt) 
     { Serial.println("alarm timer interrupt!!!!"); interrupt=0; }
  delay(5000); // every second
}
