// https://www.brainy-bits.com/post/arduino-nema-stepper-control-with-joystick-and-limit-switches
// https://www.youtube.com/watch?v=3odRT6zdzqk


#define step_pin 9  // Pin 9 connected to Steps pin on EasyDriver
#define dir_pin 8   // Pin 8 connected to Direction pin
#define MS1 10       // Pin 10 connected to MS1 pin
#define MS2 11       // Pin 11 connected to MS2 pin
#define SLEEP 12     // Pin 12 connected to SLEEP pin

#define X_pin A0    // Pin A0 connected to joystick x axis
#define Joy_switch 4  // Pin 4 connected to joystick switch

#define Limit01 2  // Pin 2 connected to Limit switch out
#define Limit02 3  // Pin 3 connected to Limit switch out

int step_speed = 10;  // Speed of Stepper motor (higher = slower)

void setup() {
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(step_pin, OUTPUT);
   pinMode(SLEEP, OUTPUT);
   
   pinMode(Limit01, INPUT);
   pinMode(Limit01, INPUT);
   
   pinMode(Joy_switch, INPUT_PULLUP);
   
   digitalWrite(SLEEP, HIGH);  // Wake up EasyDriver
   delay(5);  // Wait for EasyDriver wake up
   

/* Configure type of Steps on EasyDriver:
// MS1 MS2
//
// LOW LOW = Full Step //
// HIGH LOW = Half Step //
// LOW HIGH = A quarter of Step //
// HIGH HIGH = An eighth of Step //
*/

   digitalWrite(MS1, LOW);      // Configures to Full Steps
   digitalWrite(MS2, LOW);    // Configures to Full Steps
}

void loop() {
  if (!digitalRead(Joy_switch)) {  //  If Joystick switch is clicked
    delay(500);  // delay for deboucing
    switch (step_speed) {  // check current value of step_speed and change it
      case 1:
        step_speed=10;  // slow speed
        break;
      case 3:
        step_speed=1;  // fast speed
        break;
      case 10:
        step_speed=3;  // medium speed
        break;
    }
  }    
    
  if (analogRead(X_pin) > 712) {  //  If joystick is moved Left
    if (!digitalRead(Limit01)) {}  // check if limit switch is activated
    
      else {  //  if limit switch is not activated, move motor clockwise
      
        digitalWrite(dir_pin, LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
        digitalWrite(step_pin, HIGH);
        delay(step_speed);
        digitalWrite(step_pin, LOW);
        delay(step_speed);
    }      
  }
  
    if (analogRead(X_pin) < 312) {  // If joystick is moved right
    
    if (!digitalRead(Limit02)) {}  // check if limit switch is activated
    
      else {  //  if limit switch is not activated, move motor counter clockwise
      
        digitalWrite(dir_pin, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
        digitalWrite(step_pin, HIGH);
        delay(step_speed);
        digitalWrite(step_pin, LOW);
        delay(step_speed);
    }      
  }
}
