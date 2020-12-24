
#include <LiquidCrystal.h>

#define RS 7
#define EN 8
#define D4 9
#define D5 10
#define D6 11
#define D7 12

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Hallo Welt");
  lcd.setCursor(0, 1);
  lcd.print("Ich liebe Vim!");
}

void loop()
{
}
