#ifndef H_SERIALINTERPRETER
#define H_SERIALINTERPRETER

// serial 
String serial_received = "";         // a String to hold incoming data deleted after each \n
void serial_interpret(String received){
//Serial.println(received);
if(received =="help"){ Serial.print(FS(_help));  return; }
if(received =="init"){run_init_cond();return;}// Set init conditions secuence
if(received =="run"){run_program_sequence();return;}// Set init conditions secuence
if(received =="pause"){pause();return;}// Pause sequence
if(received =="resume"){resume();return;}// Resume sequence
if(received =="extm"){Serial.println(getEUint16(0),DEC);return;}// Get execution times value 
if(received.startsWith("extm=")){uint16_t num =received.substring(5,received.length()).toInt(); EEPROM.put(0, num);Serial.println(getEUint16(0),DEC);return;}// Set execution times value 
if(received =="extc"){Serial.println(EXTC,DEC);return;}// Get execution times counter 
if(received.startsWith("extc=")){EXTC =received.substring(5,received.length()).toInt(); Serial.println(EXTC,DEC);return;}// Set execution times counter 
if(received =="exmo"){Serial.println(EEPROM.read(2),DEC);return;}// Get execution mode
if(received.startsWith("exmo=")){uint8_t num =received.substring(5,received.length()).toInt(); EEPROM.put(2, num);Serial.println(EEPROM.read(2),DEC);return;} // set execution mode


Serial.print(FS(_unknown)); 
 
  
  }

#endif
