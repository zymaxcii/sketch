// touchy_feely_lamp.ino
// chapter 13
// arduino project book

#include <CapacitiveSensor.h>

// original pins 4,2
CapacitiveSensor capSensor = CapacitiveSensor(4,3);

int threshold = 1000;
const int ledPin = 8;


void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() 
{
  // no. of samples = 30
  long sensorValue = capSensor.capacitiveSensor(30);

  Serial.println(sensorValue);
  if (sensorValue > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
  digitalWrite(ledPin, LOW);
  }
  delay(400);
}
