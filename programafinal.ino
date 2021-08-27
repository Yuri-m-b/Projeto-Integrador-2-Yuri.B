/*
   Aluno: Yuri Marques Barboza
   INSTITUTO FEDERAL DE SANTA CATARINA
   Disciplina: Projeto Integrador II
   Curso: Graduação em Engenharia Eletrônica
 * 
 *                  Arduino MEGA
 *               -----------------
 *              |                 |
 *              |                 |         
 *  PIR   <---  | PWM2            |        
 *  LED1  <---  | PWM3            |
 *  LED2  <---  | PWM4            |
 *  LED3  <---  | PWM5        A0  | ---> MQ2        
 *  LED4  <---  | PWM6            |        
 *  LED5  <---  | PWM7        GND |->- Cabo GND
 *  LED6  <---  | PWM8        VCC |->- Cabo VCC
 *  SERVO <---  | PWM9            |        
 *  MQ2   <---  | PWM10           |        
 *  BUZZER<---  | PWM11           |    
 *              |                 |  
 *              |                 |  
 *               -----------------
 *                  USB   Fonte DC
 *                  
 *  Mapa de  teclas:
 *  q - Acende luz da Quarto 1
 *  Q - Apaga luz da Quarto 1    
 *  w - Acende luz da Banheiro
 *  W - Apaga luz da Banheiro   
 *  e - Acende luz da Quarto 2
 *  E - Apaga luz da Quarto 2   
 *  r - Acende luz da Cozinha
 *  R - Apaga luz da Cozinha   
 *  t - Acende luz da Garagem
 *  T - Apaga luz da Garagem   
 *  y - Acende luz da Sala
 *  Y - Apaga luz da Sala   
 *  a/A -  Nivel de concentração de Gás
 *  s - Portão abrindo
 *  S - Portão fechando
*/

// LEDS
#define LED1 3    // O pino em que o LED está conectado 1
#define LED2 4    // O pino em que o LED está conectado 2
#define LED3 5    // O pino em que o LED está conectado 3
#define LED4 6    // O pino em que o LED está conectado 4
#define LED5 7    // O pino em que o LED está conectado 5
#define LED6 8    // O pino em que o LED está conectado 6
// SENSOR MOVIMENTO PIR
#define PIR 2     // Pino digital do sensor de movimento
// SENSOR DE FUMACA MQ2
#define MQ2 10    // Pino digital do sensor de fumaca
#define PinA0 A0  // Pino analogico do sensor de fumaca
// BUZZER
#define buzzer 11 // Pino digital do buzzer
// SERVO
#include <Servo.h> //Inclusão da biblioteca necessária

//------------------------------------------------------------------------------------------------------
// Variaveis para Teclado e Temporizador
char incomingByte;

// Variaveis para o Sensor de Movimento PIR
int pirState = 0;
const unsigned long periodo_tarefa_2 = 2000;
unsigned long tempo_tarefa_2 = millis();

// Sensor de Fumaca
int leitura_sensor = 500;                     //Definindo um valor limite (nível de gás normal)
const unsigned long periodo_tarefa_3 = 5000;  // Frequencia em que o sensor vai escanear o ambiente, relativamente alto porque esse sensor não precisa ativar em cada segundo
unsigned long tempo_tarefa_3 = millis();

// Buzzer
int buzzState = 0;

// Servo Motor
const int pinoServo = 9;  //Pino digital utilizado pelo servo
Servo s;                 //Objeto do tipo servo
int pos;                 //Posição do servo

//------------------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);          // ABRE A PORTA SERIAL, SETANDO PARA 9600 BPS
  pinMode(LED1, OUTPUT);       // PINO DIGITAL DO LED 1 - QUARTO 1
  pinMode(LED2, OUTPUT);       // PINO DIGITAL DO LED 2 - BANHEIRO
  pinMode(LED3, OUTPUT);       // PINO DIGITAL DO LED 3 - QUARTO 2
  pinMode(LED4, OUTPUT);       // PINO DIGITAL DO LED 4 - COZINHA
  pinMode(LED5, OUTPUT);       // PINO DIGITAL DO LED 5 - GARAGEM
  pinMode(LED6, OUTPUT);       // PINO DIGITAL DO LED 6 - Sala
  pinMode(PIR, INPUT);         // PINO DIGITAL DO SENSOR PIR
  pinMode(MQ2, INPUT);         // PINO DIGITAL DO SENSOR MQ2
  pinMode(buzzer, OUTPUT);     // PINO DIGITAL DO BUZZER
  digitalWrite(buzzer, HIGH);  // OBRIGA BUZZER A COMEÇAR DESLIGADO
  s.attach(pinoServo);         // ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(10);                 // INICIA O MOTOR NA POSIÇÃO 10º
}

