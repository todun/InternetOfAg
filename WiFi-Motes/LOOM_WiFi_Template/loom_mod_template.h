// ================================================================
// ===                        LIBRARIES                         ===
// ================================================================


// ================================================================ 
// ===                        STRUCTURES                        === 
// ================================================================
struct config_<module>_t {

};

struct state_<module>_t {

};

// ================================================================ 
// ===                   GLOBAL DECLARATIONS                    === 
// ================================================================
struct config_<module>_t *config_<module>;
struct state_<module>_t *state_<module>;


// ================================================================ 
// ===                        FUNCTIONS                         === 
// ================================================================
void setup_<module>() {
	//Setup Here
}

void package_data_<module>(OSCBundle *bndl, char packet_header_string[]) {
	//Create a message and fill it here, then add it to the bndl
}

void measure_<module>() {
	//Measure data and change the state here. 
	//Potentially uses the config data
}

