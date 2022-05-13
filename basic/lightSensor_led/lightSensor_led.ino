/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-light-sensor
 */

// constants won't change
const int LIGHT_SENSOR_PIN = A0; // Arduino pin connected to light sensor's  pin
const int LED_PIN          = 13;  // Arduino pin connected to LED's pin
const int ANALOG_THRESHOLD = 550;

// variables will change:
int analogValue;

void setup()
{
  pinMode(LED_PIN, OUTPUT); // set arduino pin to output mode
  Serial.begin(9600);
}


void loop()
{
  analogValue = analogRead(LIGHT_SENSOR_PIN); // read the input on analog pin
  Serial.println(analogValue);

  if(analogValue > ANALOG_THRESHOLD)
    digitalWrite(LED_PIN, HIGH); // turn on LED
  else
    digitalWrite(LED_PIN, LOW);  // turn off LED
}
