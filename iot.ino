#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int pos = 0;
float t = 0;
float dist = 0;

void setup()
{
 lcd.begin(16,2);
  pinMode(LED_BUILTIN, OUTPUT);
   pinMode(LED_BUILTIN, OUTPUT);
 pinMode(18,OUTPUT); //trigger pin
 pinMode(19,INPUT);  //echo pin
 pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); //buzzer
 lcd.setCursor(0,1);
 lcd.print(" Water Level Detector");
 delay(2000);
}

void loop()
{
 lcd.clear();
 digitalWrite(20,LOW);
 digitalWrite(18,LOW);
 delayMicroseconds(2);
 digitalWrite(18,HIGH);
 delayMicroseconds(10);
 digitalWrite(18,LOW);
 delayMicroseconds(2);

 t=pulseIn(19,HIGH);
 dist=t*0.034/2;

 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print("Distance : ");
 lcd.print(dist/100);
 lcd.print(" m");
 delay(1000);

if(dist<40)
{
  tone(8, 523, 100);
  
 digitalWrite(20,HIGH);
 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print("Water level is rising. Kindly evacuate");
 delay(2000);
 // turn off tone function for pin 8:
  noTone(8);
  // play a note on pin 6 for 200 ms:
  tone(6, 880, 200); // play tone 69 (A5 = 880 Hz)
  delay(200); // Wait for 200 millisecond(s)
  // turn off tone function for pin 6:
  noTone(6);
  // play a note on pin 7 for 500 ms:
  tone(7, 988, 500); // play tone 71 (B5 = 988 Hz)
  delay(500); // Wait for 500 millisecond(s)
  // turn off tone function for pin 7:
  noTone(7);
  // play a note on pin 8 for 300 ms:
  tone(8, 1047, 300); // play tone 72 (C6 = 1047 Hz)
  delay(300); // Wait for 300 millisecond(s)
}
else
{
 digitalWrite(20,LOW);
 delay(2000);
}
}
