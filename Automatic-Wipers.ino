#include <Servo.h>

int sensorPin = A1;
int servoPin = 3;
Servo myServo;

int posA = 0;
int posB = 160;

int dt1 =  4000;
int dt2 =  2000;
int dt3 =  500;
int dt4 =  300;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  pinMode(sensorPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorData = analogRead(sensorPin);
  Serial.println(sensorData);

  if(sensorData < 100){
    moveServo(dt4);
  }else if (sensorData < 200){
    moveServo(dt3);    
  }else if(sensorData < 300){
    moveServo(dt2);
  }else if(sensorData < 400){
    moveServo(dt1);
  }else{
    stopServo();
  }

}

void moveServo(int dt){
  myServo.write(posB);
  delay(300);
  myServo.write(posA);
  delay(300);

  delay(dt);
}

void stopServo(){
  myServo.write(posA);
  delay(1000);
}

