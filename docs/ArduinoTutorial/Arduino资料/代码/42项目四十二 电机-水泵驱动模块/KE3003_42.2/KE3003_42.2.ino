void setup() 
{
  //设置水泵引脚为输出
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() 
{
  //开水泵
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delay(3000);
  //关水泵
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  delay(1000);
}
