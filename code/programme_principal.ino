/** Source : http://www.codebender.cc **/

//Motor A
const int motorPin1  = 2;  //sens antihoraire
const int motorPin2  = 3;  //sens horaire
//Motor B
const int motorPin3  = 6;  //sens antihoraire 
const int motorPin4  = 5;  //sens horaire 
//Motor C
const int motorPin5 = 45; //sens antihoraire
const int motorPin6 = 44; //sens horaire

//bluetooth
#include <SoftwareSerial.h>  //Software Serial Port  
#define RxD 12               //RX à brancher sur le TX du HC-06
#define TxD 11               //TX à brancher sur le RX du HC-06
SoftwareSerial BTSerie(RxD,TxD);  

//servo-moteurs
#include <Servo.h>
Servo myservo;  // création d'un objet servo pour contrôler un servo-moteur

//écran
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#define cs   10
#define dc   9
#define rst  8
TFT myScreen = TFT(cs, dc, rst); // instance de la librairie

//musique
#include <SD.h>         //librairie du module SD
#include <TMRpcm.h>     //librairie de contrôle des enceintes
#define CS 40           
#define ENABLE_MULTI    //permet d'inclure plusieurs musiques
TMRpcm audio;           //création d'un objet audio

void setup(){
  Serial.begin(9600);

  //chipSelect
  pinMode(CS,OUTPUT);
  pinMode(cs,OUTPUT);
  digitalWrite(CS,HIGH);
  digitalWrite(cs,LOW);
  
  // set bluetooth  
  pinMode(RxD, INPUT);  
  pinMode(TxD, OUTPUT); 
  BTSerie.begin(9600); 
  
  //Set Motorpins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);

  //set servo
  myservo.attach(37);  // attache le servo au pin 12

  //set screen
  myScreen.begin();  
  myScreen.background(0,0,0);  // clear the screen with black

  digitalWrite(CS,LOW),
  digitalWrite(cs,HIGH);

  //set music
  audio.speakerPin = 46;
  if (!SD.begin(CS)) {          //teste si la carte est présente et peut être initialisée
    Serial.println("sd cassé"); // si non retourne "sd cassé"
    return;                     //on sort de la boucle
  }
}                                     

void stopRobot() {
  //The robot stops
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 0);
}
void forward() { 
  //The robot moves forward.   
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 180);
  analogWrite(motorPin4, 0);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 180);
}
void right() { 
  //The robot turns right.
  analogWrite(motorPin1, 180);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 180);
  analogWrite(motorPin4, 0);
  analogWrite(motorPin5, 180);
  analogWrite(motorPin6, 0);   
}
 void left() { 
  //The robot turns left.
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 180);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 180);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 180); 
}


void servo() {
  int pos;
  for(pos = 35; pos!=100; pos+=1){     // va de 35° à 100°                              
    myservo.write(pos);                // le servo se déplace jusqu'à la position 'pos' 
    delay(15);                         // attendre 15ms quand le servo atteint sa position
  } 
  for(pos = 100; pos!=35; pos-=1){     // va de 100° à 35°                                 
    myservo.write(pos);                // le servo se déplace jusqu'à la position 'pos' 
    delay(15);                         // attendre 15ms quand le servo atteint sa position
  }
}
void stopServo() {
  myservo.write(0);                    // le servo retourne à la position initiale 0°
}

void neutre(){
  myScreen.stroke(255,255,0);    // couleur des bordures
  myScreen.fill(255,255,0);      // remplissage
  myScreen.rect(110,90,20,20);   // oeil gauche  rect: xstart ystart width height
  myScreen.rect(110,20,20,20);   // oeil droit
  myScreen.rect(30,20,20,90);    // bouche
}
void triste(){
  myScreen.stroke(0,0,255);      // couleur des bordures
  myScreen.fill(0,0,255);        // remplissage
  myScreen.rect(110,90,20,20);   // oeil gauche  rect: xstart ystart width height
  myScreen.rect(110,20,20,20);   // oeil droit
  //bouche :
  myScreen.rect(53,35,10,60);
  myScreen.rect(37,15,10,10);
  myScreen.rect(47,25,10,10);
  myScreen.rect(47,95,10,10);
  myScreen.rect(37,105,10,10);
}
void joie(){
  myScreen.stroke(0,255,0);       // couleur des bordures
  myScreen.fill(0,255,0);         // remplissage
  myScreen.rect(110,90,20,20);    // oeil gauche  rect: xstart ystart width height
  myScreen.rect(110,20,20,20);    // oeil droit
  //bouche :
  myScreen.rect(37,35,10,60);
  myScreen.rect(53,15,10,10);
  myScreen.rect(44,25,10,10);
  myScreen.rect(44,95,10,10);
  myScreen.rect(53,105,10,10);
}
void colere(){
  myScreen.stroke(255,0,0);       // couleur des bordures
  myScreen.fill(255,0,0);         // remplissage
  //oeil gauche :
  myScreen.rect(90,20,15,15);
  myScreen.rect(125,15,10,10);
  myScreen.rect(115,25,10,10);
  myScreen.rect(105,35,10,10);
  //oeil droit :
  myScreen.rect(90,90,15,15);
  myScreen.rect(105,80,10,10);
  myScreen.rect(115,90,10,10);
  myScreen.rect(125,100,10,10);
  //bouche :
  myScreen.rect(53,35,10,60);
  myScreen.rect(37,15,10,10);
  myScreen.rect(47,25,10,10);
  myScreen.rect(47,95,10,10);
  myScreen.rect(37,105,10,10);
}


