#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10,9, 8);// attach LCD pin 
int TEMP_sensor_Pin = A0;  // select the input pin for the potentiometer
int TEMP_sensor_ADC_Value = 0;  // variable to store the value coming from the sensor
int RED_LED = 6;
int BLUE_LED = 7;
void setup()
{
pinMode(TEMP_sensor_ADC_Value, INPUT_PULLUP);
pinMode(RED_LED, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
lcd.begin(20, 4);// Initialise 20*4 LCD
lcd.setCursor(0, 0);// set cursor of LCD at column0 and Row0
lcd.print("TEMPERATURE SENSOR STARTS MONITORING...");
delay(1000);
lcd.clear(); 
}
void loop() 
{
 TEMP_sensor_ADC_Value = analogRead(TEMP_sensor_Pin)-1; // read the value from the sensor
float TEMP_sensor_Value_ACTUAL=TEMP_sensor_ADC_Value/2;
if(TEMP_sensor_Value_ACTUAL>32){
lcd.clear();
lcd.setCursor(0,2);
lcd.print("TEMP = HOT");
lcd.setCursor(0,3);
lcd.print("TEMP VALUE:");
lcd.setCursor(12,3);
lcd.print(TEMP_sensor_Value_ACTUAL);
digitalWrite(RED_LED, HIGH);
digitalWrite(BLUE_LED, LOW);
delay(100);
}else if(TEMP_sensor_Value_ACTUAL<=32){
lcd.clear();
lcd.setCursor(0,2);
lcd.print("TEMP = NORMAL");
lcd.setCursor(0,3);
lcd.print("TEMP VALUE:");
lcd.setCursor(12,3);
lcd.print(TEMP_sensor_Value_ACTUAL);
digitalWrite(BLUE_LED, HIGH);
digitalWrite(RED_LED, LOW);
delay(100);
}
}
