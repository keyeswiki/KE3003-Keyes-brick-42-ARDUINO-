int item = 0;
int Water = A3; //水蒸气传感器的PIN为A3

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
}

void loop() 
{
  item = analogRead(A3);  //读取水蒸气传感器的值
  Serial.print("Water:");
  Serial.println(item);
  delay(100);
}
