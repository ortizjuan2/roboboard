#ifndef LD293_H_
#define LD293_H_


class LD293 {

    public:
        byte in_1A;
        byte in_2A;
        byte in_3A;
        byte in_4A;

        LD293(byte input_1A, byte input_2A, byte input_3A, byte input_4A){
            in_1A = input_1A;
            in_2A = input_2A;
            in_3A = input_3A;
            in_4A = input_4A;

            pinMode(input_1A, OUTPUT);
            pinMode(input_2A, OUTPUT);
            pinMode(input_3A, OUTPUT);
            pinMode(input_4A, OUTPUT);
        }

void go(int speed){
    // motor 1
    Serial.print("Go\n");
    digitalWrite(in_1A, LOW); 
    digitalWrite(in_2A, HIGH); 
    //analogWrite(in_2A, speed);

    // motor 2
    digitalWrite(in_3A, HIGH); 
    digitalWrite(in_4A, LOW); 
    
    //analogWrite(in_3A, speed);
}

void stop(){

    // motor 1
    Serial.print("Stop\n");
    digitalWrite(in_1A, LOW); 
    digitalWrite(in_2A, LOW);

    // motor 2
    digitalWrite(in_4A, LOW); 
    digitalWrite(in_3A, LOW);
}

void left(int speed){
    // motor 1
    Serial.print("Left\n");
    digitalWrite(in_1A, LOW); 
    digitalWrite(in_2A, HIGH); 
    //analogWrite(in_2A, speed);

    // motor 2
    digitalWrite(in_3A, LOW); 
    digitalWrite(in_4A, HIGH); 
    //   analogWrite(in_4A, speed);

    delay(1);
}


void right(int speed){
    // motor 1
    Serial.print("Right\n");
    digitalWrite(in_1A, HIGH); 
    digitalWrite(in_2A, LOW); 
    //analogWrite(in_1A, speed);

    // motor 2
    digitalWrite(in_3A, HIGH); 
    digitalWrite(in_4A, LOW); 
    //analogWrite(in_3A, speed);

    delay(1);
}




};



#endif /* LD293_H_ */