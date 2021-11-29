# JESSICA

Jessica is a french program written in 2021. 
Jessica is a doorbell program to welcome you and your guests at home. 
The eye-button of Jessica can be pressed in different ways. It triggers different sentence paths from Jessica.

## Installation

- Install arduino : https://www.arduino.cc/en/software
- Install Audacity : https://audacity.fr.softonic.com

## How it works 

**Hardware**

First, you'll those componants : 
- Arduino nano or uno 
- DF mini players
- Resistor 1K
- LED RVB 
- Speaker 
- Battery 9V
- Push Button

You'll find the schematic circuit built on fritzing below : 
![jessica_schema](https://user-images.githubusercontent.com/91726252/143845445-5e3127d5-458f-48c7-adbd-ce3b3f659b4e.png)

A micro SD card is also required to upload your sound threw the mini Player. .mp3 files were used for this project. 

**Software**

Jessica speaks when you push the button. If you press the button in a short time, Jessica will say one sentence. If you push the button during few seconds jessica will say something else. 
You will have to download those libaries to program jessica : 

- PMbutton.h : https://github.com/JCWentzel/PolymorphicButtons/blob/master/PMButton.h
- Df mini player : https://www.arduinolibraries.info/libraries/df-robot-df-player-mini

Polymorphic Button is very usefull to program different time pressure for the button. 
You will find in repository a code with a PMbutton example. 

## 3D model

Install Blender : https://www.blender.org/download/
Install Cura : https://ultimaker.com/fr/software/ultimaker-cura

Now that the hardware and software are done, Jessica needs a body. 
You will find blender 3D model and a .stl file. 
You can print the .stl file with a 3D print using Cura for slicer for example.

<img width="1243" alt="3D_blender" src="https://user-images.githubusercontent.com/91726252/143847567-2662e4da-88e4-4f94-b16b-3bf818835802.png">


