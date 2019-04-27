
int hallPin = 2;
int ledPin = 3;
int hallState;

void setup(){
  Serial.begin(9600);
  pinMode(hallPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop(){
  hallState = digitalRead(hallPin);
  if (hallState == HIGH){
    Serial.print("No Magnet: ");
    digitalWrite(ledPin, LOW);
  }
  if (hallState == LOW){
    Serial.print("Magnet Is Near Sesnor: ");
    digitalWrite(ledPin, HIGH);
  }
  Serial.println(hallState);
  delay(100);
}
