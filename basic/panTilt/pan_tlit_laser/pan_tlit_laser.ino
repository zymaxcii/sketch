// pan_tilt_laser.ino
// A laser diode mounted on a pan and tilt assembly
//
// https://www.lifehacker.com.au/2016/08/how-to-make-a-joystick-controlled-laser-with-an-arduino/
// Used with kind permission from http://learn.explorelabs.com/
// Creative Commons 4.0 Share Alike (CC by SA 4.0) licence

// Boards to run the sketch:
// just 2 servo motors and a ky-008 laser diode module

// pan servo:
//
// pin # Name to Uno Pin
// =====================
// 1  Black  GND
// 2  RED    +5V
// 3  ORANGE D10
//
// tilt servo:
//
// pin # Name to Uno Pin
// =====================
// 1  Black  GND
// 2  RED    +5V
// 3  ORANGE D9
//

// joystick module:
//
// pin # Name to Uno Pin
// =====================
// 1  GND  GND
// 2  +5V  +5V
// 3  VRX  A0
// 4  VRY  A1
// 5  SW   D7  
//
// ky-008 laser diode:
//
// pin # Name to Uno Pin
// =====================
// 1  -VE  GND
// 2  NC   NC
// 3  S    D8
//


#include <Servo.h>

Servo tilt, pan; // Create servo object

int joyX = A0; // Analogue pin connected to x-axis servo
int joyY = A1; // Analogue pin connected to y-axis servo
int x, y;      // Variables to read values

const int trigger = 7;  // trigger switch
int triggerVal;
const int laser = 8;    // laser control

void setup()
{
  tilt.attach(9); // Attach tilt servo on pin 9 to the servo object
  pan.attach(10); // Attach pan servo on pin 10 to the servo object

  pinMode(trigger, INPUT_PULLUP);
  pinMode(laser, OUTPUT);

  // test laser
  digitalWrite(laser, HIGH);
  delay(2000);
  digitalWrite(laser, LOW);

  Serial.begin(9600);
}


void loop()
{
  x = joyX; // Read value of x-axis (between 0 and 1023)
  y = joyY; // Read value of y-axis (between 0 and 1023)

  x = map(analogRead(joyX), 0, 1023, 900, 2100); // Scale it to use

  // with servo between 900 to 2100 microseconds
  y = map(analogRead(joyY), 0, 1023, 900, 2100);

  tilt.write(x); // Set servo position according to scaled value
  pan.write(y);

//  digitalWrite(laser, HIGH);  // laser on all the time


  triggerVal = digitalRead(trigger);
  Serial.println(triggerVal);
  if ( triggerVal == LOW)
  {
    digitalWrite(laser, HIGH);
  }
  else
  {
    digitalWrite(laser, LOW);
  }

  delay(15); // Wait for servos to get to new position
}
