#include "LiquidCrystal.h"
LiquidCrystal lcd(13,12,11,10,9,8);
int FIRE_SENSOR_LOW = 2;
int RED_LED = 7;
int GREEN_LED= 6; 

void setup() {
  pinMode(FIRE_SENSOR_LOW, INPUT_PULLUP);
  pinMode (RED_LED, OUTPUT);
  pinMode (GREEN_LED, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("FIRE SENSOR BASED");
  lcd.setCursor(0,1);
  lcd.print("FIRE DETECTION SYSTEM...");
  delay(1000);
}

void loop() {
 int FIRE_SENSOR_LOW_READ = digitalRead(FIRE_SENSOR_LOW);
 if(FIRE_SENSOR_LOW_READ == LOW){
  lcd.clear();
  lcd.setCursor(0,2);
  lcd.print("FIRE DETECTED");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(20);
 }else{
  lcd.clear();
  lcd.setCursor(0,2);
  lcd.print("FIRE NOT DETECTED");
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  delay(20);
 }
}
