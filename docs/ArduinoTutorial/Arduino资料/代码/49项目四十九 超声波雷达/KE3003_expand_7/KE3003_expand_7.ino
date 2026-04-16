volatile int distance = 0;

float checkdistance_12_13() 
{
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(13, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup() 
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{
  distance = checkdistance_12_13();
  Serial.println(distance);
  if (distance <= 10)
  {
    tone(3, 880);
    delay(100);
    noTone(3);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  } 
  else if (distance > 10 && distance <= 20) 
  {
    tone(3, 532);
    delay(200);
    noTone(3);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  } 
  else 
  {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
}
