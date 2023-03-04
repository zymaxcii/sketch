#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int TEMP_SENSOR=A0;
void setup()
{
lcd.begin(20,4);
Serial.begin(9600);// initialize serial communication at 
lcd.setCursor(0,0);
lcd.print("wireless Serial ");
lcd.setCursor(0,1);
lcd.print("communication via 2.4 GHz");
lcd.setCursor(0,2);
lcd.print("modem at SME.....");
}
void loop() 
{
int TEMP_SENSOR_ADC_VALUE = analogRead(TEMP_SENSOR);
int TEMP_VAL=TEMP_SENSOR_ADC_VALUE/2;//10mV/0C is resolution 

lcd.setCursor(0,3);
lcd.print("Temp. in 0C:");
lcd.setCursor(13,3);
lcd.print(TEMP_VAL);// print temperature value on LCD
Serial.write(TEMP_VAL);
delay(100);
}  
