#ifndef H_STRINGS
#define H_STRINGS
#define FS(x) (__FlashStringHelper*)(x)

const char _help[] PROGMEM = {"\r\nhelp           : Shows usable commands.\n\rinit           : Sets machine elements to initial conditions.\n\rrun             : Run the main program.\n\r\n\rpause         : Pause the main program.\n\rresume       : Resume the main program.\n\r"};
const char _unknown[] PROGMEM = {"Unknown command. Use help command.\n\r"};
const char _no_init_cond[] PROGMEM = {"Execution cancelled init conditions not match.\n\r"};
const char _paused[] PROGMEM = {"Paused.\n\r"};
const char _resumed[] PROGMEM = {"Resumed.\n\r"};
const char _stopped[] PROGMEM = {"Stopped.\n\r"};
const char _running[] PROGMEM = {"Running.\n\r"};

 

#endif
