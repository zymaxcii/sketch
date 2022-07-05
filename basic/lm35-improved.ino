// lm35-improved.ino
// https://www.makerguides.com/lm35-arduino-tutorial/


/* LM35 analog temperature sensor with Arduino example code. More info: https://www.makerguides.com */

// Define to which pin of the Arduino the output of the LM35 is connected:
#define sensorPin A0

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  // Set the reference voltage for analog input to the built-in 1.1 V reference:
  analogReference(INTERNAL);
}

void loop() {
  // Get a reading from the temperature sensor:
  int reading = analogRead(sensorPin);

  // Convert the reading into voltage:
  float voltage = reading * (1100 / 1024.0);

  // Convert the voltage into the temperature in degree Celsius:
  float temperature = voltage / 10;

  // Print the temperature in the Serial Monitor:
  Serial.print(temperature);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("C");

  delay(1000); // wait a second between readings
}
