
/******************************************************************************
 * tb_display.h
 * Library for a simple text buffer scrolling display on the M5StickC.
 * Hague Nusseck @ electricidea
 * v1.3 04.Feb.2020
 * https://github.com/electricidea/M5StickC-TB_Display
 * 
 * This library makes it easy to display texts on the M5StickC.
 * The display behaves like a terminal: New text is added at the bottom.
 * The text scrolls up with every new line. The lines are automatically wrapped.
 * The display can be used in any orientation. 
 * 
 * Changelog:
 * v1.0 = - initial version
 * v1.1 = - Added delay parameter to tb_display_print_String function
 *        - Added text demo in Example (Button B on M5StickC)
 * v1.2 = - Supress of space characters as first character on a new row
 *          after a new line
 *        - Add a word wrapping fuction inside the print_char function
 * v1.3 = - Bugfix if the character that causes a word wrap is a space character
 * 
 * Distributed as-is; no warranty is given.
 ******************************************************************************/

// Enable or disable Waord Wrap
extern boolean tb_display_word_wrap;

// =============================================================
//           tb_display_init(int ScreenRotation);
// Initialization of the Text Buffer and Screen
// ScreenRotation values:
// 1 = Button right
// 2 = Button above
// 3 = Button left
// 4 = Button below
// Display size of M5StickC = 160x80pixel
// With TEXT_HEIGHT=16, the screen can display:
//    5 rows of text in landscape mode
//   10 rows of text in portrait mode
// =============================================================
void tb_display_init(int ScreenRotation);

// =============================================================
//           tb_display_show();
// clear the screen and display the text buffer
// =============================================================
void tb_display_show();

// =============================================================
//           tb_display_clear();
// clear the text buffer
// without refreshing the screen
// call tb_display_show() afterwards to clear the screen
// =============================================================
void tb_display_clear();

// =============================================================
//           tb_display_new_line();
// creates a new line and scroll the display upwards
// =============================================================
void tb_display_new_line();

// =============================================================
//        tb_display_print_String(const char *s, int chr_delay = 0);
// print a string
// The string is added to the text buffer and directly printed
// on the screen.
// The otional parameter "chr_delay" allows a "character by character"
// processing of the String. Then, it looks like Teletype or Typewriter
// The delay is in milliseconds.
// The text is automatically wrapped if longer than the display
// example: 
//    tb_display_print_String("a new line\n");
//    tb_display_print_String("one\nand two lines\n");
//
//    char String_buffer[128]; 
//    snprintf(String_buffer, sizeof(String_buffer), "\nthe value: %i",value);
//    tb_display_print_String(String_buffer);
//
//    std::string msg;
//    msg = ss.str();
//    const char * c_msg = msg.c_str();
//    tb_display_print_String(c_msg);
// =============================================================
void tb_display_print_String(const char *s, int chr_delay = 0);

// =============================================================
//           tb_display_print_char(byte data);
// print a single character
// the character is added to the text buffer and
// directly printed on the screen.
// The text is automatically wrapped if longer than the display
// example: 
//    tb_display_print_char('X');
// =============================================================
void tb_display_print_char(byte data);