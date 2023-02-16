/* Multiple State Handling
 *  learnelectronics
 *  01-04-2017
 */



#define button 3                      //Push button on D3
#define redLED 5                      //red LED on D5
#define greenLED 6                    //green LED on D6
#define yellowLED 7                   //yellow LED on D7
/-----------------------------------------------------------------------
int state = 0;                        //integer to hold current state
int old = 0;                          //integer to hold last state
int buttonPoll = 0;                   //integer to hold button state
/-----------------------------------------------------------------------

void setup() {
  pinMode(button,INPUT);              //button set as input
  pinMode(redLED,OUTPUT);             //LEDs set as outputs
  pinMode(greenLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);

  digitalWrite(redLED,LOW);           //set initial state as off
  digitalWrite(greenLED,LOW);         //set initial state as off
  digitalWrite(yellowLED,LOW);        //set initial state as off

}
/-----------------------------------------------------------------------
void loop() {

                                      //debouncing routine to read button
   buttonPoll = digitalRead(button);  //poll the state of button
  if(buttonPoll == 1){                //check if it has been pressed
    delay(50);                        //wait 50ms
    buttonPoll = digitalRead(button); //poll button again
    if(buttonPoll == 0){              //if it is 0 considered one press
      state = old + 1;                //increase state by 1
  }}
  else{                               //if button has not been pressed
  delay(100);                         //wait 100ms
  }
  switch (state) {                    //react to button press & state
    case 1:                           // if state is 1
      digitalWrite(redLED,HIGH);      //red LED on
      digitalWrite(greenLED,LOW);     //geen LED off
      digitalWrite(yellowLED,LOW);    //yellow led off
      old = state;                    // set old state as current state
      break;
    case 2:
      digitalWrite(redLED,LOW);
      digitalWrite(greenLED,HIGH);
      digitalWrite(yellowLED,LOW);
      old = state;
      break;
    case 3:
      digitalWrite(redLED,LOW);
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED,HIGH);
      old = state;
      break;  
    default:                          //if state is not 1,2,3
      digitalWrite(redLED,LOW);       //all LEDs off
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED,LOW);
      old = 0;                        //reset to all off/state 0
    break;
  }
}
