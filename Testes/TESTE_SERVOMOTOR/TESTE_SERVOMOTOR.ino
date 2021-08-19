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
