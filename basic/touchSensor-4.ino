// touchSensor-4.ino
// https://arduinogetstarted.com/tutorials/arduino-touch-sensor


// constants won't change. They're used here to set pin numbers:
const int SENSOR_PIN = 7;       // the Arduino's input pin that connects to the sensor's SIGNAL pin 

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH)
    Serial.println("The sensor is touched");
  else if(lastState == HIGH && currentState == LOW)
    Serial.println("The sensor is is released");

  // save the the last state
  lastState = currentState;
}
