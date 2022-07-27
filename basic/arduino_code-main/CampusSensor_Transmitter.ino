const int FLAME_SENSOR_PIN = 7; 
int FLAME_SENSOR_state=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(14, 13, 12, 11, 6, 4);
void setup()
{
 lcd.begin(16,2);
 Serial.begin(9600);
 pinMode(FLAME_SENSOR_PIN, INPUT);
 lcd.setCursor(0,0);
 lcd.print("FLAME DETECTION");
 lcd.setCursor(0,1);
 lcd.print("SYSTENM AT UPES");
 delay(1000);
}
void loop() 
{  
 FLAME_SENSOR_state = digitalRead(FLAME_SENSOR_PIN);
  
 if(FLAME_SENSOR_state== HIGH)
 { 
  lcd.clear();     
  int FLAME_SENSOR_serial_data=10;
  Serial.write(FLAME_SENSOR_serial_data); 
  lcd.setCursor(0,1);
  lcd.print("FLAME DETECTED");
  delay(50);
 } 
  
 else
 {
  lcd.clear();     
  int FLAME_SENSOR_serial_data=20;
  Serial.write(FLAME_SENSOR_serial_data); 
  lcd.setCursor(0,1);
  lcd.print("NO FLAME");
  delay(50);
 }  
}
