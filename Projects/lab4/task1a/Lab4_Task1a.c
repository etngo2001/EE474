// Eugene Ngo
// 1965514
// 12/4/2022
// This is the main function for lab 4 task 1 part a. This function fills the LCD display in with light blue

#include "SSD2119_Display.h"

int main() {
  LCD_Init();
  LCD_ColorFill(Color4[11]);
  return 0;
}