/*
 * Aluno: Yuri Marques Barboza
 * INSTITUTO FEDERAL DE SANTA CATARINA
 * Disciplina: Projeto Integrador II
 * Curso: Graduação em Engenharia Eletrônica
 * Objetivo: Testar se o sensor PIR está funcionando, usando um LED aceso para quando o sensor detectar movimento e um LED apagado quando não detectar movimento
 *  * 
 *  *  *             Arduino MEGA
 *               -----------------
 *              |                 |
 *              |                 |         
 *              |                 |        
 *              |                 |
 *              |                 |
 *              |                 |         
 *              |                 |        
 *              |             GND |->- Cabo GND
 *              |             VCC |->- Cabo VCC
 *  SERVO <---  | PWM9            |        
 *              | PWM10           |        
 *              | PWM11           |    
 *              |                 |  
 *              |                 |  
 *               -----------------
 *                  USB   Fonte DC
*/
// https://create.arduino.cc/projecthub/nithishmurugavenkateshmaker/automatic-door-opener-64200b
// https://blog.fazedores.com/como-usar-servo-motor-com-arduino/
#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
 
const int pinoServo = 9; //PINO DIGITAL UTILIZADO PELO SERVO  
 
Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO
 
void setup (){
  s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(90); //INICIA O MOTOR NA POSIÇÃO 90º
}
void loop(){


}
