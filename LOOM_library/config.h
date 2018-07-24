// ================================================================ 
// ===                   CONFIGURATION FILE                     === 
// ================================================================
//
// Use this file to configure the device you are flashing the firmware of
//
// This file is divided into two sections:
//
//  Options: The top half that can be modified to change common settings
//
//  Advanced Options: the bottom section that is at least partially set based on  
//    the top half but may be modified for more specific behavior. 
//    Also contains other specific options that don't need to change as frequently
//
// Definitions that should not be modified by the user are
//   located in the library and are not present here


// ================================================================ 
// ===                         OPTIONS                          === 
// ================================================================

// --- Device Identification --- 
#define FAMILY "LOOM"			// Will usually be "LOOM", you can change this if you are setting up your own network
#define CHANNEL          7		// Channel to use. Set to 1-8 for channels A-H, respectively. Alternatively can define to -1 to used advanced option INIT_INST
#define REQUEST_SETTINGS 0		// 1 to request channel settings from Max Channel Manager, 0 to not
#define AUTO_NAME        1		// 1 to enable naming device based on configured settings (if not set manual name in advanced options)
#define CUSTOM_NAME "Custom"	// This is only used if Auto_name is set to be 0

// --- Debugging --- 
#define LOOM_DEBUG    1		// Set to 1 if you want Serial statements from various functions to print
							// NOTE: Serial monitor must be opened for device to setup if this is enabled
							//   Device will freeze if this in abled and device does not get plugged into Serial
							// LOOM_DEBUG_Print* are Serial prints that are removed if debugging is off

// --- Enabled Communication Platform --- 
#define is_wifi       1		// 1 to enable WiFi
#define is_lora       0		// 1 to enable LoRa (cannot be used with nRF) (Further customization in advanced options)
#define is_nrf        0		// 1 to enable nRF (cannot be used with LoRa) (Further customization in advanced options)
#define is_ethernet   0		// 1 to enable Ethernet (a number of options below might auto enable this anyway though)
#define is_fona       0		// 1 to enable cellular via Fona (808)
#define is_bluetooth  0		// Sorry, Bluetooth is not implemented yet

// --- Data Logging Platforms ---
#define is_pushingbox 0		// 1 to enable PushingBox (currently requires Ethernet) (Auto enabled if using LoRa hub) (currently does not appear to work with WiFi)
#define is_adafruitio 0		// 1 to enable Adafruit IO (currently requires WiFi)

#define is_sd         0		// 1 to enable SD card 
#define is_rtc        0		// Enable RTC functionality

// --- Device Telemetry Type ---
#define hub_node_type 0		// 0: Hub, 1: Node
#define is_repeater   0		// Sorry, this doesn't do anything yet



// --- Enabled Actuators --- 
#define num_servos    0 	// Number of servos being used (up to 8 per shield, testing has generally only been through 1 shield)
#define num_steppers  0		// Number of stepper motors being used 
#define is_relay      0		// 1 if relays are being used (enables two, on pins 5 and 6)

// --- Enabled Sensors --- 
#define num_analog    0		// Number of analog inputs being used (0=None ; 1=A0 ; 2=A0,A1 ; 3=A0,A1,A2)
#define is_decagon    0		// 1 if GS3 Decagon is being used

#define is_ms5803	  1

// --- Prebuilt Devices ---
#define is_ishield     0	// 1 to specify using Ishield (should enable only wifi as communication platform)
#define is_multiplexer 0	// 1 if tca9548a Multiplexer is being used. (Further customization in advanced options)
#define is_sapflow     0


// --- WiFi Settings ---
// Requires is_wifi to be set to 1 to take effect
#if is_wifi == 1
	#define DEFAULT_MODE      WPA_CLIENT_MODE	// AP_MODE, WPA_CLIENT_MODE or WEP_CLIENT_MODE
	#define DEFAULT_NETWORK   "OPEnS"			// Network SSID / name
	#define DEFAULT_PASSWORD  "arduino101"		// Network password
