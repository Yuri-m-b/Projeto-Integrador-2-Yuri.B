/*
 * Aluno: Yuri Marques Barboza
 * INSTITUTO FEDERAL DE SANTA CATARINA
 * Disciplina: Projeto Integrador II
 * Curso: Graduação em Engenharia Eletrônica
 * Objetivo: Testar a função do teclado que mostra a leitura o valor lido pelo pino analógico do sensor de gás, e também a função que irá alertar no teclado serial caso o nível de gases esteja em um nível muito elevado
 *  * 
 *  *  *            Arduino MEGA
 *               -----------------
 *              |                 |
 *              |                 |         
 *              |                 |        
 *              |                 |
 *              |                 |
 *              |             A0  | ---> MQ2        
 *              |                 |        
 *              |             GND |->- Cabo GND
 *              |             VCC |->- Cabo VCC
 *              |                 |        
 *  MQ2   <---  | PWM10           |        
 *              |                 |    
 *              |                 |  
 *              |                 |  
 *               -----------------
 *                  USB   Fonte DC
*/
#define MQ2 10    // Pino digital do sensor de Gás
#define PinA0 A0  // Pino analogico do sensor de Gás

char incomingByte;
// Sensor de Gás
int leitura_sensor = 500;           //Definindo um valor limite (nível de gás normal)
const unsigned long periodo_tarefa_2 = 500;
unsigned long tempo_tarefa_2 = millis();
 
void setup() {
  Serial.begin(9600);          // opens serial port, sets data rate to 9600 bps
  pinMode(MQ2, INPUT);         // PINO DIGITAL DO SENSOR MQ2
}
void tarefa_1() {                 // ARMAZENA SERIAL para incomingByte
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("Digito Recebido: ");
    Serial.println(incomingByte);
    
    // Para MQ2    
    if (incomingByte == 'a' || incomingByte == 'A')
    {
      int valor_analogico = analogRead(PinA0);
      //int valor_analogico = analogRead(PinA0);
      Serial.print("Nivel de concentracao de Gas: ");
      Serial.println(valor_analogico);                      // Mostra no monitor serial o valor lido do pino analógico
    }
  }
}
void tarefa_2(unsigned long tempo_atual) {
  if (tempo_atual - tempo_tarefa_2 > periodo_tarefa_2)
  {
    int valor_analogico = analogRead(PinA0);
    tempo_tarefa_2 = tempo_atual;
    if (valor_analogico > leitura_sensor)                   //Se o valor lido no pino analógico for maior que o valor limite, imprime a mensagem de aviso
    {
      Serial.println("FUMACA DETECTADA");
      Serial.println("PERIGO!!!!");
    }
  }
}
 
void loop(){
  unsigned long meu_tempo_atual = millis();

  tarefa_1();
  tarefa_2(meu_tempo_atual);
}
