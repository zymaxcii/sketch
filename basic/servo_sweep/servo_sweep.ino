// servo_sweep.ino
//
/*
servo_sweep.ino
Adafruit Arduino - Lesson 14. Sweep
*/

#include <Servo.h>

int servoPin = 8;

Servo servo;

int angle = 0;  // servo position in degrees


void setup()
{
  servo.attach(servoPin);
}


void loop()
{

//  servo.write(0);
//  delay(1000);
//  servo.write(179); // get stuck
  
  // scan from 0 to 180 degrees
  // for (angle = 0; angle < 180; angle++)
  for (angle = 0; angle < 180; angle++)

  {
    servo.write(angle);
    delay(100); // origin 15
  }

  // now scan back from 180 to 0 degrees
  for (angle = 180; angle > 0; angle--)
  {
    servo.write(angle);
    delay(100);
  }
}
