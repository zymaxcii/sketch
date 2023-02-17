// keypad_i2clcd_calculator.ino
// status: compile ok, upload ok

// https://maker.pro/arduino/projects/how-to-create-an-arduino-controlled-calculator

#include<Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', 'C'},
  {'*', '0', '=', '/'}
};

// byte rowPins[ROWS] = {26, 27, 28, 29};
// byte colPins[COLS] = {22, 23, 24, 25};

byte colPins[COLS] = {26, 27, 28, 29};    // R1 to R4
byte rowPins[ROWS] = {22, 23, 24, 25};    // L1 to L4


// Created instances
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2);

boolean firstNumState = true;
String firstNum = "";
String secondNum = "";
float result = 0.0;
char operatr = ' ';

void setup() {
  // lcd.begin();

  lcd.init();
  lcd.backlight();  
  
  lcd.setCursor(0, 0);
  lcd.print("Arduino Calculator");
  lcd.setCursor(0, 1);
  lcd.print("by MakerPro");
  delay(1000);
  scrollDisplay();
  clr();
}

void loop() {
  char newKey = myKeypad.getKey();
  if (newKey != NO_KEY && (newKey == '1' || newKey == '2' || newKey == '3' || newKey == '4' || newKey == '5' || newKey == '6' || newKey == '7' || newKey == '8' || newKey == '9' || newKey == '0')) {

    if (firstNumState == true) {
      firstNum = firstNum + newKey;

      lcd.print(newKey);
    }
    else {
      secondNum = secondNum + newKey;

      lcd.print(newKey);
    }
  }
  if (newKey != NO_KEY && (newKey == '+' || newKey == '-' || newKey == '*' || newKey == '/')) {
    if (firstNumState == true) {
      operatr = newKey;
      firstNumState = false;
      lcd.setCursor(15, 0);
      lcd.print(operatr);
      lcd.setCursor(5, 1);
    }
  }

  if (newKey != NO_KEY && newKey == '=') {
    if (operatr == '+') {
      result = firstNum.toFloat() + secondNum.toFloat();
    }

    if (operatr == '-') {
      result = firstNum.toFloat() - secondNum.toFloat();
    }

    if (operatr == '*') {
      result = firstNum.toFloat() * secondNum.toFloat();
    }

    if (operatr == '/') {
      result = firstNum.toFloat() / secondNum.toFloat();
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(firstNum);
    lcd.print(operatr);
    lcd.print(secondNum);
    lcd.setCursor(0, 1);
    lcd.print("=");
    lcd.print(result);
    firstNumState = true;
  }

  if (newKey != NO_KEY && newKey == 'C') {
    clr();
  }
}

void scrollDisplay() {
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }
  delay(1000);

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }
  delay(2000);
}

void clr() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1st: ");
  lcd.setCursor(12, 0);
  lcd.print("op ");
  lcd.setCursor(0, 1);
  lcd.print("2nd: ");
  lcd.setCursor(5, 0);
  firstNum = "";
  secondNum = "";
  result = 0;
  operatr = ' ';
}
