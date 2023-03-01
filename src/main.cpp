#include <Arduino.h>
#include <Wire.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(D6, D5);

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

}

void loop() {

  int distance = ultrasonic.read();

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
}