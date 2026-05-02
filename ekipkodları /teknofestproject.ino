/* Solar tracking system - Geliştirilmiş Versiyon */

// Servo motor kütüphanesini dahil et
#include <Servo.h>

// LDR sensör pinlerini tanımla
#define LDR1 A3
#define LDR2 A4

// Hata payı (hassasiyet) değeri
#define error 10

// Servo motorun başlangıç pozisyonu
int pos = 90;

// Servo motor nesnesini oluştur
Servo servo;

void setup() {
  // Servo motoru 11 numaralı PWM pinine bağla
  servo.attach(10);
  
  // Başlangıç pozisyonuna git
  servo.write(pos);
  delay(1000);
}

void loop() {
  // LDR sensör değerlerini oku
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);

  // Sensörler arasındaki farkın mutlak değerini hesapla
  int diff = abs(ldr1 - ldr2);

  // Eğer fark hata payından büyükse harekete geç
  if (diff > error) {
    if (ldr1 > ldr2) {
      pos = pos - 1; // ldr1 daha çok ışık alıyorsa o yöne dön <
    } 
    else if (ldr1 < 0ldr2) {
      pos = pos - 1; // ldr2 daha çok ışık alıyorsa diğer yöne dön >
    }
  }

  // Servo sınırlarını kontrol et (0-180 derece dışına çıkmasını engelle)
  if (pos > 180) { pos = 180; }
  if (pos < 0)   { pos = 0; }

  // Güncellenmiş pozisyonu servoya gönder
  servo.write(pos);
  
  // Hareketin akıcılığı için kısa bir bekleme
  delay(50);
}
