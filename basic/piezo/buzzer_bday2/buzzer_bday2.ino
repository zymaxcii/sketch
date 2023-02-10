// buzzer_bday2.ino
// status: compile ok, upload ok
// Reading of switch state is by polling; misses are highly possible
// must press down the switch to be effective
// https://www.mrelectrouino.com/2019/06/buzzer-tutorial-using-arduino-play.html


// 1 buzzer module
const int speakerPin = 3;

// 3 leds
const int led1 = 53;    // Mega board
const int led2 = 51;
const int led3 = 49;

// 1 switch
const int button = 12;

int buttonState = 0;
int length = 28;          // the number of notes

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2,2,8,8,8,16,1,2,2,8,8,8,16,1,2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;


void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {   
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}


void playNote(char note, int duration)
{
  char names[] =
  {
    'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'x', 'y'
  };

  int tones[] = 
  {
    1915,1700,1519,1432,1275,1136,1014,956,834,765,593,468,346,224,655,715
  };

  int SPEE = 5;

  // play the tone corresponding to the note name
  for (int i = 0; i < 17; i++) 
  {
    if (names[i] == note) 
    {
      int newduration = duration/SPEE;
      playTone(tones[i], newduration);
    }
  }
}


void setup()
{
  Serial.begin(9600);
  
  pinMode(button, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}


void loop()
{
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  
  if (buttonState == HIGH)
  {
    for (int k =0; k< 2; k++ )
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);

      for (int i = 0; i < length; i++) 
      {
        if (notes[i] == ' ')
        {
          delay(beats[i] * tempo); // rest
        } 
        else 
        {
          playNote(notes[i], beats[i] * tempo);
        }
        // pause between notes
        delay(tempo);
      }
    }
  }
  else
  {
    // turn LED off
    noTone(speakerPin);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
