/*
Team: Amanda Earp and Rachel Wright
Project: The Myth of Orpheus and Eurydice
  */
#include <Servo.h>
Servo OverworldEurydice;
const int OrpheusOriginalSpot = 5;
const int EurydiceRecieveFlower = 7;
int OrpheusOriginalState;
int OrpheusOriginalPreviousState;
int EurydiceFlowerState;

const int OrpheusArriveUnderworld = 3;
int OrpheusArriveUnderworldState;
Servo EurydiceAliveUnderworld;
Servo Hades;
const int OrpheusLeaveUnderworld = 2;
int OrpheusLeaveUnderworldState;
Servo EurydiceDeadUnderworld;


void setup() {

pinMode(OrpheusOriginalSpot, INPUT);
Serial.begin(9600);
pinMode(EurydiceRecieveFlower, INPUT);
OverworldEurydice.attach(10);
EurydiceAliveUnderworld.attach(11);
Hades.attach(12);
EurydiceDeadUnderworld.attach(13);
//Reset servos
  OverworldEurydice.write(0);
  EurydiceAliveUnderworld.write(0);
  Hades.write(0);
  EurydiceAliveUnderworld.write(0);
  EurydiceDeadUnderworld.write(0);
}

void loop() {
//Overworld Code
OrpheusOriginalState = digitalRead(OrpheusOriginalSpot);
EurydiceFlowerState = digitalRead(EurydiceRecieveFlower);

// Triggers Eurydice to die once Orpheus moves from his original spot AND he gives Eurydice a flower
if(OrpheusOriginalState != OrpheusOriginalPreviousState){
  if(OrpheusOriginalState == LOW && EurydiceFlowerState == HIGH){
  OverworldEurydice.write(180);
  }

}
OrpheusOriginalPreviousState = OrpheusOriginalState;

// Underworld Code
OrpheusArriveUnderworldState = digitalRead(OrpheusArriveUnderworld);
OrpheusLeaveUnderworldState = digitalRead(OrpheusLeaveUnderworld);

if(OrpheusArriveUnderworldState == HIGH){
 OverworldEurydice.write(90);
 Hades.write(90);
 EurydiceAliveUnderworld.write(90); //Eurydice UW pops up????
}

if(OrpheusLeaveUnderworldState == HIGH){
 EurydiceAliveUnderworld.write(0);
 EurydiceDeadUnderworld.write(90);
}
}
