/*
 * Arduino Air Quality Monitor
 * 
 * learnelectronics
 * 24 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * 
 * Be sure to burn in sensor by leaving
 * plugged in for 24 hours before initial
 * use, then calibrate by placing outside
 * for at least 10 minutes. Outdoor C02
 * levels are between 380-400ppm unless
 * you live in Shenzen. If you live in
 * this ain't gonna help you.
 */



#include <LiquidCrystal.h>                //LCD Library


#define beeper    8                       //beeper on Digital 8
#define sensor    A0                      //sensor on Analog 0



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    //Create instance of LCD

int gasLevel = 0;                         //int variable for gas level
String quality ="";

void setup() {
  Serial.begin(9600);                     //start serial comms
  pinMode(beeper,OUTPUT);                 //set beeper for output
  pinMode(sensor,INPUT);                  //set sensor for input

  
  lcd.begin(16, 2);                       //initial LCD setup
  lcd.setCursor (0,0);                    //splash screen and warmup
  lcd.print("                ");
  lcd.setCursor (0,1);
  lcd.print("                ");
  lcd.setCursor (0,0);
  lcd.print("   Air Sensor   ");
  lcd.setCursor (0,1);
  lcd.print("   Warming Up   ");
  delay(2000);                            //set for at least 2 minutes

  lcd.setCursor (0,0);                    //clear screen
  lcd.print("                ");
  lcd.setCursor (0,1);
  lcd.print("                ");
  
}

void loop() {
  gasLevel = analogRead(sensor);

  if(gasLevel<175){
    quality = "GOOD!           ";
  }
  else if (gasLevel >175 && gasLevel<225){
    quality = "Did you fart?   ";
  }
  else if (gasLevel >225 && gasLevel<300){
    quality = "Something dead?";
  }
  else if (gasLevel >300){
    quality = "Pretty fk'n bad ";
  }
lcd.setCursor (0,0);
lcd.print("Air Quality is:");
lcd.setCursor(0,1);
lcd.print(quality);
}

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
 * 5K pot:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/
