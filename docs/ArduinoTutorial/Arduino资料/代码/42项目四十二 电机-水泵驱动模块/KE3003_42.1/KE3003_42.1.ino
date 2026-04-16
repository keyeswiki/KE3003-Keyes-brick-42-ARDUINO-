void setup() 
{
  //设置电机引脚为输出
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop()
 {
  //逆时针转
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delay(2000);
  //停止
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  delay(1000);
  //顺时针转
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delay(2000);
  //停止
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  delay(1000);
}
