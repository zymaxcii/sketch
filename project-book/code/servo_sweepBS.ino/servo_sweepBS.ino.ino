// servo_sweepBS.ino
// Sweeping the servo left to right and reverse

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

// Boards to run the sketch:
// just a servo and a potentiometer

// servo sg90 or mg90:
// 
// pin # Name to Uno Pin
// =====================
// 1  Brown   GND
// 2  Red     +5V
// 3  Yellow  D9
// 
// potentiometer:
// 
// pin # Name to Uno Pin
// =====================
// 1  VCC     +5V
// 2  Output  A0
// 3  GND     GND
// 

#include <Servo.h>

Servo myservo;

int pos = 0;    // servo position

void setup()
{
  myservo.attach(9);  // attach servo to pin 9
  Serial.begin(9600);
}


void loop()
{
  for (pos = 0; pos <= 180; pos += 1)
  {
    // goes from 0 to 180 degrees in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(15);                       // waits 15ms for servo to reach position
  }

  delay(1000);
  
  for (pos = 180; pos >= 0; pos -= 1)
  {
    // goes from 180 to 0 degrees
    myservo.write(pos);
    Serial.println(pos);
    delay(15);
  }

  delay(1000);
}
