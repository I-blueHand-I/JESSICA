#include "PMButton.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// here is where we define the buttons that we'll use.
// The analog 0-5 pins are also known as 14-19
PMButton button1(14); // pin button for polymorphic button
int busy = 6; // port busy -> HIGH : mp3 is playiing LOW : is not
int stateButton = 7; //variable to init the player to play mp3

//led variables
int ledB = 2;
int ledV = 3;
int led = 5;

// the PWM pin the LED is attached to
// use for fade led when jessica is talking
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

//init DF MINI PLAYER AUDIOI
SoftwareSerial mySoftwareSerial(9, 10); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  //led init
  pinMode(led, OUTPUT); //red led from RVB
  pinMode(ledV, OUTPUT);//green led from RVB
  pinMode(ledB, OUTPUT);//blue led from RVB
  // set up serial port
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  //setup buttons
  button1.begin();
  //You can set button timing values for each button to fine tune interaction.
  button1.debounce(20);//Default is 10 milliseconds
  button1.holdTime(1000);//Default is 2 seconds

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
}
//use button to pull-up statebutton and trigger the different mp3//
void useButonCheck()
{
  if (button1.clicked()) {
    stateButton = 0;
  }
  if (button1.held()) {
    stateButton = 1;
  }
}
void loop() {
  boolean play_state = digitalRead(busy); //decalre bool to read Busy port
  //Serial.println(play_state);
  static unsigned long timer = millis(); //init long for mp3 plays
  Serial.println(stateButton);
  //check_switches to get the current state
  button1.checkSwitch();
  //used to see the state change
  useButonCheck();
  switch (stateButton) {
    case 0 : //jessica presents herself
      if (millis() - timer > 1000) {
        timer = millis();
        myDFPlayer.play(1);
        delay(20);
        stateButton = 3; //Play the first mp3
      }
      break;
    case 1 : //please my gap between train and platform
      if (millis() - timer > 1000) {
        timer = millis();
        delay(1200);
        myDFPlayer.play(3);//Play the first mp3
        delay(20);
        stateButton = 4;
      }
      break;
  }
  if (play_state == 1) { // if mp3 is not playing then led RVB is LOW
    analogWrite(led, LOW);
    analogWrite(ledV, LOW);
    analogWrite(ledB, LOW);
  }
  else {
    ledBlink(); //if mp3 is playing - > blink led
  }
}
void ledBlink() {
  analogWrite(led, brightness);
  analogWrite (ledB, brightness);
  analogWrite (ledV, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
