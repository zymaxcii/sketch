// dotMatrixDisplay.ino
// https://www.engineersgarage.com/dot-matrix-display-using-arduino/

#define shcp_colun 7          // coln
#define stcp_colun 8          // coln
#define ds_colun 9             // coln
#define shcp_row 10           //  row
#define stcp_row 11           //row
#define ds_row 13    
int scr_speed,p,j,i,lenth,temp;
int data_row,data_colon;
int move_data[30];
int colun_data[31]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char inputString[100];
char font_5x7[95][6] = {
    {0x00,0x00,0x00,0x00,0x00}, //
    {0x00,0x00,0x7d,0x00,0x00}, // !
    {0x00,0x70,0x00,0x70,0x00}, // "
    {0x14,0x7f,0x14,0x7f,0x14}, // #
    {0x12,0x2a,0x6b,0x2a,0x24}, // $
    {0x32,0x34,0x08,0x16,0x26}, // %
    {0x36,0x49,0x4d,0x52,0x25}, // &
    {0x00,0x00,0x70,0x00,0x00}, // '
    {0x00,0x3e,0x41,0x00,0x00}, // (
    {0x00,0x0,0x41,0x3e,0x00}, // )
    {0x2a,0x1c,0x08,0x1c,0x2a}, // *
    {0x08,0x08,0x3e,0x08,0x08}, // +
    {0x00,0x01,0x06,0x04,0x00}, // ,
    {0x08,0x08,0x08,0x08,0x00}, // -
    {0x00,0x00,0x03,0x03,0x00}, // .
    {0x02,0x04,0x08,0x10,0x20}, // /
    {0x3e,0x41,0x41,0x3e,0x00}, // 0
    {0x11,0x21,0x7f,0x01,0x01}, // 1
    {0x21,0x43,0x45,0x49,0x31}, // 2
    {0x22,0x49,0x49,0x49,0x36}, // 3
    {0x0c,0x14,0x24,0x7f,0x04}, // 4
    {0x72,0x51,0x51,0x51,0x4e}, // 5
    {0x3e,0x49,0x49,0x49,0x26}, // 6
    {0x60,0x40,0x43,0x4c,0x70}, // 7
    {0x36,0x49,0x49,0x49,0x36}, // 8
    {0x32,0x49,0x49,0x49,0x3e}, // 9
    {0x00,0x36,0x36,0x00,0x00}, // :
    {0x01,0x36,0x34,0x00,0x00}, // ;
    {0x08,0x14,0x22,0x41,0x00}, // <
    {0x14,0x14,0x14,0x14,0x00}, // =
    {0x00,0x41,0x22,0x14,0x08}, // >
    {0x30,0x40,0x45,0x48,0x30}, // ?
    {0x3e,0x41,0x59,0x55,0x3c}, // @
    {0x3f,0X44,0x44,0x44,0x3f}, // A
    {0x7f,0x49,0x49,0x49,0x36}, // B
    {0x3e,0x41,0x41,0x41,0x22}, // C
    {0x41,0x7f,0x41,0x41,0x3e}, // D
    {0x7f,0x49,0x49,0x49,0x41}, // E
    {0x7f,0x48,0x48,0x48,0x40}, // F
    {0x3e,0x41,0x45,0x45,0x26}, // G
    {0x7f,0x08,0x08,0x08,0x7f}, // H
    {0x41,0x41,0x7f,0x41,0x41}, // I
    {0x42,0x41,0x41,0x7e,0x40}, // J
    {0x7f,0x08,0x14,0x22,0x41}, // K
    {0x7f,0x01,0x01,0x01,0x01}, // L
    {0x7f,0x20,0x18,0x20,0x7f}, // M
    {0x7f,0x20,0x18,0x06,0x7f}, // N
    {0x3e,0x41,0x41,0x41,0x3e}, // O
    {0x7f,0x48,0x48,0x48,0x30}, // P
    {0x3c,0x42,0x46,0x42,0x3d}, // Q
    {0x7f,0x48,0x4c,0x4a,0x31}, // R
    {0x32,0x49,0x49,0x49,0x26}, // S
    {0x40,0x40,0x7f,0x40,0x40}, // T
    {0x7e,0x01,0x01,0x01,0x7e}, // U
    {0x7c,0x02,0x01,0x02,0x7c}, // V
    {0x7e,0x01,0x06,0x01,0x7e}, // W
    {0x41,0x22,0x1c,0x22,0x41}, // X
    {0x70,0x08,0x0F,0x08,0x70}, // Y
    {0x43,0x45,0x49,0x51,0x61}, // Z
    {0x00,0x7f,0x41,0x00,0x00}, // [
    {0x20,0x10,0x08,0x04,0x02}, // ""
    {0x00,0x00,0x41,0x7f,0x00}, // ]
    {0x00,0x20,0x40,0x20,0x00}, // ^
    {0x01,0x01,0x01,0x01,0x01}, // _
    {0x00,0x40,0x20,0x00,0x00}, // `
    {0x0c,0x12,0x14,0x0e,0x01}, // a
    {0x7e,0x11,0x11,0x0e,0x00}, // b
    {0x0e,0x11,0x11,0x11,0x00}, // c
    {0x0e,0x11,0x11,0x7e,0x00}, // d
    {0x0e,0x15,0x15,0x0d,0x00}, // e
    {0x08,0x3f,0x48,0x20,0x00}, // f
    {0x12,0x29,0x29,0x1e,0x00}, // g
    {0x7f,0x08,0x08,0x07,0x00}, // h
    {0x00,0x11,0x5f,0x01,0x00}, // i
    {0x00,0x12,0x11,0x5e,0x00}, // j
    {0x7f,0x04,0x0a,0x11,0x00}, // s
    {0x00,0x41,0x7f,0x01,0x00}, // l
    {0x3f,0x10,0x0f,0x10,0x0f}, // m
    {0x20,0x1f,0x10,0x10,0x0f}, // n
    {0x0e,0x11,0x11,0x0e,0x00}, // o
    {0x1f,0x14,0x14,0x08,0x00}, // p
    {0x08,0x14,0x14,0x1f,0x02}, // q
    {0x1f,0x08,0x10,0x00,0x00}, // r
    {0x09,0x15,0x15,0x12,0x00}, // s
    {0x10,0x7e,0x11,0x02,0x00}, // t
    {0x1e,0x01,0x01,0x1e,0x01}, // u
    {0x1e,0x01,0x1e,0x00,0x00}, // v
    {0x1e,0x01,0x06,0x01,0x1e},// w
    {0x11,0x0a,0x04,0x0a,0x11}, // x
    {0x19,0x05,0x06,0x18,0x00}, // y
    {0x13,0x15,0x19,0x11,0x00}, // z
    {0x00,0x08,0x36,0x41,0x00}, // {
    {0x00,0x00,0x7f,0x00,0x00}, // |
    {0x00,0x41,0x36,0x08,0x00}, // }
    {0x08,0x10,0x08,0x10,0x00}, // ~
};
void setup()
{
 Serial.begin(9600); 
 pinMode(shcp_colun, OUTPUT);
 pinMode(stcp_colun, OUTPUT);
 pinMode(ds_colun, OUTPUT);
 pinMode(shcp_row, OUTPUT);
 pinMode(stcp_row, OUTPUT);
 pinMode(ds_row, OUTPUT);
 }
