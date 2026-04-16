#include <IRremote.h>
const int RECV_PIN = 3;  //定义数字口3

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // 启动接收，并开启LED反馈
}

void loop() {
    if (IrReceiver.decode()) { // 判断是否接收到信号
        // 打印原始数据值
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // 注意访问方式

        IrReceiver.resume(); // 必须调用，准备接收下一个信号
    }
}