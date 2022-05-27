// control_pan_tilt_pot.ino
// https://create.arduino.cc/projecthub/gulshanmishra02/control-pan-tilt-mount-with-potentiometers-4dfa18

#include <Servo.h>  // add servo library

Servo myservo;
Servo myservo1;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;
int val;    // variable to read the value from the analog pin
int val1;

void setup() {
  myservo.attach(6);
  myservo1.attach(7);    // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            
  val = map(val, 0, 1023, 0, 180);     
  myservo.write(val);                  
  delay(15);     

  val1 = analogRead(potpin1);            
  val1 = map(val1, 0, 1023, 0, 180);     
  myservo1.write(val1);                  
  delay(15);     
}
