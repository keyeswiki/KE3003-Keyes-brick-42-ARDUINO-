#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C mylcd(0x27, 16, 2);
int item = 0;

void setup() 
{
  mylcd.init();
  mylcd.backlight();
  pinMode(3, OUTPUT);
}

void loop() 
{
  item = analogRead(A3);
  mylcd.setCursor(1 - 1, 1 - 1);
  mylcd.print("Alcoho:");
  if (item < 10) 
  {
    mylcd.setCursor(1 - 1, 2 - 1);
    mylcd.print(item);
    mylcd.setCursor(2 - 1, 2 - 1);
    mylcd.print("   ");
    digitalWrite(3, LOW);
  }
  else if (item < 100) 
  {
    mylcd.setCursor(1 - 1, 2 - 1);
    mylcd.print(item);
    mylcd.setCursor(3 - 1, 2 - 1);
    mylcd.print("   ");
    digitalWrite(3, LOW);
  }
  else 
  {
    mylcd.setCursor(1 - 1, 2 - 1);
    mylcd.print(item);
    digitalWrite(3, HIGH);
  }
  delay(100);
}
