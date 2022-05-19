// 7seg4dI2C_clock.ino
// https://thecustomizewindows.com/2017/02/making-digital-clock-arduino-7-segment-4-digit-tm1637/

#include <Wire.h>
#include "TM1637.h" 
#define CLK 6         
#define DIO 7 
#define brightness 6 
#define keyHor 5
#define keyMin 4 
#define keyPL  3

TM1637 tm1637(CLK,DIO);  
#define DS3231_I2C_ADDRESS 0x68
  
volatile boolean flag;

byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val){
  return ( (val/16*10) + (val%16) );
}

void setDateDs3231(byte second,  
                   byte minute,        // 0-59
                   byte hour,          // 1-23
                   byte dayOfWeek,     // 1-7
                   byte dayOfMonth,    // 1-28/29/30/31
                   byte month,         // 1-12
                   byte year)          // 0-99
{
   Wire.beginTransmission(DS3231_I2C_ADDRESS);
   Wire.write(0);
   Wire.write(decToBcd(second));    
   Wire.write(decToBcd(minute));
   Wire.write(decToBcd(hour));     
   Wire.write(decToBcd(dayOfWeek));
   Wire.write(decToBcd(dayOfMonth));
   Wire.write(decToBcd(month));
   Wire.write(decToBcd(year));
   Wire.endTransmission();
}

void getDateDs3231(byte *second,
          byte *minute,
          byte *hour,
          byte *dayOfWeek,
          byte *dayOfMonth,
          byte *month,
          byte *year)
{

  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();

  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);

  *second     = bcdToDec(Wire.read() & 0x7f);
  *minute     = bcdToDec(Wire.read());
  *hour       = bcdToDec(Wire.read() & 0x3f); 
  *dayOfWeek  = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month      = bcdToDec(Wire.read());
  *year       = bcdToDec(Wire.read());
}

void setINT(){  
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x0E);
  Wire.write(0x0);
  Wire.endTransmission();
}

void blink() {
  digitalWrite(13, !digitalRead(13));
  flag = !flag;
  tm1637.point(flag); 
}

void setup() {
//  Serial.begin(9600);
  Wire.begin();
  pinMode(13, OUTPUT);
  pinMode(keyHor, INPUT_PULLUP);
  pinMode(keyMin, INPUT_PULLUP);
  pinMode(keyPL, INPUT_PULLUP);

  tm1637.init();
  tm1637.set(brightness);  
  
  setINT(); 
  attachInterrupt(0, blink, CHANGE);
}

void loop(){
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year; 
  getDateDs3231(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year); 
  int8_t TimeDisp[4]; 
  
  TimeDisp[0] = hour / 10;
  TimeDisp[1] = hour % 10;
  TimeDisp[2] = minute / 10;
  TimeDisp[3] = minute % 10;

  if (!digitalRead(keyHor) && !digitalRead(keyPL)){   
      second = 0;     
      hour++;  
      if (hour > 23) hour = 0;  
      setDateDs3231(second, minute, hour, dayOfWeek, dayOfMonth, month, year); 
      delay(200);
  }
  if (!digitalRead(keyMin) && !digitalRead(keyPL)){   // минуты
      second = 0;
      minute++;
      if (minute > 59) minute = 0;
      setDateDs3231(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
      delay(200);
  }

  tm1637.display(TimeDisp);
 
  
} 
