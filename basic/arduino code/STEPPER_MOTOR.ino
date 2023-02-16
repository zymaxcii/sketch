#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int A_Phase_MPIN1 = 7;
int A_Phase_MPIN2 = 6;
int A_Phase_MPIN3 = 5;
int A_Phase_MPIN4 = 4;
void setup() {
  pinMode(A_Phase_MPIN1, OUTPUT);
  pinMode(A_Phase_MPIN2, OUTPUT);
  pinMode(A_Phase_MPIN3, OUTPUT);
  pinMode(A_Phase_MPIN4, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("DC Motor direction");
  lcd.setCursor(0,1);
  lcd.print("control system...");
  delay(1000);
  lcd.clear();
}
void loop() {
  digitalWrite(A_Phase_MPIN1, HIGH);
  digitalWrite(A_Phase_MPIN2, LOW);
  digitalWrite(A_Phase_MPIN3, LOW);
  digitalWrite(A_Phase_MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("90 Degree");
  delay(2000); 
  lcd.clear();

  digitalWrite(A_Phase_MPIN1, LOW);
  digitalWrite(A_Phase_MPIN2, HIGH);
  digitalWrite(A_Phase_MPIN3, LOW);
  digitalWrite(A_Phase_MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("180 Degree");
  delay(2000); 
  lcd.clear();

  digitalWrite(A_Phase_MPIN1, LOW);
  digitalWrite(A_Phase_MPIN2, LOW);
  digitalWrite(A_Phase_MPIN3, HIGH);
  digitalWrite(A_Phase_MPIN4, LOW);
  lcd.setCursor(0,2);
  lcd.print("270");
  delay(2000); 
  lcd.clear();

  digitalWrite(A_Phase_MPIN1, LOW);
  digitalWrite(A_Phase_MPIN2, LOW);
  digitalWrite(A_Phase_MPIN3, LOW);
  digitalWrite(A_Phase_MPIN4, HIGH);
  lcd.setCursor(0,2);
  lcd.print("360");
  delay(2000); 
  lcd.clear(); 
}
