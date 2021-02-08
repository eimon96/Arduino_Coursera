int sensorValue = 0;
int outputValue = 0;

const int analogPin = A0;
const int outPin = 9;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensorValue = analogRead(analogPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(outPin, outputValue);
  
  Serial.print("Sensor: ");
  Serial.println(sensorValue);
  Serial.print("\t Output");
  Serial.println(outputValue);

  delay(13);
}
