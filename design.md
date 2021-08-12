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

* LED Branco: Serão usados para a iluminação dos cômodos dentro da residência. Eles serão conectados nas saídas digitais do Arduino juntamente com seus respectivos resistores, tendo assim uma corrente de 8.1mA e tensão de 5V chegando até seus conectores.

* Protoboard 830 pontos: A protoboard será usada para receber principalmente as ligações dos componentes nos conectores GND e de 5V da placa Arduino Mega

* Módulo Buzzer 5V: Será usado para servir como um alerta ao morador, quando forem detectados valores muitos altos de gás pelo sensor de fumaça MQ2. O módulo buzzer possui três pinos sendo eles; um pino de alimentação 5V, um pino de terra GND e um pino para a saída digital do arduino.

## Maquete

![maquete1](https://i.imgur.com/6uID7ZO.jpg)

![maquete2](https://i.imgur.com/Eg2hgGE.jpg)
