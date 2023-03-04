/*  Arduino Powered
 *  Frequency Counter
 *  learnelectronics
 *  09 Jan 17
 *  
 *  If'n she don't work, make sure
 *  all grounds are commoned
 */


#include <LiquidCrystal.h>
//---------------------------------------------------------------
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

const int pulsePin = 8;                 // Signal In

int pulseHigh;                           // Pulse High Time in uS
int pulseLow;                            // Pulse Low time in uS
float pulseTotal;                        // Total of high & low times
float frequency;                         // Calculated Frequency
//---------------------------------------------------------------
void setup()
{
    pinMode(pulsePin,INPUT);              //Set pin 8 for Input
    lcd.begin(16, 2);                     //Activate the LCD
    lcd.setCursor(0,0);                   //Set cursor to top line full left
    lcd.print("Arduino Powered");         //splash screen
    lcd.setCursor(0,1);                   //second line full left
    lcd.print("  Freq Counter  ");         // more splash
    delay(2000);                          //take a break
}

//---------------------------------------------------------------
void loop()
{
    lcd.setCursor(0,0);                   //Set cursor to top line full left
    lcd.print("Frequency is    ");        //User Interface
    lcd.setCursor(0,1);                   //drop down one line
    lcd.print("                ");        //clear from previous
    
    pulseHigh = pulseIn(pulsePin,HIGH);   //get the high
    pulseLow = pulseIn(pulsePin,LOW);     //get the low
    
    pulseTotal = pulseHigh + pulseLow;    // add em up
    frequency=1000000/pulseTotal;         // convert to Hz with MATH!
    
    lcd.setCursor(0,1);                   //second line
    lcd.print(frequency);                 //print the freq to LCD
    lcd.print(" Hz");                     //print units
    delay(500);                           //take a break
}
