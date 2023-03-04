// re_test.ino
// Test rotary encoder
// status: compile ok, upload 


// https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
// https://www.youtube.com/watch?v=v4BbSzJ-hz4


/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
*/


#define outputA 6
#define outputB 7

int counter = 0; 
int aState;
int aLastState;  


void setup()
{
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  
  Serial.begin (9600);
  // Reads initial state of the outputA
  aLastState = digitalRead(outputA);   
} 


void loop()
{ 
  aState = digitalRead(outputA);
  
  // states are different, that means a Pulse has occured
  if (aState != aLastState)
  {     
  // If outputB is different to outputA, means encoder is rotating clockwise
    if (digitalRead(outputB) != aState)
    {
      counter ++;
    }
    else
    {
      counter --;
    }
    
    Serial.print("Position: ");
    Serial.println(counter);
  } 
  aLastState = aState;   // Update state
}
