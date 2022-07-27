#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int RELAY_2N2222= 7;
void setup() 
{   
 lcd.begin(20,4);
     pinMode(RELAY_2N2222, OUTPUT); 
     lcd.setCursor(0, 0);
     lcd.print("AC MOTOR ON/OFF");
     lcd.setCursor(0, 1);
     lcd.print("System at UPES");
     delay(1000);
}
void loop() 
{
lcd.setCursor(0, 2);
lcd.print("AC MOTOR ONN");
 digitalWrite(RELAY_2N2222, HIGH);   

delay(2000); 
lcd.setCursor(0, 2);
lcd.print("AC MOTOR OFF");
 digitalWrite(RELAY_2N2222, LOW);   

delay(2000); 
}
