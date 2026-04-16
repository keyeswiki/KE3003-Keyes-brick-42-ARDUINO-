void attachInterrupt_fun_3() 
{  //中断服务程序
  Serial.println("   Vibrate");
}

void setup() 
{
  Serial.begin(9600);//波特率为9600
  pinMode(3, INPUT_PULLUP);//输入上拉
  attachInterrupt(digitalPinToInterrupt(3), attachInterrupt_fun_3, FALLING); //下降沿触发
}

void loop() 
{
  Serial.println("   It's still");  //循环打印
  delay(100);
}
