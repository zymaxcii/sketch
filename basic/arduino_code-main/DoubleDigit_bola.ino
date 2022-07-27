#define DATA 6
#define LATCH 8
#define CLOCK 10
int digits[] = {252,96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};

void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}
void displayNumber(int n)
{
  int left, right = 0;
  if (n<10)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[n]);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
  else if (10>=10)
  {
    right = n % 10;
    left = n / 10;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[right]);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[left]);
    digitalWrite(LATCH, HIGH);
  }
}
void loop()
{
  int i;
  for (i = 0; i < 100; i++)
  {
    displayNumber(i);
    delay(100);
  }
}
