#include "Motor.h"

Motor::Motor(uint8_t en, uint8_t p0, uint8_t p1){
pinMode(en,OUTPUT);  digitalWrite(en,LOW); // disable driver
pinMode(p0,OUTPUT);
pinMode(p1,OUTPUT);
  this->en = en;
    this->p0 = p0;
    this->p1 = p1; 
  }



 
void Motor::move(uint8_t dir){
//if(digitalRead(en)==HIGH)return;   // moving already
  if(dir==1){
    digitalWrite(this->p0,LOW);
    digitalWrite(this->p1,HIGH); 
  }else{
    digitalWrite(this->p0,HIGH);
    digitalWrite(this->p1,LOW); 
  }
  digitalWrite(this->en,HIGH);
  }  

void Motor::stop(){
 digitalWrite(this->en,LOW);  
}
