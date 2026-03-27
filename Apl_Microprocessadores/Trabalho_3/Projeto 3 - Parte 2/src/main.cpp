//Gustavo Curado Ribeiro - 14576732
//Luis Filipe Silva Forti - 14592348
//Miguel Rodrigues Fonseca - 14682196

#include <Arduino.h>
//Servo
#include <ESP32Servo.h>
//LCD I2C
#include <LiquidCrystal_I2C.h>
//MicroSD
#include <FS.h>
#include <SD.h>
#include <SPI.h>

//----------------Servos----------------
#define pinAileronEsquerdo 14
#define pinAileronDireito 17

#define pinFlapEsquerdo 26
#define pinFlapDireito 4

#define pinProfundorEsquerdo 27
#define pinProfundorDireito 16

#define pinLeme 25

Servo servoAileronEsquerdo;
Servo servoAileronDireito;
Servo servoFlapEsquerdo;
Servo servoFlapDireito;
Servo servoProfundorEsquerdo;
Servo servoProfundorDireito;
Servo servoLeme;

//----------------Joystick----------------

#define pinVertical 34
#define pinHorizontal 35

#define valorMax 4095
#define valorMin 0

//----------------LCD----------------

#define nroColunas 16
#define nroLinhas 2

LiquidCrystal_I2C lcd(0x27, nroColunas, nroLinhas); 

//----------------MicroSD----------------

#define pinSD 5
#define pinSCK 18
#define pinMISO 19
#define pinMOSI 23

#define enderecoLog "/log.txt"

SPIClass spiSD(VSPI);
File logFile;

//----------------Controle----------------

#define angHorizontal 90
#define angVariacao 30

#define delayMs 20
#define floatLambda 0.05 //Margem de erro dos floats
#define intervaloRegistros 2000

enum Posicoes
{
  nada, cima, baixo, esquerda, direita
};

Posicoes ultimaPosicaoVertical, ultimaPosicaoHorizontal;

//Para salvar a cada X milisegundos
int ultimoRegistro = 0;

//Pega o tempo que esteve ligado e transforma para uma string
//Não está tratando dias, pois assume-se que o avião não vai ficar mais de 24h ligado direto
String GetTempo()
{
  unsigned long tempo = millis();

  unsigned long segundosTotais = tempo/1000;
  unsigned long minutosTotais = segundosTotais/60;
  unsigned long horasTotais = minutosTotais/60;

  int segundos = segundosTotais % 60;
  int minutos = minutosTotais % 60;
  int horas = horasTotais % 24;

  //Coloca "0" se o número não tiver 2 dígitos
  String sHoras = (horas < 10) ? "0" + String(horas) : String(horas);
  String sMinutos = (minutos < 10) ? "0" + String(minutos) : String(minutos);
  String sSegundos = (segundos < 10) ? "0" + String(segundos) : String(segundos);

  return sHoras + "h - " + sMinutos + "m - " + sSegundos + "s";
}

//Lê todos os registros do arquivo e passa pro serial
void LerArquivo() {
  File file = SD.open(enderecoLog);
  if(!file){
    Serial.println("\nFalha ao abrir arquivo para leitura");
    return;
  }
  
  Serial.println("\n--- CONTEÚDO DO ARQUIVO LOG.TXT ---");
  while(file.available()){
    Serial.write(file.read());
  }
  Serial.println("--- FIM DO ARQUIVO ---");
  file.close();
}

//Registra os dados
void AtualizarArquivo(float proporcaoVertical, float proporcaoHorizontal)
{
  //Se o arquivo foi aberto
  if(logFile)
  {
    logFile.println(GetTempo() + ": Movimento vertical = " + proporcaoVertical + "\t - Movimento horizontal = " + proporcaoHorizontal);
    //flush() para não precisar ficar abrindo e fechando o arquivo
    logFile.flush();

    //Escreve os registros, para mostrar o funcionamento
    LerArquivo();
  }
}

//Verifica se deve atualizar o LCD
void AtualizarLCD(float proporcaoVertical, float proporcaoHorizontal)
{
  //As validações dos enuns melhoram muito o desempenho (em torno de 15% da velocidade do simulador)
  //As validações dos enuns ficam aninhadas para não cancelar a validação da posição 
  //ex: ele está para cima, mas o enum passaria para o else, chegando no Posicoes::nada

  if (proporcaoVertical - floatLambda > 0)
  {
    if(ultimaPosicaoVertical != Posicoes::cima)
    {
      lcd.setCursor(0, 0);
      lcd.print("Cima ");
      ultimaPosicaoVertical = Posicoes::cima;
    }
  }
  else if (proporcaoVertical + floatLambda < 0)
  {
    if(ultimaPosicaoVertical != Posicoes::baixo)
    {
      lcd.setCursor(0, 0);
      lcd.print("Baixo");
      ultimaPosicaoVertical = Posicoes::baixo;
    }
  }
  else
  {
    if(ultimaPosicaoVertical != Posicoes::nada)
    {
      lcd.setCursor(0, 0);
      lcd.print("Nada ");
      ultimaPosicaoVertical = Posicoes::nada;
    }
  }

  if (proporcaoHorizontal - floatLambda > 0)
  {
    if(ultimaPosicaoHorizontal != Posicoes::esquerda)
    {
      lcd.setCursor(0, 1);
      lcd.print("Esquerda");
      ultimaPosicaoHorizontal = Posicoes::esquerda;
    }
  }
  else if (proporcaoHorizontal + floatLambda < 0)
  {
    if(ultimaPosicaoHorizontal != Posicoes::direita)
    {
      lcd.setCursor(0, 1);
      lcd.print("Direita ");
      ultimaPosicaoHorizontal = Posicoes::direita;
    }
  }
  else
  {
    if(ultimaPosicaoHorizontal != Posicoes::nada)
    {
      lcd.setCursor(0, 1);
      lcd.print("Nada    ");
      ultimaPosicaoHorizontal = Posicoes::nada;
    }
  }
}