#endif

#define enable_hub_scripts 1

// ================================================================
// ================================================================ 
// ===                    ADVANCED OPTIONS                      === 
// ================================================================
// ================================================================


// --- Set Instance Number and UDP Port ---
// If not using channels, then the following 
// intial instance number port will be used
#if CHANNEL == -1
	#define INIT_INST    3	// Initial device instance number (normally 1-8 when using channels)
	#define INIT_PORT 9443	// Initial device UDP port (normally 1-8 when using channels)
#endif

// --- BUTTON OPTIONS ---
#define BUTTON_PIN 10               // Using on-board button, specify attached pin, transmitting
									// Button is on most feathers, but may not work on 
									// relay shield if pin 10 is used for relay


// ================================================================
// ===                PREBUILT DEVICE OPTIONS                   === 
// ================================================================
// These may override setting above to ensure all features of device are enabled


// --- Multiplexer Options ---
#if is_multiplexer == 1
	#define UPDATE_PERIOD 5000		// Milliseconds between multiplexer sensor list being updated
	
	// 1 to enable supported sensor type
	#define is_tsl2591         1	// Lux Sensor
	#define is_fxos8700        1	// Accelerometer / Magnetometer
	#define is_fxas21002       1	// Gyroscope
	#define is_zxgesturesensor 1	// ZX_Distance Sensor
	#define is_sht31d          1	// Temperature / Humidity
	#define is_mb1232          1	// Sonar
	#define is_mpu6050         1	// Accelerometer / Gyroscope
#endif


// --- Ishield Options ---
#if is_ishield == 1
	#define is_mpu6050  0			// Enables MPU6050 on Ishield
	#define is_neopixel 1			// Toggle based on whether Neopixels are being used 

	#if is_neopixel == 1			// Which Ishield ports to enable Neopixels for 
		#define NEO_0   0			// Port 0 (A0, closest to end of Ishield)
		#define NEO_1   0			// Port 1 (A1, middle port)
		#define NEO_2   1			// Port 2 (A2, port closest to MPU6050)
	#endif  
#endif


// --- Sapflowmeter Options ---
#if is_sapflow
	// #define hub_node_type 0       // 0: hub, 1: node
	#define is_lora           1      // enable LoRa
	#define is_rtc            1
	#define is_sd             1

	#if hub_node_type == 0       // if is hub
		#define is_ethernet   1
		#define is_pushingbox 1
	#elif hub_node_type == 1     // if is node
		#define num_analog    2      // two temperature sensors
		#define probe_type    0      // 0:TDM, 1: HRM
		#define heatpulse     2500   // For HRM probe heat pulse (e.g 2500:2.5 sec) 
		#define is_sht31d     1      // Temperature / Humidity
		#define senddelay     60000  // send data every 1 min
	#endif
#endif 


// ================================================================ 
// ===             COMMUNICATION PLATFORM OPTIONS               === 
// ================================================================

// --- LoRa Options ---
#if is_lora == 1
	#define LORA_HUB_ADDRESS 0			// Use 0-9 for SERVER_ADDRESSes
	#define RF95_FREQ      915.0		// Hardware specific, Tx must match Rx

	#if hub_node_type == 1 					// If Node
		#define NODE_ADDRESS 10			// 10 CLIENT_ADDRESSes belong to each SERVER_ADDRESS, 
	#endif								// 10-19 for 0, 20 - 29 for 1, etc.
	
	#define lora_bundle_fragment 0		// Splits bundles into smaller bundles to avoid overflowing size LoRa can send
#endif

// --- nRF Options --- 
#if is_nrf == 1
	#define NRF_HUB_ADDRESS 1			// Use 0-9 for SERVER_ADDRESSes
	
	#if hub_node_type == 1
		#define NRF_NODE_ADDRESS 0
	#endif

	#define nrf_bundle_fragment 0		// Splits bundles into smaller bundles to avoid overflowing size LoRa can send
