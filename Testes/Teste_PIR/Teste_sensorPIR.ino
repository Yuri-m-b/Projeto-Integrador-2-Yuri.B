/*
 * Aluno: Yuri Marques Barboza
 * INSTITUTO FEDERAL DE SANTA CATARINA
 * Disciplina: Projeto Integrador II
 * Curso: Graduação em Engenharia Eletrônica
 * Objetivo: Testar se o sensor PIR está funcionando, usando um LED aceso para quando o sensor detectar movimento e um LED apagado quando não detectar movimento
 *  * 
 *  *  *                  Arduino MEGA
 *               -----------------
 *              |                 |
 *              |                 |         
 *  PIR   <---  | PWM2            |        
 *              |                 |
 *              |                 |
 *              |                 |        
 *              |                 |        
 *              |             GND |->- Cabo GND
 *              |             VCC |->- Cabo VCC
 *              |                 |        
 *              |                 |        
 *              |                 |    
 *              |                 |  
 *              |                 |  
 *               -----------------
 *                  USB   Fonte DC
*/
#define PIR 2
int ledPin = 3;                // LED 

int pirStat = 0;                   // PIR status
void setup() {
 pinMode(ledPin, OUTPUT);     
 pinMode(PIR, INPUT);     
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // Se movimento for detectado
   digitalWrite(ledPin, HIGH);      // LED ON
   Serial.println("Hey I got you!!!");
 } 
 else {
   digitalWrite(ledPin, LOW); // desliga o LED quando não tiver movimento sendo detectado
 }
} 
