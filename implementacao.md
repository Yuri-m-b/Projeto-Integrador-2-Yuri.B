# Implementação

Esse projeto tem como intenção trazer as vantagens da tecnologia atual para o dia-a-dia das pessoas, o tema Domotica abrange o universo existente de instrumentos eletrônicos que podem ser usados para melhorar e trazer mais conforto nas residências. A etapa de Implementação de um projeto, é o momento onde será executado tudo que foi comunicado nas etapas anteriores, nesta fase a implementação estará sendo executada com o intuito de entregar o projeto finalizado. 

Na etapa de Design foram mostrado os resultados da criação da maquete idealizada pela planta-baixa proposta, essa maquete servirá para a demonstração das funcionalidades dos eletrônicos em um ambiente mais próximo da realidade. Com a maquete pronta é necessário instalar os componentes eletrônicos em seus determinados locais, como foi projetado na planta baixa. 

Com os componentes informados na etapa de design, o primeiro passo tomado foi realizar testes para averiguar se todos os componentes eletrônicos estão funcionando corretamente. Os testes foram realizados usando programas criados separadamente para cada componente usando o software próprio do Arduino, visando testar suas condições físicas, e ao mesmo tempo planejando como será sua implementação no código final, dessa forma alguns arquivos testes ficaram mais complexos do que necessário para evitar possíveis problemas posteriores.
Em alguns casos os códigos testes já foram criados pensando nas possíveis maneiras de como esses componentes serão implementados juntos no programa final, isso pode ser notado pela utilização do monitor serial em alguns códigos testes, e a utilização das funções tarefas. 

[Como pode ser visto na sessão de testes do repositório](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/tree/main/Testes)

Decidiu-se então o planejamento de como cada componente se comportará dentro do programa, e como o úsuario poderá interagir com eles:

* LED'S: Os LEDs serão acionados pelo comando serial disponível pelo software do Arduino, cada LED usado no projeto necessita de um comando em um input específico do teclado dado pelo usuário para seu acionamento ou desligamento, um input de acionamento e um input de desligamento foram separados para cada LED. Eles não são influenciados por nenhum outro componente eletrônico do projeto dessa forma pode ser criar apenas uma tarefa/função para seu funcionamento. 

* Sensor MQ2: Como o intuito do sensor MQ2 é principalmente alertar o usuário quando o nível de gás na residência está em níveis perigosos, criou-se uma função onde quando o volume de gás captado pelo sensor for maior que um valor constante dado pelo programa, nesse caso foi usado 500, o programa mostrará uma mensagem de alerta no monitor serial e também será acionado o Buzzer causando um efeito sonoro. Decidiu-se também dar a liberdade para o usuário verificar os níveis de gás a partir do uso de um input de teclado dado pelo usuário.

* Sensor PIR: O sensor PIR foi planejado para servir como um sistema de segurança, dessa forma todo seu funcionamento é dado a partir do programa sem a necessidade ou interferência do usuário, a tarefa função criada para esse sensor tem como objetivo alertar pelo monitor serial quando algum movimento for detectado, esse sensor fica escaneando a área conforme o seu delay configurado usando seus potenciômetros interno mais o tempo determinado dentro do programa usando a tarefa_tempo. 

* Buzzer: Teve-se várias ideias para a implementação do buzzer no projeto final, porém foi mantido sua ideia inicial onde sua única interação é juntamente com o sensor MQ2, dessa forma o buzzer foi implementado na função de alerta do sensor MQ2, devido a problemas no uso da função noTone(), foi preferido usar as funções digitalWrite(High) e digitalWrite(LOW) para o ativamento e desligamento do Buzzer. 



### Maquete

A segunda parte da implementação é a criação de uma maquete para a planta baixa proposta na parte de concepção do projeto. Essa maquete servirá para a demonstração das funcionalidades dos eletrônicos em um ambiente mais próximo da realidade. Com a maquete pronta é necessário instalar os componentes eletrônicos em seus determinados locais, como foi projetado na planta baixa. 

![image](https://i.imgur.com/V8Kt01R.jpg)

## Programação dos componentes

Após ter completado todas as etapas anteriores, chegou-se na etapa mais importante do projeto, onde o objetivo é criar um código que será usado para controlar e monitorar todos os componentes eletrônicos que estão sendo usados.
Para criar um programa que consiga realizar todas as ações projetadas para o circuito, algumas medidas tiveram que ser tomadas para que as tarefas que serão controladas pelo Arduino consigam acontecer sem conflitos ou interrupções, dessa forma a função delay() não foi utilizada em nenhum momento no programa, e no seu lugar é usado uma equação com tempo, usando como base o exemplo a seguir:

[Usando função loop() com várias tarefas sem bloqueio (delay)](https://github.com/LPAE/arduino_tutorial/tree/main/tarefas)

Para todas as funções que necessitam de um "feedback" como o acionamentos dos LED's, ou mensagens de erros, é necessário o uso do teclado e monitor serial incluído no software do Arduino, todavia para que exista esse contato entre o programa e o teclado/monitor serial, foi preciso criar um código que construísse essa conexão, dando assim a função tarefa_1(loop) no programa.

* Tarefa_1
~~~ C
Linha 104 a 206
void tarefa_1()
~~~
O objetivo dessa tarefa é controlar todas as funções que necessitam do uso do teclado serial para que sejam realizadas, como todas as funções que pertencem a essa tarefa realizam apenas um comando, não foi necessário o uso de nenhum tipo de bloqueio para o seu funcionamento.
A tarefa_1 inclui todos os acionamentos e desligamentos dos LED's, a leitura do volume de gás gerada pelo pino analógico do sensor MQ2, e o controle de movimento do servo motor.

* Tarefa_2
~~~ C 
Linha 209 a 228
* void tarefa_2(unsigned long tempo_atual)
~~~
Essa tarefa foi criada com o intuito de fazer o programa ler quando o sensor PIR entrar em estado (High), que significa movimento detectado, e como resposta acionar uma mensagem de alarme na tela do monitor serial, uma das ideias planejadas para o circuito era de fazer o buzzer acionar juntamente com o sensor PIR, contudo como eu não consegui criar uma função que desligasse o alarme quando desejado, decidiu-se não usar esses dois eletrônicos juntos.

* Tarefa_3
~~~ C 
Linha 230 a 247
* void tarefa_3(unsigned long tempo_atual)
~~~
A tarefa 3 possui a segunda função relacionada ao sensor MQ2, a primeira como falada antes está dentro da tarefa_1 e utiliza um comando do teclado serial para seu acionamento, já essa função dentro da tarefa 3 tem como objetivo alertar o usuário enviando uma mensagem no monitor serial, quando o volume de gás estiver maior do que o volume de gás normal armazenado no programa como pode ser visto a seguir:

~~~ C
Linha 71
int leitura_sensor = 500; 
if (valor_analogico > leitura_sensor)
{
  Serial.println("GÁS DETECTADO");
  Serial.println("PERIGO!!!!");
  digitalWrite(buzzer, LOW);
}
~~~
Quando esse volume detectado pelo MQ2 for maior que o valor dado pela variável leitura_sensor , o programa aciona um alerta para o monitor digital, juntamente com o acionamento do Buzzer criando assim também um alarme sonoro.

Por fim com todas as tarefas completas, o código final para o projeto foi criado, esse código pode ser acessado no link abaixo e mais informações podem ser vistas nas anotações feitas no próprio programa.

[Programa final para o projeto](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/programafinal.ino)


