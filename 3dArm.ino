#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 13
Servo servo1, servo2, servo3, servo4, servo5;
int var1 = 0,var2 = 0,var3 = 0,var4 = 0, var5 = 0;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
void setup() {
  Serial.begin(9600);
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(12);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(6,INPUT_PULLUP);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

void loop() {
  cubeFull();
}

void servos(void){
  var1 = analogRead(A3);
  var1 = map(var1, 0, 1023, 0, 180);
  servo1.write(var1);
  var2 = analogRead(A0);
  var2 = map(var2, 0, 1023, 0, 180);
  servo2.write(var2);
  var3 = analogRead(A1);
  var3 = map(var3, 0, 1023, 0, 180);
  servo3.write(var3);
  var4 = analogRead(A2);
  var4 = map(var4, 0, 1023, 0, 180);
  servo4.write(var4);
  var5 = digitalRead(6);
  if(var5 == 1){
    servo5.write(0);
  }
  else{
    if(var5 == 0){
      servo5.write(180);
    }
  }
  Serial.println(servo5.read());
}
int cubeFull(void){
  servo5.write(0);
  servo3.write(40);
  delay(1000);
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
 
  delay(100);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenfrequency = pulseIn(sensorOut, LOW); 
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  bluefrequency = pulseIn(sensorOut, LOW);
  delay(1000);
  if (redfrequency>25 && redfrequency< 77) {
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
    servo1.write(90);
    delay(1000);
    servo4.write(90);
    delay(1000);
    servo3.write(90);
    delay(1000);
    servo5.write(0);
    }
    else if (bluefrequency>25 && bluefrequency< 77) {
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
      } 
    else if (greenfrequency>25 && greenfrequency< 77){
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
  }
}
