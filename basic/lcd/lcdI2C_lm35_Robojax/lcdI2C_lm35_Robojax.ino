// lcdI2C_lm35_Robojax.ino
// Display temperature from lm35 on a LCD
// http://robojax.com/node/1162

/*
 * This Arduin sketch is to use LM35 to measure temperature

 * prints the temperature as C, F or K on the LCD1602 or LCD2004 with I2C module (4 wires)
 
 * 
 * Watch Video instrution for this code:https://youtu.be/XpMtQVCMIRA
 * 
 * Full explanation of this code and wiring diagram is available at
 * my Arduino Course at Udemy.com here: http://robojax.com/L/?id=62

 * Written by Ahmad Shamshiri on May 12, 2020 at 19:53 in Ajax, Ontario, Canada
 * in Ajax, Ontario, Canada. www.robojax.com
 * 

 * Get this code and other Arduino codes from Robojax.com
Learn Arduino step by step in structured course with all material, wiring diagram and library
all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62

If you found this tutorial helpful, please support me so I can continue creating 
content like this. You can support me on Patreon http://robojax.com/L/?id=63

or make donation using PayPal http://robojax.com/L/?id=64

 *  * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see .


*/

const int inPin =A0;                     // can change
const int VCC2 =2;
const int iteration = 1000;              // can change (see video)
const float LM35_FACTOR =0.01;           // do not change

// start of settings for LCD1602 with I2C
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup()
{
  Serial.begin(9600);
  Serial.println("Robojax LM35 with LCD for Arduino");
  
  pinMode(VCC2,OUTPUT);
  digitalWrite(VCC2, HIGH);

  lcd.init();
  // lcd.begin();  
  lcd.backlight();
  lcd.print("Robojax LM35");
  lcd.setCursor(0,1);
  lcd.print("Temp: "); 
}


void loop()
{
  lcdDisplay(getTemperature('C'),'C');
  delay(2000);
  
  lcdDisplay(getTemperature('F'),'F');
  delay(2000);
    
  lcdDisplay(getTemperature('K'),'K');  
  delay(2000);    

  if (getTemperature('C') >87)
  {
    // do somethig here (watch video)
  }

//  printTemperature('C');
//  Serial.println();
//  printTemperature('F');
//  Serial.println();  
//  printTemperature('K'); 
//  Serial.println();     
//  Serial.println();    
//  Serial.print(" Temperature: ");
//  printDegree();    
//  Serial.print(getTemperature('C'));
//  Serial.println();
  delay(100);
}


/*
 * getTemperature()
 * @brief gets the average temperature
 * @param average temperature
 * @param "type" is character
 *     C = Celsius
 *     K = Kelvin
 *     F = Fahrenheit
 * @return returns one of the values above
 * Written by Ahmad Shamshiri for robojax.com
 * on May 08, 2020 at 02:36 in Ajax, Ontario, Canada
 */
float getTemperature(char type)
{
  float value;
  float averageTemperature =0;
  int sensorValue = analogRead(inPin);
  float voltage = sensorValue * (5.0 / 1023.0); 
  float temperature = voltage / LM35_FACTOR;
  
  for (int i=0; i< iteration; i++)
  {
    averageTemperature += temperature;
  }

  averageTemperature /=iteration;
  if (type =='F')
  {
    value = averageTemperature *9/5 + 32;    // convert to Fahrenheit 
  }
  else
    if (type =='K')
    {
      value = averageTemperature + 273.15;    // convert to Kelvin
    }
    else
    {
     value = averageTemperature;              // return Celsius
    }
    return value ;
} //getTemperature()


/*
 * printTemperature()
 * @brief prints  temperature on serial monitor
 * @param charact type
 * @param "type" is character
 *     C = Celsius
 *     K = Keliven
 *     F = Fahrenheit
 * @return none
 * Written by Ahmad Shamshiri for robojax.com
 * on May 08, 2020 at 02:45 in Ajax, Ontario, Canada
 */
void printTemperature(char type)
{
  float value;
  float temp = getTemperature(type);
  Serial.print(temp);
  printDegree();    
  
  if(type =='F')
  {
    Serial.print("F");
  }
  else
    if (type =='K')
    {
      Serial.print("K");
    }
    else
    {
     Serial.print("C");
    }    
} //printTemperature()


/*
 * @brief prints degree symbol on serial monitor
 * @param none
 * @return returns nothing
 * Written by Ahmad Shamshiri on July 13, 2019
 * for Robojax Tutorial Robojax.com
 */
void printDegree()
{
  Serial.print("\\xC2"); 
  Serial.print("\\xB0");  
}


/*
 * lcdDisplay(float value,char symbol)
 * displays value and title on LCD1602
 * How to use:
 * lcdDisplay(35.3,'C');
 */
void lcdDisplay(float value, char symbol)
{
  // Robojax.com LCD1602 for LM35 Demo   

  for (int i=7; i<16;i++)
  {
    lcd.setCursor(i,1);
    lcd.write(254);  
  }
  lcd.setCursor (7,1); //
  lcd.print(value);
  lcd.print((char)223);    

  if (symbol =='F')
  {
    lcd.print("F");
  }
  else
   if (symbol =='K')
   {
     lcd.print("K");
   }
   else
   {
    lcd.print("C");    
   }
}
