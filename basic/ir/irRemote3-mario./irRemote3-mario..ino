// ir_Remote3-mario.ino
// fail to compile, to rename

// https://www.instructables.com/Beginners-Guide-to-Use-an-IR-Remote-Transmitter-an/


/*  
 *  IR REMOTE CONTROL + RGB 
 *  by Hanie Kiani 
 *  https://electropeak.com/learn/    
*/ 

// hardware setup
//


#include <IRremote.h>
#include <Keyboard.h>

int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN); 
decode_results results; 


void setup() 
{ 
  Serial.begin(9600); 
  irrecv.enableIRIn();                         // Start the receiver 
  Keyboard.begin(); 
} 


void loop()
{
  if (irrecv.decode(&results))  
  {
    int value = results.value; 
    Serial.println(value);          

    switch(value) 
    { 
                                                       // Backward key is used for left key operation                  
      case 8925:
        Keyboard.press(KEY_LEFT_ARROW);
        // Keyboard.press(KEY_LEFT_ARROW);                // left key 
        delay(100); 
        Keyboard.releaseAll(); 
        break; 

                                                       // Forward Key is used for right key operation 
      case 765:
        Keyboard.press(KEY_RIGHT_ARROW);               // right  key 
        delay(100); 
        Keyboard.releaseAll(); 

                                                       // Play Key is used for up key operation  
      case -15811:
        Keyboard.press(KEY_UP_ARROW);                  // up key 
        delay(100); 
        Keyboard.releaseAll(); 
        break;                         
    }   

    irrecv.resume();                                   // Receive the next value 
  } 
}
