#include <DS3231.h>
#include <Wire.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <Adafruit_BMP085.h>

#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10



Adafruit_BMP085 bmp;
MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);
DS3231 Clock;

byte year, month, date, DoW, hour, minute, second;


void setup() {

  Serial.begin(9600);
  Wire.begin();
  P.begin();
  P.setInvert(false);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }

}

void loop() {

int temp = bmp.readTemperature();
float pres = bmp.readPressure();
Clock.getTime(year, month, date, DoW, hour, minute, second);
 String mytime = String(hour)+":"+String(minute);
 P.print(mytime);
 delay(3000);
 String mytemp = String(temp)+"C";
 P.print(mytemp);
 delay(3000);
 float presx = pres * 0.0002953;
 String mypress = String(presx)+"in";
 P.print(mypress);
 delay(3000);
 Serial.println(pres);
}
