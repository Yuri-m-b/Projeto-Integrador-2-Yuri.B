# Códigos Testes

Esse documento tem como objetivo demonstrar e explicar resumidamente os códigos que foram criados e utilizados, com o intuito de testar as condições dos componentes eletrônicos, e em alguns casos já pensando na forma que esses códigos serão implementados no código final do projeto.

### Código Teste para LED's

No código utilizado para testar o funcionamento dos LED'S, aproveitou-se a ideia de usar o teclado serial do arduino para o acionamento e desligamento dos LED 's usando um caractere digitado pelo usuário, esse teclado seria também utilizado no projeto final posteriormente. 

* [Arquivo Teste p/ LEDs](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_6LED/TESTE_6led_acendendocomteclado.ino)

### Código Teste para o sensor MQ2

O código teste utilizado para o sensor MQ2, possui 2 tarefas, onde a primeira é usada para testar o teclado serial juntamente com a leitura do pino analogico do sensor, com a função de ler e imprimir o valor que estiver nesse pino e demonstrar no monitor serial do arduino, e a tarefa 2 possui uma equação que será utilizado para o acionamento da mensagem de aviso quando o volume de gás captada pelo MQ2 seja maior que o volume de gás limite selecionado pele usuário na linha 13 do código

* [Arquivo Teste p/ MQ2](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_MQ2/TESTE_MQ2.ino)

### Código Teste para o sensor PIR

O código teste para o sensor PIR, é um código simples que apenas lê o estado digital do sensor, e quando esse sinal estiver em 'HIGH'  (movimento detectado), um LED é aceso para alertar o usúario.

* [Arquivo Teste p/ PIR](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/Teste_PIR/Teste_sensorPIR.ino)

### Código Teste para o sensor BUZZER

No código teste do Buzzer, é utilizado o teclado serial para o acionamento do Buzzer usando o comando Tone(pino,frequência) e o encerramento do som usando o comando noTone, porém devido a problemas vistos com os comandos Tone e noTone, foi necessário a adição do comando digitalWrite para o completo desligamento do componente, caso contrário esse codigo nao funcionaria na maneira desejada.

* [Arquivo Teste p/ BUZZER](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_BUZZER/TESTE_BUZZER.ino)

### Código Teste para o componente SERVO

E por fim o código teste para o Servo Motor, utiliza da função s.digitalwrite logo na parte void setup, e dessa forma já é possível verificar se o componente está funcionando.

* [Arquivo Teste p/ SERVO](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_SERVOMOTOR/TESTE_SERVOMOTOR.ino)
