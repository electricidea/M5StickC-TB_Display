/******************************************************************************
 * Example for tb_display
 * 
 * Library for a simple text buffer scrolling display on the M5StickC.
 * Hague Nusseck @ electricidea
 * v1.2 02.Feb.2020
 * https://github.com/electricidea/M5StickC-TB_Display
 * 
 * This library makes it easy to display texts on the M5StickC.
 * The display behaves like a terminal: New text is added at the bottom.
 * The text scrolls up with every new line. The lines are automatically wrapped.
 * The display can be used in any orientation. 
 * 
 * This example shows characters from the serial port on the M5StickC display.
 * If a Keyboard-Hat is connected, also the characters from the Keyboard
 * are shown on the display.
 * 
 * Changelog:
 * v1.0 = - initial version
 * v1.1 = - Added delay parameter to tb_display_print_String function
 *        - Added text demo in Example (Button B on M5StickC)
 * v1.2 = - Supress of space characters as first character on a new row
 *          after a new line
 *        - Add a word wrapping fuction inside the print_char function
 * v1.3 = - Bugfix if the character that causes a word wrap is a space character
 * v1.4 = - Added "tb_display_delete_char" function
 *        - screen_xpos and text_buffer_write_pointer_x set in display_show function
 * v1.5 = - Bugfix if the character that causes a word wrap is a space character
 * v1.6 = Added case differentiation between M5StcikC und M5StickCPlus
 * 
 * M5StickC screen resolution:       80*160
 * M5StickC-plus screen resolution: 135*240
 * 
 * Distributed as-is; no warranty is given.
 ******************************************************************************/
#include <Arduino.h>

// M5StickCPlus Library:
// Install for PlatformIO:
// pio lib install "m5stack/M5StickCPlus"
#include "M5StickCPlus.h"

// M5StickC Library:
// Install for PlatformIO:
// pio lib install "M5StickC"
//#include <M5StickC.h>

#include "tb_display.h"

// I2C Adress of the Keyboard Hat
#define CARDKB_ADDR 0x5F

// Display brightness level
// possible values: 7 - 15
uint8_t screen_brightness = 15; 

// scren Rotation values:
// 1 = Button right
// 2 = Button above
// 3 = Button left
// 4 = Button below
int screen_orientation = 3;


void setup() {
  // initialize the M5Stack object
  m5.begin();
  // initialize I2C for the Keyboard Hat (not required)
  Wire.begin(0, 26);
  // Grove-Connector: Pin 32 and 33
  //Wire.begin(32, 33);
  // set screen brightness
  //M5.Axp.ScreenBreath(screen_brightness);
  M5.Lcd.setTextColor(TFT_WHITE);  

  // print a welcome message over serial porta
	Serial.println("===================");
	Serial.println("     M5StickC");
	Serial.println("Textbuffer Display");
	Serial.println(" 29.07.2024 v1.6");
	Serial.println("===================");

  // init the text buffer display and print welcome text on the display
  tb_display_init(screen_orientation);
  tb_display_print_String("M5StickC\n\nTextbuffer Display\n\n");
}


void loop() {
  M5.update();

  // change the display orientation if Button A is pressed
  if (M5.BtnA.wasPressed()){
    screen_orientation++;
    if(screen_orientation > 4)
      screen_orientation = 1;
    // init the text buffer display with the new orientation
    tb_display_init(screen_orientation);
    // different text alignment for landscape or portrait mode
    switch (screen_orientation) {
      case 1: case 3: {
        tb_display_print_String("        M5StickC\n\n   Textbuffer Display\n\n");
        break;
      }
      case 2: case 4: {
        tb_display_print_String(" M5StickC\n\nTextbuffer\n  Display\n\n\n\n\n");
        break;
      }
      default: {
        break;
      }
    }
  }

  // Display a long Text if Button B is pressed
  if (M5.BtnB.wasPressed()){
    // note:
    // with 85ms Character delay, the display looks more
    // like Teletype or a typewriter
    tb_display_print_String("The quick brown fox jumps over the lazy dog and was surprised that he used all letters of the alphabet.", 85);
  }

  // check for serial input and print the received characters
  while(Serial.available() > 0){
    char data = Serial.read();
    tb_display_print_char(data);
    Serial.write(data);
  }

  
  // check for input from the Keyboard Hat and print the received characters
  Wire.requestFrom(CARDKB_ADDR, 1);
  while (Wire.available())
  {
    char c = Wire.read(); // receive a byte as characterif
    if (c != 0)
    {
      if (c == 13) { //0x0D = CR = '\r'
        // Map CR to LF (0x0A)
        tb_display_print_char('\n');
        Serial.write('\n');
      } else {
        if(c == 8){ // del on the Keyboard
          tb_display_delete_char();
        } else {
          tb_display_print_char(c);
          Serial.write(c);
        }
      }
    }
  }
}

