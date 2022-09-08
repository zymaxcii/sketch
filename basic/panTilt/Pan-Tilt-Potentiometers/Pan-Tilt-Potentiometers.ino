// panTiltPot.ino

/*
Pan-tilt Software
by Liz Miller
for Learn Robotics www.learnrobotics.org

Control Pan & Tilt using two angular potentiometers

**** Wiring ****
Pan
  Vcc - 100µF Cap > 7.2V
  GND - 100µF Cap > GND
  Sig - Digital 3

Tilt
  Vcc - 100µF Cap > 7.2V
  GND - 100µF Cap > GND
  Sig - Digital 9

Pan Potentiometer
  Vcc - Arduino 5V
  GND - GND
  Sig - Analog 2

Tilt Potentiometer
  Vcc - Arduino 5V
  GND - GND
  Sig - Analog 2
*/

#include <Servo.h>

Servo tilt;  // create servo object to control a servo
Servo pan;

int tiltKnob = 0;  // analog pin used to connect the potentiometer
int panKnob = 2;  // analog pin used to connect the potentiometer
int tiltVal;    // variable to read the value from the analog pin
int panVal;

bool viewPrints = true;

void setup() {
  pinMode(panKnob, INPUT);
  pinMode(tiltKnob, INPUT);
  tilt.attach(9);  // attaches the servo on pin 9 to the servo object
  pan.attach(3);
  tilt.write(90);
  pan.write(90); 
  Serial.begin(9600);
}

void panTiltControl(){
  tiltVal = analogRead(tiltKnob);
  panVal = analogRead(panKnob);

  if(viewPrints){
    Serial.print("TILT: init val = ");
    Serial.print(tiltVal);
    
    Serial.print(" PAN: init val = ");
    Serial.print(panVal);
  }
  
  tiltVal = map(tiltVal, 0, 1023, 0, 180);
  panVal = map(panVal, 0, 1023, 0, 180);

  if(viewPrints){
    Serial.print(" TILT: mapped val = ");
    Serial.print(tiltVal);
  
    Serial.print(" PAN: mapped val = ");
    Serial.println(panVal);
  }

  delayMicroseconds(50);
  
  tilt.write(tiltVal);
  pan.write(panVal);                 
  delay(15);
}

void loop() {
  panTiltControl();                           
}
