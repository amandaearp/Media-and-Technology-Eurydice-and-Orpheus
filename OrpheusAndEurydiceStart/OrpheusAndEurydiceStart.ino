const int buttonPin = 8;
const int LED = 11;
int buttonVal;

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonVal = digitalRead(buttonPin);

  if(buttonVal == LOW) {
    digitalWrite(LED, HIGH);
}
  else{
     digitalWrite(LED, LOW);
}
}
