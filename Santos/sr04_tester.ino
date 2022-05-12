// sr04_tester.ino
// ultrasonic hc sr04 sensor

/*
 * created by Rui Santos, http://randomnerdtutorials.com
 * Complete Guide for Ultrasonic Sensor HC-SR04
   Ultrasonic sensor Pins:
     VCC: +5VDC
     Trig : Trigger (INPUT) - Pin11
     Echo: Echo (OUTPUT) - Pin 12
     GND: GND
*/

 
int trigPin = 11;          // Trig - green Jumper
int echoPin = 12;          // Echo - yellow Jumper
long duration, cm, inches;


void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop()
{
  // sensor is triggered by a HIGH pulse of 10 or more microseconds
  // give a short LOW pulse beforehand to ensure a clean HIGH pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // read signal from sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert time into distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  // original 250
  delay(5000);
}
