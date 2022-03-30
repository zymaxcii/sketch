// pan_tilt_sweep.ino
// Modified from servo_sweep.ino
//
/*
servo_sweep.ino
Adafruit Arduino - Lesson 14. Sweep
*/

#include <Servo.h>

int pan = 10;
int tilt = 9;

Servo panServo, tiltServo;

int angle = 0;  // servo position in degrees


void setup()
{
  panServo.attach(pan);
  tiltServo.attach(tilt);
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
    panServo.write(angle);
    tiltServo.write(angle);
    delay(100); // origin 15
  }

  // now scan back from 180 to 0 degrees
  for (angle = 180; angle > 0; angle--)
  {
    panServo.write(angle);
    tiltServo.write(angle);
    delay(100);
  }
}
