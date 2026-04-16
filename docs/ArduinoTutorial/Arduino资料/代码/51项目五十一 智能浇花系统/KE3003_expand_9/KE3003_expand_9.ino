volatile int item = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() 
{
  item = analogRead(A4);
  Serial.println(item);
  if (item < 200) 
  {
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
  } 
  else 
  {
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
  }
  delay(100);
}
