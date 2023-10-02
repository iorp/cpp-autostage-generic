#ifndef H_SYSTEM
#define H_SYSTEM

// USING MOTORS
 Motor PA(PAE,PA0,PA1); 
 
uint16_t getEUint16(uint8_t start){ return EEPROM.read(start+1)*256 + EEPROM.read(start); }

// ui
void uiOutput(uint8_t state){
  if(state ==RUNNING){ 
      digitalWrite(LRUN,HIGH);
      digitalWrite(LPAU,LOW);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_running));
    }else  if(state ==RUNNING){ 
      digitalWrite(LRUN,HIGH);
      digitalWrite(LPAU,LOW);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_resumed));
    }
    else if(state==PAUSED ){ 
      digitalWrite(LRUN,LOW);
      digitalWrite(LPAU,HIGH);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_paused));
    }else if(  state ==STOPPED){ 
      digitalWrite(LRUN,LOW);
      digitalWrite(LPAU,HIGH);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_stopped));
    }else if(state==ERROR){
       digitalWrite(LRUN,LOW);
      digitalWrite(LPAU,LOW);
      digitalWrite(LERR,HIGH);
     }
  }

void stop(){EXDI=0;  EXTC=0; uiOutput(STOPPED); }
void pause(){ EXDI=0;  uiOutput(PAUSED); }
void resume(){EXDI=1; uiOutput(RESUMED);}
void run(){EXDI=1; uiOutput(RUNNING);}
 
// after stage operation 
void aso(){ 
  if(EXMO==1){pause();}
  }
// after unit operation 
void auo(){
Serial.print("Completed "); Serial.print(EXTC); Serial.print(" of ");Serial.println(EXTM);
 if(EXMO==2){pause();} 
 } 

bool check_init_cond(){
if(digitalRead(MAA)!=1){Serial.println("MAA not 1");return false;} 
if(digitalRead(PAB)!=1){Serial.println("PAB not 1");return false;} 
if(digitalRead(PAF)!=0){Serial.println("PAF not 0");return false;} 
return true;  
  }

void set_init_cond(){
  // load init condition sequence in EXSL
  // Generate execution list 
  EXSL[0]=SPAB; // move PA to B 
  EXSL[1]=SMAM; // Find mark 
 
  EXSC=2; // Set execution stage count
  PSPO=-1;// Set previous Stage pointer
  EXPO=0; // set execution pointer to zero

   EXTY = 0 ; // running initial conditions sequence
  }

void set_program_sequence(){



 EXSL[0]=SMAN;  //Move MA to next mark
 EXSL[1]=SPAF;  //Move PA to F
 EXSL[2]=SPAB;  //Move PA to B
 

  EXSC=3; // Set execution stage count
  PSPO=-1;// Set previous Stage pointer
  EXPO=0; // set execution pointer to zero

 EXTY = 1 ; // running program sequence
  }


void run_init_cond(){
set_init_cond();
  run();
  }

void run_program_sequence(){
  EXTM = getEUint16(0); // retrieve execution times 
  if(EXTM==0xFFFF){EXTM=1; EEPROM.put(0,EXTM);} // set default EXTM if not set 

  EXTC = 0 ; // Reset execution times counter

  EXMO = EEPROM.read(2); // retrieve execution mode  
  if(EXMO==0xFF) {EXMO = 0; EEPROM.write(2,EXMO);}  // set default EXMO if  not set 
  
 
  if(!check_init_cond()){Serial.print(FS(_no_init_cond));return;}
  set_program_sequence();
  run();
  }

void inputs_listen(){  
  if(digitalRead(BINI)==HIGH && FBINI==false){ FBINI=true;}  if(digitalRead(BINI)==LOW && FBINI==true){   run_init_cond(); FBINI=false; }
  if(digitalRead(BRUN)==HIGH && FBRUN==false){ FBRUN=true;}  if(digitalRead(BRUN)==LOW && FBRUN==true){   run_program_sequence(); FBRUN=false; }
  if(digitalRead(BPAU)==HIGH && FBPAU==false){ FBPAU=true;}  if(digitalRead(BPAU)==LOW && FBPAU==true){   pause(); FBPAU=false; }
  if(digitalRead(BRES)==HIGH && FBRES==false){ FBRES=true;}  if(digitalRead(BRES)==LOW && FBRES==true){   resume(); FBRES=false; }
 
  }

void init_pinout(){
  
 
// inputs 
pinMode(MAA,INPUT);

pinMode(PAF,INPUT);
pinMode(PAB,INPUT);
 

// MA and BA
pinMode(MAM,OUTPUT);
 
// Input buttons
pinMode(BINI,INPUT);
pinMode(BRUN,INPUT);
pinMode(BPAU,INPUT);
pinMode(BRES,INPUT);
//Output indicators
pinMode(LRUN,OUTPUT);
pinMode(LPAU,OUTPUT);
pinMode(LERR,OUTPUT);


  }
  
#endif