// Tarefa 1 teclado serial e suas funções
void tarefa_1() {                       // ARMAZENA SERIAL para incomingByte
  
  if (Serial.available() > 0) {         // send data only when you receive data:
    
    incomingByte = Serial.read();       // Lê o byte recebido:

    // Digito recebido:
    Serial.print("Digito Recebido: ");  
    Serial.println(incomingByte);

    // Para LED1 - QUARTO 1
    if (incomingByte == 'q')
    {
      digitalWrite(LED1, HIGH);
      Serial.println("LED1 ON");
    }
    else if (incomingByte == 'Q')
    {
      digitalWrite(LED1, LOW);
      Serial.println("LED1 OFF");
    }

    // Para LED2 - BANHEIRO
    else if (incomingByte == 'w')
    {
      digitalWrite(LED2, HIGH);
      Serial.println("LED2 ON");
    }
    else if (incomingByte == 'W')
    {
      digitalWrite(LED2, LOW);
      Serial.println("LED2 OFF");
    }

    // Para LED3 - QUARTO 2
    else if (incomingByte == 'e')
    {
      digitalWrite(LED3, HIGH);
      Serial.println("LED3 ON");
    }
    else if (incomingByte == 'E')
    {
      digitalWrite(LED3, LOW);
      Serial.println("LED3 OFF");
    }

    // Para LED4 - COZINHA
    else if (incomingByte == 'r')
    {
      digitalWrite(LED4, HIGH);
      Serial.println("LED4 ON");
    }
    else if (incomingByte == 'R')
    {
      digitalWrite(LED4, LOW);
      Serial.println("LED4 OFF");
    }

    // Para LED5 - GARAGEM
    else if (incomingByte == 't')
    {
      digitalWrite(LED5, HIGH);
      Serial.println("LED5 ON");
    }
    else if (incomingByte == 'T')
    {
      digitalWrite(LED5, LOW);
      Serial.println("LED5 OFF");
    }

    // Para LED6 - SALA
    else if (incomingByte == 'y')
    {
      digitalWrite(LED6, HIGH);
      Serial.println("LED6 ON");
    }
    else if (incomingByte == 'Y')
    {
      digitalWrite(LED6, LOW);
      Serial.println("LED6 OFF");
    }

    // Para MQ2
    else if (incomingByte == 'a' || incomingByte == 'A')
    {
      int valor_analogico = analogRead(PinA0);
      Serial.print("Nivel de concentração de Gás: ");
      Serial.println(valor_analogico);                      // Mostra no monitor serial o valor lido do pino analógico
    }

    // Para SERVO
    else if (incomingByte == 's')
    {
      Serial.println("Portão Abrindo");
      s.write(120);
    }
    else if (incomingByte == 'S')
    {
      Serial.println("Portão Fechando");
      s.write(10);
    }
  }
}

// Tarefa 2 para o sensor PIR
void tarefa_2(unsigned long tempo_atual) {
  if (tempo_atual - tempo_tarefa_2 > periodo_tarefa_2)
  {
    tempo_tarefa_2 = tempo_atual;
        
    pirState = digitalRead(PIR);
    if (pirState == HIGH)   // Se movimento for detectado
    { 
      Serial.println(" MOVIMENTO DETECTADO ");
      Serial.println("   __  ");
      Serial.println(" |    |");
      Serial.println("( STOP )");
      Serial.println(" | __ |");
      Serial.println("   ||");
      Serial.println("   ||");
      Serial.println("   ||");
      Serial.println(" ~~~~~~~");
    }
  }
}

// Tarefa 3 para o sensor MQ2
void tarefa_3(unsigned long tempo_atual) {
  if (tempo_atual - tempo_tarefa_3 > periodo_tarefa_3)
  {
    int valor_analogico = analogRead(PinA0);
    tempo_tarefa_3 = tempo_atual;
    if (valor_analogico > leitura_sensor)     //Se o valor lido no pino analógico for maior que o valor limite, imprime a mensagem de aviso
    {
      Serial.println("GÁS DETECTADO");
      Serial.println("PERIGO!!!!");
      digitalWrite(buzzer, LOW);
    }
    else
    {
      digitalWrite(buzzer, HIGH);
    }
  }
}




  void loop() {
    unsigned long meu_tempo_atual = millis();

    tarefa_1();                         // Tarefa para o teclado e suas funções
    tarefa_2(meu_tempo_atual);          // Tarefa para o sensor de movimento
    tarefa_3(meu_tempo_atual);          // Tarefa para o detector de fumaça
  }
