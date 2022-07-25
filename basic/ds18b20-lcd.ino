// ds18b20-lcd.ino
// https://www.makerguides.com/ds18b20-arduino-tutorial/


/* DS18B20 1-Wire digital temperature sensor with 16x2 I2C LCD and Arduino example code. More info: https://www.makerguides.com */

// Include the required Arduino libraries:
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2

// Create a new instance of the oneWire class to communicate with any OneWire device:
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library:
DallasTemperature sensors(&oneWire);

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

void setup() {
  // Start up the library:
  sensors.begin();
  // Start the LCD and turn on the backlight:
  lcd.init();
  lcd.backlight();
  // Create a custom character:
  lcd.createChar(0, Degree);
}

void loop() {
  // Send the command for all devices on the bus to perform a temperature conversion:
  sensors.requestTemperatures();

  // Fetch the temperature in degrees Celsius for device index:
  float tempC = sensors.getTempCByIndex(0); // the index 0 refers to the first device

  // Print the temperature on the LCD;
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print(tempC);
  lcd.write(0); // print the custom character
  lcd.print("C");

  // Wait 1 second:
  delay(1000);
}

