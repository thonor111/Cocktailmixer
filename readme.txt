Bibliothek zur Ansteueuerung des Cocktailmixers der CaRoBot3 AG des Carolinums Osnabr�ck geschrieben von Thomas Nortmann
Der Ordner cocktailmixer.zip muss �ber "Sketch" - "Bibliothek einbinden" - ".ZIP-Bibliothek hinzuf�gen..." in die Arduino-Umgebung eingebunden werden.
Bei "Werkzeuge" - "Board"  muss ein "Arduino/Genuino Mega or Mega 2560" ausgew�hlt werden.
Der .zip-komprimierte Ordner cocktailmixer.zip enth�lt die Dateien cocktailmixer.h, cocktaimixer.cpp und keywords.txt, welche in kommentierter und entpackter Form ebenfalls in dem Ordner
"Programm f�r den Cocktailmixer" vorliegen.


Der Motor X bewegt den Wagen, Motor Y und Z stehen auf dem Wagen.
Kabel: Von der Stromzufuhr des Motorshields aus f�r alle Motoren grau, rot, gr�n, gelb
Stromzufuhr: vom Board aus gesehen die linken beiden, (max.) 12V 1A DC
Die Positionen der Flaschen sind von links nach rechts von 1 bis 6 durchnummeriert. Die Position 0 beschreibt die Position ganz links, wenn der Wagen bis zum Anschlag geschoben wurde.
�ber ihr ist keine Flasche, sie ist die Startposition, an der das Glas auf den Wagen gestellt oder von ihm entfernt werden kann. (Siehe "Nummern der Positionen.png")


Konstruktor:

Cocktailmixer(int schrittweite, int schritthoehe, int nullerschrittweite) 

Erkl�rung: schrittweite gibt an, um wie viel Grad sich Motor X dreht, um den Wagen von einer Flasche zur n�chsten zu bewegen.
           schritthoehe gibt an, um wie viel grad sich die Motoren X und Y drehen m�ssen, um von der Position knapp unter den Flaschen so weit hoch zu dr�cken, dass die Fl�ssigkeit abgezapft wird.
           nullerschrittweite gibt die Differenz von schrittweite und der zwischen Position 0 und 1 erforderlichen Schrittweite an.
empfohlene Werte: schrittweite=380 , schritthoehe=10000 , nullerschrittweite=110   (Werte variieren mit eingestellter Spannung minimal, sie m�ssen gegebenenfalls durch Testen noch angepasst werden)



Public-Operationen:

Operation                                    Erkl�rung

void doDegX(int deg, boolean dir, byte v);   Der Motor X macht eine Drehung in Richtung dir um deg Grad mit ver�nderbarer Geschwindigkeit v von 1 (langsam) bis 10 (schnell)
void doDegY(int deg, boolean dir, byte v);   doDegX f�r Motor Y 
void doDegZ(int deg, boolean dir, byte v);   doDegX f�r Motor Z
void goTo(int gp);                           Der Wagen f�hrt zu der Position gp, Startposition ist Position 0, sie ist die Position ganz links, so dass der Wagen das Holz ber�hrt (0<=gp<=6)
void fuellen(int v);                         Der Wagen zapft v ml aus der Flasche an der aktuellen Position, v sollte durch 20 teilbar sein (es wird angenommen, dass das einmalige Dr�cken
                                             gegen einen Getr�nkehalter 20 ml entspricht)
void zapfen(int nr, int v);                  In den Cocktail werden v ml des Getr�nks an Position nr gef�llt (Kombination aus goTo und fuellen)