// solenoid_lock.ino
// https://arduinogetstarted.com/tutorials/arduino-solenoid-lock

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-solenoid-lock
*/

const int RELAY_PIN = A5;        // connect to IN pin of relay


void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
}


void loop()
{
  digitalWrite(RELAY_PIN, HIGH); // uhlock the door
  delay(5000);
  
  digitalWrite(RELAY_PIN, LOW);  // lock the door
  delay(5000);
}

