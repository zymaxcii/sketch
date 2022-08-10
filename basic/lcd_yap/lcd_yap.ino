// lcd_yap.ino
// https://mikeyancey.com/hamcalc/lcd_characters.php

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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

void setup() {
    lcd.createChar(0, newChar);
    lcd.begin(16, 2);
    lcd.write(0);
}

void loop() {}
