/*
.cpp-Datei der Bibliothek zur Ansteueuerung des Cocktailmixers der CaRoBot3 AG des Carolinums Osnabr�ck geschrieben von Thomas Nortmann
*/




#include "Cocktailmixer.h"                                                                                          //Dem Programm wird mitgeteilt, dass Cocktailmixer.h die Header-Datei ist, in der die Deklarationen erfolgen

Cocktailmixer::Cocktailmixer(int schrittweite, int schritthoehe, int nullerschrittweiteConstructor){               //Beginn des Konstruktors
  this->schrittweite = schrittweite;
  this->schritthoehe=schritthoehe;
  this->nullerschrittweiteConstructor=nullerschrittweiteConstructor;

  this->pos=0;
  this->fahrtrichtung=true;
  
  setup();
}                                                                                                                   //Ende des Konstruktors

void Cocktailmixer::setup(){                                                                                        //Die Operation setze() wird im Konstruktor aufgerufen und uebernimmt die Aufgaben, die sonst im Setup enthalten sind
  wagenEins.setup(60, 61, 56, 14, 15);
  wagenZwei.setup(46, 48, 62, 18, 19);
  kette.setup(54, 55, 38, 3, 2);
}                                                                                                                   //Ende der Operation setze()


void Cocktailmixer::goTo(int gp){                                                                                   //Beginn der public-Operation goTo, welche den Wagen zu der Flasche an der Position gp fahren laesst

  int nullerschrittweite=0;
  if(gp==0 || pos==0){
    nullerschrittweite=nullerschrittweiteConstructor;                                                                //Veraenderung der schrittweite, falls pos 0 mit einbezogen ist, da 0 einen anderen Abstand zu 1 hat
  }                                                                                                                  //als alle anderen Abstaende
  boolean direction = (gp > pos);
  int puffer=0;
 
  if(direction!=fahrtrichtung){
    puffer=10;                                                                                                     //Puffer beim Richtungswechsel, da die Kette, die den Wagen zieht, erst neu gespannt werden muss.
  }                                                                                                                  //Falls der Cocktailmixer nach dem Richtungswechsel seine gewuenschte Position nicht erreicht, muss
                                                                                                                    //der Puffer, der aktuell bei 10 liegt, leicht angepasst werden.
  for (int i=0; i < abs(gp-pos); i++){
    kette.doDeg((double) (schrittweite+puffer-nullerschrittweite), direction, 1);
    nullerschrittweite=0;
  }
  pos=gp;
  fahrtrichtung=direction;

}                                                                                                                   //Ende der Operation goTo


void Cocktailmixer::fuellen(int v){                                                                                 //Start der public operation fuellen, welche v ml Zapfen soll

  int d = v / 20;                                                                                                       //Das Volumen wird durch 20 geteilt, da angenommen wird, dass einmal zapfen 20 ml entspricht
  for (int i=0; i < d; i++){
    for(int j=0; j < schritthoehe; j++){
      wagenEins.doDeg((double) 1, true, 9);
      wagenZwei.doDeg((double) 1, true, 9);
    }
    delay(2500);                                                                                                    //delay nach dem Hoch- und vor dem Runterfahren, damit die Fl�ssigkeit in das Glas flie�en kann
    for(int j=0; j<schritthoehe; j++){
      wagenEins.doDeg((double) 1, false, 9);
      wagenZwei.doDeg((double) 1, false, 9);
    }
    delay(100);
  }

}                                                                                                                   //Ende der Operation fuellen


void Cocktailmixer::zapfen(int nr, int v){                                                                          //public Operation zapfen, sie verbindet die Operationen goTo und fuellen, der erste Parameter gibt die Position
                                                                                                                    //des zu zapfenden Getraenks und der zweite Parameter das Volumen in ml an
  goTo(nr);
  fuellen(v);

}



