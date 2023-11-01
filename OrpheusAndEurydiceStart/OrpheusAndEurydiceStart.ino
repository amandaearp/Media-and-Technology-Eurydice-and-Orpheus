#include <Servo.h>
Servo myservo;
const int buttonPin = 8;
int buttonVal;

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonVal = digitalRead(buttonPin);

  if(buttonVal == HIGH) {
    myservo.write(180);
}
  else{
    myservo.write(0);
}
}
