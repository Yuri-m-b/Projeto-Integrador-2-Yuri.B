# Design

Para essa etapa do projeto, será definido os componentes e materiais que serão empregados na etapa de implementação, e também será demonstrado como esses componentes devem ser ligados, dessa forma foram criados uma tabela com todos os componentes que serão usados e uma maquete eletrônica para ilustrar como esses componentes serão conectados.

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

![maquete1](https://i.imgur.com/6uID7ZO.jpg)

![maquete2](https://i.imgur.com/Eg2hgGE.jpg)

## Teste dos Componentes

Para evitar problemas na etapa de implementação e para entender a funcionalidade dos componentes eletrônicos, foram realizados testes isoladamente cada componente que será usado no projeto.

* LED'S

Para testar os 6 LED's planejados para o projeto, desenvolveu-se apenas um circuito que ligaria esses LED's ao uma protoboard, com seus devidos requisitos de resistência com uma de suas portas ligadas ao gnd, e sua outra porta ligada nas entradas digitais do Arduino, usando um programa simples no software do Arduino, foi possível ligar e desligar os LED's confirmando assim que eles estavam funcionando.


![test_leds](https://i.imgur.com/QwQHbCX.jpg)

* Sensor de Movimento PIR

De forma a realizar o teste para o sensor de movimento PIR, deu-se necessario usar um LED que servíra de feedback para o sensor PIR, dessa forma ligando esse LED em uma das entradas digitais da placa Arduino, e também ligando esse sensor PIR em sua respectiva entrada digital na placa Arduino, seria então possível acionar um comando que fizesse com que quando a leitura de estado do sensor PIR estiver em Alta (HIGH), o LED acionara, e quando esse estado voltar para Baixo (LOW) apagando o LED.

![test PIR](https://i.imgur.com/fBLlfSG.jpg)

* Sensor de Gás MQ2

O sensor de gás MQ2, pode ser testado ligando suas saídas digitais e analogicas diretamente na placa Arduino, o programa teste criado para esse sensor, visa fazer a leitura do sinal do analogico do sensor apenas por demanda do usuario usando o teclado serial disponivel do programa Arduino, porém também testar um sistema de alerta em casos onde o volume de gás detectado esteja em um nível maior que o desejado, dessa forma também comprovando que o componente está funcionando corretamente.

![test MQ2](https://i.imgur.com/qAqopc8.jpg)

* Servo Motor

Para testar o componente Servo, foi apenas necessario conectar suas saídas GND, Vcc e Digital diretamente na placa Arduino, o codigo criado para seu teste tem como objetivo realizar com que esse Servo movimente sua saída parando nos angulos determinados pelo codigo teste.

![test servo](https://i.imgur.com/SMNGBUD.jpg)

* Buzzer

Conectando as saídas do Buzzer diretamente na placa Arduino, foi criado um programa que a partir de um comando por teclado serial seria acionado o Buzzer, por questão de preferencia não foi usado as funções Tone e noTone da documentação do Arduino, então para o ativamente e desligamento do equipamento é usado a alteração do estado digital do pino em que o Buzzer está ligado na placa Arduino

![test buzzer](https://i.imgur.com/qH9RSeD.jpg)

* Códigos usados para testes podem ser encontrados aqui:

[Testes](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/tree/main/Testes)
