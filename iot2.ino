#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float value;
int tmp = A0;
void setup()
{
  pinMode(tmp,INPUT);
}

void loop()
{
  value = analogRead(tmp)*0.004882814;
    value = (value - 0.5) * 100.0;
    lcd.setCursor(0,1);
  lcd.print("Tmp:");
    lcd.print(value);
    lcd.print(" C");
   for (int i = 0; i < 10; i++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
    
    lcd.clear();
}
