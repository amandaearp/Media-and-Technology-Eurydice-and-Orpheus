/*
Team: Amanda Earp and Rachel Wright
Project: The Myth of Orpheus and Eurydice
  */
#include <Servo.h>
Servo OverworldEurydice;
const int OrpheusOriginalSpot = 7;
const int EurydiceRecieveFlower = 8;
int OrpheusOriginalState;
int OrpheusOriginalPreviousState;
int EurydiceFlowerState;

const int OrpheusArriveUnderworld = 6;
int OrpheusArriveUnderworldState;
Servo EurydiceAliveUnderworld;
Servo Hades;
const int OrpheusLeaveUnderworld = 5;
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
}

void loop() {
//Overworld Code
OrpheusOriginalState = digitalRead(OrpheusOriginalSpot);
EurydiceFlowerState = digitalRead(EurydiceRecieveFlower);

// Triggers Eurydice to die once Orpheus moves from his original spot AND he gives Eurydice a flower
if(OrpheusOriginalState != OrpheusOriginalPreviousState){
  if(OrpheusOriginalState == HIGH && EurydiceFlowerState == HIGH){
    OverworldEurydice.write(90);
   EurydiceAliveUnderworld.write(180); //Eurydice UW pops up????
  }

}
OrpheusOriginalPreviousState = OrpheusOriginalState;

// Underworld Code
OrpheusArriveUnderworldState = digitalRead(OrpheusArriveUnderworld);
OrpheusLeaveUnderworldState = digitalRead(OrpheusLeaveUnderworld);

if(OrpheusArriveUnderworldState == HIGH){
 Hades.write(180);
}
else{
  Hades.write(0);
}

if(OrpheusLeaveUnderworldState == HIGH){
 EurydiceAliveUnderworld.write(0);
 EurydiceDeadUnderworld.write(180);
}
else{
  EurydiceAliveUnderworld.write(0);
  EurydiceDeadUnderworld.write(180);
}

}
