#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Ultrasonic ultrasonic(D7, D8);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.read();

  lcd.setCursor(0,0);
  lcd.print("distance : ");
  lcd.print(distance);
  lcd.print("cm");
  delay(1000);
  lcd.clear();
}