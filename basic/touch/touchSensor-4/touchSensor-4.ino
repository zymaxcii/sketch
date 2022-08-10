// touchSensor-4.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor

const int SENSOR_PIN = 7;

int lastState = LOW;
int currentState;


void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}


void loop()
{
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == LOW && currentState == HIGH)
  {
    Serial.println("The sensor is touched");
  }
  else
  {
   if (lastState == HIGH && currentState == LOW)
   {
     Serial.println("The sensor is is released");
   }
  }
  
  // save last state
  lastState = currentState;
}
