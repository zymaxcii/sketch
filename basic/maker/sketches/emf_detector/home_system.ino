/* Home Arduino System v1.0
 *  learnelectronics
 *  01-02-2017
 */
//---------------------------------------------------------------------------------
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#define safeLED 2                         //green LED for not triggered
#define alertLED 3                        //red LED for when alarm is triggered
#define buzzer 4                          // buzzer for alarm
#define ldr A0                            //Light Dependent Resistor
#define flameAlarm A2
int ldrValue = 0;                         //Value for LDR
int flameSensor = 0;
int alarmState = 0;                       //State of Alarm

//----------------------------------------------------------------------------------

void setup() {
  
pinMode(safeLED, OUTPUT);                 // Set green LED to OUTPUT
pinMode(alertLED, OUTPUT);                // Set red LED to OUTPUT
pinMode(buzzer, OUTPUT);                  // Set buzzer to OUTPUT
Serial.begin(9600);                       // turn on serial comms
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.display();
digitalWrite(safeLED,HIGH);               // turn on SAFE LED
delay(2000);                              // delay to arm
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("System Armed");
  display.display();


}
//----------------------------------------------------------------------------------
void alarm(){                             //ALARM FUNCTION
  alarmState = 1;                         // set alarm state to 1
  digitalWrite(alertLED, HIGH);           // turn alert LED on
  digitalWrite(safeLED,LOW);              // turn safe LED off
  tone(buzzer,3000,1000);                 // make anoying sound
  delay(500);
  tone(buzzer,1000,1000);
  delay(500);
}

//----------------------------------------------------------------------------------




void loop() {
  
if(alarmState == 1){                    //check alarm state, if 1, alarm has been triggered
  alarm();                              // so keep sounding the alarm
}

ldrValue = analogRead(ldr);             //get LDR vale
Serial.print("LDR value ");
Serial.println(ldrValue);               // for debugging

if(ldrValue > 100){                     // threshold for alarm
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("LASER Tripped");
  display.display();
  alarm();                              //sound alarm
}
else{
  digitalWrite(safeLED,HIGH);           // if all is well, re-run the loop
  
  }

flameSensor = analogRead(A2);
Serial.print("Flame value ");
Serial.println(flameSensor);
if(flameSensor <100){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Flame Detected");
  display.display();
  alarm();
}
else{
  digitalWrite(safeLED,HIGH);           // if all is well, re-run the loop
  
  }
}
