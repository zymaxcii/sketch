#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10,9, 8);// attach LCD pin 
int TEMP_sensor_Pin = A0;  // select the input pin for the potentiometer
int TEMP_sensor_ADC_Value = 0;  // variable to store the value coming from the sensor
const int pingPin = A5;
const int echoPin = A4;
int RED_LED = 7;
int BLUE_LED = 6;
int YELLOW_LED = 5;
int GREEN_LED = 4;

void setup()
{
pinMode(TEMP_sensor_ADC_Value, INPUT_PULLUP);
pinMode(RED_LED, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
pinMode(YELLOW_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);
lcd.begin(20, 4);// Initialise 20*4 LCD
lcd.setCursor(0, 0);// set cursor of LCD at column0 and Row0
lcd.print("SENSOR STARTS MONITORING...");
delay(1000);
lcd.clear(); 
}
void loop() 
{

TEMP_sensor_ADC_Value = analogRead(TEMP_sensor_Pin)-1; // read the value from the sensor
float TEMP_sensor_Value_ACTUAL=TEMP_sensor_ADC_Value/2;
if(TEMP_sensor_Value_ACTUAL>32){
lcd.clear();
lcd.setCursor(0,0);
lcd.print(TEMP_sensor_Value_ACTUAL);
lcd.print(" CELCIUS");
lcd.setCursor(0,1);
lcd.print("HIGH TEMPERATURE");
delay(100);
}else if(TEMP_sensor_Value_ACTUAL<=32){
lcd.clear();
lcd.setCursor(0,0);
lcd.print(TEMP_sensor_Value_ACTUAL);
lcd.print(" CELCIUS");
lcd.setCursor(0,1);
lcd.print("NORMAL TEMPERATURE");
delay(100);
}

long duration,cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);

lcd.setCursor(0,2);
lcd.print(cm);
lcd.print("cm");

if(cm>=500){
  lcd.setCursor(0,3);
  lcd.print("NORMAL");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
}
if(cm>=301 && cm<=499){
  lcd.setCursor(0,3);
  lcd.print("PREPARE");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(1000);
}
if(cm>=101 && cm<=299){
  lcd.setCursor(0,3);
  lcd.print("EVACUATE");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  delay(1000);
}
if(cm<100){
  lcd.setCursor(0,3);
  lcd.print("FORCED EVACUATION");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  delay(1000);
  
}

}//void loop

long microsecondsToinches(long microseconds){
  return microseconds/74/2;
}
long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}
