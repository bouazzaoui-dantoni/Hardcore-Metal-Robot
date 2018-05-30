//Motor A
const int motorPin1  = 2;  // sens antihoraire
const int motorPin2  = 3;  // sens horaire
//Motor B
const int motorPin3  = 6; // sens antihoraire 
const int motorPin4  = 5;  // sens horaire 
//Motor C
const int motorPin5 = 45; //sens antihoraire
const int motorPin6 = 44; //sens horaire


void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);

  analogWrite(motorPin1, 180);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  analogWrite(motorPin5, 0);
  analogWrite(motorPin6, 0); 


}

void loop() {
  // put your main code here, to run repeatedly:

}
