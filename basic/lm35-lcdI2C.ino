// lm35-I2C.ino
// https://www.makerguides.com/lm35-arduino-tutorial/


/* LM35 analog temperature sensor with I2C LCD and Arduino example code. More info: https://www.makerguides.com */

// Include the required Arduino libraries:
#include <LiquidCrystal_I2C.h>

// Create a new instance of the LiquidCrystal_I2C class:
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Degree symbol:
byte Degree[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

// Define to which pin of the Arduino the output of the LM35 is connected:
#define sensorPin A0

void setup() {
  // Start the LCD and turn on the backlight:
  lcd.init();
  lcd.backlight();

  // Create a custom character:
  lcd.createChar(0, Degree);
}

void loop() {
  // Get a reading from the temperature sensor:
  int reading = analogRead(sensorPin);

  // Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);

  // Convert the voltage into the temperature in degree Celsius:
  float temperature = voltage / 10;

  // Print the temperature on the LCD;
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.write(0); // print the custom character
  lcd.print("C");

  delay(1000); // wait a second between readings
}
