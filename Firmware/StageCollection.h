#ifndef H_STAGECOLLECTION
#define H_STAGECOLLECTION

typedef void (*StageCollection) ();







 // move PA to B
 void _SPAB (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPAB"); PA.move(0);PSPO = EXPO;}
 //  if(PSPO!=EXPO){  Serial.println(FS(_ss[((uint8_t)EXSL[EXPO])])); PA.move(0);PSPO = EXPO;}

  // On stage completed
  if(digitalRead(PAB)==HIGH){ PA.stop();  EXPO++; aso();}  
}
 // move PA to F
 void _SPAF (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPAF"); PA.move(1);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(PAF)==HIGH){ PA.stop();  EXPO++;aso(); }  
}

// Move MA and BA  till mark found used in initcond (NU)
void _SMAM(){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SMAM"); digitalWrite(MAM,HIGH); PSPO = EXPO;}
  // On stage completed
  if(digitalRead(MAA)==HIGH){ digitalWrite(MAM,LOW);  EXPO++;aso(); }  
  }


  // Move MA til next mark  
void _SMAN(){
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SMAN"); digitalWrite(MAM,HIGH); PSPO = EXPO;}
  // On stage completed
  if(digitalRead(MAA)==LOW){ FNMAA=true; }  
  if(digitalRead(MAA)==HIGH && FNMAA){ digitalWrite(MAM,LOW); FNMAA = false;  EXPO++;aso(); }  
  }
 
StageCollection STCO [] =  {
 _SPAB,
 _SPAF,
 _SMAM,
 _SMAN

 };
 
void Stage(uint8_t index){
EXPO = index;
STCO[EXSL[EXPO]]();  
}
#endif
