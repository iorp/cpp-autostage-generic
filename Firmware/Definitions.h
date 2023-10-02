#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H 
 
// SRAM DECLARATIONS 
uint8_t EXPO = 0;   // Execution Stage pointer 
uint8_t EXDI =0;    // Execution directive
uint8_t EXSL[32]={};// Execution stage list  (EXSL[EXPO])
uint8_t EXSC =0;    // Execution stage count
int PSPO =-1; // previous started pointer, used to cal onstageLoad on each stage
uint16_t EXTM = 0 ; // Execution times multiplier loads from eeprom address 0, length 2  
uint16_t EXTC = 0 ; // Execution times counter
uint8_t EXMO = 0 ; // Execution mode loads from eeprom addres 2, length 1 
uint8_t EXTY = 0; // Execution sequence 0 is init conditions 1 is main program sequence 
bool FNMAA =false; // Flag next maa

bool FBRUN=false; // Flag BRUN button
bool FBINI=false; // Flag BINI button
bool FBPAU=false; // Flag BPAU button
bool FBRES=false; // Flag BRES button

 // Inputs   

#define MAA 22  // Main black mark  
#define PAB 23  // Main black mark  
#define PAF 24  // Main black mark  


  
// Input buttons
#define BINI      2// Button run initial sequence
#define BRUN      3// Button run main sequence
#define BPAU      4// Button run initial sequence
#define BRES      5// Button resume sequence EXDI  = 1


//Outputs Using motors as pull elements
#define PA0 53  // PA direction p0
#define PA1 52  // PA direction p1
#define PAE 51  // PA enable 
#define MAM 42  // Ma move
 
// Output indicators
#define LRUN      11// LED running main sequence
#define LPAU      12// LED running initial sequence
#define LERR      13// LED error indicator


// Stages index
#define SPAB      0 // Move PA to B
#define SPAF      1 // Move PA to F 
#define SMAN      2// Move MA until next mark 
#define SMAM      4// Move MA until next mark 



// Compiler defines 
#define RUNNING 0
#define PAUSED 1
#define STOPPED 2
#define RESUMED 3
#define ERROR 4

 
#endif
