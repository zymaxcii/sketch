#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int Temp_sensor_Pin = A0;
int Temp_sensor_ADC_Value = 0; // storage value for temp sensor
const int pingPin = A5;
const int echoPin = A4;

int RED_LED = 7;
int BLUE_LED = 6;
int YELLOW_LED = 5;
int GREEN_LED = 4;

void setup() {
pinMode(Temp_sensor_Pin, OUTPUT);
pinMode(RED_LED, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
pinMode(YELLOW_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);

lcd.begin(20,4);
lcd.setCursor(0,0);
lcd.print("SENSOR STARTS MONITORING...");
delay(1000);
lcd.clear();
}
void loop() {
  Temp_sensor_ADC_Value = analogRead(Temp_sensor_Pin)-1;
  float Temp_sensor_Value_ACTUAL = Temp_sensor_ADC_Value/2;
  if(Temp_sensor_Value_ACTUAL>32){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(Temp_sensor_Value_ACTUAL);
    lcd.print(" CELCIUS");
    lcd.setCursor(0,1);
    lcd.print("HIGH TEMPERATURE");
    delay(100);
  }else if(Temp_sensor_Value_ACTUAL<=32){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(Temp_sensor_Value_ACTUAL);
    lcd.print(" CELCIUS");
    lcd.setCursor(0,1);
    lcd.print("NORMAL TEMPERATURE");
    delay(100);
  }
  long duration, cm;
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
  if(cm>=300 && cm<=499){
    lcd.setCursor(0,3);
    lcd.print("PREPARE");
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);
  }
  if(cm>=100 && cm<=299){
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
}

long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}
