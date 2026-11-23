#include <Arduino.h>
#include <BluetoothSerial.h>
#include <Bounce2.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>

Bounce botaozinho = Bounce();

BluetoothSerial BT;
// Endereco bluetooth: F4:65:0B:47:E3:CA

JsonDocument doc;

unsigned long intervalo = 500;
unsigned long intervaloB = 3000;
unsigned long tempoAnterior = 0;
unsigned long tempoAnteriorB = 0;
// String mensagem = "escreva seu nome, idade e se é habilitado ou não: ";

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  // lcd.init();
  // lcd.backlight();
  Serial.begin(115200);
  Serial.setTimeout(5000);

  if (BT.begin("BtSlaveRebecca"))
  {
    Serial.println("Bluetooth iniciado com sucesso");
    Serial.print("Endereco bluetooth: ");
    Serial.println(BT.getBtAddressString());
  }
  else
  {
    Serial.println("Erro ao iniciar o bluetooth");
  }





  // ex2
  // Salvar os dados no doc

  Serial.println("Digite seu nome:");

  if (Serial.available())
  {
    String msgEnviar = Serial.readStringUntil('\n');
    msgEnviar.trim();
    // BT.println(msgEnviar);
    doc["NOME"] = msgEnviar;
  }



  Serial.println("Digite sua idade:");

  if (Serial.available())
  {
    String msgEnviar = Serial.readStringUntil('\n');
    msgEnviar.trim();
    // BT.println(msgEnviar);
    doc["IDADE"] = msgEnviar;
  }



  Serial.println("Você é habilitado? ");

  if (Serial.available())
  {
    String msgEnviar = Serial.readStringUntil('\n');
    msgEnviar.trim();
    doc["HABILITADO"] = msgEnviar;
  }
  
  String mensagem;
  serializeJson(doc, mensagem);


  BT.println(mensagem);





  // if (BT.available()) // verifica se tem info no BT e mostra na Serial
  // {
  //   String msgRecebida = BT.readStringUntil('\n');
  //   msgRecebida.trim();
  //   Serial.printf("Mensagem recebida: %s", msgRecebida);

  //   doc["IDADE"] = ;
  //   doc["HABILITADO"] = ;

  //   BT.println(mensagem);
  // }
}

void loop()
{

  // if (BT.available()) // verifica se tem info no BT e mostra na Serial
  // {
  //   String msgRecebida = BT.readStringUntil('\n');
  //   Serial.printf("Mensagem recebida: %s", msgRecebida);
  //   msgRecebida.trim();

  //   // Serial.println(msgRecebida);

  //   lcd.setCursor(0, 0);
  //   lcd.printf("Temp em C: %s", msgRecebida);

  //   lcd.setCursor(0, 1);
  //   lcd.printf("Umidade: %s", msgRecebida);

  // }

  //  if (BT.available()) // verifica se tem info no BT e mostra na Serial
  // {
  //    String msgRecebida = BT.readStringUntil('\n');
  //   Serial.printf("Mensagem recebida: %s", msgRecebida);
  //   msgRecebida.trim();

  //   DeserializationError erro = deserializeJson(doc, msgRecebida);

  //   if (erro)
  //   {
  //     Serial.println("Erro ao interpretar o JSON");
  //     return;
  //   }
  //   Serial.println(msgRecebida);
  //   lcd.setCursor(0, 0);
  //   lcd.printf("Temp em C: %s", msgRecebida);
  //   float temperatura = doc["temp"];

  //   lcd.setCursor(0, 1);
  //   lcd.printf("Umidade: %s", msgRecebida);
  //   float umidade = doc["umi"];
  // }

  //  doc["temp"] = mensagem;
  //  doc["umi"] = mensagem;

  // Serial.println(temperatura);
  // Serial.println(umidade);

  // if (Serial.available()) // verifica informação na serial
  // {
  //   String msgEnviar = Serial.readStringUntil('\n');
  //   msgEnviar.trim();
  //   BT.println(msgEnviar);
  // }

  // delay(3000);
}