// piezo.ino

// https://electronics.stackexchange.com/questions/37525/piezo-barely-audible

#include <Servo.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
const byte PINLENGTH = 4;

char keys[ROWS][COLS] =
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {8, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char PIN[PINLENGTH]={'2','5','8','0'};
char attempt[PINLENGTH] = {0,0,0,0};
int z=0;

Servo lock;
int pos = 0;

int pinSpeaker = 11;

int redLED = 12;
int grnLED = 13;
boolean armed = true;


void setup()
{
  pinMode(pinSpeaker, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(grnLED, OUTPUT);
  
  Serial.begin(9600);
  resetLock();
  Serial.println("* SYSTEM ARMED *");
  Serial.println("  Ready...");
}


void resetLock()
{
  lock.attach(9);
  for(pos=20; pos>0; pos-=1)
  {
    lock.write(pos);
    delay(15);
  }
  lock.detach();
}


void closeLock()
{
  lock.attach(9);
  for(pos=lock.read(); pos>=1; pos-=1)
  {
    lock.write(pos);
    delay(15);
  }
  lock.detach();
}


void openLock()
{
  lock.attach(9);
  for(pos=lock.read(); pos<100; pos+=1)
  {
    lock.write(pos);
    delay(15);
  }
  lock.detach();
}


void correctPIN()
{
  armed = false;
  playTone(750, 2500);
  openLock();
  Serial.println("* SYSTEM DISARMED *");
  Serial.println("  Ready...");
}


void incorrectPIN()
{
  playTone(750, 1000);
  Serial.println(" * Incorrect PIN *");
  z = 0;
  Serial.println("  Ready...");
}


void checkPIN()
{
  int correct = 0;
  for (int q=0; q<PINLENGTH; q++)
  {
    if (attempt[q]==PIN[q])
    {
      correct++;
    }
  }

  if (correct==PINLENGTH)
  {
    correctPIN();
  }
  else
  {
    incorrectPIN();
  }

  for (int zz=0; zz<PINLENGTH; zz++)
  {
    attempt[zz]=0;
  }
}


void readKeypad()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    switch(key)
    {
    case '*':
      if(armed==false)
      {
        armed=true;
        playTone(750, 1000);
        closeLock();
        Serial.println("* SYSTEM ARMED *");
        Serial.println("  Ready...");
      }
      z=0;
      break;
      
    case '#':
      if(armed==true)
      {
        Serial.print("\n");
        delay(100);
        checkPIN();
      }
      break;
      
    default:
      if(armed==true)
      {
        playTone(250, 2000);
        Serial.print(key);
        attempt[z]=key;
        z++;
      }
    }
  }
}


void playTone(long duration, int freq)
{
  duration *=1000;
  int period = (1.0 / freq) * 1000000;
  long elapsed_time = 0;
  
  while (elapsed_time < duration)
  {
    digitalWrite(pinSpeaker, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pinSpeaker, LOW);
    elapsed_time += (period);
  }
}


void loop()
{
  if(armed==true)
  {
    digitalWrite(grnLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else
  {
    digitalWrite(redLED, LOW);
    digitalWrite(grnLED, HIGH);
  }
  readKeypad();
}
