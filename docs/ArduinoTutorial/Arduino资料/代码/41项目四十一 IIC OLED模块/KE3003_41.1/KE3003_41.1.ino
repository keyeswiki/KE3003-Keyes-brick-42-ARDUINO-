
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void page1() 
{
  u8g2.setFont(u8g2_font_timR12_tf);//12号罗马字体
  u8g2.setFontPosTop();//设置输出位置
  u8g2.setCursor(0, 0);//设置光标为0,0(最大为128,64)
  u8g2.print("Hello World");//显示"Hello World"
  u8g2.setFont(u8g2_font_timR18_tf);////18号罗马字体
  u8g2.setFontPosTop();//设置输出位置
  u8g2.setCursor(0, 20);//设置光标为0,20
  u8g2.print("Hello Keyes");//显示"Hello Keyes"
  u8g2.setFont(u8g2_font_open_iconic_all_2x_t);//设置字体
  u8g2.drawGlyph(100, 30 + 2 * 8, 187);//显示位置和图案
}

void setup() 
{
  u8g2.setI2CAddress(0x3C * 2);
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void loop() 
{
  u8g2.firstPage();   //调用此过程,标志着图像循环的开始
  do
  {
    page1();
  } 
  while (u8g2.nextPage());  //调用此过程,标志着图像循环的结束
}
