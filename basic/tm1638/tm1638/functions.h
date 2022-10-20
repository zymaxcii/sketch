// Header file "functions.h":

// Convert frequency value to display characters
void value2DispConv(int n)
{
  for (int i=0; i<=n; i++)
  {
    switch(value[i])
    {
      case 0: value[i] = digit[0]; break;
      case 1: value[i] = digit[1]; break;
      case 2: value[i] = digit[2]; break;
      case 3: value[i] = digit[3]; break;
      case 4: value[i] = digit[4]; break;
      case 5: value[i] = digit[5]; break;
      case 6: value[i] = digit[6]; break;
      case 7: value[i] = digit[7]; break;
      case 8: value[i] = digit[8]; break;
      case 9: value[i] = digit[9]; break;
    }
  }
}


// Frequency display on TM1638
void freqCounter()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  delay(200);
  buttons = readButtons();
  
  while (buttons == 0)
  {
    buttons = readButtons();
    if (FreqCount.available())
    {
      freq = FreqCount.read();

      for (int i=6; i>=0; i--)
      {
        value[i] = freq % 10;
        freq /= 10;
      } 
      value2DispConv(6);
    } 
    setDisplay(0x71, 0);
    for(int j=0; j<=6; j++) setDisplay(value[j], j+1);
  }
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// Temp & humidity display on TM1630
void tempHumidity()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  delay(200);
  buttons = readButtons();

  while (buttons == 0)
  {
    buttons = readButtons();
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    value[0] = (temp/10) % 10;
    value[1] = temp % 10;
    value[2] = (hum/10) % 10;
    value[3] = hum % 10;
    value2DispConv(3);
    setDisplay(value[0], 0);
    setDisplay(value[1], 1);
    setDisplay(0x39, 2);
    setDisplay(0x40, 3);
    setDisplay(0x40, 4);
    setDisplay(value[2], 5);
    setDisplay(value[3], 6);
    setDisplay(0x73, 7);
  }
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// Bar graph display on TM1630
void barGraph()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  delay(200);
  buttons = readButtons();
  while (buttons == 0)
  {
    buttons = readButtons();
    pot = constrain(analogRead(A7), 0, 1000);
    pot = map(pot, 0,1000, 0,16);

    switch(pot)
    {
      case 0:
      {
        for (int i=0; i<=7; i++) setDisplay(0, i); break;
      }
      
      case 1:
      {
        for (int i=1; i<=7; i++) setDisplay(0, i);
        setDisplay(0x30, 0); break;
      }
      
      case 2:
      {
        setDisplay(0x36, 0); break;
      }
      
      case 3:
      {
        for (int i=2; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x30, 1); break; 
      }
      
      case 4:
      {
        for (int i=2; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1); break;
      }
      
      case 5:
      {
        for (int i=3; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x30, 2); break;
      }
      
      case 6:
      {
        for (int i=3; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); break;
      }
      
      case 7:
      {
        for (int i=4; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x30, 3); break;
      }
      
      case 8:
      {
        for (int i=4; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3); break;
      }
      
      case 9:
      {
        for (int i=5; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x30, 4); break;
      }
      
      case 10:
      {
        for (int i=5; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); break;
      }
      
      case 11:
      {
        for(int i=6; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x30, 5); break;
      }
      
      case 12:
      {
        for (int i=6; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5); break;
      }
      
      case 13:
      {
        for (int i=7; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x30, 6); break;
      }
      
      case 14:
      {
        for (int i=7; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x36, 6); break;
      }
      
      case 15:
      {
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x36, 6); setDisplay(0x30, 7); break;
      }
      
      case 16:
      {
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x36, 6); setDisplay(0x36, 7); break;
      }
    }
  }
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// Scroll text on TM1630
void scrollText()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  do
  {
    for (int i=0; i<=4; i++)
    {
      for (int j=0; j<=7; j++)
      {
        buttons = readButtons();
        
        if (buttons == 128)
        {
          setLed(0, j); setDisplay(0, j);
          return;
        }
        
        pot = map(analogRead(A7),0,1023, 50,1000);
        setLed(1, j);
        setDisplay(letter[i], j);
        delay(pot);
        setLed(0, j);
        setDisplay(0, j);
        delay(pot);
      }
    }
    scroll_2021();
  } while(1);
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// 8-bit Binary Count on TM1630
//============================
void binaryCount()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  do
  {
    for (int i=0; i<=1; i++)
    {
      for (int j=0; j<=1; j++)
      {
        for (int k=0; k<=1; k++)
        {
          for (int l=0; l<=1; l++)
          {
            for (int m=0; m<=1; m++)
            {
              for (int n=0; n<=1; n++)
              {
                for (int o=0; o<=1; o++)
                {
                  for (int p=0; p<=1; p++)
                  {
                    buttons = readButtons();
                    if (buttons == 128)
                    {
                      for (int i=0; i<=7; i++) setLed(0, i);
                      for(int j=0; j<=7; j++) setDisplay(0, j);
                      return;
                    }
                    
                    setLed(i, 0); setLed(j, 1);
                    setLed(k, 2); setLed(l, 3);
                    setLed(m, 4); setLed(n, 5);
                    setLed(o, 6); setLed(p, 7);
                    
                    setDisplay(digit[i], 0);
                    setDisplay(digit[j], 1);
                    setDisplay(digit[k], 2);
                    setDisplay(digit[l], 3);
                    setDisplay(digit[m], 4);
                    setDisplay(digit[n], 5);
                    setDisplay(digit[o], 6);
                    setDisplay(digit[p], 7);
                    delay(map(analogRead(A7),0,1023, 50,1000));
                  }
                }
              }
            }
          }
        }  
      }
    }
  } while(1);
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}
