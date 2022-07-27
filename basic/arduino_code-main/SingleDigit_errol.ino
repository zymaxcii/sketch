int DATA = 6;
int LATCH = 8;
int CLOCK = 10;
int digits[] = {252,96,218,242,102,182,190,224,254,246,238,62,156,122,158,142};

void setup() {
    pinMode(LATCH, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(DATA, OUTPUT);
}
void loop() {
  int i;
  for(i=0; i<16; i++){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
    digitalWrite(LATCH, HIGH);
    delay(250);
  }
  for(i=0; i<16; i++){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i]+1);
    digitalWrite(LATCH, HIGH);
    delay(250);
  }
}
