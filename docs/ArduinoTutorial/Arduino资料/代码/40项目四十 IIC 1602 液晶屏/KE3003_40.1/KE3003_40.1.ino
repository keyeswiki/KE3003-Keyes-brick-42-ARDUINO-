#include <Wire.h>
#include <LiquidCrystal_I2C.h>//通过i2c驱动lcd显示屏的库函数

LiquidCrystal_I2C mylcd(0x27, 16, 2);//将LCD地址设置为0x27（16个字符和2行）

void setup() 
{
  mylcd.init();//1602初始化
  mylcd.backlight();//设置背光
  mylcd.setCursor(0, 0);//设置光标为第一行第一个字符
  mylcd.print("  Hello World!");//打印
  mylcd.setCursor(0, 1);//设置光标为第二行第一个字符
  mylcd.print("  Hello Keyes!");
}

void loop() 
{

}
