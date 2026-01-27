#include <DHT22.h>
#include <FS.h>
#include <LittleFS.h>

// ตั้งค่า Pin
#define pinDATA SDA // แนะนำให้ระบุเป็นตัวเลข Pin เช่น 21 (SDA ของ ESP32)

DHT22 dht22(pinDATA); 

void setup() {
  Serial.begin(115200);
  Serial.println("\n--- ESP32 Data Logger ---");

  // 1. เริ่มต้น LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS Mount Failed");
    return;
  }
  Serial.println("LittleFS mounted successfully");
}

void loop() {
  // 2. อ่านค่าจากเซนเซอร์
  float t = dht22.getTemperature();
  float h = dht22.getHumidity();

  if (dht22.getLastError() != dht22.OK) {
    Serial.print("Sensor error: ");
    Serial.println(dht22.getLastError());
  } else {
    // แสดงผลบน Serial Monitor
    Serial.print("Humidity: "); Serial.print(h, 1);
    Serial.print("\tTemperature: "); Serial.println(t, 1);

    // 3. เขียนค่าลงใน Text File
    // ใช้ FILE_APPEND เพื่อให้ข้อมูลใหม่ต่อท้ายข้อมูลเก่า (ไม่เขียนทับ)
    File file = LittleFS.open("/data.txt", FILE_APPEND); 
    if (file) {
      file.print("H:"); file.print(h, 1);
      file.print(" T:"); file.println(t, 1);
      file.close();
      Serial.println(">> Data saved to LittleFS");
    } else {
      Serial.println(">> Failed to open file for appending");
    }
  }

  delay(2000); // รอ 2 วินาทีตามสเปคเซนเซอร์
}
