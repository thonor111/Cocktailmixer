#include <Arduino.h>  

class Engine {



private:                                                                                     //Deklarieren der privaten Attribute

  int STEP_PIN;
  int DIR_PIN;
  int ENABLE_PIN;
  int MIN_PIN;
  int MAX_PIN;
  boolean fahrtrichtung;                                                                     //Ende der Deklaration der Attribute

  void doSteps(int steps, boolean dir, byte v);                                              //Deklaration der privten Operationen (Ausf�hrliche Kommentierung in der .cpp-Datei)



public:                                                                                      //Deklaration der public Operationen

  void setup(int STEP_PIN, int DIR_PIN, int ENABLE_PIN, int MIN_PIN, int MAX_PIN);

  void doDeg(double deg, boolean dir, byte v);

};