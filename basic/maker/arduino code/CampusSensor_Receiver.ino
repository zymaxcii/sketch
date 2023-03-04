#include <LiquidCrystal.h>
LiquidCrystal lcd(14, 13, 12, 11, 6, 4);
void setup()
{
 lcd.begin(16,2);
 Serial.begin(9600);
 lcd.setCursor(0,0);
 lcd.print("FLAME DETECTION");
 lcd.setCursor(0,1);
 lcd.print("SYSTENM AT UPES");
 delay(1000);
}
void loop() 
{  
 int FLAME_SENSOR_serial_data= Serial.read();;
 if(FLAME_SENSOR_serial_data == 10) 
 { 
  lcd.clear();     
  Serial.print("FLAMESENSOR:");
   Serial.println(FLAME_SENSOR_serial_data);
  lcd.setCursor(0,0);
  lcd.print("FLAME DETECTED");
  delay(50);
 } 
 else if(FLAME_SENSOR_serial_data == 20) 
 {
  lcd.clear();
  Serial.print("FLAMESENSOR:");
  Serial.println(FLAME_SENSOR_serial_data);
  lcd.setCursor(0,1);
  lcd.print("NO FLAME");
  delay(50); 
 }
}
