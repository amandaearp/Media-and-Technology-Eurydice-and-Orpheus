/*
Team: Amanda Earp and Rachel Wright
Project: The Myth of Orpheus and Eurydice
*/
#include <Servo.h>
const int SunLED = 8;
Servo OverworldEurydice;
const int OrpheusOriginalSpot = 6;
const int EurydiceRecieveFlower = 7;
int OrpheusOriginalState;
int OrpheusOriginalPreviousState;
int EurydiceFlowerState;

const int FireLED1 = 5;
const int FireLED2 = 4;
const int OrpheusArriveUnderworld = 3;
int OrpheusArriveUnderworldState;
Servo EurydiceAliveUnderworld;
Servo Hades;
const int OrpheusLeaveUnderworld = 2;
int OrpheusLeaveUnderworldState;
Servo EurydiceDeadUnderworld;


void setup() {

pinMode(OrpheusOriginalSpot, INPUT);
pinMode (SunLED, OUTPUT);
pinMode (FireLED1, OUTPUT);
pinMode (FireLED2, OUTPUT);
Serial.begin(9600);
pinMode(EurydiceRecieveFlower, INPUT);
OverworldEurydice.attach(10);
EurydiceAliveUnderworld.attach(12);
EurydiceDeadUnderworld.attach(11);
Hades.attach(13);

//Reset servos and LEDS
  digitalWrite(SunLED, HIGH);
  digitalWrite(FireLED1, LOW);
  digitalWrite(FireLED2, LOW);
  OverworldEurydice.write(180);
  EurydiceAliveUnderworld.write(0);
  Hades.write(0);
  EurydiceAliveUnderworld.write(180);
  EurydiceDeadUnderworld.write(180);
}

void loop() {
//Overworld Code
OrpheusOriginalState = digitalRead(OrpheusOriginalSpot);
EurydiceFlowerState = digitalRead(EurydiceRecieveFlower);

// Triggers Eurydice to die once Orpheus moves from his original spot AND he gives Eurydice a flower
if(OrpheusOriginalState != OrpheusOriginalPreviousState){
  if(OrpheusOriginalState == HIGH && EurydiceRecieveFlower == HIGH){
  OverworldEurydice.write(0);
  digitalWrite(SunLED, LOW);
  digitalWrite(FireLED1, HIGH);
  digitalWrite(FireLED2, HIGH);
  }

}
OrpheusOriginalPreviousState = OrpheusOriginalState;

// Underworld Code
OrpheusArriveUnderworldState = digitalRead(OrpheusArriveUnderworld);
OrpheusLeaveUnderworldState = digitalRead(OrpheusLeaveUnderworld);

if(OrpheusArriveUnderworldState == HIGH){
 OverworldEurydice.write(90);
 Hades.write(180);
 EurydiceAliveUnderworld.write(90); //Eurydice UW pops up????
}

if(OrpheusLeaveUnderworldState == HIGH){
 EurydiceAliveUnderworld.write(180);
 EurydiceDeadUnderworld.write(90);
}


}
