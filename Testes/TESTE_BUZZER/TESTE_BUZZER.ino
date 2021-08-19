/*
 * Aluno: Yuri Marques Barboza
 * INSTITUTO FEDERAL DE SANTA CATARINA
 * Disciplina: Projeto Integrador II
 * Curso: Graduação em Engenharia Eletrônica
 * Objetivo: Verificar se o Buzzer está ligando
 * 
 *  *  *                  Arduino MEGA
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
*/

int buzzer = 11; // Pino que o buzzer está conectado
int buzzState = 0;
char incomingByte;

void setup() 
{
    Serial.begin(9600);             // opens serial port, sets data rate to 9600 bps
        
    pinMode(buzzer,OUTPUT);         // Define o pino do buzzer
    digitalWrite(buzzer, HIGH);     // Comeca com buzzer desligado
}

void loop() 
{
// send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("Digito Recebido: ");
    Serial.println(incomingByte);

    // Para buzzer on
    if (incomingByte == 'q')
    {
    tone(buzzer,500);
    digitalWrite(buzzer, LOW);
    }
    // Para buzzer off
    else if (incomingByte == 'Q')
    {
     noTone(buzzer);
     digitalWrite(buzzer, HIGH);
    }
  }
}
