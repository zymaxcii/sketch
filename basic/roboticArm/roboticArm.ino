// roboticArm.ino
// 4DOF

// https://circuitdigest.com/microcontroller-projects/diy-arduino-robotic-arm-tutorial


#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

int sensorvalue0;
int sensorvalue1;
int sensorvalue2;
int sensorvalue3;

void setup()
{
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);

  servo0.attach(3);
  pinMode(A1,INPUT);
  pinMode(5,OUTPUT);

  servo1.attach(5);
  pinMode(A2,INPUT);
  pinMode(6,OUTPUT);

  servo2.attach(6);
  pinMode(A3,INPUT);
  pinMode(9,OUTPUT);

  servo3.attach(9);
}


void loop()
{
  sensorvalue0 = analogRead(A0);
  sensorvalue0 = map(sensorvalue0, 0, 1023, 0, 180);
  servo0.write(sensorvalue0);

  sensorvalue1 = analogRead(A1);
  sensorvalue1 = map(sensorvalue1, 0, 1023, 0, 180);
  servo1.write(sensorvalue1);

  sensorvalue2 = analogRead(A2);
  sensorvalue2 = map(sensorvalue2, 0, 1023, 0, 180);
  servo2.write(sensorvalue2);

  sensorvalue3 = analogRead(A3);
  sensorvalue3 = map(sensorvalue3, 0, 1023, 0, 180);
  servo3.write(sensorvalue3);
}


