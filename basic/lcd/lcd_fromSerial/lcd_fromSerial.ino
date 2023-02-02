// lcd_fromSerial.ino
// Display input from serial monitor to lcd
// Non I2C version
// status: 

// filename: non-I2C assumes to use LiquidCrystal library
// I2C assumes to use LiquidCrystal_I2C
// If using Wire directly appends Wire to filename

// My standard hardware setup
// lcd pins:  RS EN D4 D5 D6 D7
// to MCU:    D8 D9 D4 D5 D6 D7

#include <LiquidCrystal.h>

//                RS EN D4 D5 D6 D7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup()
{
  Serial.begin(9600);
  lcd.clear();
}


void loop()
{
  if (Serial.available())
  {
    // lcd.clear();              // why not working with clear?
    // delay(1000);
    lcd.write(Serial.read());
  }
}
