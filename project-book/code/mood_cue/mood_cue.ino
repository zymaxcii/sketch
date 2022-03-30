// mood_cue.ino
// chapter 5
// mood cue

// connect potentiometer to A0: the other 2 terminals to gnd and +5v
// connect servo to pin 9: the other 2 wires to gnd and +5v
// adjust the potentiometer to set angle for servo to turn to

#include <Servo.h>

Servo myServo;

int const potPin = A0;

int potVal;
int angle;


void setup()
{
  myServo.attach(9);
  Serial.begin(9600);
}


void loop()
{
  potVal = analogRead(potPin);

  Serial.print("potVal: ");
  Serial.print(potVal);

  // map to 180 degree
  angle = map(potVal, 0, 1023, 0, 179);
  // angle = map(potVal, 9, 982, 0, 179);


  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(100);
}
