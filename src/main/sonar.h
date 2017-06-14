#ifndef SONAR_H_
#define SONAR_H_
/*
 * Definicion de Clase para el SONAR HC-SR04
 * Autor: Juan Carlos Ortiz (ortizjuan2@gmail.com)
 * Fecha: Abril 20 de 2017
 */

/*
 * TODO: Ensure timeout handling when writing to digital pins
 */

/*
 * Class Sonar
 */ 
class Sonar {
  public:
    long duration, distance;
    byte trigPin;
    byte echoPin;
    Sonar(byte trgPn, byte echPn){
      trigPin = trgPn;
      echoPin = echPn;
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    long read(){
      digitalWrite(trigPin, LOW); 
      delayMicroseconds(2); 
      digitalWrite(trigPin, HIGH);
      // IO Trigger for at least 10us high level signal
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;

      if (distance > 400 || distance <= 0){
        distance = -1;
        
      }
      return distance;
    }
};




#endif /* SONAR_H_ */
