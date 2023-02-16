#include <LiquidCrystal.h>
LiquidCrystal lcd(14,13,12,11,6,4);
const int PIR_sensor_PIN = 7; 
  
int PIR_sensor_PIN_state=1;
void setup()
{
lcd.begin(20,4);
Serial.begin(9600);
pinMode(PIR_sensor_PIN, INPUT);
lcd.setCursor(0,0);
lcd.print("SECURITY SYSTEM");
lcd.setCursor(0,1);
lcd.print("OF RESTRICTED AREA");
}
// the loop routine runs over and over again forever:
void loop() 
{
PIR_sensor_PIN_state = digitalRead(PIR_sensor_PIN);
if(PIR_sensor_PIN_state == HIGH)
{ 
     lcd.clear();      
     int PIR_SERIAL_BYTE=10;
 Serial.write(PIR_SERIAL_BYTE); 
 lcd.setCursor(0,1);
 lcd.print("SECURITY BREAK");
 delay(50);
} 
else
{
lcd.clear();   
 int PIR_SERIAL_BYTE=20;
 Serial.write(PIR_SERIAL_BYTE); 
 lcd.setCursor(0,1);
 lcd.print("SYSTEM SECURED");
 delay(50);
}
}
