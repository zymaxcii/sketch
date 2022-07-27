#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#define STEPPER_MOTOR_PHASE_A 4
#define STEPPER_MOTOR_PHASE_B 5
#define STEPPER_MOTOR_PHASE_C 6
#define STEPPER_MOTOR_PHASE_D 7
void setup()
{ 
 Serial.begin(9600);
 lcd.begin(20,4);
 pinMode(STEPPER_MOTOR_PHASE_A, OUTPUT);
 pinMode(STEPPER_MOTOR_PHASE_B, OUTPUT);
 pinMode(STEPPER_MOTOR_PHASE_C, OUTPUT);
 pinMode(STEPPER_MOTOR_PHASE_D, OUTPUT);
 lcd.setCursor(0,0);
 lcd.print("DC motor control");
 lcd.setCursor(0,1);
 lcd.print("+ remote control");
 delay(1000);
}
void loop()
{
char LABVIEW_SERIAL_CHAR;
LABVIEW_SERIAL_CHAR=Serial.read();
 if (LABVIEW_SERIAL_CHAR=='W')
  
 {  
    lcd.clear();     
    lcd.setCursor(0,3);
    lcd.print("4 STEP SYSTEM");
    digitalWrite(STEPPER_MOTOR_PHASE_A, HIGH);
    digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
    delay(20);
    digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_B, HIGH);
    digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
    delay(20);
    digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_C, HIGH);
    digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
    delay(20);
    digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
  digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_D, HIGH);
 } 
 else if (LABVIEW_SERIAL_CHAR=='Z')
 {
   lcd.clear(); 
   lcd.setCursor(0,3);
   lcd.print("Motor Reverse");
   digitalWrite(STEPPER_MOTOR_PHASE_A, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
   delay(20);
   digitalWrite(STEPPER_MOTOR_PHASE_A, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_B, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
   delay(20);
   digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_B, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
   delay(20);
   digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_B, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_C, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
   delay(20);
   digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_C, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
   delay(20);
   digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_C, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_D, HIGH);
   delay(20);
   digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_D,HIGH);
   delay(20);
digitalWrite(STEPPER_MOTOR_PHASE_A, HIGH);
   digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
   digitalWrite(STEPPER_MOTOR_PHASE_D, HIGH);
       
 }
 else if (LABVIEW_SERIAL_CHAR=='E')
 {
   lcd.clear(); 
   lcd.setCursor(0,3);
   lcd.print("STOP");
    digitalWrite(STEPPER_MOTOR_PHASE_A, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_B, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_C, LOW);
    digitalWrite(STEPPER_MOTOR_PHASE_D, LOW);
 }
    delay(10);      
}
