#include <Servo.h>
Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(37);  // attaches the servo on pin 12 to the servo object

}

void servo() {
  int pos;
  for(pos = 35; pos!=100; pos+=1){     // goes from 35 degrees to 100 degrees                                
    myservo.write(pos);                // tell servo to go to position in variable 'pos' 
    delay(15);                         // waits 15ms for the servo to reach the position 
  } 
  for(pos = 100; pos!=35; pos-=1){     // goes from 100 degrees to 35 degrees                                
    myservo.write(pos);                // tell servo to go to position in variable 'pos' 
    delay(15);                         // waits 15ms for the servo to reach the position 
  }
}
void stopServo() {
  myservo.write(0);
}

void loop() {
  int i=0;
  while(i!=10) {
    servo();
    i+=1;
  }
  stopServo();
  delay(5000);
}



