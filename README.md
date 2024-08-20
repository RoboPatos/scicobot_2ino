# scicobot_2ino

Aqui são apresentados dois códigos: 


-scicobot_1.ino: controla a velocidade dos motores por entrada serial e por um switch case que conta de 1 a 7, de modo que:

    "1) Velocidade 1 (75%)"
    "2) Velocidade 2 (50%)"
    "3) Velocidade 3 (25%)"
    "4) Freiar"
    "5) Velocidade 4 (100%)"
    "6) Para trás (anti-horário)"
    "7) Para frente (horário)"

-scicobot_2.ino: feito para controlar os motores separadamente, por uma entrada serial, que recebe dois valores entre -255 a 255, indicando a velocidade e a orientação do movimento.
