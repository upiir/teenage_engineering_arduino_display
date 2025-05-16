// Learn how to recreate the segmented display from Teenage Engineering EP–133 K.O. II sampler 
// using the 8x8 LED matrix display driven by MAX7219 and Arduino UNO

// created by upir, 2025
// youtube channel: https://www.youtube.com/upir_upir

// Youtube video: https://youtu.be/CeOC7Bf_YKw
// Source files: https://github.com/upiir/teenage_engineering_arduino_display

// Links from the video:
// Do you like this video? You can buy me a coffee ☕: https://www.buymeacoffee.com/upir
// MAX7219 module: https://s.click.aliexpress.com/e/_DkX1kNF
// LED Matrix display 4x: https://s.click.aliexpress.com/e/_DlnFAYz
// 8x8 LED matrix with square pixels: https://s.click.aliexpress.com/e/_oBSRdcf
// Starting WOKWI project: https://wokwi.com/projects/384622406444001281
// LED Matrix online editor: https://xantorohara.github.io/led-matrix-editor
// Breadboard wires: https://s.click.aliexpress.com/e/_Dkbngin
// LedControl library: https://github.com/wayoda/LedControl
// 8x8 matrix to 16 segment video from Shiura: https://youtu.be/gt2merZcuno?si=QGEFlSMcsxfV3Z5m
// 8x8 matrix to 16 segment 3D file: https://www.thingiverse.com/thing:5696225
// Soviet EL segmented display: https://www.youtube.com/watch?v=p6mNbgtnFK8&ab_channel=KainkaLabs
// Soviet EL segmented display: https://www.youtube.com/watch?v=j0fvadiuw-4&ab_channel=VoltageGoat
// Teenage Engineering EP–133 K.O. II: https://teenage.engineering/store/ep-133
// Teenage Engineering medieval: https://teenage.engineering/store/medieval-quest-kit
// WOKWI Matrix Display documentation: https://docs.wokwi.com/parts/wokwi-max7219-matrix
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Autodesk Fusion: https://www.autodesk.com/products/fusion-360
// BambuLab X1C printer: https://shareasale.com/r.cfm?b=2353821&u=3422904&m=138211&urllink=&afftrack=

// Related videos 
// Arduino Wood Clock: https://youtu.be/50bVXHYW_9Q
// Arduino + Matrix Display (The Proper Way): https://youtu.be/jlhcDzS17vU
// Why are pixels square?: https://youtu.be/oLgUtjyKO6Q
// Pimp my Potentiometer -CHEAPER-: https://youtu.be/Bot865qmdsM
// Pimp My Potentiometer (again): https://youtu.be/sE3LSYoCqLQ


#include "LedControl.h" // LedControl library is used to interface the MAX7219 chip (and the LED Ring Light)
LedControl lc=LedControl(/*DIN*/11,/*CLK*/13,/*CS*/10,/*number of displays*/1); // initialization of the display

// 8x8 LED Matrix display to Arduino UNO connection
//
// Display -> Arduino UNO
// Data In (DIN) -> Pin 11
// Chip Select (CS) -> Pin 10
// Clock (CLK) -> Pin 13
// GND -> GND
// VCC -> 5V

// IMAGES array sets which segments should be lit, created using the LED Matrix online editor: https://xantorohara.github.io/led-matrix-editor
//
// open this link to prepopulate the editor with those images:
// https://xantorohara.github.io/led-matrix-editor/#3c4242424242423c|0040404040404000|3c0404081020203c|3c2020101020203c|0020201018242400|3c2020100804043c|3c2424180804043c|004040404040403c|3c2424181824243c|3c2020101824243c|0018180000181800|0024241818242400|3c0000000000003c|000000000000003c|0040404040404000|3c00000000000000|0002020202020200|0000000008040400|0000000010202000|0020201000000000|0004040800000000|0000000000181800|0018180000000000

const uint8_t IMAGES[][8] = {
{
  0b00111100,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01000010,
  0b01000010,
  0b00111100
},{
  0b00000000,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000000
},{
  0b00111100,
  0b00000100,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
  0b00100000,
  0b00111100
},{
  0b00111100,
  0b00000100,
  0b00000100,
  0b00001000,
  0b00001000,
  0b00000100,
  0b00000100,
  0b00111100
},{
  0b00000000,
  0b00100100,
  0b00100100,
  0b00011000,
  0b00001000,
  0b00000100,
  0b00000100,
  0b00000000
},{
  0b00111100,
  0b00100000,
  0b00100000,
  0b00010000,
  0b00001000,
  0b00000100,
  0b00000100,
  0b00111100
},{
  0b00111100,
  0b00100000,
  0b00100000,
  0b00010000,
  0b00011000,
  0b00100100,
  0b00100100,
  0b00111100
},{
  0b00111100,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000000
},{
  0b00111100,
  0b00100100,
  0b00100100,
  0b00011000,
  0b00011000,
  0b00100100,
  0b00100100,
  0b00111100
},{
  0b00111100,
  0b00100100,
  0b00100100,
  0b00011000,
  0b00001000,
  0b00000100,
  0b00000100,
  0b00111100
},{
  0b00000000,
  0b00011000,
  0b00011000,
  0b00000000,
  0b00000000,
  0b00011000,
  0b00011000,
  0b00000000
},{
  0b00000000,
  0b00100100,
  0b00100100,
  0b00011000,
  0b00011000,
  0b00100100,
  0b00100100,
  0b00000000
},{
  0b00111100,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100
},{
  0b00111100,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000010,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100
},{
  0b00000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b00000000
},{
  0b00000000,
  0b00100000,
  0b00100000,
  0b00010000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000100,
  0b00000100,
  0b00001000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00001000,
  0b00000100,
  0b00000100,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00010000,
  0b00100000,
  0b00100000,
  0b00000000
},{
  0b00000000,
  0b00011000,
  0b00011000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00011000,
  0b00011000,
  0b00000000
}};




void setup() {

  lc.shutdown(0, false);   // The MAX72XX is in power-saving mode on startup, we have to do a wakeup call
  lc.setIntensity(0, 15);  // Set the brightness to a medium values - value 0 (lowest brightness) -15 (highest brightness)
  lc.clearDisplay(0);      // clear the display
}

void loop() {  // main loop

  for (int digit = 0; digit < 10; digit++) {  // go over all the "images"
    for (int i = 0; i < 8; i++) {             // for every row
      lc.setRow(0, i, IMAGES[digit][i]);      // set the row to the content of the iamges array
    }
    delay(500);  // wait half a second
  }
}
