#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// create an instance of the library
TFT myScreen = TFT(cs, dc, rst);

void setup(){
  myScreen.begin();  
  myScreen.background(0,0,0);  // clear the screen with black
}

void neutre(){
  myScreen.stroke(0,0,0);//couleur
  myScreen.fill(255,255,0);//remplissage
  myScreen.rect(30,20,20,20);//oeil gauche  rect: xstart ystart width height
  myScreen.rect(110,20,20,20);//oeil droit
  myScreen.rect(30,90,100,20);//bouche
  
  delay(150);
  myScreen.fill(0,0,0);
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  delay(150);
  myScreen.fill(255,255,0);//remplissage     // clignement
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  delay(2000);
}

void triste(){
   myScreen.stroke(0,0,0);//couleur
  myScreen.fill(0,0,255);//remplissage
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  
  myScreen.rect(40,85,10,10);
  myScreen.rect(50,80,60,10);//bouche
  myScreen.rect(110,85,10,10);
  myScreen.rect(30,95,10,10);
  myScreen.rect(120,95,10,10);

  delay(150);
  myScreen.fill(0,0,0);
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  delay(150);
  myScreen.fill(0 ,0,255);//remplissage     // clignement
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  delay(2000);
}

void joie(){
  myScreen.stroke(0,0,0);//couleur
  myScreen.fill(0,255,0);//remplissage
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  
  myScreen.rect(40,85,10,10);
  myScreen.rect(50,95,60,10);//bouche
  myScreen.rect(110,85,10,10);
  myScreen.rect(30,75,10,10);
  myScreen.rect(120,75,10,10);

  delay(150);
  myScreen.fill(0,0,0);
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  delay(150);
  myScreen.fill(0,255,0);//remplissage     // clignement
  myScreen.rect(30,20,20,20);//oeil gauche
  myScreen.rect(110,20,20,20);//oeil droit
  delay(2000);
}

void colere(){
  myScreen.stroke(0,0,0);//couleur
  myScreen.fill(255,0,0);//remplissage
  myScreen.rect(35,15,10,10);
  myScreen.rect(45,25,10,10);//oeil gauche
  myScreen.rect(55,35,10,10);
  myScreen.rect(35,35,15,15);

  myScreen.rect(110,15,10,10);
  myScreen.rect(100,25,10,10);//oeil gauche
  myScreen.rect(90,35,10,10);
  myScreen.rect(105,35,15,15);
  

  myScreen.rect(40,85,10,10);
  myScreen.rect(50,80,60,10);//bouche
  myScreen.rect(110,85,10,10);
  myScreen.rect(30,95,10,10);
  myScreen.rect(120,95,10,10);

  delay(150);
  myScreen.fill(0,0,0);
  myScreen.rect(35,35,15,15);//oeil gauche
  myScreen.rect(105,35,15,15);//oeil droit
  delay(150);
  myScreen.fill(255,0,0);//remplissage     // clignement
  myScreen.rect(35,35,15,15);//oeil gauche
  myScreen.rect(105,35,15,15);//oeil droit
  delay(2000);
}

void loop(){
  neutre();
   myScreen.background(0,0,0); 
  colere();
   myScreen.background(0,0,0); 
  joie();
   myScreen.background(0,0,0); 
  triste();
   myScreen.background(0,0,0); 
  }


