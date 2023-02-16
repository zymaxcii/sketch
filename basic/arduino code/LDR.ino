#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int LDR_sensor_Pin = A0;
int LDR_sensor_ADC_Value = 0;
int RED_LED = 7;

void setup() {
  lcd.begin(20,4);
  pinMode(RED_LED, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("LDR based light");
  lcd.setCursor(0,1);
  lcd.print("intensity monitoring");
  lcd.setCursor(0,2);
  lcd.print("system at UPES");
  delay(1000);
  lcd.clear();
}
void loop() {
 LDR_sensor_ADC_Value = analogRead(LDR_sensor_Pin);
 lcd.setCursor(0,2);
 lcd.print("ADC LEVEL+LDR:");
 lcd.setCursor(17,2);
 lcd.print(LDR_sensor_ADC_Value);
 if(LDR_sensor_ADC_Value){
  digitalWrite(RED_LED, HIGH);
  delay(20);
 }else{
  digitalWrite(RED_LED,LOW);
  delay(20);
 }
}
