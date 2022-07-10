#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5;

int s0_pin = 2;
int s1_pin = 7;
int s2_pin = 4;
int s3_pin = 5;
int out_pin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(s0_pin, OUTPUT);
  pinMode(s1_pin, OUTPUT);
  pinMode(s2_pin, OUTPUT);
  pinMode(s3_pin, OUTPUT);
  pinMode(out_pin, INPUT);
  digitalWrite(s0_pin,HIGH);
  digitalWrite(s1_pin,LOW);
  servo1.attach(3); //asignare pin servomotor (umar)
  servo2.attach(9); //asignare pin servomotor (cot)
  servo3.attach(10);//asignare pin servomotor (incheietura)
  servo4.attach(11);//asignare pin servomotor (falange)
  servo5.attach(6);//asignare pin servomotor (cleste)

  //deplasare brat la pozitie de detectare culoare
  servo5.write(0); 
  servo3.write(0);
  servo1.write(0);
  delay(1000);
  servo4.write(0);
  delay(1000);
  servo3.write(40);
  delay(1000);
  servo4.write(178);
  delay(1000);

  //se configureaza senzor pt culoarea rosu
  digitalWrite(s2_pin,LOW);
  digitalWrite(s3_pin,LOW);
  int red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color, 25,72,255,0);
  delay(50);

  //se configureaza senzor pt culoarea verde
  digitalWrite(s2_pin,HIGH);
  digitalWrite(s3_pin,HIGH);
  int green_color = pulseIn(out_pin, LOW);
  green_color = map(green_color, 30,90,255,0);
  delay(50);

  //se configureaza senzor pt culoarea albastra
  digitalWrite(s2_pin,LOW);
  digitalWrite(s3_pin,HIGH);
  int blue_color = pulseIn(out_pin, LOW);
  blue_color = map(blue_color, 25,70,255,0);
  delay(50);

  //se afiseaza culoarea
  Serial.print("RED: ");
  Serial.print(red_color);
  Serial.print("  ");
  Serial.print("GREEN: ");
  Serial.print(green_color);
  Serial.print("  ");
  Serial.print("BLUE: ");
  Serial.print(blue_color);
  Serial.println("  ");
  
  delay(1000);

  //se testeaza culoarea cubului, daca este rosu se plaseaza cubul in cutia pt cuburi rosii
  if(red_color > blue_color && red_color > green_color){
    Serial.println("red");
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
    servo1.write(150);
    delay(1000);
    servo4.write(90);
    delay(1000);
    servo5.write(0);
    delay(1000);
  }
  //se testeaza culoarea cubului, daca este albastru se plaseaza cubul in cutia pt cuburi albastri
  if(blue_color > red_color && blue_color > green_color){
    Serial.println("blue");
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
    servo1.write(90);
    delay(1000);
    servo4.write(90);
    delay(1000);
    servo3.write(90);
   
  }
  //se testeaza culoarea cubului, daca este verde se plaseaza cubul in cutia pt cuburi verzi
  if(green_color > blue_color && green_color > red_color){
    Serial.println("green");
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
    servo1.write(90);
  }
}


void loop() {
}
