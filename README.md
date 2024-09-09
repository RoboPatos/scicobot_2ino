<p align="center">
  <img src="https://github.com/RoboPatos/scicobot_2ino/blob/main/outros_arquivos/LOGO.png"/ height="200" width="1080">
</p>

Aqui são apresentados códigos Arduino Usados no projeto SciCoBot. Eles devem ser carregados separadamente pela IDE antes da conexão serial ser efetuada. Para ter acesso aos arquivos a serem compilados no Raspberry Pi, clique [aqui](https://github.com/RoboPatos/serial_motor_demo.git).

## SciCoBot 2024

<p align="center">
  <img src="https://github.com/RoboPatos/scicobot_2ino/blob/main/outros_arquivos/scicobot.png"/ height="845" width="770">
</p>

            TABELA DE LIGAÇÃO

      Arduino      |     Ponte H
      --------------------------------
         5V        |       +12V
      --------------------------------
        GND        |        GND
      --------------------------------
         5V        |        +5V
      --------------------------------
         D3        |        IN2
      --------------------------------
         D4        |        IN1
      --------------------------------
         D5        |        ENB
      --------------------------------
         D6        |        ENA
      --------------------------------
         D7        |        IN4
      --------------------------------
         D8        |        IN3
      --------------------------------
       * Remover jumper do VLogic

<p align="center">
  <img src="https://github.com/RoboPatos/scicobot_2ino/blob/main/outros_arquivos/Montagem_comentada.png"/ height="700" width="1080">
</p>

 * scicobot.ino: feito para controlar os motores separadamente, por uma entrada serial, que recebe dois valores entre -255 a 255. O módulo do número recebido indica a velocidade de rotação do motor, enquanto a condição de maior ou menor que zero indica o sentido de rotação do mesmo. Os parâmetros a serem recebidos são:

    `o <velocidade e sentido do motor1> <velocidade e sentido do motor2>`

Por exemplo, Para o máximo em sentido horário para ambos motores, escreva: 

    o 255 255
    

E para o máximo em sentido anti-horário para ambos motores, escreva: 

    o -255 -255


OBS: Para testes com a arduino IDE, marque a opção de "Retorno de Linha" e "9600 baud". A montagem está apresentada abaixo:



Além disso, [aqui](https://github.com/RoboPatos/scicobot_2ino/blob/main/outros_arquivos/Guia%20SciCoBot%20Motor.docx) está presente o manual do projeto. Nele foi apresentado da forma mais didática possível como o robô foi pensado, montado e executado,desde a instalação de programas, até o uso do projeto aqui descrito.

# Outros códigos:

 * scicobot_1-7.ino: controla a velocidade dos motores por entrada serial e por um switch case que conta de 1 a 7, de modo que:
```
    1) Velocidade 1 (75%)
    2) Velocidade 2 (50%)
    3) Velocidade 3 (25%)
    4) Freiar
    5) Velocidade 4 (100%)
    6) Para trás (anti-horário)
    7) Para frente (horário)
```
 * OBS: O código `scicobot_1-7.ino` foi utilizado apenas para testes e estudo, a versão final do projeto não seguiu continuidade com a ideia. Mas para futuros contribuintes com a pesquisa, acredita-se que seria de grande valia a implementação de um script que capaz de aproveitar o material.