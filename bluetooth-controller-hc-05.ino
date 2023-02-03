/**
* Para definir o módulo HC-05 em modo de configuração:
* com o cabo do Vcc(5v) desconectado, pressione o botão do
* módulo por 3 segundos e conecte novamente o cabo do modulo.
* 
*/
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // Pinos RX, TX

void setup() {
  //Inicia a serial
  Serial.begin(38400);
  Serial.println(F("Digite os comandos AT:"));
  //Inicia a serial configurada nas portas 10 e 11
  bluetooth.begin(38400);
}

void loop() {
  //Check received a byte from hardware serial
  if (Serial.available()) {
    char r = Serial.read(); //Read and save the byte
    bluetooth.print(r);  //Send the byte to bluetooth by software serial
    Serial.print(r);  //Echo
  }
  //Check received a byte from bluetooth by software serial
  if (bluetooth.available()) {
    char r = bluetooth.read(); //Read and save the byte
    Serial.print(r); //Print the byte to hardware serial
  }
}
