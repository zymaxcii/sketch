// solenoid_lock.ino
// https://arduinogetstarted.com/tutorials/arduino-solenoid-lock

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-solenoid-lock
 */

// constants won't change
const int RELAY_PIN = A5;  // the Arduino pin, which connects to the IN pin of relay

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 3 as an output.
  pinMode(RELAY_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, HIGH); // uhlock the door
  delay(5000);
  digitalWrite(RELAY_PIN, LOW);  // lock the door
  delay(5000);
}

