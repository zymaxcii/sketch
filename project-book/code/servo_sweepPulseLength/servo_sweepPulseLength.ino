// servo_sweepPulseLength.ino
// Sweep servo from 0 to 180 degree and then reverse
// can set the 0 and 180 degree pulse lengths in microseconds
// sg90 range: 500 to 2400

// test_servo2.ino

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

Servo myservo;


void setup()
{
  // attaches servo object to servo on pin 9 and
  // sets the 0 and 180 pulse lengths in microseconds 
  // myservo.attach(9, 500, 3000);
  myservo.attach(9, 500, 2400);

  // myservo.attach(9, 900, 2100);
  // myservo.attach(9, 100, 4000);
  // myservo.attach(9);

}


void loop()
{
  for (int pos = 0; pos <= 180; pos += 1)
  { 
    // goes from 0 to 180 degrees in steps of 1 degree
    myservo.write(pos);
    delay(15);
  }

  for (int pos = 180; pos >= 0; pos -= 1)
  { 
    // goes from 180 0 degrees
    myservo.write(pos);
    delay(15);
  }
}