void loop() {
  char recvChar;
  if (BTSerie.available()) {   // si la connexion BT est établie
    recvChar = BTSerie.read(); // lecture   
    /*switch(recvChar){
      case 'B': audio.play("Silence.wav"); break;
      case 'r': audio.play("Reign.wav",50); break;    
      case 'G': audio.play("Caravan.wav"); break;    
      case 'Y': audio.play("Tetris.wav",5); break;    
      case 'S': audio.stopPlayback(); break;       //Stop all playback 
      case 'U' : forward();
      case 'R' : right();
      case 'L' : left();
      case 'D' : right();
      case 's' : stopRobot();
    } */
    if(recvChar=='U'){  // on clique sur le bouton 'avancer'
      forward();
    }
    if(recvChar=='R'){  // on clique sur le bouton 'tourner à droite'
      right();
    }
    if (recvChar=='L'){  // on clique sur le bouton 'tourner à gauche'
      left();
    } 
    if (recvChar=='s'){  // lorsqu'on relâche le bouton
      stopRobot();
    }
    if (recvChar=='D') {  // lorsqu'on appuies sur 'faire danser le robot'
      digitalWrite(CS,LOW);
      audio.play("Dance.wav");
      
      right();
      delay(2500);
      left();
      delay(2500);
      stopRobot();
      digitalWrite(CS,HIGH);
    }
    if(recvChar=='r'){    // on clique sur le bouton 'rouge
      audio.stopPlayback();
      digitalWrite(CS,HIGH);
      digitalWrite(cs,LOW);
      myScreen.background(0,0,0); // réinitialise l'écran pour éviter la superposition
      colere();
      digitalWrite(cs,HIGH);
      delay(10);  
      digitalWrite(CS,LOW);
      audio.play("Bat.wav"); 
    }
    if (recvChar=='Y'){  // on clique sur le bouton 'jaune'
      audio.stopPlayback();
      digitalWrite(CS,HIGH);
      digitalWrite(cs,LOW);
      myScreen.background(0,0,0); // réinitialise l'écran pour éviter la superposition
      neutre();
      digitalWrite(cs,HIGH);
      delay(10);
      digitalWrite(CS,LOW);
      audio.play("Tetris.wav",5);
         
    } 
    if(recvChar=='G') {  // on clique sur le bouton 'vert'
      audio.stopPlayback();
      digitalWrite(CS,HIGH);
      digitalWrite(cs,LOW);
      myScreen.background(0,0,0); // réinitialise l'écran pour éviter la superposition
      joie();
      digitalWrite(cs,HIGH); 
      delay(10);
      digitalWrite(CS,LOW); 
      audio.play("Caravan.wav");
      if(audio.isPlaying()){
        Serial.println("cool");
      }
       
    }
    if (recvChar=='B') {  // on clique sur le bouton 'bleu'
      audio.stopPlayback();
      digitalWrite(CS,HIGH);
      digitalWrite(cs,LOW);
      myScreen.background(0,0,0); // réinitialise l'écran pour éviter la superposition
      triste();
      digitalWrite(cs,HIGH);
      delay(10);
      digitalWrite(CS,LOW);
      audio.play("Silence.wav");
          
    }
    if (recvChar=='S') {  // on clique sur le bouton 'arrêter la musique'
      digitalWrite(CS,LOW);
      audio.stopPlayback();
      digitalWrite(CS,HIGH);
    }
  }
}
