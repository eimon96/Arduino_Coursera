#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[] = { ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8 };
const byte col[] = { COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8 };

byte c0[] = {B11111111,B10000001,B10000001,B10000001,B10000001,B10000001,B10000001,B11111111};
byte c1[] = {B00000000,B01111110,B01000010,B01000010,B01000010,B01000010,B01111110,B00000000};
byte c2[] = {B00000000,B00000000,B00111100,B00100100,B00100100,B00111100,B00000000,B00000000};
byte c3[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};


void setup() 
{
    Serial.begin(9600);
   
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
        
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() 
{
    drawScreen(c0);
    blank();
    drawScreen(c1);
    blank();
    drawScreen(c2);
    blank();
    drawScreen(c3);
    blank();

    drawScreen(c3);
    blank();
    drawScreen(c2);
    blank();
    drawScreen(c1);
    blank();
    drawScreen(c0);
    blank();
}


void setColumns(byte b) 
{
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
}


void  drawScreen(byte buffer2[])
{
    for (byte i = 0; i < 8; i++) 
    {
        setColumns(buffer2[i]);
              
        digitalWrite(rows[i], HIGH);
        delay(1); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
    }
}

void blank()
{
  byte b[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  drawScreen(b);
  delay(50);
}
