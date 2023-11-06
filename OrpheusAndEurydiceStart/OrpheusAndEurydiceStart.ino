#include <Servo.h>
Servo OverworldEurydice;
Servo myservo2;
const int OrpheusOriginalSpot = 7;
const int EurydiceRecieveFlower = 8;
int OrpheusOriginalState;
int OrpheusOriginalPreviousState;
int EurydiceFlowerState;

void setup() {
  // put your setup code here, to run once:
pinMode(OrpheusOriginalSpot, INPUT);
Serial.begin(9600);
pinMode(EurydiceRecieveFlower, INPUT);
OverworldEurydice.attach(9);
myservo2.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
OrpheusOriginalState = digitalRead(OrpheusOriginalSpot);
EurydiceFlowerState = digitalRead(EurydiceRecieveFlower);

if(OrpheusOriginalState != OrpheusOriginalPreviousState){
  if(OrpheusOriginalState == HIGH && EurydiceFlowerState == HIGH){
    OverworldEurydice.write(180);
  }
  else{
    OverworldEurydice.write(0);
  }
}
OrpheusOriginalPreviousState = OrpheusOriginalState;

}
