#include <NewPing.h>
int trig=12;
int echo=13;
float cm=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void distance() {
  // put your main code here, to run repeatedly:
  NewPing sonar(trig,echo);
  cm=sonar.ping_cm();
  if(cm<15){
    Serial.println(cm);
  }
}

void loop(){
  distance();
}
