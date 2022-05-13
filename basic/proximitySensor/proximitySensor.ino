//


unsigned int IRpin = 3;
unsigned int Indicatorpin = 13;

void blink_indicator()
{
  digitalWrite(Indicatorpin, HIGH);
  delay(200);

  digitalWrite(Indicatorpin, LOW);
  delay(200);
}


void setup()
{
  pinMode(IRpin, INPUT);          // need INPUT_PULLUP?
  pinMode(Indicatorpin, OUTPUT);
}


void loop()
{
  if (digitalRead(IRpin) == LOW)
  { 
  blink_indicator();
  }
  else
  {
    digitalWrite(Indicatorpin, LOW);
  }
}

