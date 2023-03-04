// Libraries---------------------------------------
#include <Wire.h>
#include <INA219.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Defines-----------------------------------------
#define OLED_RESET 4
#define pwmPin     6
// Variables---------------------------------------
float maxCurrent = 250;
float nowCurrent = 0;
float lastCurrent =0;
float maxVoltage = 1.8;
float nowVoltage = 0;
float mAh = 0;
int elapsed = 0;
int startTime = 0;
int pwm = 99;
int hours = 0;
int minutes = 0;
int seconds = 0;
long maxTime = 36000000;


// ------------------------------------------------
INA219 monitor;
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  monitor.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.display();
  display.clearDisplay();
  pinMode(pwmPin, OUTPUT);
  startTime = millis();
}

void loop() {
seconds = (millis()/1000);
if(seconds>59){
  minutes++;
  seconds = 0;
}

nowCurrent = (monitor.shuntCurrent() * 1000);
if (nowCurrent <= maxCurrent && pwm < 255){
  pwm++;
  lastCurrent = nowCurrent;
}

  analogWrite(pwmPin, pwm);

  display.setCursor(0,0);
  display.setTextColor(BLACK, WHITE);
  display.println("NiMh Charger");
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.print("Crnt :");
  display.setCursor(48,10);
  display.print(nowCurrent);
  display.setCursor(0,20);
  display.print("elap :");
  display.setCursor(48,20);
  display.print(minutes);
  display.print(":");
  display.print(seconds);
  display.display();
  display.clearDisplay();
  
  
  
   
   
   
   
   
   
   
   Serial.println("******************");
  
  Serial.print("raw shunt voltage: ");
  Serial.println(monitor.shuntVoltageRaw());
  
  Serial.print("raw bus voltage:   ");
  Serial.println(monitor.busVoltageRaw());
  
  Serial.println("--");
  
  Serial.print("shunt voltage: ");
  Serial.print(monitor.shuntVoltage() * 1000, 4);
  Serial.println(" mV");
  
  Serial.print("shunt current: ");
  Serial.print(monitor.shuntCurrent() * 1000, 4);
  Serial.println(" mA");
  
  Serial.print("bus voltage:   ");
  Serial.print(monitor.busVoltage(), 4);
  Serial.println(" V");
  
  Serial.print("bus power:     ");
  Serial.print(monitor.busPower() * 1000, 4);
  Serial.println(" mW");
  
  Serial.println(" ");
  Serial.println(" ");
  Serial.print("pwm :");
  Serial.println(pwm);
  
  delay(100);
  

}
