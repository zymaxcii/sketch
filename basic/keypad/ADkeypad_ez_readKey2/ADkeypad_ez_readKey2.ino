// ADkeypad_ez_readKey2.ino
// status: compile ok, upload ok
// but not working properly
// 1 click returns 2 or 3 presses
// need to debug


#include <ezAnalogKeypad.h>
// #include <Keyboard.h>

#define PIN_ANALOG_KEYPAD_5BUT A0

ezAnalogKeypad keypad_5but(PIN_ANALOG_KEYPAD_5BUT);


void setup()
{
  Serial.begin(9600);

  keypad_5but.setNoPressValue(1023);  // analog value when no key is pressed
  keypad_5but.registerKey('w', 140);  // sw2 (up) 119
  keypad_5but.registerKey('z', 320);   // sw3 (down) 122
  keypad_5but.registerKey('a', 0);    // sw1 (left) 97
  keypad_5but.registerKey('d', 501);   // sw4 (right) 100
  keypad_5but.registerKey('s', 736);   // sw5 (but) 115

  keypad_5but.setDebounceTime(200);    // critical, original set to 100

  // Keyboard.begin();
}


void loop()
{
  // Serial.println(analogRead(PIN_ANALOG_KEYPAD_5BUT));

  unsigned char button_k5 = keypad_5but.getKey();
  
  if (button_k5)
  {
    Serial.print("The button ");
    Serial.print(char(button_k5));
    Serial.println(" is pressed");
    
    switch (button_k5)
    {
      case 'w':
        Serial.println("UP");
        //Keyboard.press(KEY_UP_ARROW);
        break;
      case 'z':
        Serial.println("DOWN");
        //Keyboard.press(KEY_DOWN_ARROW);
        break;
      case 'a':
        Serial.println("LEFT");
        //Keyboard.press(KEY_LEFT_ARROW);
        break;
      case 'd':
        Serial.println("RIGHT");
        //Keyboard.press(KEY_RIGHT_ARROW);
        break;
      case 's':
        Serial.println("p");
        //Keyboard.press('p');
        break;
      default:
        break;
    }
    delay(100);
    //Keyboard.releaseAll();
  }
}
