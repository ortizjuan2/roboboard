#include "sonar.h"
#include "ld293.h"
#include <SoftwareSerial.h>

// Definir Pines para ser usados con el Sonar
#define trigPin 13
#define echoPin 12

// Definir Pins para el Bluetooth
#define RXBTH 10
#define TXBTH 11

//LD293 Input pins
#define enable_pin 11
#define input_1A 9
#define input_2A 5
#define input_3A 6
#define input_4A 3


SoftwareSerial mySerial(RXBTH, TXBTH); // RX, TX
String cmd = ""; // Bluetooth command
int direction = 0;

long distance;
long dist_final;
long turn;

int mode = 0; // 0 = Autonomo, 1 = Manual


Sonar sonar(trigPin, echoPin);
LD293 motor_driver(input_1A, input_2A, input_3A, input_4A);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  Serial.setTimeout(50);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  
}

void loop() {

  /*
   * 
   * if (mySerial.available()) {
    cmd = mySerial.readString();
    //Serial.write(mySerial.read());
    Serial.println(cmd);
  }
  delay(500);
  
   */

   if (mySerial.available()){
    cmd = mySerial.readString();

    if(cmd == "up") direction = 0; // up
    else if(cmd == "left") direction = 1; // left
    else if(cmd == "right") direction = 2; // right
    else if(cmd == "down") direction = 3; // down
    else direction = 9;
     
    mode = 1;
   }


  if (mode == 0){ // go autonomous
   
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
   // Serial.println(" cm");
    motor_driver.go(255);
    delay(500);
  } else{ // go manual
    switch(direction){
      case 0: // up
        motor_driver.go(255);
        delay(1000);
        motor_driver.stop();
        break;
      case 1: // left
        motor_driver.left(255);
        delay(500);
        motor_driver.stop();
        break;
      case 2: // right
        motor_driver.right(255);
        delay(500);
        motor_driver.stop();
        break;
      case 3:
        motor_driver.stop();
        break;
      default:
        motor_driver.stop();
    }

    
  }
    /*
    motor_driver.left(255);
    delay(2000);
    motor_driver.right(255);
    delay(2000);
    motor_driver.stop();
    delay(5000);
    */
}
