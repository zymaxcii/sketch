/*  Temp Display 2 Digit 7 Segment
 *  learnelectronics
 *  09 Jan 17
 */



#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN            3
#define DHTTYPE           DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);
//-------------------------------------------------



//RIGHT DIGIT
const int latchPin2 = 12;        //Pin 12 connected to 12 of 74HC595
const int clockPin2 = 8;         //Pin  8 connected to 11 of 74HC595 
const int dataPin2 = 11;         //Pin 11 connected to 14 of 74HC595 

//LEFT DIGIT
const int latchPin1 = 7;        //Pin 7 connected to 12 of 74HC595
const int clockPin1 = 6;         //Pin  6 connected to 11 of 74HC595 
const int dataPin1 = 5;         //Pin 5 connected to 14 of 74HC595

//-------------------------------------------------

const int zero=252;
const int one=96;
const int two=218;
const int three=242;
const int four=102;
const int five=182;
const int six=190;
const int seven=224;
const int eight=254;
const int nine=246;
int val;
//-------------------------------------------------



void setup() {
  dht.begin();
  pinMode(latchPin1,OUTPUT);
  pinMode(clockPin1,OUTPUT);
  pinMode(dataPin1,OUTPUT);
  pinMode(latchPin2,OUTPUT);
  pinMode(clockPin2,OUTPUT);
  pinMode(dataPin2,OUTPUT);
  pinMode(3,INPUT);
  
}

void loop() {
  

sensors_event_t event;  
dht.temperature().getEvent(&event);
val = (event.temperature)*1.8+32;
ledDraw();
delay(2000);
}



void ledDraw(){

switch (val) {
    case 0:
      digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 1:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 2:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 3:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 4:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 5:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 6:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 7:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 8:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 9:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,zero);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 10:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 11:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 12:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 13:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 14:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 15:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 16:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 17:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 18:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 19:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,one);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
   case 20:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 21:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 22:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 23:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 24:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 25:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 26:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 27:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 28:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 29:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,two);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
      case 30:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 31:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 32:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 33:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 34:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 35:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 36:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 37:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 38:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 39:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,three);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 40:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 41:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 42:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 43:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 44:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 45:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 46:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 47:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 48:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 49:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,four);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 50:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 51:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 52:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 53:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 54:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 55:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 56:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 57:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 58:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 59:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 60:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 61:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 62:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 63:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 64:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 65:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 66:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 67:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 68:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 69:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,five);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 70:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 71:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 72:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 73:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 74:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 75:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 76:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 77:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 78:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 79:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,seven);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 80:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 81:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 82:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 83:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 84:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 85:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 86:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 87:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 88:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 89:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,eight);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 90:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,zero);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 91:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,one);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 92:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,two);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 93:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,three);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 94:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,four);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 95:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,five);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 96:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,six);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 97:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,seven);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 98:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,eight);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
    case 99:
       digitalWrite(latchPin1,LOW);
      digitalWrite(latchPin2,LOW);
      shiftOut(dataPin1,clockPin1,MSBFIRST,nine);
      shiftOut(dataPin2,clockPin2,MSBFIRST,nine);
      digitalWrite(latchPin1,HIGH);
      digitalWrite(latchPin2,HIGH);
      break;
   
  }
}




