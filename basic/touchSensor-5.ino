// touchSensor-5.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor


/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-touch-sensor
 */

// constants won't change. They're used here to set pin numbers:
const int SENSOR_PIN = 7; // the Arduino's input pin that connects to the sensor's SIGNAL pin 

// Variables will change:
int lastState = LOW;      // the previous state from the input pin
int currentState;         // the current reading from the input pin
int ledState = LOW;             // the current LED state

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH){
    // toggle LED state
    if(ledState == LOW)
      ledState = HIGH;
    else if(ledState == HIGH)
      ledState = LOW;

    // control LED
    digitalWrite(LED_BUILTIN, ledState);
  }

  // save the the last state
  lastState = currentState;
}
