#include "sonar.h"
#include "ld293.h"

// Definir Pines para ser usados con el Sonar
#define trigPin 13
#define echoPin 12

//LD293 Input pins
#define enable_pin 11
#define input_1A 9
#define input_2A 5
#define input_3A 6
#define input_4A 3


long distance;
long dist_final;
long turn;

Sonar sonar(trigPin, echoPin);
LD293 motor_driver(input_1A, input_2A, input_3A, input_4A);

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = sonar.read();
  dist_final = distance;
  distance = sonar.read();
  dist_final += distance;
  dist_final /= 2;

  if (dist_final <=40){
    turn = random(0,2);
    if(turn == 0){
      motor_driver.stop();
      delay(500);
      motor_driver.left(255);
      delay(1000);
    }else{
      motor_driver.stop();
      delay(500);
      motor_driver.right(255);
      delay(1000);
    }
  }
  
  //Serial.print(distance);
  //  Serial.println(" cm");
    motor_driver.go(255);
    delay(500);
    
    /*
    motor_driver.left(255);
    delay(2000);
    motor_driver.right(255);
    delay(2000);
    motor_driver.stop();
    delay(5000);
    */
}
