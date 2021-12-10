// DFPlayer Code minimal pour test

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(D5, D6);  // TX, RX
DFRobotDFPlayerMini myDFPlayer ;

void setup() {
  mySoftwareSerial.begin(9600) ;
  myDFPlayer.begin(mySoftwareSerial) ;
}
void loop() {
  // Joue la premiere chanson de la carte SD pendant 10 secondes
  myDFPlayer.setTimeOut(500) ;
  myDFPlayer.volume(10) ; // fixe le son à 10 (maximum)
  myDFPlayer.play(1);         // joue le premier fichier son.
  delay(10000); //pause de 10 secondes
}
