/*
Team: Amanda Earp and Rachel Wright
Project: The Myth of Orpheus and Eurydice
  */
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
OrpheusOriginalState = digitalRead(OrpheusOriginalSpot);
EurydiceFlowerState = digitalRead(EurydiceRecieveFlower);

// Triggers Eurydice to die once Orpheus moves from his original spot AND he gives Eurydice a flower
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
