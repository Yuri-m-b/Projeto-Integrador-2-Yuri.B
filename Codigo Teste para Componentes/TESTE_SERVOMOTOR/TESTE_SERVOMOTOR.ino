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
