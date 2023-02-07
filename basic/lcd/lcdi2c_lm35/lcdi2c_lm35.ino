// lcdi2c-lm35.ino
// Display temperature readings on I2C 2004 LCD
// not accurate, on the lower side
// status: compile ok, upload ok

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20, 4);

const long eventTime_Tem = 2000;              // delay time
unsigned long previousTime_Tem = 0; 
int x;
unsigned long temptot = 0;


void setup()
{
  Serial.begin(9600);

  // INTERNAL was not declared in this scope
  analogReference(INTERNAL);                  // set reference of 1.1V
  lcd.init();
  lcd.backlight();
}


void loop()
{
  int x;
  unsigned long currentTime = millis();        // assigning the value of mills
  unsigned long temptot = 0;
  
  // taking 100 sample and adding
  for (x=0; x<100 ; x++)
  {
    temptot += analogRead(A0);
    // delay(50);
  }

  float  sensorValue = temptot/100;            // calculating average
  float voltage = sensorValue * (1100 / 1023); // convert sensor reading into milli volt
  float temp = voltage*0.1;                    // convert milli volt to Celsius 
  float tempf = 1.8 * temp + 32;               // converting Celsius to Fahrenheit  
  
  // Check for delay time
  if (currentTime-previousTime_Tem >= eventTime_Tem)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.setCursor(5,0);
    lcd.print("'C");
    lcd.setCursor(0,1);
    lcd.print(tempf);
    Serial.println(temp);
    lcd.setCursor(5,1);
    lcd.print("'F");
    Serial.println(tempf);
    previousTime_Tem = currentTime;
  }
}
