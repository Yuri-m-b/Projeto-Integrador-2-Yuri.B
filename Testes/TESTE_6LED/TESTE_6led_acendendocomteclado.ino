/*
 * Aluno: Yuri Marques Barboza
 * INSTITUTO FEDERAL DE SANTA CATARINA
 * Disciplina: Projeto Integrador II
 * Curso: Graduação em Engenharia Eletrônica
 * Objetivo desse arquivo: Testar se os LED estão funcionando, e se a função que aciona os LED pelo teclado SERIAL está funcionando.
 * 
 *  *  *            Arduino MEGA
 *               -----------------
 *              |                 |
 *              |                 |         
 *              |                 |        
 *  LED1  <---  | PWM3            |
 *  LED2  <---  | PWM4            |
 *  LED3  <---  | PWM5            |        
 *  LED4  <---  | PWM6            |        
 *  LED5  <---  | PWM7        GND |->- Cabo GND
 *  LED6  <---  | PWM8        VCC |->- Cabo VCC
 *              |                 |        
 *              |                 |        
 *              |                 |    
 *              |                 |  
 *              |                 |  
 *               -----------------
 *                  USB   Fonte DC
*/
// LEDS
#define LED1 3  // Pino que o LED1 está conectado
#define LED2 4  // Pino que o LED2 está conectado
#define LED3 5  // Pino que o LED3 está conectado
#define LED4 6  // Pino que o LED4 está conectado
#define LED5 7  // Pino que o LED5 está conectado
#define LED6 8  // Pino que o LED6 está conectado

char incomingByte;


void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void tarefa_1() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("Digito Recebido: ");
    Serial.println(incomingByte);
    
      // Para LED1
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
    
      // Para LED2
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
    
      // Para LED3
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
    
      // Para LED4
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
    
      // Para LED5
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
    
      // Para LED6
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
   }

  
}

void loop() {

  tarefa_1();


}
