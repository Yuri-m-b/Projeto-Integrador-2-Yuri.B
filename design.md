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
| Sensor de Movimento PIR HC-sr501 | 1

## Maquete Eletrônica

![img1](https://i.imgur.com/224ynTA.jpg)

Para a construção da maquete eletrônica foi usado o software Fritzing (0.9.3b), para esse projeto em particular se mostrou necessario adicionar manualmente os esquematicos de alguns componentes, sendo eles, o micro servo SG92R, o sensor de fumaça MQ2 e por fim o sensor de movimento PIR.

* Arduino Mega 2560: Componente principal do projeto, tendo como função controlar todo os outros componentes que serão usados, esse modelo foi escolhido devido ao maior número de portas de entrada e saída, que serão usadas para conectar o Arduino com os outros componentes.

* Micro Servo SG92R 9g: Usado para controlar o portão da residência, esse componente pode ser usado juntamente com o Arduino Mega devido sua tensão de alimentação ser de 5V.

* Sensor de Fumaça MQ2: Também chamado de sensor de gás, esse componente tem como função detectar gás de cozinha (GLP).

* Sensor de Movimento PIR HC-sr501: Esse sensor detecta movimentos em sua área de ação, enviando assim um sinal em nível logico alto para o arduino
