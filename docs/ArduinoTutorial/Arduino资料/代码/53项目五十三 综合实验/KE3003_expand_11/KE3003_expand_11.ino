#include <Wire.h>
#include <I2Cdev.h>
#include <ADXL345.h>
#include <dht11.h>
#include <IRremote.h>
dht11 DHT;
#define DHT11_PIN 8
const int RECV_PIN = 4;  
int PushCounter = 0;
int State = 1;
int LastState = 1;
int PushCounter1 = 0;
int val1 = 0;
int val2 = 0;
int x = 0;
int y = 0;
int button = 0;
float ADXL345_X = 0;
float ADXL345_Y = 0;
float ADXL345_Z = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int distance = 0;

ADXL345 accel;
decode_results results;

float checkdistance_12_13() {
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(13, HIGH) / 58.00;
  delay(10);
  return distance;
}

void yushu_0() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(300);
}

void yushu_1() {
  if (IrReceiver.decode()) {  // 判断是否接收到信号
    // 打印原始数据值
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // 注意访问方式

    IrReceiver.resume();  // 必须调用，准备接收下一个信号
  }
}

void yushu_2() {
  int chk;
  chk = DHT.read(DHT11_PIN);  // READ DATA
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM:  //校检和错误返回
      break;
    case DHTLIB_ERROR_TIMEOUT:  //超时错误返回
      break;
    default:
      break;
  }
  // DISPLAT DATA
  Serial.print("humidity:");
  Serial.print(DHT.humidity);
  Serial.print("   temperature:");
  Serial.println(DHT.temperature);
  delay(200);
}

void yushu_3() {
  x = analogRead(A0);
  y = analogRead(A1);
  button = digitalRead(7);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("    Y:");
  Serial.print(y);
  Serial.print("    B:");
  Serial.println(button);
  delay(100);
}

void yushu_4() {
  ADXL345_X = accel.getAccelerationX();
  ADXL345_Y = accel.getAccelerationY();
  ADXL345_Z = accel.getAccelerationZ();
  Serial.print("ADXL345_X:");
  Serial.print(ADXL345_X);
  Serial.print("    ADXL345_Y:");
  Serial.print(ADXL345_Y);
  Serial.print("    ADXL345_Z:");
  Serial.println(ADXL345_Z);
  delay(50);
}

void yushu_5() {
  val3 = analogRead(A3);
  val4 = map(val3, 0, 1023, 0, 255);
  Serial.println(val4);
  analogWrite(5, val4);
  delay(100);
}

void yushu_6() {
  val5 = analogRead(A2);
  Serial.println(val5);
  delay(100);
}

void yushu_7() {
  distance = checkdistance_12_13();
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

void setup() {
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  accel.initialize();

  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);  // 启动接收，并开启LED反馈

  pinMode(7, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}

void loop() {
  State = digitalRead(2);
  if (State != LastState) {
    if (State == 0) {
      PushCounter = PushCounter + 1;
    }
  }

  LastState = State;
  PushCounter1 = (long)(PushCounter) % (long)(8);
  if (PushCounter1 == 0) {
    yushu_0();
  } else if (PushCounter1 == 1) {
    yushu_1();
  } else if (PushCounter1 == 2) {
    yushu_2();
  } else if (PushCounter1 == 3) {
    yushu_3();
  } else if (PushCounter1 == 4) {
    yushu_4();
  } else if (PushCounter1 == 5) {
    yushu_5();
  } else if (PushCounter1 == 6) {
    yushu_6();
  } else if (PushCounter1 == 7) {
    yushu_7();
  }
}
