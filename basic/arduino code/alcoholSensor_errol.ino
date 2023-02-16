#include "LiquidCrystal.h"
LiquidCrystal lcd(13,12,11,10,9,8);
int ALCOHOL_SENSOR_LOW = 3;
int RED_LED = 5;
int GREEN_LED = 4;

void setup() {
  pinMode(ALCOHOL_SENSOR_LOW, INPUT_PULLUP);
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("ALCOHOL SENSOR BASED");
  lcd.setCursor(0,1);
  lcd.print("ALCOHOL DETECTION");
  lcd.setCursor(0,2);
  lcd.print("SYSTEM AT UPES.....");
  delay(1000);
}
void loop() {
 int ALCOHOL_SENSOR_LOW_READ = digitalRead(ALCOHOL_SENSOR_LOW);
 if(ALCOHOL_SENSOR_LOW_READ == LOW){
  lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("ALCOHOL DETECTED ");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(20);
 }else{
  lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("ALCOHOL NOT DETECTED ");
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  delay(20);
 }
}
