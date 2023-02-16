#include<Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
Servo myservo;
  int POT_PIN = A0;
  int POT_PIN_ADC_LEVEL;

void setup() {
 myservo.attach(3);
 lcd.begin(20,4);
 lcd.setCursor(0,0);
 lcd.print("Servo ANALOG write ");
 lcd.setCursor(0,1);
 lcd.print("system at UPES....");
}

void loop() {
 POT_PIN_ADC_LEVEL = analogRead(POT_PIN);
 POT_PIN_ADC_LEVEL = map(POT_PIN_ADC_LEVEL, 0, 1023, 0, 179);

 myservo.write(POT_PIN_ADC_LEVEL);
 lcd.setCursor(0,2);
 lcd.print("ANGLE: ");
 lcd.print(POT_PIN_ADC_LEVEL);
 delay(15);
}
