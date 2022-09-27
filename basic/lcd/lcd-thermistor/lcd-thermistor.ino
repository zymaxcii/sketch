// lcd-thermistor.ino
// Display thermistor's temperature in lcd

// My standard hardware setup
// lcd pins:  RS EN D4 D5 D6 D7
// to MCU:    D8 D9 D4 D5 D6 D7
//
// thermistor: pin A0

#include <LiquidCrystal.h>

int tim = 50;                       // delay time

//                RS EN D4 D5 D6 D7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int thermistorPin = 0;           // thermistor connected to A0


void setup()
{
  lcd.begin(16, 2);              // set up column and row 
  lcd.clear();                   // Clear screen 
}


void loop() 
{
  float a = analogRead(thermistorPin);
  
  // the calculating formula of temperature
  float resistor = (1023.0*10000)/a-10000;
  float tempC = (3435.0/(log(resistor/10000)+(3435.0/(273.15+25)))) - 200.00;

  lcd.setCursor(0, 0);            // set cursor to column 0 line 0
  lcd.print(" THIS IS A TEST ");  // Print message

  lcd.setCursor(0, 1);
  lcd.print("  Temp: ");
  lcd.print(tempC);               // temperature in Celsius 
  lcd.print(" C  ");
  delay(500);
}
