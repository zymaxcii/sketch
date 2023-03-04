#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;
bool Century=false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

byte year, month, date, DoW, hour, minute, second;




void setup() {
  Wire.begin();
        Clock.setSecond(00);//Set the second 
        Clock.setMinute(2);//Set the minute 
        Clock.setHour(12);  //Set the hour 
        Clock.setDoW(3);    //Set the day of the week
        Clock.setDate(28);  //Set the date of the month
        Clock.setMonth(3);  //Set the month of the year
        Clock.setYear(17);  //Set the year (Last two digits of the year)
    Serial.begin(9600);


Clock.getTime(year, month, date, DoW, hour, minute, second);
  





Serial.print("day of the week :");
Serial.println(DoW, DEC);
Serial.print(hour, DEC);
Serial.print(":");
Serial.print(minute, DEC);
Serial.print(":");
Serial.println(second, DEC);
Serial.println("---------");
Serial.print(date, DEC);
Serial.print("/");
Serial.print(month, DEC);
Serial.print("/");
Serial.println(year, DEC);
Serial.print("day of the week :");
Serial.println(DoW, DEC);
}

void loop() {
  // put your main code here, to run repeatedly:

}
