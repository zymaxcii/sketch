// https://www.youtube.com/watch?v=qEw8cHM6VXU
// http://educ8s.tv/arduino-easy-module-shield/

   //////////////////////////////////////////////
  //   Easy Module Shield Weather Station     //
 //                                          //
//           http://www.educ8s.tv           //
/////////////////////////////////////////////

#include "DHT.h"
#include <LiquidCrystal_I2C.h>


#define DHTPIN 4   
#define DHTTYPE DHT11 

float humidity = 0;
float temperature = 0;
float light = 0;

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup()  
{
  dht.begin();
  lcd.begin(20,4); 
  printText();
}

void loop() 
{
  readHumidity();
  readTemperature();
  readLight();
  printData();
  delay(1000);
}

void printText()
{
  lcd.setCursor(2,0);
  lcd.print("Weather Station");
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.setCursor(18,1);
  lcd.print((char)223); //Degrees symbol
  lcd.print("C");
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.setCursor(19,2);
  lcd.print("%");
  lcd.setCursor(0,3);
  lcd.print("Light: ");
  lcd.setCursor(19,3);
  lcd.print("%");
}

void readHumidity()
{
    humidity = dht.readHumidity();
}

void readTemperature()
{
  temperature = dht.readTemperature(); //Celsius
}

void readLight()
{
  light = analogRead(A1);
  light = map(light,200,1023,0,100);
}

void printData()
{
  lcd.setCursor(13,1);
  lcd.print(temperature);
  lcd.setCursor(13,2);
  lcd.print(humidity);
  lcd.setCursor(13,3);
  lcd.print(light);
}

