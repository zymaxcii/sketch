// pololu.ino
// no speed control
// rotate in one direction for 3 secs
// then rotate in the opposite direction for 3 secs

int motor1pin1 = 4;
int motor1pin2 = 7;

// only 1 motor
//int motor2pin1 = 4;
//int motor2pin2 = 5;


void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  
  //  pinMode(motor2pin1, OUTPUT);
  //  pinMode(motor2pin2, OUTPUT);
}


void loop() {
    
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  //  digitalWrite(motor2pin1, HIGH);
  //  digitalWrite(motor2pin2, LOW);
  
  delay(3000);

  // reverse direction
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  //  digitalWrite(motor2pin1, LOW);
  //  digitalWrite(motor2pin2, HIGH);
  
  delay(3000);
}
