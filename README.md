# SciCoBot

<p align="center">
  <img src="https://github.com/NatanaelAmil/scicobot_2ino/blob/main/outros_arquivos/LOGO.png"/ height="200" width="1080">
</p>

Aqui são apresentados códigos Arduino Usados no projeto SciCoBot. Eles devem ser carregados separadamente pela IDE antes da conexão serial ser efetuada.

 * scicobot.ino: feito para controlar os motores separadamente, por uma entrada serial, que recebe dois valores entre -255 a 255. O módulo do número recebido indica a velocidade de rotação do motor, enquanto a condição de maior ou menor que zero indica o sentido de rotação do mesmo. Os parâmetros a serem recebidos são:

    `o <velocidade e sentido do motor1> <velocidade e sentido do motor2>`

Por exemplo, Para o máximo em sentido horário para ambos motores, escreva: 

    o 255 255
    

E para o máximo em sentido anti-horário para ambos motores, escreva: 

    o -255 -255


OBS: Para testes com a arduino IDE, marque a opção de "Retorno de Linha" e "9600 baud". A montagem está apresentada abaixo:

<p align="center">
  <img src="https://github.com/NatanaelAmil/scicobot_2ino/blob/main/outros_arquivos/scicobot.png"/ height="845" width="770">
</p>

<p align="center">
  <img src="https://github.com/NatanaelAmil/scicobot_2ino/blob/main/outros_arquivos/Montagem.png"/ height="500" width="1080">
</p>

<p align="center">
  <img src="https://github.com/NatanaelAmil/scicobot_2ino/blob/main/outros_arquivos/Montagem_comentada.png"/ height="590" width="1080">
</p>

Além disso, [aqui](https://github.com/NatanaelAmil/scicobot_2ino/blob/main/outros_arquivos/Guia%20SciCoBot%20Motor.docx) está presente o manual do projeto. Nele foi apresentado da forma mais didática possível como o robô foi pensado, montado e executado.

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

