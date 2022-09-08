// lcd-thermistor.ino
// using lcd 1602

#include <LiquidCrystal.h>

int tim = 50;                       // value of delay time

// initialize library with numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

int thermistorPin = 0;              // thermistor connected to analog pin 3


void setup()
{
  lcd.begin(16, 2);                 // set up LCD's number of columns and rows
  lcd.clear();                      // Clear LCD screen and positions the cursor in the upper-left corner 
}


void loop() 
{
  float a = analogRead(thermistorPin);
  
  // calculating formula of temperature
  float resistor = (1023.0*10000)/a-10000;
  float tempC = (3435.0/(log(resistor/10000)+(3435.0/(273.15+25)))) - 200.00;

  lcd.setCursor(0, 0);              // set cursor to column 0, line 0
  lcd.print(" THIS IS A TEST ");    // Print a message of "Temp: "to the LCD

  lcd.setCursor(0, 1);              // set cursor to column 0, line 0
  lcd.print("  Temp: ");            // Print a message of "Temp: " to LCD
  lcd.print(tempC);                 // Print a centigrade temperature to LCD
  lcd.print(" C  ");                // Print unit of centigrade temperature to LCD
  delay(500);
}
