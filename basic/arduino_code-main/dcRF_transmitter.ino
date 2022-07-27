#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#define BUTTON_MODE_SELECTION 7
#define BUTTON_PIN_FORWARD 6
#define BUTTON_PIN_REVERSE 5
#define BUTTON_PIN_STOP 4
void setup()
{
lcd.begin(20,4);
Serial.begin(9600);
pinMode(BUTTON_MODE_SELECTION,INPUT_PULLUP);
pinMode(BUTTON_PIN_FORWARD,INPUT_PULLUP);
pinMode(BUTTON_PIN_REVERSE,INPUT_PULLUP);
pinMode(BUTTON_PIN_STOP,INPUT_PULLUP);
lcd.setCursor(0,0);
lcd.print("DC motor control");
lcd.setCursor(0,1);
lcd.print("+ remote control");
delay(1000);
}
void loop() 
{
int
BUTTON_MODE_SELECTION_digital=digitalRead(BUTTON_MODE_SELECTION);
if (BUTTON_MODE_SELECTION_digital==LOW)
 {
 char LABVIEW_SERIAL_CHAR;
 LABVIEW_SERIAL_CHAR=Serial.read();
 if (LABVIEW_SERIAL_CHAR=='W')
 {
 lcd.clear();
 lcd.setCursor(0,3);
 lcd.print("CLOSEWISE");
 Serial.write('W');
 } 
 else if (LABVIEW_SERIAL_CHAR=='Z')
 {
 lcd.clear();
lcd.setCursor(0,3);
 lcd.print("ANTICLOCKWISE");
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
else if(BUTTON_MODE_SELECTION_digital==HIGH)
 {
 int
 BUTTON_PIN_FORWARD_digital=digitalRead (BUTTON_PIN_FORWARD);
 int BUTTON_PIN_REVERSE_digital=digitalRead 
(BUTTON_PIN_REVERSE);
 int BUTTON_PIN_STOP_digital=digitalRead (BUTTON_PIN_STOP);
 if (BUTTON_PIN_FORWARD_digital==LOW)
 {
 lcd.clear();     
 lcd.setCursor(0,3);
 lcd.print("CLOSEWISE");
 Serial.write('W');
 }
 if(BUTTON_PIN_REVERSE_digital==LOW)
 {
 lcd.clear();
 lcd.setCursor(0,3);
 lcd.print("ANTICLOCKWISE");
 Serial.write('Z');
 }
 if(BUTTON_PIN_STOP_digital==LOW)
 {
 lcd.clear();
 lcd.setCursor(0,3);
 lcd.print("STOP");
 Serial.write('E');
 }
 }
}
