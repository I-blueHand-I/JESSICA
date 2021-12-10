#include "PMButton.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//init DF MINI PLAYER AUDIO
SoftwareSerial serialplayer(10, 11); // RX, TX
DFRobotDFPlayerMini player;

const int btn_1 = 2;
boolean bt1State, bt1PrevState;

void setup()
{
  serialplayer.begin(9600);
  Serial.begin(115200);
  //condition to staart the df mini player
  if (player.begin(serialplayer)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println("all good");
  player.volume(10);  //Set volume value. From 0 to 30
  bt1PrevState = false;
}

void loop() {
  bt1State = digitalRead(btn_1);
  if (!bt1State) {
    if (bt1PrevState != bt1State) {
      player.playMp3Folder(1);
    }
  }
  bt1PrevState = bt1State;
}
