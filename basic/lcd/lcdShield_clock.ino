// https://cheaphousetek.blogspot.com/2012/06/freeduinoarduino-real-time-clock-sensor.html


// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// 2010-02-04 <jcw@equi4.com> http://opensource.org/licenses/mit-license.php
// $Id: ds1307.pde 4773 2010-02-04 14:09:18Z jcw $

// Added LCD display and LM35 temperature function by Befun Hung 2011-10-13
// File Name: LCDDS1307RTClibLM35A3.pde
// The sketch works on Arduino IDE 0022

#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

RTC_DS1307 RTC;
int potPin = 3;
float temperature = 0;

void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    lcd.begin(16, 2);
    // lcd.print("*cheaphousetek*");
    
    // following line sets the RTC to the date & time this sketch was compiled
    // RTC.adjust(DateTime(__DATE__, __TIME__));
}

void printTenths(long value) {
  // prints a value of 123 as 12.3
  Serial.print(value / 10);
  Serial.print('.');
  Serial.print(value % 10);
  Serial.println();
  lcd.setCursor(10, 1);
  lcd.print(value / 10);
  lcd.setCursor(12, 1);
  lcd.print('.');
  lcd.setCursor(13, 1);
  lcd.print(value % 10);
}

void loop () {
    DateTime now = RTC.now();
    int span = 10;
    long aRead = 0;
    unsigned long tmp;
      
    tmp = now.year();
    Serial.print(now.year(), DEC);
    lcd.setCursor(0, 0);
    lcd.print(tmp);
    Serial.print('/');
    lcd.setCursor(4, 0);
    lcd.print("-");
    
    tmp = now.month();
    if (now.month() < 10) {
      Serial.print('0');
      Serial.print(now.month(), DEC);
      lcd.setCursor(5, 0);
      lcd.print('0');
      lcd.setCursor(6, 0);
      lcd.print(tmp);
    }
    else {
      Serial.print(now.month(), DEC);
      lcd.setCursor(5, 0);
      lcd.print(tmp);
    }
    Serial.print('/');
    lcd.setCursor(7, 0);
    lcd.print('-');
    
    tmp = now.day();
    if (now.day() < 10) {
      Serial.print('0');
      Serial.print(now.day());
      lcd.setCursor(8, 0);
      lcd.print('0');
      lcd.setCursor(9, 0);
      lcd.print(tmp);
    }
    else {
      Serial.print(now.day(), DEC);
      lcd.setCursor(8, 0);
      lcd.print(tmp);
    }
    Serial.print(' ');
    
    tmp = now.hour();
    if (now.hour() < 10) {
      Serial.print('0');
      Serial.print(now.hour(), DEC);
      lcd.setCursor(0, 1);
      lcd.print('0');
      lcd.setCursor(1, 1);
      lcd.print(tmp);
    }
    else {
      Serial.print(now.hour(), DEC);
      lcd.setCursor(0, 1);
      lcd.print(tmp);
    }
    Serial.print(':');
    lcd.setCursor(2, 1);
    lcd.print(':');
    
    tmp = now.minute();
    if (now.minute() < 10) {
      Serial.print('0');
      Serial.print(now.minute(), DEC);
      lcd.setCursor(3, 1);
      lcd.print('0');
      lcd.setCursor(4, 1);
      lcd.print(tmp);
    }
    else {
      Serial.print(now.minute(), DEC);
      lcd.setCursor(3, 1);
      lcd.print(tmp);
    }
    Serial.print(':');
    lcd.setCursor(5, 1);
    lcd.print(':');
    
    tmp = now.second();
    if (now.second() < 10) {
      Serial.print('0');
      Serial.print(now.second(), DEC);
      lcd.setCursor(6, 1);
      lcd.print('0');
      lcd.setCursor(7, 1);
      lcd.print(tmp);
    }
    else {
      Serial.print(now.second(), DEC);
      lcd.setCursor(6, 1);
      lcd.print(tmp);
    }
    Serial.print (' ');
    lcd.setCursor(8, 1);
    lcd.print(' ');
    // Serial.println();
    
    for (int i=0;i<span;i++) {
      aRead = aRead + analogRead(potPin);
      // Serial.print(aRead);
      // Serial.print(' ');
    }
    // aRead = aRead / span;
    temperature = (aRead / span * 500.0 / 1024.0);
    // Serial.print(aRead);
    // Serial.print(' ');
    // Serial.print(temperature);
    // Serial.print(' ');
    printTenths(long (temperature * 10));
    lcd.setCursor(14, 1);
    lcd.print(char(223));
    lcd.setCursor(15, 1);
    lcd.print('C');
        
    delay(968);
    
    // Serial.print(" since 2000 = ");
    // Serial.print(now.get());
    // Serial.print("s = ");
    // Serial.print(now.get() / 86400L);
    // Serial.println("d");
    
    // calculate a date which is 7 days and 30 seconds into the future
    // DateTime future (now.get() + 7 * 86400L + 30);
    
    // Serial.print(" now + 7d + 30s: ");
    // Serial.print(future.year(), DEC);
    // Serial.print('/');
    // Serial.print(future.month(), DEC);
    // Serial.print('/');
    // Serial.print(future.day(), DEC);
    // Serial.print(' ');
    // Serial.print(future.hour(), DEC);
    // Serial.print(':');
    // Serial.print(future.minute(), DEC);
    // Serial.print(':');
    // Serial.print(future.second(), DEC);
    // Serial.println();
    
    // Serial.println();
    // delay(3000);
}

