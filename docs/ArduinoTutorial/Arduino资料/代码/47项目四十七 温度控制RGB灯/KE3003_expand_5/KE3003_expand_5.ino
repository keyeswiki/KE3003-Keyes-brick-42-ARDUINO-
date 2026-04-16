volatile int val;

void setup() 
{
  val = 0;
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{
  val = analogRead(A3);
  Serial.print("Temperature:");
  Serial.println(val);
  delay(100);
  if (val <= 400) 
  {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);

  } 
  else if (val > 400 && val <= 600) 
  {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  } 
  else if (val > 600) 
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
