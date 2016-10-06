// Configuration - SET THESE!
#define OUTPUT_PIN  (0x80)  // Set to whatever UCB0SIMO is on your processor (Px.7 here)
#define NUM_LEDS    (12)    // NUMBER OF LEDS IN YOUR STRIP

// Useful typedefs
typedef unsigned char u_char;	// 8 bit
typedef unsigned int u_int;     // 16 bit

// Transmit codes
#define HIGH_CODE   (0xF0)      // b11110000
#define LOW_CODE    (0xC0)      // b11000000

// Configure processor to output to data strip
void initStrip(void);

// Send colors to the strip and show them. Disables interrupts while processing.
void showStrip(void);

// Set the color of a certain LED
void setLEDColor(u_int p, u_char r, u_char g, u_char b);

// Clear the color of all LEDs (make them black/off)
void clearStrip(void);

// Fill the strip with a solid color. This will update the strip.
void fillStrip(u_char r, u_char g, u_char b);
