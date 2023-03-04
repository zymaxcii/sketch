#include "LiquidCrystal.h"
const int rs= 13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int BUTTON_HIGH = 5;
int RED_LED = 3;
int BLUE_LED = 2;

void setup() {
  pinMode(BUTTON_HIGH, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("DIGITAL HIGH BUTTON");
  lcd.setCursor(0,1);
  lcd.print("READ SYSTEM...");
  delay(1000);
}

void loop() {
  int BUTTON_HIGH_READ = digitalRead(BUTTON_HIGH);
   if (BUTTON_HIGH_READ == HIGH){
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("BUTTON_PRESSED");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay(1000);
   }else{
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("BUTTON_NOT_PRESSED");
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(1000);
   }
}
