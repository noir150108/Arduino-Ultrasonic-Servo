#include <Servo.h>

const int trigPin = 9;
const int echoPin = 8;
Servo myServo;

void setup() {
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);   
  
  Serial.begin(9600); 
  myServo.attach(3); 
}

void loop() {
  // Đo khoảng cách từ cảm biến siêu âm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Giới hạn khoảng cách đọc được trong phạm vi từ 0 đến 180cm để xử lý
  if (distance > 180) distance = 180;

  // HÀM ÁNH XẠ THẦN KỲ:
  // Nếu khoảng cách chạy từ 0 -> 180cm, tự động tính toán ra góc quay từ 0 -> 180 độ tương ứng
  int gocServo = map(distance, 0, 180, 0, 180);

  // Ép Servo quay theo góc vừa tính toán
  myServo.write(gocServo);

  // In báo cáo lên màn hình máy tính để kiểm tra
  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.print(" cm ---> Goc Servo: ");
  Serial.print(gocServo);
  Serial.println(" do");

  // Đèn led chớp nháy cảnh báo nếu vật cản quá gần (dưới 30cm)
  if (distance < 30) {
    digitalWrite(12, HIGH); digitalWrite(11, LOW);  delay(50);             
    digitalWrite(12, LOW);  digitalWrite(11, HIGH); delay(50); 
  } else {
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(100); 
  }
}
