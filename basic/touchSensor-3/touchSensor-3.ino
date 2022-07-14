// touchSensor-3.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-touch-sensor
*/

const int SENSOR_PIN = 7;


void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN,  INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
  int state = digitalRead(SENSOR_PIN);
  // control LED according to sensor's state
  digitalWrite(LED_BUILTIN, state);
}
