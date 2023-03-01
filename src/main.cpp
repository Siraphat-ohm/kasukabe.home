#include <Arduino.h>
#include <Wire.h>
#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>

Ultrasonic ultrasonic(D6, D5);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define Motor_L D3
#define Motor_R D4

bool isOpen = true;
bool isClose = false;

void setup() {
  Serial.begin(9600);

  pinMode(Motor_L, OUTPUT);
  pinMode(Motor_R, OUTPUT);

  digitalWrite(Motor_L, 0);
  digitalWrite(Motor_R, 1);
  delay(2000);
  digitalWrite(Motor_L, 0);
  digitalWrite(Motor_R, 0);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.clear();

}

void loop() {

  int distance = ultrasonic.read();
  lcd.print("distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.clear();

  if ( distance >= 0 && distance <= 7) {

    isClose = true;
    if ( isOpen ) {
      digitalWrite(Motor_L, 1);
      digitalWrite(Motor_R, 0);
      delay(2500);
      isOpen = false;
    } 

  } else if( isClose ) {
      digitalWrite(Motor_L, 0);
      digitalWrite(Motor_R, 1);
      delay(2500);
      isOpen = true;
      isClose = false;

  } else {
      digitalWrite(Motor_L, 0);
      digitalWrite(Motor_R, 0);
  }

  Serial.print(isOpen);
  Serial.println();

  Serial.print(isClose);
  Serial.println();
  delay(1000);
}