#endif

#if is_ethernet == 1
	#include <Ethernet2.h>				// (this is needed for IPAddress object below, do not remove)
	
	//Use this for OPEnS Lab
	// byte mac[] = {0x98, 0x76, 0xB6, 0x10, 0x61, 0xD6}; 

	byte mac[] = {0x00, 0x23, 0x12, 0x12, 0xCE, 0x7D};    // mac address of Ethernet port
	IPAddress ip(128,193,56,138); 						  // device's IP address  				try to make this a string, so #include can be move to ethernet file
#endif


// --- FONA Options ---
#if is_fona == 1
	#define LOOM_DEBUG 1	// This is just temporary for now, as all Fona tests are done interactively through serial monitor
	#define fona_test  1    // This enables the Fona interactive testing Loop, note that this will override normal 
							//   Loom loop behavior until command to exit testing loop is issued
	#define fona_type 2G 	// Can be '2G' (808) or '3G' (5320A), currently only 2G is supported
#endif


// ================================================================ 
// ===                   TELEMETRY OPTIONS                      === 
// ================================================================

// --- Hub Options ---
#if hub_node_type == 0
	#define is_pushingbox 1 // only if Ethernet, WiFi, or cellular

	#define device_poll_refresh 60  // Seconds between re-searching for devices on the network

	// The following two defines are planned to be implemented, but are not in use currently
	// #define hub_input  LORA
	// #define hub_output ETHERNET
#endif


// ================================================================ 
// ===                 DATA LOGGING OPTIONS                     === 
// ================================================================

// --- PushingBox Options ---
#if is_pushingbox == 1	
	// Google Spreadsheet ID
	// (found betweeen the "docs.google.com/spreadsheets/d/" and "/edit..." in the URL; random string of characters)
	// #define spreadsheet_id "17XjrTjXENChYsHMVvKgePg8rsohwz0hyASkdeZZKROk"
	// #define spreadsheet_id "16K7gOczeewt-wVHdnMR0ttWSrcqmVvWvG-2zJxo1-MA"	    
	#define spreadsheet_id "1Hv2oME5sjumUXv36GtFV1Q7I83xnXu-f-ZrxUNsXS_U"

	// Google Spreadsheet Sheet/Tab number. Sent as parameter to PushingBox/Google Scripts
	#define tab_id  "sheet3"   

	// Required by PushingBox, specific to each scenario
	char device_id[]   = "v7ECCEF7A460E57A";
#endif

// --- Adafruit IO Options ---
#if is_adafruitio == 1
	#define AIO_USERNAME    "Goertzel"
	#define AIO_KEY         ""
#endif

// --- SD Options ---
#if is_sd
	// Timestamp formatting options:
	// 0: none, 1: date, 2: time, 3: date+time two fields, 4: data+time combined field
	#define sd_save_time_format 3
#endif

// --- RTC Options ---
#if is_rtc == 1
	// Select only one of the below options
	#define is_rtc3231 0 	// RTC DS 3231 Featherwing
	#define is_rtc8523 1	// RTC Adalogger Featherwing with PCF8523 RTC (the one with SD card)
#endif


// ================================================================
// ===              BETWEEN LOOP SLEEP OPTIONS                  === 
// ================================================================

// --- Delay between loops ---
#if is_lora == 0 						// Cannot not use with LoRa
	#define is_sleep_period 80			// Uncomment to use SleepyDog to transmit at intervals up to 16s and sleep in between. 
										// Change the value according to the length of your desired transmission interval
										// 80 seems to be a good amount, around 50 and lower may result in lost packets over WiFi
#else
	#define is_sleep_interrupt 11			// Uncomment to use Low-Power library to sit in idle sleep until woken by pin interrupt, parameter is pin to interrupt
#endif

