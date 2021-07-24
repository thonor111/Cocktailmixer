/*
.cpp-Datei der Bibliothek zur Ansteueuerung des Cocktailmixers der CaRoBot3 AG des Carolinums Osnabr�ck geschrieben von Thomas Nortmann
*/




#include "Engine.h"                                                                                          //Dem Programm wird mitgeteilt, dass Engine.h die Header-Datei ist, in der die Deklarationen erfolgen


void Engine::setup(int STEP_PIN, int DIR_PIN, int ENABLE_PIN, int MIN_PIN, int MAX_PIN){      
  this->STEP_PIN = STEP_PIN;                                                                                              //vom Motorshield abhaengige Nummerierung der Pins
  this->DIR_PIN = DIR_PIN;
  this->ENABLE_PIN = ENABLE_PIN;
  this->MIN_PIN = MIN_PIN;
  this->MAX_PIN = MAX_PIN;                                                                                  //Die Operation setze() wird im Konstruktor aufgerufen und uebernimmt die Aufgaben, die sonst im Setup enthalten sind
  pinMode(STEP_PIN,OUTPUT);                                                                                         //(private Operation)
  pinMode(DIR_PIN,OUTPUT);
  pinMode(ENABLE_PIN,OUTPUT);
  digitalWrite(ENABLE_PIN,LOW);
}                                                                                                                   //Ende der Operation setze()

void Engine::doSteps(int steps, boolean dir, byte v){                                                       //private Operation doStepsX, welche den Motor X um steps Schritte in die Richtung dir mit der Geschwindigkeit v
                                                                                                                    //(1=langsam, 10=schnell) dreht
int d=11-v;                                                                                                         //doStepsY und doStepsZ sind die selbe Operation fuer die Motoren Y und Z
d=d*100;  
if (dir){
    digitalWrite(DIR_PIN, HIGH);
  }
  else{
    digitalWrite(DIR_PIN, LOW);
  }
  for(int i=0; i<steps; i++) {
    digitalWrite(STEP_PIN, HIGH);                                                                                 //ein Wechsel des Pins "X_STEP_PIN" von HIGH auf LOW entspricht einem Schritt
    delayMicroseconds(d);
    digitalWrite(STEP_PIN, LOW);
  }

}
                                                                                              //Ende der doStep-Operationen

void Engine::doDeg(double deg, boolean dir, byte v){                                                           //Beginn der public doDeg-Operationen. Sie entsprechen doStep,
  double steps = (deg / 360) * 3200;
  this->doSteps((int) steps, dir, v);
}
