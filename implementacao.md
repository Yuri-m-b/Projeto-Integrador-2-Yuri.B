# Implementação

A etapa de Implementação de um projeto, é o momento onde será executado tudo que foi comunicado nas etapas anteriores, nesta fase a implementação estará sendo executada com o intuito de entregar o projeto finalizado. 

### Testes dos componentes

Com os materiais informados na etapa de design, o primeiro passo a ser tomado foi realizar testes para averiguar se todos os componentes eletrônicos estão funcionando corretamente. Os testes foram realizados usando programas criados usando o software próprio do Arduino separadamente para cada componente, visando testar suas condições físicas, e ao mesmo tempo planejando como será sua implementação no código final, dessa forma alguns arquivos testes ficaram mais complexos do que necessário para evitar possíveis problemas posteriores.

[Como pode ser visto na sessão de testes do repositório](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/tree/main/Testes)

### Maquete

A segunda parte da implementação é a criação de uma maquete para a planta baixa proposta na parte de concepção do projeto. Essa maquete servirá para a demonstração das funcionalidades dos eletrônicos em um ambiente mais próximo da realidade. Com a maquete pronta é necessário instalar os componentes eletrônicos em seus determinados locais, como foi projetado na planta baixa. 

![image](https://i.imgur.com/V8Kt01R.jpg)

## Programação dos componentes

Após ter completado todas as etapas anteriores, chegou-se na etapa mais importante do projeto, onde o objetivo é criar um código que será usado para controlar e monitorar todos os componentes eletrônicos que estão sendo usados.
Para criar um programa que consiga realizar todas as ações projetadas para o circuito, algumas medidas tiveram que ser tomadas para que as tarefas que serão controladas pelo Arduino consigam acontecer sem conflitos ou interrupções, dessa forma a função delay() não foi utilizada em nenhum momento no programa, e no seu lugar é usado uma equação com tempo, usando como base o exemplo a seguir:

[Usando função loop() com várias tarefas sem bloqueio (delay)](https://github.com/LPAE/arduino_tutorial/tree/main/tarefas)

[Programa final para o projeto](https://github.com/Yuri-m-b/Projeto-Integrador-2-Yuri.B/blob/main/programafinal.ino)


