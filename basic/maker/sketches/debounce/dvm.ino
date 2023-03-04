/*
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

// include the library code:
#include <LiquidCrystal.h>


float voltage = 0.0;
float temp=0.0;
int analog_value;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
   lcd.begin(16, 2); 
   lcd.setCursor (0,0);
   lcd.print(" Arduino based ");
   lcd.setCursor(0,1); 
   lcd.print("Digital Voltmeter");
delay(2000);

}

void loop() {

 analog_value = analogRead(A0);
   temp = (analog_value * 5.0) / 1024.0; 

   voltage = temp/(0.0909);
   if (voltage < 0.1) 
   {
     voltage=0.0;
   } 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage= ");
    lcd.print((voltage)-.32);
    lcd.setCursor(13,1);
    lcd.print("V");
    delay(30);
}

