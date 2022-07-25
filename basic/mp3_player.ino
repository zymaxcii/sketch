// mp3_player.ino
// https://rajendroid.blogspot.com/2017/01/wtv020-i2cspi-music-player-module-for.html


  1
  2
  3
  4
  5
  6
  7
  8
  9
 10
 11
 12
 13
 14
 15
 16
 17
 18
 19
 20
 21
 22
 23
 24
 25
 26
 27
 28
 29
 30
 31
 32
 33
 34
 35
 36
 37
 38
 39
 40
 41
 42
 43
 44
 45
 46
 47
 48
 49
 50
 51
 52
 53
 54
 55
 56
 57
 58
 59
 60
 61
 62
 63
 64
 65
 66
 67
 68
 69
 70
 71
 72
 73
 74
 75
 76
 77
 78
 79
 80
 81
 82
 83
 84
 85
 86
 87
 88
 89
 90
 91
 92
 93
 94
 95
 96
 97
 98
 99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230

	

// Wtv20sd16p Pin <-> Arduino Pin
//              1 <-> 2
//              7 <-> 3
//              8 <-> to GND
//             10 <-> 4
//             15 <-> 5
//             16 <-> to 3,3V


#include <Wtv020sd16p.h>
 
int resetPin = 2; // The pin number of the reset pin.
int clockPin = 3; // The pin number of the clock pin.
int dataPin = 4; // The pin number of the data pin.
int busyPin = 5; // The pin number of the busy pin.

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

double old_millis;
double old_millis2;
double old_millis3;


int Wtv_ElementiVettore=11;
int Wtv_VettArrivo[12] = {0,0,0,0,0,0,0,0,0,0,0}; 
void setup() {
//Initializes the module.
Serial.begin(115200); // set up Serial library at 115200
wtv020sd16p.reset();
old_millis=0;
old_millis2=0;
old_millis3=0;
}
 
 
void loop() {
 
     //siklus untuk menghapus , berguna untuk testing, memutar file 98 selama 90detik
     if (millis()-old_millis3 >= 100000 )
        {
        Serial.println("-------------- Memutar Lagu no.98 -------------");
        Wtv_PlaySong(98);  
        old_millis3 = millis();       
        }

     //siklus untuk menghapus , berguna untuk testing , memutar masing2 file selama 50detik  
     if (millis()-old_millis2 >= 60000 )
        {
             Serial.println("-------------- Memutar Lagu Selama 50 detik-------------");  
        Wtv_PlaySong(1);  
        Wtv_PlaySong(99);  
        Wtv_PlaySong(2);  
        Wtv_PlaySong(32);
        Wtv_PlaySong(2);         
        Wtv_PlaySong(2);        
        Wtv_PlaySong(2);         
        Wtv_PlaySong(2);  
        Wtv_PlaySong(3);  
        old_millis2 = millis();       
        }
    
 
     //Jika berikut ini untuk diletakkan di loop program utama
     //Lalu , dari mana saja dalam program Anda dapat menempatkan pendidikan Wtv_PlaySong ( 3 ) untuk membiarkan dia bermain , dalam hal ini file0003.ad4;  
     if (millis()-old_millis >= 50 )
        {
        Wtv_SendToWtv020sd16();
        old_millis = millis();       
        }
 }
 
 
