/* 
 *  
!!!!!Bitte zuerst die readme.txt Datei lesen!!!!!
 *
Testprogramm für die Bibliothek zur Ansteueuerung des Cocktailmixers der CaRoBot3 AG des Carolinums Osnabrück
Autor: Thomas Nortmann
*/

#include <Cocktailmixer.h>


Cocktailmixer c(330,10000, 110);        //Erstellen des Objekts c vom Typ Cocktailmixer, Übergabe der Werte für die Attribute zur Einstellung

void setup() {
}



void loop() {
  int getraenk=0;                    //Nummer des zu zapfenden Getränks
  int volumen=20;                    //Volumen der zu zapfenden Flüssigkeit in ml
  c.zapfen(getraenk, volumen);       //Aufruf der Operation Zapfen
  c.goTo(0);
  delay(10000);
}
