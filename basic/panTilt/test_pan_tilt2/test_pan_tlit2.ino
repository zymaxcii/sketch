// test_pan_tilt.ino

// www.learnrobotics.org

#include <Servo.h>

Servo panServo;  // create servo object to control a servo
Servo tiltServo;


void setup()
{
  // attaches the servo object to the servo on pin 9 and
  // sets the 0 and 180 pulse lengths in microseconds 
  panServo.attach(9, 500, 3000);
  tiltServo.attach(10, 500, 3000);
}


void loop()
{
  for (int pos = 0; pos <= 180; pos += 1)
  { 
    // goes from 0 to 180 degrees
    // in steps of 1 degree
    panServo.write(pos);        // go to position in variable 'pos'
    delay(15);
    tiltServo.write(pos);
    delay(15);                  // waits 15ms for the servo to reach the position
  }

  for (int pos = 180; pos >= 0; pos -= 1)
  { 
    // goes from 180 degrees to 0 degrees
    panServo.write(pos);        // go to position in variable 'pos'
    tiltServo.write(pos);
    delay(15);                 // waits 15ms for the servo to reach the position
  }
}
