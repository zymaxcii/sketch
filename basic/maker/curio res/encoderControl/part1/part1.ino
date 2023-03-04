// part1.ino
// Read encoder outputs
// Remove cover use hand to adjust encoder outputs
// no interrupt

#define ENCA 2 // Yellow
#define ENCB 3 // White

void setup()
{
  Serial.begin(9600);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
}


void loop()
{
  int a = digitalRead(ENCA);
  int b = digitalRead(ENCB);

  Serial.print(a*5);  // easier to read by times 5
  Serial.print(" ");

  Serial.print(b*5);
  Serial.println();
}
