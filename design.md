# Design

Como a ideia do projeto é introduzir a robótica dentro um ambiente residencial, com intuito de proporcionar uma melhor qualidade de vida do residente, dado assim o nome Domótica, tem-se na etapa de Design do projeto a definição dos componentes e materiais que serão empregados na etapa de implementação, e também será demonstrado como esses componentes devem ser ligados, dessa forma foram criados uma tabela com todos os componentes que serão usados e uma maquete eletrônica para ilustrar como esses componentes serão conectados.

## Tabela de Componententes

| Componente	Quantidade| Quantidade |   
| ----------------------| ---------- |
|Arduino Mega 2560| 1
| Micro Servo SG92R 9g| 1
| Sensor de Fumaça MQ2	 |  1
| LED Branco	 |  6
| Resistor 620 ohm	| 6
| Protoboard 830 pontos |  1
| Módulo Buzzer 5V Passivo | 1
| Sensor de Movimento PIR HC-sr501 | 1

## Maquete Eletrônica

![img1](https://i.imgur.com/gItJHRy.jpg)

* Arduino Mega 2560: Componente principal do projeto, tendo como função controlar todo os outros componentes que serão usados, esse modelo foi escolhido devido ao maior número de portas de entrada e saída, que serão usadas para conectar o Arduino com os outros componentes.

* Micro Servo SG92R 9g: Usado para controlar o portão da residência, esse componente pode ser usado juntamente com o Arduino Mega devido sua tensão de alimentação ser de 5V. O servo motor será conectado em uma porta digital, e nas portas GND e de alimentação 5V da placa arduino

* Sensor de Fumaça MQ2: Também chamado de sensor de gás, esse componente tem como função detectar gás de cozinha (GLP). Esse sensor será conectado em uma porta digital e uma porta analógica, e nas portas GND e de alimentação 5V da placa arduino.

* Sensor de Movimento PIR HC-sr501: Esse sensor detecta movimentos em sua área de ação, enviando assim um sinal em nível lógico alto para o arduino. Esse componente será conectado em uma porta digital, e nas portas GND e de alimentação 5V da placa arduino.

* LED Branco: Serão usados para a iluminação dos cômodos dentro da residência. Eles serão conectados nas saídas digitais do Arduino juntamente com seus respectivos resistores, tendo assim uma corrente menor que 10mA.

* Protoboard 830 pontos: A protoboard será usada para fazer a ligações entre os cabos usados pelos componentes.

* Módulo Buzzer 5V: Será usado para servir como um alerta ao morador, quando forem detectados valores muitos altos de gás pelo sensor de fumaça MQ2. O módulo buzzer possui três pinos sendo eles; um pino de alimentação 5V, um pino de terra GND e um pino para a saída digital do arduino.

## Maquete

![maquete1](https://i.imgur.com/Ngvynqq.jpg)

![maquete2](https://i.imgur.com/y2Hcp6w.jpg)

## Teste dos Componentes

Para evitar problemas na etapa de implementação e para entender a funcionalidade dos componentes eletrônicos, foram realizados testes de forma isolada para cada componente que será usado no projeto. Como o projeto final poderá ter mais de um componente funcionando ao mesmo tempo, não seria inteligente usar a função delay porque essa função bloqueia completamente o programa até que a função que está ocorrendo no momento termine. Então para resolver esse problema foi decidido separar o código das ações de cada componente em "tarefas", cada tarefa terá um tempo determinado para enviar os dados de sua função, permitindo assim múltiplas ações acontecerem ao mesmo tempo enquanto o programa estiver rodando.

* LED'S

* [Arquivo Teste p/ LEDs](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_6LED/TESTE_6led_acendendocomteclado.ino)

Para testar os 6 LED 's planejados para o projeto, desenvolveu-se um circuito que ligaria esses LED's uma protoboard, sendo sua saída digital filtrada por uma resistência, e sua outra saída conectada ao GND. Então usando um programa simples no software Arduino, foi possível ligar e desligar os LED's a partir do uso do teclado serial disponível, confirmando assim que eles estavam funcionando.


![test_leds](https://i.imgur.com/QwQHbCX.jpg)


* Sensor de Movimento PIR

* [Arquivo Teste p/ PIR](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/Teste_PIR/Teste_sensorPIR.ino)

De forma a realizar o teste para o sensor de movimento PIR, deu-se necessário usar um LED que serviria de feedback para o sensor PIR, dessa forma ligando esse LED em uma das entradas digitais da placa Arduino, e também ligando esse sensor PIR em outra entrada digital na placa Arduino, seria então possível acionar um comando que fizesse com que, quando a leitura de estado do sensor PIR estiver em Alta (HIGH), o LED acenderá, e quando esse estado voltar para Baixo (LOW) o LED será apagado.

![test PIR](https://i.imgur.com/fBLlfSG.jpg)

* Sensor de Gás MQ2

* [Arquivo Teste p/ MQ2](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_MQ2/TESTE_MQ2.ino)

O sensor de gás MQ2 foi  testado ligando suas saídas digitais e analogicas diretamente na placa Arduino, o programa criado para  testar esse sensor visa fazer a leitura do sinal da saída analogica do sensor apenas quando o usuário requerer essa informação, para isso foi usado o teclado serial disponível do programa Arduino. Outra funcionalidade testada pelo programa é um sistema de alerta em casos onde o volume de gás detectado esteja em um nível maior que o desejado, onde quando essa situação acontece, o programa imprime uma mensagem de alerta no monitor serial do software Arduino, dessa forma comprovando que o componente está funcionando corretamente.

![test MQ2](https://i.imgur.com/qAqopc8.jpg)

* Servo Motor

* [Arquivo Teste p/ SERVO](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_SERVOMOTOR/TESTE_SERVOMOTOR.ino)

Para testar o componente Servo, foi apenas necessário conectar suas saídas GND, Vcc e Digital diretamente na placa Arduino, o código criado para seu teste tem como objetivo realizar com que esse Servo movimente sua saída parando nos ângulos determinados pelo programa.

![test servo](https://i.imgur.com/SMNGBUD.jpg)

* Buzzer

* [Arquivo Teste p/ BUZZER](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/Testes/TESTE_BUZZER/TESTE_BUZZER.ino)

Conectando as saídas do Buzzer diretamente na placa Arduino, foi criado um programa que a partir de um comando por teclado serial será acionado o auto falante do Buzzer, por questão de preferência não foi usado as funções Tone e noTone da documentação do Arduino, então para o ativamente e desligamento do equipamento é usado a alteração do estado digital do pino em que o Buzzer está ligado na placa Arduino

![test buzzer](https://i.imgur.com/qH9RSeD.jpg)

* Mais informações sobre os códigos usados para testes podem ser encontrados aqui:

[Programa Teste](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/tree/main/Testes)
