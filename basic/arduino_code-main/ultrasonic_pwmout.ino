#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // initialize the LCD 
const int pingPin = 5; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 4; // Echo Pin of Ultrasonic Sensor
void setup() 
{
lcd.begin(20, 4);
lcd.setCursor(0, 0);
lcd.print("Ultrasonic distance");
lcd.setCursor(0, 1);
lcd.print("System at UPES");
delay(1000);
}
void loop()
{
long duration, inches, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
lcd.clear();
lcd.setCursor(0, 2);
lcd.print(inches);
lcd.setCursor(4, 2);
lcd.print("in, ");
lcd.setCursor(8, 2);
lcd.print(cm);
lcd.setCursor(12, 2);
lcd.print("cm");
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(200);
}
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
