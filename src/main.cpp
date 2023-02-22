#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(D6, D5);

#define Motor_L D3
#define Motor_R D4

#define Switch1 D6
#define Switch2 D7

void setup() {
  Serial.begin(9600);
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);

  pinMode(Motor_L, OUTPUT);
  pinMode(Motor_R, OUTPUT);

  digitalWrite(Motor_L, 0);
  digitalWrite(Motor_R, 1);
  delay(2000);
  digitalWrite(Motor_L, 0);
  digitalWrite(Motor_R, 0);

}

void loop() {

  int v_switch1 = digitalRead(Switch1);
  int v_switch2 = digitalRead(Switch2);

  int distance = ultrasonic.read();
  Serial.println(distance);

  delay(1000);

  if ( distance >= 0 && distance <= 7){

    if ( v_switch1 == 1 && v_switch2 == 0){
      Serial.println("is open");
      digitalWrite(Motor_L, 1);
      digitalWrite(Motor_R, 0);
      delay(2500);
    } 
  } else if ( v_switch1 == 0 && v_switch2 == 1) {
      Serial.println("is close");
      digitalWrite(Motor_L, 0);
      digitalWrite(Motor_R, 1);
      delay(2500);

      digitalWrite(Motor_L, 0);
      digitalWrite(Motor_R, 0);
    }
}