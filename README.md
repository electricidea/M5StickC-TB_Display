# M5StickC Text Buffer Scrolling Display
This small and simple library makes it easy to display texts on the M5StickC.

![M5StickC](/images/M5StickC_001.jpg)

The display behaves like a terminal: New text is added at the bottom and scrolls up with every new line. 
The lines are automatically wrapped. 
Any orientation of the M5StickC can be used!

## How it works:

A text buffer is used to store the text which is to be displayed. Depending on whether the display is used in portrait or landscape orientation, the text buffer has 5 lines or 10 lines.
New characters are always written in the last line of the buffer, so that the text scrolls up like a classic terminal. 
The number of possible characters per line varies between characters. In the portrait orientation, between 8 and 23 characters fit in one line. A typical text needs 9 to 11 characters. In the landscape orientation between 19 and 50 characters fit in one line. A typical text requires between 21 and 24 characters.
When a new character is to be displayed, it draws the function on the display and checks if the position behind the character is outside the display. If so, the line is automatically wrapped and the character is displayed as the first character in the new line.

An example can be viewed here:
[Example Video](https://youtu.be/PCo_sT5_lpc)

The project page on hackster.io can be found here:
[hackster.io page](https://www.hackster.io/hague/m5stickc-textbuffer-scrolling-display-fb6428)

## How to use it:

The initialization is very simple. You only need to call the init function with the desired orientation as parameter:
```c++
void tb_display_init(int ScreenRotation);
```
Either single characters can be written into the buffer, or a whole string. The following functions are available:
```c++
void tb_display_print_char(byte data);
void tb_display_print_String(const char *s, int chr_delay = 0);
```
The print_string function has an optional parameter for a delay, so that the display looks like an old teletype or typewriter. 

With the global variable tb_display_word_wrap the word-wrapping function can be switched on or off. If this function is active, then the line is wrapped before the last uncompleted word and the word is displayed in the new line.

## Environment:

The files work fine with PlatformIO. For use with the Arduino IDE only really minor changes are required:
Change main.cpp to tb_display.ino and place the .cpp .h and .ino into a directory.

## Changelog

* v1.0
  * initial version
* v1.1
  * Added delay parameter to tb_display_print_String function
  * Added text demo in Example (Button B on M5StickC)
* v1.2
  * Supress of space characters as first character on a new row after a new line
  * Add a word wrapping fuction inside the print_char function
* v1.3
  * Bugfix if the character that causes a word wrap is a space character
