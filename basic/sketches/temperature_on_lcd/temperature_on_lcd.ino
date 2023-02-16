#include <LiquidCrystal.h>
#include DHT.h

#define DHTPIN 8
#define DHTTYPE DHT22

LiquidCrystal lcd(12,11,5,4,3,2);
DHT dht(DHTPIN,DHTTYPE);



void setup() {
  // put your setup code here, to run once:

lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:

float f=dht.readTemperature(true);
float h=dht.readHumidity();
lcd.setCursor(0,0);
lcd.print("Temp.:    ");
lcd.print(f);
lcd.print("F");
lcd.setCursor(0,1);
lcd.print("Humidity: ");
lcd.print(h);
lcd.print("%");
delay(3000);

}
