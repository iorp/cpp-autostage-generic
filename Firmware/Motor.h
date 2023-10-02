#ifndef H_MOTOR
#define H_MOTOR
#include <Arduino.h>

class Motor{
  public:
  uint8_t en;
  uint8_t p0;
  uint8_t p1; 
 Motor(uint8_t en, uint8_t p0, uint8_t p1);
void move(uint8_t dir);
void stop();

 
  };



#endif
