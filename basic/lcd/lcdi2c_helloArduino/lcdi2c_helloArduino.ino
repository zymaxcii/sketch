// lcdi2c_helloArduino.ino

// My standard hardware setup
// Uno: pins sda, scl; gnd and vcc

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);       // I2C address 0x27, 20 column and 4 rows


void setup()
{
  lcd.init();                                // initialize lcd
  lcd.backlight();
                                             // (col, row) please note
  lcd.setCursor(0, 0);                       // move cursor to   (0, 0)
  lcd.print("Arduino");                      // print message at (0, 0)

  lcd.setCursor(0, 1);                       // move cursor to   (2, 1)
  lcd.print("GetStarted.com");               // print message at (2, 1)
  
  lcd.setCursor(0, 2);
  lcd.print("Wonderful world of");
  
  lcd.setCursor(0, 3);
  lcd.print("Arduino!!!!!!");
}


void loop() { }
