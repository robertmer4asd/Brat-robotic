#include <LowPower.h>

int stare = 0,solHum = 0; //declaram variabila starii din switch si variabila umiditatii solului
void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT); //setam releul pe modul output
  Serial.begin(9600); //deschidem seriala pe 9600 baud
  digitalWrite(12,HIGH); //inchidem releul
}

void loop() {
  switch(stare){ //comanda switch trece de la anumite stagii din program reprezentate de variabila stare
    case 0: //se declara primul stagiu
      solHum = analogRead(A0); //variabila solHum este egala cu valoarea analogica de pe pinul A0
      if(solHum <= 400){ //daca solHum este mai mic sau egal cu 400 ramane in primul stagiu
        stare = 0;
      }
      else if(solHum > 700){ //daca solHum este mai mare de 700 se trece la urmatorul stagiu
        stare = 1;
      }
    case 1:// se declara al dolea stagiu
      digitalWrite(12,LOW);//se porneste pompa/releul
      stare = 2;// se trece la urmatorul stagiu

    case 2:// se declara al treilea stagiu
      delay(5000);//asteapta 5 secunde
      digitalWrite(12,HIGH);//se inchide pompa/releul
      for(int i = 0;i <= 37;i++){
        LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);//microcontroller-ul va intra in sleep pentru 8 secunde de 37 de ori adica aproximativ 5 minute
      }
      stare = 0;
  }
}
