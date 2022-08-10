// servo_30to90deg.ino
// Move servo from 30 to 90 degree
// It will reset to 30 degree first

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-servo-motor
 */


// Boards to run the sketch:
// just a servo

// servo sg90 or mg90:
// 
// pin # Name to Uno Pin
// =====================
// 1  Brown   GND
// 2  Red     +5V
// 3  Yellow  D9
// 


#include <Servo.h>

Servo myServo;

unsigned long MOVING_TIME = 3000;     // moving time is 3 seconds
unsigned long moveStartTime;

int startAngle = 30;                  // 30°
int stopAngle  = 90;                  // 90°


void setup()
{
  myServo.attach(9);
  moveStartTime = millis();           // start moving

  // TODO: other code
}


void loop()
{
  unsigned long progress = millis() - moveStartTime;

  if (progress <= MOVING_TIME)
  {
    long angle = map(progress, 0, MOVING_TIME, startAngle, stopAngle);
    myServo.write(angle); 
  }

  // TODO: other code
}
