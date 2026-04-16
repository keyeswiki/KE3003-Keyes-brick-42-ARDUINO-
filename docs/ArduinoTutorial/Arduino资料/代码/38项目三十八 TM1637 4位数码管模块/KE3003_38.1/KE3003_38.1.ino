#include "SevenSegmentTM1637.h" // 导入SevenSegmentTM1637库

/* 初始化全局TM1637显示对象
  构造函数有两个参数，时钟引脚号和数字输出引脚号：
  SevenSegmentTM1637（pinCLK，pinDIO）;
*/
int PIN_CLK = A3;   //定义CLK引脚为数字口A3
int PIN_DIO = A2;   //定义DIO引脚为数字口A2
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

// run setup code
void setup() 
{
  Serial.begin(9600);         // 设置波特率为9600
  display.begin();            // 初始化显示
  display.setBacklight(100);  // 设置亮度为100%
  delay(1000);                // wait 1000 ms
}

void loop() 
{
  display.print("LOOP");                // 显示LOOP
  delay(1000);                          // 等待1秒
  display.clear();                      // 清除显示
  for (uint8_t i = 0; i < 100; i++)    // 循环100次
  {
    display.print(i);                   // 显示计数
    delay(100);                         // 延时100ms
  }
  display.clear();                      // 清除显示
  display.print("SUCC");                // 显示SUCC
  display.blink();                      // 闪烁SUCC
  delay(1000);                          // 等待1秒
}
