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
  // Verifica se existe informações a serem enviadas do arduino para o módulo bluetooth.
  // if (Serial.available()) {
  //   char value = Serial.read();
  //   Serial.print(value);
  //   delay(10);
  //   bluetooth.write(value);
  // }
  
  // // Verifica se o módulo bluettoth recebeu algum dado para o arduino ler.
  // if (bluetooth.available()) {
  //   while(bluetooth.available()) { // enquanto tiver dados a receber continua no loop.
  //     command += (char)bluetooth.read();
  //   }
  //   Serial.println(command);
  //   command = "";
  // }
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
