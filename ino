#include <Adafruit_BMP280.h>

// ---------------- ПІНИ CS ----------------

// Chip Select для першого датчика
#define BMP_CS1 5

// Chip Select для другого датчика
#define BMP_CS2 4


// ---------------- ДВА ДАТЧИКИ ----------------

// Передаємо CS у конструктор → бібліотека сама знає,
// який датчик "активувати"
Adafruit_BMP280 bmp1(BMP_CS1); 
Adafruit_BMP280 bmp2(BMP_CS2); 


void setup() {

  Serial.begin(115200);
  while (!Serial);

  Serial.println(F("Тест 2-х BMP280 через SPI"));


  // ---------- ПЕРШИЙ ДАТЧИК ----------

  if (!bmp1.begin()) {
    Serial.println(F("Помилка: Датчик 1 (CS 5) не знайдено!"));
    while (1);
  }

  // ---------- ДРУГИЙ ДАТЧИК ----------

  if (!bmp2.begin()) {
    Serial.println(F("Помилка: Датчик 2 (CS 4) не знайдено!"));
    while (1);
  }

  Serial.println(F("Обидва датчики SPI готові!"));
}


void loop() {

  // ---------- ДАТЧИК 1 ----------

  Serial.print("Датчик 1: ");
  Serial.print(bmp1.readTemperature());
  Serial.print(" *C, ");

  Serial.print(bmp1.readPressure() / 100.0F);
  Serial.println(" hPa");


  // ---------- ДАТЧИК 2 ----------

  Serial.print("Датчик 2: ");
  Serial.print(bmp2.readTemperature());
  Serial.print(" *C, ");

  Serial.print(bmp2.readPressure() / 100.0F);
  Serial.println(" hPa");


  Serial.println("------------------------------------");

  delay(2000);
  // оновлення кожні 2 секунди
}
