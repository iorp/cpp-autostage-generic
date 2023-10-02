#include <EEPROM.h>  
#include "Strings.h"
#include "Definitions.h"    
#include "Motor.h"   // if using motors for PA and PB

#include "System.h"
#include "StageCollection.h"   
#include "SerialInterpreter.h"
 
void setup(){ 
Serial.begin(115200);

delay(100);
Serial.println("Initialized");  

init_pinout();

} 


void seq_init_cond(){
   if(EXPO<EXSC){
    Stage(EXPO); 
    }else{ 
    stop();
    Serial.println("Initial conditions sequence completed.");
  
  }
  }

void seq_main_program(){
  
  if(EXPO<EXSC){
    Stage(EXPO); 
    }else{
     EXTC++; // increase execution times counter
	 auo(); // after unit operations
      if(EXTC<EXTM){
        EXPO = 0 ;  // reset execution pointer
        
        }else{
           stop();
           Serial.println("Main program sequence finished.");
          }
    
  }
  }


void loop(){
inputs_listen();
if(EXDI==1){ 

  if(EXTY==0){ // if initial conditions sequence
   seq_init_cond();
  }else if (EXTY==1){ // if main program sequence 
  seq_main_program();

    }
}

}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // Todo delete key 
    if ((uint8_t)inChar == 13) {
    serial_interpret(serial_received);
    serial_received=""; 
    }else{ 
    serial_received += inChar;
     }
  }
}
