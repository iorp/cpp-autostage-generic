

 // Inputs   

 #define MAA 22  // Main black mark 
 
 #define PAF 23  // PA forward
 #define PAB 24  // PA backward
 #define PAH 25  // PA heat
 
 #define PBF 26  // PB forward
 #define PBB 27  // PB backward
 #define PBH 28  // PB heat

 #define FLO 29  // FL open
 #define FLC 30  // FL closed

 #define FUO 31  // FU open
 #define FUC 32  // FU closed 
 #define FAF 33  // FA full
 #define FAE 34  // FA empty



 #define BIC 54  // Button init conditions
 #define BNS 55 // Button next stage
  #define BRA 56 // Button run auto


uint8_t DIRP = 0 ; 
void set_init_cond(){
digitalWrite(MAA,HIGH); 
digitalWrite(PAF,LOW);
digitalWrite(PAB,HIGH);
digitalWrite(PAH,LOW); 
digitalWrite(PBF,LOW);
digitalWrite(PBB,HIGH);
digitalWrite(PBH,LOW); 
digitalWrite(FLO,LOW);
digitalWrite(FLC,HIGH);
digitalWrite(FUO,LOW);
digitalWrite(FUC,HIGH); 
digitalWrite(FAF,LOW);
digitalWrite(FAE,HIGH); 

DIRP=0; 
  }



typedef void (*DirectiveCollection) ();


void d0(){digitalWrite(MAA,LOW);}
void d1(){digitalWrite(MAA,HIGH);}
void d2(){digitalWrite(PBB,LOW);}
void d3(){digitalWrite(PBF,HIGH);}
void d4(){digitalWrite(PBH,HIGH);}
void d5(){digitalWrite(PBH,LOW);}
void d6(){digitalWrite(PBF,LOW);}
 void d7(){digitalWrite(PBB,HIGH);}
 void d8(){digitalWrite(PAB,LOW);}
 void d9(){digitalWrite(PAF,HIGH);}
 void d10(){digitalWrite(PAH,HIGH);}
 void d11(){digitalWrite(PAH,LOW);}
 void d12(){digitalWrite(PAF,LOW);}
 void d13(){digitalWrite(PAB,HIGH);}
 void d14(){digitalWrite(FLO,HIGH);}
 void d15(){digitalWrite(FAE,LOW);}
 void d16(){digitalWrite(FAF,HIGH);}
 void d17(){digitalWrite(FUO,HIGH);}
 void d18(){digitalWrite(FAF,LOW);}
 void d19(){digitalWrite(FAE,HIGH);}
 void d20(){digitalWrite(FUO,LOW);}
 void d21(){digitalWrite(FUC,HIGH);}
 void d22(){digitalWrite(MAA,LOW);}
 void d23(){digitalWrite(MAA,HIGH);}
 void d24(){digitalWrite(PBB,LOW);}
 void d25(){digitalWrite(PBF,HIGH);}
 void d26(){digitalWrite(PBH,HIGH);}
 void d27(){digitalWrite(PBH,LOW);}
 void d28(){digitalWrite(PBF,LOW);}
 void d29(){digitalWrite(PBB,HIGH);}
 

DirectiveCollection DIR [] =  {d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17,d18,d19,d20,d21,d22,d23,d24,d25,d26,d27,d28,d29};


bool bnsflag = false;
bool autoflag = false;


void next(){
  if(DIRP<30){
  Serial.println(DIRP, DEC);DIR[DIRP]();DIRP++;delay(10);
  }else{
    DIRP=0;
    Serial.println("Sequence over");
    }
  }

void run_auto(){  for(int i = 0 ; i <31;i++){ next(); delay(10);  } }


void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);

delay(100);

pinMode(MAA,OUTPUT); 
pinMode(PAF,OUTPUT);
pinMode(PAB,OUTPUT);
pinMode(PAH,OUTPUT); 
pinMode(PBF,OUTPUT);
pinMode(PBB,OUTPUT);
pinMode(PBH,OUTPUT); 
pinMode(FLO,OUTPUT);
pinMode(FLC,OUTPUT);
pinMode(FUO,OUTPUT);
pinMode(FUC,OUTPUT); 
pinMode(FAF,OUTPUT);
pinMode(FAE,OUTPUT);

pinMode(BIC,INPUT);
pinMode(BNS,INPUT);
pinMode(BRA,INPUT);


set_init_cond();
}




void loop() {
if(digitalRead(BIC)==HIGH){ set_init_cond(); delay(10);}

if(digitalRead(BNS)==HIGH && bnsflag==false){ bnsflag=true;}  if(digitalRead(BNS)==LOW && bnsflag==true){   next(); bnsflag=false; }
if(digitalRead(BRA)==HIGH && autoflag==false){ autoflag=true;}  if(digitalRead(BRA)==LOW && autoflag==true){   run_auto(); autoflag=false; }


  
  // put your main code here, to run repeatedly:

}
