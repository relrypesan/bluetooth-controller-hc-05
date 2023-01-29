#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // Pinos RX, TX
String command = "";

void setup() {
  //Inicia a serial
  Serial.begin(115200);
  Serial.println("Digite os comandos AT:");
  //Inicia a serial configurada nas portas 10 e 11
  bluetooth.begin(38400);
}

void loop() {
  // Verifica se o módulo bluettoth recebeu algum dado para o arduino ler.
  if (bluetooth.available()) {
    while(bluetooth.available()) { // enquanto tiver dados a receber continua no loop.
      command += (char)bluetooth.read();
    }
    Serial.println(command);
    command = "";
  }

  // Verifica se existe informações a serem enviadas do arduino para o módulo bluetooth.
  if (Serial.available()) {  
    delay(10); 
    bluetooth.write(Serial.read());
  }  
}
