// lightSensor.ino

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  unsigned int AnalogValue;
  AnalogValue = analogRead(A0);
  Serial.println(AnalogValue);
}

