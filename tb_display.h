
/******************************************************************************
 * tb_display.h
 * Library for a simple text buffer scrolling display on the M5StickC.
 * Hague Nusseck @ electricidea
 * v1.0 01/19/2020
 * https://github.com/electricidea/M5StickC-TB_Display
 * 
 * This library makes it easy to display texts on the M5StickC.
 * The display behaves like a terminal: New text is added at the bottom.
 * The text scrolls up with every new line. The lines are automatically wrapped.
 * The display can be used in any orientation. 
 * 
 * 
 * Distributed as-is; no warranty is given.
 ******************************************************************************/


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
//           tb_display_print_String(const char *s);
// print a string
// The string is added to the text buffer and directly printed
// on the screen.
// The text is automatically wrapped if longer than the display
// example: 
//    tb_display_print_String("a new line\n");
//    tb_display_print_String("one\nand two lines\n");
//
//    char String_buffer[128]; 
//    snprintf(String_buffer, sizeof(String_buffer), "\nthe value: %i",value);
//    tb_display_print_String(String_buffer);
// =============================================================
void tb_display_print_String(const char *s);

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