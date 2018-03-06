#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
void setup() {
  lcd.begin(16,2);

  lcd.print("Hello aziz");
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 13; i++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int i = 0; i < 16; i++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
  delay(1000);
}