void loop()
{ 
 int i;
 while(1){
   char *Str="Dot Matrix by SADDAM KHAN   ";
   while(*Str!=''){
    printf(*Str);
    Str++;
   }
  }
}
void scroll(char a,char b,char c,char d,char e)            //input_string function //
{
  int count=6; 
  while(count>0){
    move_data[0]=a;a=b;b=c;c=d;d=e;e=0;
    for(scr_speed=0;scr_speed<50;scr_speed++){
      for(i=0;i<30;i++){
        temp=move_data[i];
        for(j=0;j<8;j++){
          data_row=(temp&(0x80));
          digitalWrite(ds_row,data_row);
          temp<<=1;
          digitalWrite(shcp_row,HIGH);
          for(int z=0;z<3;z++){}
          digitalWrite(shcp_row,LOW);
          }
        data_colon=colun_data[i];
        digitalWrite(ds_colun, data_colon);
        digitalWrite(shcp_colun,HIGH);//delay(1);
        digitalWrite(shcp_colun,LOW);
        digitalWrite(stcp_row,HIGH);//delay(1);
        digitalWrite(stcp_colun,HIGH);
        digitalWrite(stcp_row,LOW);
        digitalWrite(stcp_colun,LOW);
        if(Serial.available()){serial_string();}    
       }
    }
  for(i=29;i>0;i--){move_data[i]=move_data[i-1];}
  count--;
 }
}
void printf(char khan)
{ 
    p=khan-32;
    scroll(font_5x7[p][0],font_5x7[p][1],font_5x7[p][2],font_5x7[p][3],font_5x7[p][4]);
}
void serial_string()
{
  for(i=0;i<100;i++){
    inputString[i]=0;}
  lenth=0;
  for(lenth=0;lenth<3;lenth++){
    inputString[lenth]=' ';}
  lenth=3;
  while(1){
    while(Serial.available()){
      char inChar = (char)Serial.read(); 
      inputString[lenth]= inChar;
      lenth++; 
      if(inChar=='n'){
        while(1){
          for(int z=0;z<lenth-2;z++){
            printf(inputString[z]);}
  }}}}
}

