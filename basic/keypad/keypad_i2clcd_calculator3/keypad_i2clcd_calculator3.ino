// keypad_i2clcd_calculator3.ino
// status: compile ok, upload ok
// code is cleaner than the others
// but still far from a cheap calculator

// https://www.youtube.com/watch?v=JUmno7PdRic


#include "LiquidCrystal_I2C.h"
#include "Keypad.h"

const int ROW_NUM = 4; 
const int COLUMN_NUM = 4; 

char keys[ROW_NUM][COLUMN_NUM] = 
{
  {'1','2','3', '+'},
  {'4','5','6', '-'},
  {'7','8','9', '*'},
  {'C','0','=', '/'}          
};

byte pin_rows[ROW_NUM]      = {22, 23, 24, 25};    // L1 to L4
byte pin_column[COLUMN_NUM] = {26, 27, 28, 29};   // R1 to R4

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

LiquidCrystal_I2C lcd(0x27, 20, 4);

String input;
int counter;
long fn;
char op;
const int maxLength=5;

void setup() 
{
  lcd.init();
  lcd.backlight();
  Reset();
}


void loop() 
{
  char key = keypad.getKey();

  if (key)
  {
    if(IsNumber(key))
    {
      ProcessNumber(key);
    }
    else if(IsOperator(key))
    {
      ProcessOperator(key);
    }
    else if(key == '=')
    {
      Calculate(key);
    }
    else if(key == 'C')
    {
      Reset();
    }
  }
}


void ClearScreen()
{
  lcd.setCursor(0,0);
  lcd.print("                  ");
  lcd.print("                  ");
  lcd.print("                  ");
  lcd.print("                  ");
}


void Reset()
{
  counter = 0;
  op = ' ';
  input.remove(0);
  ClearScreen();
}


void ProcessNumber(char key)
{
  if (counter >= maxLength)
  return;
  
  counter++;
  input += key;
  
  if (op == ' ')  
   lcd.setCursor(2,0);
  else
    lcd.setCursor(2,1);
    lcd.print(input);
}


void ProcessOperator(char key)
{
  if (input.length() <= 0) return;

  if (op != ' ') return;

  counter = 0;
  op = key;

  lcd.setCursor(0,1);
  lcd.print(op);

  fn = input.toInt();
  input.remove(0);
}


void Calculate(char key)
{
  if (input.length() <= 0) return;

  long sn = input.toInt();
  long result = DoOperation(op,fn,sn);

  lcd.setCursor(0,3);
  lcd.print("= ");
  lcd.print(result);
}


bool IsNumber(char key)
{
  if (key >= '0' && key <= '9') return true;
  return false;
}


bool IsOperator(char key)
{
  if (key == '+' || key == '-' || key == '*'||key == '/' ) return true;
  return false;
}


long DoOperation(char key , long a ,long b)
{
  if (key == '+') return a + b;

  if (key == '-') return a - b;

  if (key == '*') return a * b;

  if (key == '/') return a / b;
}