//Beberapa Void untuk Mempermudah Fungsi Play File (sorry bahasa iTali soalnya copas)
 
 void Wtv_PlaySong(int numerofile)
     {
     //metti il valore in numero file in coda al vettore.
     //Però se è 98 allora cancella tutti i 99 presenti nel vettore e metti il 98 per primo in modo da suonarlo subito.
     //Se invece il valore in numerofile è uguale all'ultimo elemento precedentmente inserito allora non fa nulla.
     
     int Wtv_appo = 0;
     int Wtv_esci=0  ;
     //il primo valore è vuoto allora mettilo direttamente    
     if (Wtv_VettArrivo[0] == 0)
        {
        Wtv_VettArrivo[0] = numerofile;  //è il 98         
        Wtv_esci=1;  
        
        }
    
     if (numerofile!=98 && Wtv_esci==0)  
        {
        Wtv_appo = 0;
        Wtv_appo = Wtv_posizione();  
        if  (Wtv_appo >=1 && Wtv_VettArrivo[Wtv_appo-1]==numerofile )
             {
             //in pratica se il valore è uguale a quello precedente allora non lo metti nel buffer  
             }
         else
             {
             Wtv_VettArrivo[Wtv_appo] = numerofile;
             }
        }  
 
     //Se 98 elimina tutti i 99 e mettilo nel buffer
     if (numerofile==98)  
        {
        Wtv_appo = 0;
        Wtv_appo = Wtv_posizione();   //trova il primo valore a zero, così non faccio il for per tutti gli elementi  
        int Wtv_i = 0;
        //elimina tutti i 99 e 98 nel vettore
        while (Wtv_i <= Wtv_appo )
            {
            if (Wtv_VettArrivo[Wtv_i] == 99 || Wtv_VettArrivo[Wtv_i] == 98 )
               {
               Wtv_shiftvettore (Wtv_i);
               }
            else
               {
               Wtv_i=Wtv_i+1;   
               }
             }

        //sposta tutto il vettore in basso per poter mettere in prima posizione il 98
        for (int Wtv_i = Wtv_appo ; Wtv_i>=1 ; Wtv_i--)
            {
            Wtv_VettArrivo[Wtv_i] = Wtv_VettArrivo[Wtv_i-1];
            }
        
        Wtv_VettArrivo[0] = numerofile;  //è il 98
        }
    }  

 
 
 
 
 
void Visualizza()
     {
     //Per visualizzare gli elementi del vettore  
     int i=0;
     for (i=0; i<=Wtv_ElementiVettore; i++)  
         {
         Serial.print( i ) ;
         Serial.print( " -> " ) ;   
         Serial.println(  Wtv_VettArrivo[i]) ;
         }
     Serial.println("") ;    
     }  
 
 
 
 
void Wtv_SendToWtv020sd16()
   {   
   int Wtv_appo =0;
   if (digitalRead(busyPin) == 0 )    //solo se la scheda non sta suonando faccio quanto segue
      {   
    
      //Se è 99 allora riproponilo in coda sempre
      if (Wtv_VettArrivo[0] == 99)
         {
         Wtv_appo = Wtv_posizione();
         if (Wtv_appo == 1 || Wtv_VettArrivo[Wtv_appo - 1] != 99)
            { //se l'ultimo valore è già 99 allora non farlo
            Wtv_VettArrivo[Wtv_appo] = 99;
            }
         }
          
         if (Wtv_VettArrivo[0]!=0)   //se non è zero suonalo
            {
            wtv020sd16p.playVoice(Wtv_VettArrivo[0]);  //suonalo
            Wtv_shiftvettore(0);                       //shift-a il vettore cosi che la prima posizione viene sostituita dalla seconda e così via...  
            Visualizza();
            }
         }  
         


}
 
 
void Wtv_shiftvettore(int start)
   {
   //sposta tutti gli elementi. Da START+1 vengono portati di una posizione indietro.
   int Wtv_esci = 0;
   int Wtv_i=0;
   Wtv_i = start;
   while (Wtv_i <= Wtv_ElementiVettore - 1 && Wtv_esci == 0)
      {
      Wtv_VettArrivo[Wtv_i] = Wtv_VettArrivo[Wtv_i + 1];
      if (Wtv_VettArrivo[Wtv_i] == 0 && Wtv_VettArrivo[Wtv_i + 1] == 0)
         {Wtv_esci = 1;}
      Wtv_i = Wtv_i + 1;
      }
   Wtv_VettArrivo[Wtv_ElementiVettore] = 0;
     
   }

 
int Wtv_posizione()
   {
   //Questa funzione restituice il numero del primo elemento libero del vettore al fine di poterlo utilizzarlo.
   //La ricerca avviene tramite metodo dicotomico per ridurre il numero di cofronti necessari
   if (Wtv_VettArrivo[0] == 0 )
      {
      return 0  ;
      }
      else
      {
      int Wtv_inizio = 0;
      int Wtv_mezzo = 0;
      int Wtv_fine = 0;
      Wtv_fine = Wtv_ElementiVettore;
      while (Wtv_fine - Wtv_inizio > 1)
         {
         Wtv_mezzo = int((Wtv_inizio + Wtv_fine) / 2);
         if (Wtv_VettArrivo[Wtv_mezzo] == 0 )
            {
            Wtv_fine = Wtv_mezzo;
            }
            else
            {
            Wtv_inizio = Wtv_mezzo;
            }
         }
      return Wtv_fine;  //restituisci valore
      }
   }
