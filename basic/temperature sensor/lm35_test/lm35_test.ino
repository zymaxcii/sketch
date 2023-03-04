// lm35_test.ino

// https://www.makerguides.com/lm35-arduino-tutorial/


// LM35 analog temperature sensor with Arduino example code
// More info: https://www.makerguides.com

// My standard hardware setup
// lm35
// ====
// Bottom facing flat side, right to left
// 1 GND
// 2 OUT A0
// 3 VCC +5V

// Define pin
#define sensorPin A0


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  // Get a reading from the temperature sensor
  int reading = analogRead(sensorPin);

  // Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);

  // Convert the voltage into the temperature in degree Celsius:
  float temperature = voltage / 10;

  // Print the temperature in the Serial Monitor:
  Serial.print(temperature);
  Serial.print(" \xC2\xB0");      // shows degree symbol
  Serial.println("C");

  delay(1000);                    // wait a second between readings
}
