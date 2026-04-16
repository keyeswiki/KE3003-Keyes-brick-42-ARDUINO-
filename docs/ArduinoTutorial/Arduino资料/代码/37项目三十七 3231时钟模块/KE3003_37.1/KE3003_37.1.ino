//DS3231时钟模块的库
#include <RtcDS3231.h>
#include <SoftwareWire.h>
SoftwareWire myWire(A4, A5); //i2c接口
RtcDS3231<SoftwareWire> Rtc(myWire);

void setup() 
{
  Serial.begin(57600);//设置波特率为57600
  Rtc.Begin();
  Rtc.SetIsRunning(true);
  Rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));
}

void loop() 
{
  //打印年/月/日/时/分/秒/星期
  Serial.print(Rtc.GetDateTime().Year());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Month());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Day());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Hour());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Minute());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Second());
  Serial.print("    ");
  Serial.println(Rtc.GetDateTime().DayOfWeek());
  delay(1000);//延时1秒
}
