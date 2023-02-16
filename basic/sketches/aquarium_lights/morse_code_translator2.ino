/*
 * Morse Code Translator
 * Takes serial input & translates it
 * into Morse Code which is then sent
 * to a buzzer & LED
 * 
 * 
 * by learnelectronics
 * 15 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * 
 * NOTE: INPUT MUST BE IN CAPS
 */

//-------------------------------------------------------------------------------------------------
//                                           LIBRARIES
//-------------------------------------------------------------------------------------------------

//NO LIBRARIES NECESSARY

//-------------------------------------------------------------------------------------------------
//                                            DEFINES
//-------------------------------------------------------------------------------------------------

//NO DEFINES NECESSARY

//-------------------------------------------------------------------------------------------------
//                                           VARIABLES
//-------------------------------------------------------------------------------------------------

String mCode = "";                                //string to store serial inut
byte mCodeLength = 0;                             //byte to store length of mCode
byte space = 150;                                 //delay for spacing
char i;                                           //char for parsing of mCode



//-------------------------------------------------------------------------------------------------
//                                             SETUP
//-------------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);                             //start serial comms for debuging
  pinMode(6,OUTPUT);                              //pin 6 (buzzer) set for OUTPUT
  pinMode(12,OUTPUT);                             //pin 12 (LED) set for OUTPUT
}

//-------------------------------------------------------------------------------------------------
//                                          FUNCTIONS
//-------------------------------------------------------------------------------------------------

void dot(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(50);                                     //on for 100ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(100);                                     //wait for 100ms
}

void dash(){
  digitalWrite(6,HIGH);                           //buzzer on
  digitalWrite(12,HIGH);                          //LED on
  delay(150);                                     //on for 300ms
  digitalWrite(6,LOW);                            //buzzer off
  digitalWrite(12,LOW);                           //LED off
  delay(100);                                     //wait for 100ms
}






void translate(){                                 //translate characters to Morse Code
  switch(i){
    case 'A':                                     //if it is A
      dot();                                      //do a dot
      delay(space);                               //wait
      dash();                                     //do a dash
      delay(space);                               //wait
    break;
    case 'B':
      dash();
      dot();
      delay(space);
      dot();
      delay(space);
      dot();
      delay(space);
     break;
     case 'C':
       dash();
      delay(space);
       dot();
      delay(space);
       dash();
      delay(space);
      dot();
      delay(space);
     break;
     case 'D':
       dash();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
     break;
     case 'E':
       dot();
       delay(space);
     break;
     case 'F':
       dot();
       delay(space);
       dot();
       delay(space);
       dash();
       delay(space);
     break;
     case 'G':
       dash();
       delay(space);
       dash();
       delay(space);
       dot();
       delay(space);
      break;
      case 'H':
       dot();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
      break;
      case 'I':
       dot();
       delay(space);
       dot();
       delay(space);
      break;
      case 'J':
       dot();
       delay(space);
       dash();
       delay(space);
       dash();
       delay(space);
       dash();
       delay(space);
      break;
      case 'K':
       dash();
       delay(space);
       dot();
       delay(space);
       dash();
       delay(space);
      break;
      case 'L':
       dot();
       delay(space);
       dash();
       delay(space);
       dot();
       delay(space);
       dot();
       delay(space);
      break;
      case 'M':
       dash();
       delay(space);
       dash();
       delay(space);
       break;
       case 'N':
        dash();
        delay(space);
        dot();
        delay(space);
       break;
       case 'O':
        dash();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
       break;
       case 'P':
        dot();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
       break;
       case 'Q':
        dash();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
       case 'R':
        dot();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
       break;
       case 'S':
        dot();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
       break;
       case 'T':
        dash();
        delay(space);
       break;
       case 'U':
        dot();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
       case 'V':
        dot();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
       case 'W':
        dot();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
       break;
       case 'X':
        dash();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
       break;
       case 'Y':
        dash();
        delay(space);
        dot();
        delay(space);
        dash();
        delay(space);
        dash();
        delay(space);
       break;
       case 'Z':
        dash();
        delay(space);
        dash();
        delay(space);
        dot();
        delay(space);
        dot();
        delay(space);
       break;
       default:
         delay(250);
       break;
   
  }
}

void doString(){                                  //parse the string
  mCodeLength = mCode.length();                   //get the length of the string
  for(int x = 0;x<=mCodeLength;x++){              //repeat until reach end of string
    i = mCode.charAt(x);                          //get character at pos x
    translate();                                  //translate character to Morse Code
  }
}
//-------------------------------------------------------------------------------------------------
//                                              LOOP
//-------------------------------------------------------------------------------------------------

void loop() {
 while (Serial.available()) {                     //when something comes through serial
    char inChar = (char)Serial.read();            //get the new byte
    mCode += inChar;                              // add it to mCode
    if (inChar == '\n') {                         //if receive as CR
      Serial.println(mCode);
      doString();                                 //process the string
  }
                                       
 }
   delay(1000);                                    //delay between strings
   mCode = "";                                     //reset string
}







