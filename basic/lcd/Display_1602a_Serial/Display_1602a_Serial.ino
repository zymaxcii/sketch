//
// Non I2C version

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  if (Serial.available())
  {
    lcd.write(Serial.read());
  }
}
