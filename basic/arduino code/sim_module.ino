#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4);
#define MESSAGE_button 7
#define CALL_button 6
#define END_button 5
String number ="9837043685"; 
void setup()
{
lcd.begin(20, 4);
Serial.begin(9600);
mySerial.begin(9600);
pinMode(MESSAGE_button,INPUT_PULLUP);
pinMode(CALL_button,INPUT_PULLUP);
pinMode(END_button,INPUT_PULLUP);
//digitalWrite(msg_key,HIGH);
//digitalWrite(call_key,HIGH);
//digitalWrite(end_key,HIGH);
lcd.setCursor(0, 0);
lcd.print("GSM MESSAGE ");
lcd.setCursor(0, 1);
lcd.print("sending system.... ");
delay(1000);
}
void loop()
{
//Sends an sms everytime msg_key is pressed
 if (digitalRead(MESSAGE_button)==LOW)
{
lcd.clear();
mySerial.println("AT+CMGF=1"); // Set the Mode as Text Mode
lcd.setCursor(0, 2);
lcd.print("AT+CMGF=1");
delay(150);
 mySerial.println("AT+CMGS=\"+919837043685\"\r");
lcd.setCursor(0, 2);
lcd.print("AT+CMGS=\"+919837043685\"\r");
delay(150);
mySerial.print("message Send"); // Enter the message 
lcd.setCursor(0, 2);
lcd.print("message Send");
delay(150);
 mySerial.write((byte)0x1A);
lcd.setCursor(0, 2);
lcd.print("cntrl+Z");
delay(50);
mySerial.println();
}
//Makes a call when call_key is pressed
 else if (digitalRead(CALL_button)==LOW) 
{  
lcd.clear();
lcd.setCursor(0, 2);
lcd.print("ATD+91"+number+";");
mySerial.println("ATD+91"+number+";"); 
while(digitalRead(CALL_button)==LOW);
delay(50);
}
//Hang the call
else if (digitalRead(END_button)==LOW) 
lcd.clear();
lcd.setCursor(0, 2);
lcd.print("ATH");
mySerial.println("ATH");
while(digitalRead(END_button)==LOW);
delay(50);
}
