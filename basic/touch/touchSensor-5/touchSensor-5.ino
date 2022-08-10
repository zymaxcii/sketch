// touchSensor-5.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor


/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-touch-sensor
*/

const int SENSOR_PIN = 7;

int lastState = LOW;
int currentState;
int ledState = LOW;


void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == LOW && currentState == HIGH)
  {
    // toggle LED state
    if (ledState == LOW)
    {
       ledState = HIGH;
    }
    else
    {
      if (ledState == HIGH)
      {
        ledState = LOW;
      }
    }
    // control LED
    digitalWrite(LED_BUILTIN, ledState);
  }

  // save last state
  lastState = currentState;
}
