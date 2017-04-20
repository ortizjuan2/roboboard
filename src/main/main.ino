#include "sonar.h"
#include "ld293.h"

// Definir Pines para ser usados con el Sonar
#define trigPin 13
#define echoPin 12
#define input_1A 3
#define input_2A 5
#define input_3A 6
#define input_4A 9

long distance;
Sonar sonar(trigPin, echoPin);
LD293 motor_driver(input_1A, input_2A, input_3A, input_4A);

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = sonar.read();
  Serial.print(distance);
    Serial.println(" cm");
    motor_driver.go(255);
    delay(2000);
    motor_driver.left(255);
    delay(2000);
    motor_driver.right(255);
    delay(2000);
    motor_driver.stop();
    delay(5000);
}
