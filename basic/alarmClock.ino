// alarmClock.ino
// https://mytectutor.com/tm1637-4-digit-7-segment-display-with-arduino-digital-clock-example/


#include <Wire.h>
#include "RTClib.h"
#include <TM1637Display.h>

RTC_DS3231 rtc;

#define CLK 8
#define DIO 9

TM1637Display display(CLK, DIO);

const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};

int setButton = 2; // pushbutton for setting alarm
int hourButton = 3; // pushbutton for hour
int minButton = 4; // pushbutton for minutes
int exitButton = 5; // pushbutton for exit of set alarm
int buzzer = 13;

int t, a, Hour, Min, h, m;
int set_time, alarm_time, auto_alarmStop, set_alarm_min, set_alarm_hour;

int setButtonState = 0; // pushbutton state for setting alarm
int hourButtonState = 0; // pushbutton state for hour
int minButtonState = 0;// pushbutton state for minutes
int exitButtonState = 0; // pushbutton state for exit of set alarm

int activate;

void setup() {
  
  Serial.begin(9600);  // Begin serial communication at a baud rate of 9600: 
  delay(3000);  // Wait for console opening:
  if (! rtc.begin()) {  // Check if RTC is connected correctly:
    Serial.println("Couldn't find RTC");
while (1);
  }

  if (rtc.lostPower()) { // Check if the RTC lost power and if so, set the time:
    Serial.println("RTC lost power, lets set the time!");
    // The following line sets the RTC to the date & time this sketch was compiled:
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // July 02, 2020 at 3:47am you would call:
    //rtc.adjust(DateTime(2020, 7, 02, 03, 47, 0));
  }
  
  Wire.begin();
  display.setBrightness(0xA);            
  pinMode(setButton,
INPUT_PULLUP);      
  pinMode(hourButton, INPUT_PULLUP);     
  pinMode(minButton, INPUT_PULLUP);      
  pinMode(exitButton, INPUT_PULLUP);     
  pinMode(buzzer, OUTPUT);
  activate = 0;
}

void loop() {
    
    DateTime now = rtc.now();
    Hour = now.hour();
    Min = now.minute();
    t =(now.hour()* 100 )+ now.minute();
    a=now.second()%2;
    if(a==0){display.setColon(false);}
    else{display.setColon(true);}

    switch(activate){
    case 0:
    display.showNumberDec(t, true);
    setButtonState = digitalRead(setButton);
    if(setButtonState == LOW){ delay(50); activate = 1;}
    if(t == alarm_time &&
now.second()==0){activate = 2;}
    break;
    case 1:
       display.setSegments(blank);//clear display
       display.showNumberDec(0, true);
       display.setColon(true);
       while(activate == 1){
       hourButtonState = digitalRead(hourButton);
       if(hourButtonState == LOW){
           h++;
           edit();
           set_alarm_hour = h;
           delay(200);
       }
       
       minButtonState = digitalRead(minButton);
       if(minButtonState == LOW){
          m++;
          edit();
          set_alarm_min = m;
 delay(200);
       }
       
       
       exitButtonState = digitalRead(exitButton);
       if(exitButtonState == LOW){delay(50); activate = 0;}
     }
     alarm_time = (set_alarm_hour*100)+set_alarm_min;
    break;
    case 2:
      alarm();
      display.showNumberDec(t, true);
      auto_alarmStop = alarm_time+1;
      exitButtonState = digitalRead(exitButton);
      if(exitButtonState == LOW){delay(50); activate = 0;}
      if(t == auto_alarmStop){activate = 0;}
      display.showNumberDec(t, true);
 break;
      
    }
    delay(5);
} 
 

void edit(){
  if(m==60){m=0; h++;}
  if(m<0){m=59; h--;}
  if(h==24){h=0;}
  if(h<0){h=23; m=59;}
  set_time = (h*100)+ m;
  display.showNumberDec(set_time, true);
  display.setColon(true);
}

void alarm(){
    tone(13, 500, 200);
    delay(100);
    tone(13, 1000, 200);
    delay(100);
    tone(13, 2000, 200);
    delay(100);
    tone(13, 3000, 200);
    delay(100);
    tone(13, 4000, 200);
    delay(100);
    tone(13, 3000, 200);
    delay(100);
    tone(13, 2000, 200);
    delay(100);
    tone(13, 1000, 200);
    delay(100); 
}
