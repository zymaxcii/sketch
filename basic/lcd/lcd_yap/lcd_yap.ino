// lcd_yap.ino
// Display characters "Yap" in Chinese to lcd
// https://mikeyancey.com/hamcalc/lcd_characters.php

// My standard hardware setup
// lcd pins:  RS EN D4 D5 D6 D7
// to MCU:    D8 D9 D4 D5 D6 D7

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//                RS EN D4 D5 D6 D7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte newChar[8] = {
  B00010,
  B00010,
  B11010,
  B11111,
  B11010,
  B00010,
  B00010,
  B00000
};


void setup()
{
    lcd.createChar(0, newChar);
    lcd.begin(16, 2);

    for (int i=0; i<16; i++)
    {
      lcd.write((byte) 0x00);        // must cast to byte
    }
}


void loop() {}
