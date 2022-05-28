#include <Servo.h>
#define S0 2
#define S1 12
#define S2 4
#define S3 5
#define sensorOut 13
Servo servo1, servo2, servo3, servo4, servo5;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(6);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

void loop() {
  servo5.write(0);
  servo3.write(0);
  servo1.write(0);
  delay(1000);
  servo4.write(0);
  delay(1000);
  servo3.write(40);
  delay(1000);
  servo4.write(160);
  delay(1000);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redfrequency = pulseIn(sensorOut, LOW);
  redfrequency = map(redfrequency, 25,72,255,0);
 
  delay(100);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenfrequency = pulseIn(sensorOut, LOW);
  greenfrequency = map(greenfrequency, 30,90,255,0);
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  bluefrequency = pulseIn(sensorOut, LOW);
  bluefrequency = map(bluefrequency, 25,70,255,0);
  delay(1000);
  if (redfrequency >=0) {
    delay(1000);
    servo4.write(0);
    delay(1000);
    for(int n = 0;n<=90;n++){
      delay(10);
      servo3.write(n);
    }
    delay(1000);
    for(int i = 0;i<=90;i++){
      delay(10);
      servo4.write(i);
    }
    delay(3000);
    servo5.write(180);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo1.write(90);
    delay(1000);
    servo4.write(90);
    delay(1000);
    servo5.write(0);
    delay(1000);
    }
    else if (bluefrequency>=0) {
      delay(1000);
      servo4.write(0);
      delay(1000);
      servo3.write(0);
      for(int n = 0;n<=90;n++){
        delay(10);
        servo3.write(n);
      }
      delay(1000);
      for(int i = 0;i<=90;i++){
        delay(10);
        servo4.write(i);
      }
      delay(3000);
      servo5.write(180);
      delay(1000);
      servo3.write(0);
      delay(1000);
      servo4.write(180);
      delay(1000);
      servo5.write(0);
      delay(1000);
      } 
    else if (greenfrequency>=0){
      Serial.println("GREEN COLOUR");
      }

   else{
      Serial.println("NO COLOUR DETECTION");
      delay(1000);
      servo4.write(0);
      delay(1000);
      servo3.write(0);
      for(int n = 0;n<=90;n++){
        delay(10);
        servo3.write(n);
      }
      delay(1000);
      for(int i = 0;i<=90;i++){
        delay(10);
        servo4.write(i);
      }
      delay(3000);
      servo5.write(180);
      delay(1000);
      servo4.write(90);
      delay(1000);
      servo3.write(0);
      delay(1000);
      servo1.write(25);
      delay(1000);
      servo4.write(90);
      delay(1000);
      servo3.write(90);
      delay(1000);
      servo5.write(0);
      delay(1000);
  }
}
