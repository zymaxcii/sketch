#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int MPIN1 = 7;
int MPIN2 = 6;
int MPIN3 = 5;
int MPIN4 = 4;
void setup() {
  pinMode(MPIN1, OUTPUT);
  pinMode(MPIN2, OUTPUT);
  pinMode(MPIN3, OUTPUT);
  pinMode(MPIN4, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("DC Motor direction");
  lcd.setCursor(0,1);
  lcd.print("control system...");
  delay(1000);
  lcd.clear();
}
void loop() {
  digitalWrite(MPIN1, HIGH);
  digitalWrite(MPIN2, LOW);
  digitalWrite(MPIN3, HIGH);
  digitalWrite(MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("CLOCKWISE");
  delay(2000); 
  lcd.clear();

  digitalWrite(MPIN1, LOW);
  digitalWrite(MPIN2, HIGH);
  digitalWrite(MPIN3, LOW);
  digitalWrite(MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("ANTI-CLOCKWISE");
  delay(2000); 
  lcd.clear();

  digitalWrite(MPIN1, LOW);
  digitalWrite(MPIN2, LOW);
  digitalWrite(MPIN3, HIGH);
  digitalWrite(MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("LEFT");
  delay(2000); 
  lcd.clear();

  digitalWrite(MPIN1, HIGH);
  digitalWrite(MPIN2, LOW);
  digitalWrite(MPIN3, LOW);
  digitalWrite(MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("RIGHT");
  delay(2000); 
  lcd.clear(); 
}
