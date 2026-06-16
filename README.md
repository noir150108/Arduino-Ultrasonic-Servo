# 🚪 Dự Án: Cửa Tự Động Thông Minh (Arduino)

Dự án sử dụng cảm biến siêu âm để đo khoảng cách vật cản, tự động điều khiển góc quay của động cơ Servo để đóng/mở cửa và nháy đèn LED cảnh báo nguy hiểm.

---

### ⚙️ Linh kiện sử dụng
* **Bo mạch chính:** Arduino Uno R3
* **Cảm biến:** Siêu âm HC-SR04 (Đo khoảng cách)
* **Động cơ:** Servo SG90 (Cơ cấu đóng mở)
* **Tín hiệu:** 2 Đèn LED (Đỏ / Xanh dương) + 2 Điện trở 220 Ohm

---

### 🔌 Sơ đồ nối dây (Pinout)
* **Cảm biến siêu âm:** `Trig` -> Pin 9, `Echo` -> Pin 8
* **Động cơ Servo:** `Signal` -> Pin 3
* **Đèn LED:** Đỏ -> Pin 12, Xanh -> Pin 11

---

### 🧠 Nguyên lý hoạt động
* Khi vật cản ở xa **(> 20cm)**: Servo giữ ở góc `0 độ` (Cửa đóng), đèn tắt.
* Khi vật cản đến gần **(< 20cm)**: Servo lập tức quay góc `90 độ` (Mở cửa), đồng thời cụm đèn LED Đỏ-Xanh chớp tắt liên tục để báo động.
