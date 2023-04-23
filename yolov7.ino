#include <Servo.h>

Servo brakeServo;
String incomingByte;
//int ghettoBuff = 0;

void setup(){
    brakeServo.attach(3);
    Serial.begin(9600);
}

void loop(){
    brakeServo.write(180);
    delay(3000);
    brakeServo.write(90);
    delay(5000);
}

void oldCode(){
    brakeServo.write(90);
    while (Serial.available()){
        brakeServo.write(180);
        delay(100);
        brakeServo.write(90);
        incomingByte = Serial.read();
        int readValue = incomingByte.toInt();
        //Serial.print("I recieved: ");
        //Serial.println(readValue, DEC);
        //if (ghettoBuff < 3){
        //    ghettoBuff += 1;
        //}
        if (readValue == 1){
            brakeServo.write(180);
            delay(500);
            //if (ghettoBuff > 0){
            //    ghettoBuff -= 1;
            //}
        }    
    }
}


