
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define LDRPIN A0
#define LEDPIN 13

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  int light = analogRead(LDRPIN);

  if (isnan(temp)) {
    Serial.println("Ошибка чтения температуры!");
  } else {
    Serial.print("Температура: ");
    Serial.print(temp);
    Serial.print(" °C, Освещенность: ");
    Serial.println(light);
  }

  int delayTime = map(temp, 20, 35, 1000, 200);
  digitalWrite(LEDPIN, HIGH);
  delay(delayTime);
  digitalWrite(LEDPIN, LOW);
  delay(delayTime);
}
