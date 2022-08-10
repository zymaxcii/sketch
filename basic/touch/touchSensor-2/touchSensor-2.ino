// touchSensor-2.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor
// 

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-touch-sensor
*/

const int SENSOR_PIN = 7; 


void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}


void loop()
{
  int state = digitalRead(SENSOR_PIN);
  Serial.println(state);
}
