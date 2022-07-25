// pingPongLarson.ino
// https://www.instructables.com/Ping-Pong-Larson-Scanner/


#include <Servo.h>
Servo myservoR;
Servo myservoL;


int val;
int pinArray[] = {12, 11, 10, 9, 8, 7, 6, 5};
int count = 0;
int timer = 25;

void setup(){

myservoR.attach(3);
myservoL.attach(13);

for (count=0;count<8;count++) {
pinMode(pinArray[count], OUTPUT);
}
}

void loop() {
for (count=0;count<8;count++) {
digitalWrite(pinArray[count], HIGH);

delay(timer);
digitalWrite(pinArray[count + 1], HIGH);
val= (count*22.5);
myservoR.write(val);
myservoL.write(val);

delay(timer);
digitalWrite(pinArray[count], LOW);
delay(timer*2);
}
for (count=7;count>0;count--) {
digitalWrite(pinArray[count], HIGH);
  digitalWrite(pinArray[count], HIGH);

delay(timer);
digitalWrite(pinArray[count - 1], HIGH);
  val=(count*22.5);
  myservoR.write(val);
  myservoL.write(val);
delay(timer);
digitalWrite(pinArray[count], LOW);
delay(timer*2);
}
}
