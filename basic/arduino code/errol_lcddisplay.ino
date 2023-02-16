#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
 lcd.begin(20,4);
 lcd.print("Errol James Bola");
 delay(2000);
 lcd.clear();
}

void loop() {
 lcd.setCursor(0, 1);
 lcd.print("BS CPE");
 delay(2000);
 lcd.setCursor(0, 2);
 lcd.print("4th year");
 delay(2000);
}
