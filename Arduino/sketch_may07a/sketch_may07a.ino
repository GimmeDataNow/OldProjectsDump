int inPin = 2;
int inPinRead = digitalRead(2);

void setup() {
  pinMode(inPin,INPUT_PULLUP);
  pinMode(12,OUTPUT);
  Serial.begin(57600);
}

void loop() {

  digitalWrite(12, LOW);
  Serial.print( digitalRead(2));
  delay(1000);

  digitalWrite(12, HIGH);
  Serial.print( digitalRead(2));
  delay(1000);
}
