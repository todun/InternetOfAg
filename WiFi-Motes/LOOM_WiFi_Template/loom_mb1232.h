// ================================================================ 
// ===                        LIBRARIES                         === 
// ================================================================
//#include <Wire.h>


// ================================================================ 
// ===                        STRUCTURES                        === 
// ================================================================
struct config_mb1232_t {

};

struct state_mb1232_t {

};


// ================================================================ 
// ===                   GLOBAL DECLARATIONS                    === 
// ================================================================
struct config_mb1232_t *config_mb1232;
struct state_mb1232_t *state_mb1232;


// ================================================================ 
// ===                        FUNCTIONS                         === 
// ================================================================
void setup_mb1232() {
	//Setup Here
}

void package_data_mb1232(OSCBundle *bndl, char packet_header_string[]) {
	//Create a message and fill it here, then add it to the bndl
}

void measure_mb1232() {
	//Measure data and change the state here. 
	//Potentially uses the config data
}

