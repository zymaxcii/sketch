// lcdi2c_scanOven.ino
// Simulate oven alarm system using i2c version of lcd 2004A
// logic not working yet

// My standard hardware setup
// Uno: pins sda, scl; gnd and vcc

#include <LiquidCrystal_I2C.h>

void monitorOven();

// address at 0x27
LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup()
{
  lcd.init();                       // initialize the lcd
  lcd.backlight();                  // turn backlight on
  
  // Print a message to the LCD
  // lcd.print("hello, yang fan!");
  // lcd.display();
  // delay(5000);
  // lcd.noDisplay();

  lcd.setCursor(0, 0);
  lcd.print("Oven Alarm System");
  lcd.setCursor(0, 1);
  lcd.print("Texas Instrument");
  lcd.setCursor(0, 2);
  lcd.print("Singapore");
  delay(1000);
  
  lcd.clear();
  lcd.print("Scanning ovens...");
  delay(1000);

  // Test message
  Serial.begin(9600);
  Serial.println("Testing in progress...\n");
}


void loop()
{
//  // Turn off the display:
//  lcd.noDisplay();
//  delay(500);
//   // Turn on the display:
//  lcd.display();
//  delay(500);

  monitorOven();
}


void monitorOven()
{
  int numOven = 20;
  int i = 1;                         // counter
  char prefix[16] = "Scan oven ";
  char msg[16];
  char ovenNum[2];
  sprintf(ovenNum, "%d", i);
  strcat(msg, prefix);
  strcat(msg, ovenNum);
  
  for (i=1; i<numOven+1; i++)
  {
   
    //    lcd.clear();
    //    sprintf(ovenNum, "%d", i);
    //    strcat(msg, prefix);
    //    strcat(msg, ovenNum);
    //    lcd.print(msg);
    //    delay(5000);

    lcd.clear();
    lcd.print("Scan oven 1");
    delay(500);
    lcd.print(" ok");
    delay(5000);

    lcd.clear();
    lcd.print("Scan oven 2");
    delay(500);
    lcd.print(" ok");
    delay(5000);

    lcd.clear();
    lcd.print("Scan oven 3");
    delay(500);
    lcd.print(" ok");
    delay(5000);

    lcd.clear();
    lcd.print("End of current scan");
    delay(500);
    lcd.clear();
    lcd.print("Re-scanning...");
    delay(2000);
  }
}
