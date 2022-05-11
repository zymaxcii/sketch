// soil_tester.ino

// soil_moisture_sensor.ino
// code is almost identical to rainsensor.ino
/*
 All the resources for this project:
 http://randomnerdtutorials.com/
*/

// my standard pin for analog sensor
int rainPin  = A0;
int greenLED = 6;
int redLED   = 4;

// you can adjust the threshold value
int thresholdValue = 800;


void setup()
{
  pinMode(rainPin,  INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,   OUTPUT);
  
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED,   LOW);
  Serial.begin(9600);
  Serial.println("Soil moisture sensor tester:");
}


void loop()
{
  // read input on analog pin A0
  int sensorValue = analogRead(rainPin);
  Serial.print(sensorValue);
  
  if (sensorValue < thresholdValue)
  {
    Serial.println(" - Doesn't need watering");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  else
  {
    Serial.println(" - Time to water your plant");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  delay(2000);
}
