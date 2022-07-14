// touchSensor-1.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor

const int SENSOR_PIN = 7; 

int lastState = LOW;      // previous state from input pin
int currentState;         // current reading from input pin


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
  
  // save last state
  lastState = currentState;
}
