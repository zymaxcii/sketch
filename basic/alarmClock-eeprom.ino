// alarmClock-eeprom.ino
// https://mytectutor.com/tm1637-4-digit-7-segment-display-with-arduino-digital-clock-example/


#include <Wire.h>
#include "RTClib.h"
#include <TM1637Display.h>
#include <EEPROM.h>

RTC_DS3231 rtc;

#define CLK 8
#define DIO 9
#define pinjam 2
#define pinalarm 3
#define pinenter 4
#define pinmati 5
#define buzzer 13

TM1637Display display(CLK, DIO);



int state, a, t, tj, ta, te, tm ;
int setjam, setalarm, enter, mati;
int edit1, alarm_time, jam, menit, selesai;
//int alarm_time1, alarm_time2, selesai;

void setup() {
  Wire.begin();
  display.setBrightness(0xA);
  pinMode(pinjam, INPUT_PULLUP);
  pinMode(pinalarm, INPUT_PULLUP);
  pinMode(pinenter, INPUT_PULLUP);
  pinMode(pinmati, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  state=0;
  edit1=0;
}

void loop() {    
  DateTime now = rtc.now();
  button();
  EEPROM.get(0, alarm_time);
  t =(now.hour()* 100 )+ now.minute();
  a=now.second()%2;
  if(a==0){display.setColon(false);}
  else{display.setColon(true);}
  
  switch (state) {
    case 0: //main display
 if (tj==1 && te==1){tone(13, 2000, 100);delay(200);tone(13, 2000, 100);delay(200);state=1;}
      if (ta==1 && te==1){tone(13, 2000, 100);delay(200);tone(13, 2000, 100);delay(200);tone(13, 2000, 100);delay(200);state=2;}
      display.showNumberDec(t, true);
      if(t==alarm_time && now.second()==0){state=3;}
      break;
    case 1: //edit jam
      if (tj==1){menit++;}
      if (ta==1){menit--;}
      edit();
      display.showNumberDec(edit1, true);
      if(te==1){tone(13, 2000, 500);delay(100);rtc.adjust(DateTime(2018, 7, 19, jam, menit, 0));menit=0;jam=0;state=0;}
 if(tm==1){menit=0;jam=0;state=0;}
      break;
    case 2: //edit alarm
      if (tj==1){menit++;}
      if (ta==1){menit--;}
      edit();
      alarm_time=edit1;
      if(te==1){tone(13, 2000, 500);delay(100);EEPROM.put(0,alarm_time);menit=0;jam=0;state=0;}
      if(tm==1){menit=0;jam=0;state=0;}
      break;
    case 3: //buzzing
      tone(13, 500, 200);
      delay(100);
      tone(13, 1000, 200);
      delay(100);
      tone(13, 2000, 200);
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
  
      display.showNumberDec(t, true);
      selesai=alarm_time+1;
      if(tm==1){state=0;}
      //if(tm==1){tone(13, 2000, 1000);delay(200);state=0;}
      if(t==selesai){state=0;}
      display.showNumberDec(t, true);
      break;
  }

  delay(1); // delay in between reads for stability
}

void button(){
  int waktu=50;
  setjam = digitalRead(pinjam);
  setalarm = digitalRead(pinalarm);
  enter = digitalRead(pinenter);
  mati = digitalRead(pinmati);
  if (setjam == LOW) { delay(waktu);tj=1;} else {tj=0;}
  if (setalarm == LOW) {
delay(waktu);ta=1;} else {ta=0;}
  if (enter == LOW) { delay(waktu);te=1;} else {te=0;}
  if (mati == LOW) { delay(waktu);tm=1;} else {tm=0;}
  }
  
void edit(){
  if(menit==60){menit=0;jam++;}
  if(menit<0){menit=59;jam--;}
  if(jam==24){jam=0;}
  if(jam<0){jam=23;menit=59;}
  edit1=(jam*100)+menit;
  display.showNumberDec(edit1, true);
  display.setColon(true);
}
