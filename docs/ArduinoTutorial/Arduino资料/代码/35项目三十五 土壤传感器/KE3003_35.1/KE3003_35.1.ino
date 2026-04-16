int item = 0;
int Soil = A3; //土壤传感器接A3

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
}
void loop() 
{
  item = analogRead(A3);//读取模拟值
  Serial.print("Soil moisture:");
  Serial.println(item);//打印土壤湿度值
  delay(100);//延时100MS
}
