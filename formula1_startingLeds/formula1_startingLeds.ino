int s1 = 13;
int s2 = 12;
int s3 = 11;
int s4 = 9;
int s5 = 8;

int buz = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5, OUTPUT);

  pinMode(buz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnOn(s1);
  turnOn(s2);
  turnOn(s3);
  turnOn(s4);
  turnOn(s5);

  delay(2000);

  turnOff(s1);
  turnOff(s2);
  turnOff(s3);
  turnOff(s4);
  turnOff(s5);
  tone(buz, 3000, 1200);

  delay(2000);
}

void turnOn(int pin)
{
  digitalWrite(pin, HIGH);
  tone(buz, 3000, 10);
  
  delay(1000);
}

void turnOff(int pin)
{
  digitalWrite(pin, LOW);
}
