#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{ 
 lcd.begin(20,4);
 Serial.begin(9600);
 lcd.setCursor(0,0);
 lcd.print("DC motor control");
 lcd.setCursor(0,1);
 lcd.print("+ remote control");
 delay(1000);
}
void loop() 
{
char LABVIEW_SERIAL_CHAR;
LABVIEW_SERIAL_CHAR=Serial.read();
 if (LABVIEW_SERIAL_CHAR=='W')
  
 {  
   lcd.clear();     
   lcd.setCursor(0,3);
   lcd.print("4 STEP SYSTEM");
   Serial.write('W');
    
 } 
 else if (LABVIEW_SERIAL_CHAR=='Z')
 {
   lcd.clear(); 
   lcd.setCursor(0,3);
   lcd.print("8 STEP SYSTEM");
   Serial.write('Z');
         
 }
 else if (LABVIEW_SERIAL_CHAR=='E')
 {
   lcd.clear(); 
   lcd.setCursor(0,3);
   lcd.print("STOP");
   Serial.write('E');
 }
  delay(10);        
}
