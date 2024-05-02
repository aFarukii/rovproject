#include <Servo.h>

byte ESCpin=5;
Servo ESC;
int value=1500;
void setup(){
  Serial.begin(9600);
  ESC.attach(ESCpin);
  ESC.writeMicroseconds(1500);
  delay(5000);
}
void loop(){
  while(Serial.available()){
    int input=Serial.parseInt();
    if (input!=0){
      value=(int)input;
    }
    ESC.writeMicroseconds(value);
    delay(5);
  }
}