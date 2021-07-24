/*
Header-Datei der Bibliothek zur Ansteueuerung des Cocktailmixers der CaRoBot3 AG des Carolinums Osnabrueck geschrieben von Thomas Nortmann
*/



#ifndef __COCKTAILMIXER__                                                                    //vernachlaessigbare Zeile, sie verhindert fehlerhaftes Mehrfach-Aufrufen              
#define __COCKTAILMIXER__                                                                    // s.o.

#include <Arduino.h>                                                                         //Dem Programm wird mitgeteilt, dass Arduino als Entwicklungsuumgebung genutzt wird
#include "Engine.h"

class Cocktailmixer {



private:                                                                                     //Deklarieren der privaten Attribute

  int pos;
  int schrittweite;
  int schritthoehe;
  int nullerschrittweiteConstructor;
  Engine wagenEins;
  Engine wagenZwei;
  Engine kette;
  boolean fahrtrichtung;                                                                     //Ende der Deklaration der Attribute

  void setup();


public:                                                                                      //Deklaration der public Operationen

  Cocktailmixer(int schrittweite, int schritthoehe, int nullerschrittweiteConstructor);

  void goTo(int gp);

  void fuellen(int v);

  void zapfen(int nr, int v);
};

#endif                                                                                       //vernachlaessigbare Zeile, sie verhindert fehlerhaftes Mehrfach-Aufrufen