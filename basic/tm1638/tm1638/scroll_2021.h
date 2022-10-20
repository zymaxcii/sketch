// Header file "scroll_2021.h":

// scroll "2021"
void scroll_2021()
{
  setDisplay(digit[1], 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(digit[2], 0); setDisplay(digit[1], 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(digit[0], 0); setDisplay(digit[2], 1); setDisplay(digit[1], 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(digit[2], 0); setDisplay(digit[0], 1); setDisplay(digit[2], 2); setDisplay(digit[1], 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(digit[2], 1); setDisplay(digit[0], 2); setDisplay(digit[2], 3);
  setDisplay(digit[1], 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(digit[2], 2); setDisplay(digit[0], 3);
  setDisplay(digit[2], 4); setDisplay(digit[1], 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(digit[2], 3);
  setDisplay(digit[0], 4); setDisplay(digit[2], 5); setDisplay(digit[1], 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(digit[2], 4); setDisplay(digit[0], 5); setDisplay(digit[2], 6); setDisplay(digit[1], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(digit[2], 5); setDisplay(digit[0], 6); setDisplay(digit[2], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(digit[2], 6); setDisplay(digit[0], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(digit[2], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
}
