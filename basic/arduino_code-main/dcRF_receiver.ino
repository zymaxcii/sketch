#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#define DC_MOTOR1_POSITIVE A4
#define DC_MOTOR1_NEGATIVE A5
void setup()
{ 
Serial.begin(9600);
lcd.begin(20,4);
pinMode(DC_MOTOR1_POSITIVE, OUTPUT);
pinMode(DC_MOTOR1_NEGATIVE, OUTPUT);
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
 lcd.print("CLOCKWISE");
 digitalWrite(DC_MOTOR1_POSITIVE, HIGH);
 digitalWrite(DC_MOTOR1_NEGATIVE, LOW);
}
else if (LABVIEW_SERIAL_CHAR=='Z')
{
 lcd.clear(); 
 lcd.setCursor(0,3);
 lcd.print("ANTICLOCKWISE");
 digitalWrite(DC_MOTOR1_POSITIVE, LOW);
 digitalWrite(DC_MOTOR1_NEGATIVE, HIGH);
}
else if (LABVIEW_SERIAL_CHAR=='E')
{
 lcd.clear(); 
 lcd.setCursor(0,3);
 lcd.print("STOP");
 digitalWrite(DC_MOTOR1_POSITIVE, LOW);
 digitalWrite(DC_MOTOR1_NEGATIVE, LOW);
}
delay(10);
}