void setup() {
  Serial.begin(115200);

  //Configura os servos
  servoAileronEsquerdo.attach(pinAileronEsquerdo, 500, 2400);
  servoAileronDireito.attach(pinAileronDireito, 500, 2400);
  servoFlapEsquerdo.attach(pinFlapEsquerdo, 500, 2400);
  servoFlapDireito.attach(pinFlapDireito, 500, 2400);
  servoProfundorEsquerdo.attach(pinProfundorEsquerdo, 500, 2400);
  servoProfundorDireito.attach(pinProfundorDireito, 500, 2400);
  servoLeme.attach(pinLeme, 500, 2400);

  //Configura o joystick
  pinMode(pinVertical, INPUT);
  pinMode(pinHorizontal, INPUT);

  //Configura o LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  //Tenta configurar o MicroSD
  spiSD.begin(pinSCK, pinMISO, pinMOSI, pinSD);
  if (!SD.begin(pinSD, spiSD, 4000000))
  {
    Serial.println("Falha na montagem do cartão!");
    return;
  }
  Serial.println("Cartão reconhecido");

  //Coloca todos os servos na posição neutra
  int pulsoHorizontal = map(angHorizontal, 0, 180, 500, 2400);
  
  servoAileronEsquerdo.writeMicroseconds(pulsoHorizontal);
  servoAileronDireito.writeMicroseconds(pulsoHorizontal);
  servoFlapEsquerdo.writeMicroseconds(pulsoHorizontal);
  servoFlapDireito.writeMicroseconds(pulsoHorizontal);
  servoProfundorEsquerdo.writeMicroseconds(pulsoHorizontal);
  servoProfundorDireito.writeMicroseconds(pulsoHorizontal);
  servoLeme.writeMicroseconds(pulsoHorizontal);

  ultimaPosicaoHorizontal = Posicoes::nada;
  ultimaPosicaoVertical = Posicoes::nada;

  //Escreve o texto inicial do LCD
  lcd.setCursor(0, 0);
  lcd.print("Nada");
  lcd.setCursor(0, 1);
  lcd.print("Nada");

  //Cria/abre o arquivo de log
  //Como é uma simulação no Wokwi, sempre criará um novo
  logFile = SD.open(enderecoLog, FILE_APPEND);
  if(logFile){
    Serial.println("Arquivo aberto com sucesso!");
    logFile.println("--- Nova Sessão Iniciada ---");
  }
  else
  {
    logFile.println("Erro ao abrir o arquivo de log!");
    return;
  }
}

void loop() {
  //analogRead(pinVertical) == valorMax -> joystick para cima
  //analogRead(pinHorizontal) == valorMax -> joystick para esquerda

  //valJoystick - valorMax/2 -> valorMax/2 a -valorMax/2
  //(valJoystick - valorMax/2) / ((valorMax - valorMin)/2) -> 1 a -1
  float proporcaoVertical = (float)(analogRead(pinVertical) - valorMax/2.0) / ((float)(valorMax - valorMin)/2.0);
  float proporcaoHorizontal = (float)(analogRead(pinHorizontal) - valorMax/2.0) / ((float)(valorMax - valorMin)/2.0);

  //Controles do avião:
  //https://www.gov.br/anac/pt-br/centrais-de-conteudo/biblioteca/asas-do-conhecimento/06-cartilha-asas-do-conhecimento-controles-de-voo.pdf
  //Ailerons: página 7
  //Leme: página 11
  //Profundor: página 13

  //No servo, 0 graus é para cima e 180 é para baixo, por isso os sinais invertidos
  int pulsoVertical = map(angHorizontal - proporcaoVertical * angVariacao, 0, 180, 500, 2400);
  int pulsoEsquerda = map(angHorizontal - proporcaoHorizontal * angVariacao, 0, 180, 500, 2400);
  int pulsoDireita = map(angHorizontal + proporcaoHorizontal * angVariacao, 0, 180, 500, 2400);

  //Posiciona os servos nas posições adequadas
  servoAileronEsquerdo.writeMicroseconds(pulsoEsquerda);
  servoAileronDireito.writeMicroseconds(pulsoDireita);
  servoLeme.writeMicroseconds(pulsoDireita);

  servoProfundorEsquerdo.writeMicroseconds(pulsoVertical);
  servoProfundorDireito.writeMicroseconds(pulsoVertical);

  AtualizarLCD(proporcaoVertical, proporcaoHorizontal);

  //Se deu o intervalo entre registros
  if (ultimoRegistro + intervaloRegistros < millis())
  {
    AtualizarArquivo(proporcaoVertical, proporcaoHorizontal);
    ultimoRegistro += intervaloRegistros;
  }

  delay(delayMs);
}