//                       SciCoBot_2.0 

//A ideia aqui é receber dois valores via serial e controlar os motores isoladamente
//Esse projeto foi pensado para se comunicar com um raspberry por meio de nós ros2. 

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////  TESTE ////////////////////////////////////////////

// Definição dos pinos para os motores
const int PINO_ENA = 6; //pino utilizado para controlar a velocidade do motor A 
const int PINO_ENB = 5; //pino utilizado para controlar a velocidade do motor B

const int PINO_IN1 = 4; //pino utilizado para controlar o sentido do motor A
const int PINO_IN2 = 3; //pino utilizado para controlar o sentido do motor A
const int PINO_IN3 = 8; //pino utilizado para controlar o sentido do motor B
const int PINO_IN4 = 7; //pino utilizado para controlar o sentido do motor B

void setup() {
  
  // Configura os pinos como saída
  pinMode(PINO_ENA, OUTPUT); // Configura os pinos como saída
  pinMode(PINO_ENB, OUTPUT); // Configura os pinos como saída
  pinMode(PINO_IN1, OUTPUT); // Configura os pinos como saída
  pinMode(PINO_IN2, OUTPUT); // Configura os pinos como saída
  pinMode(PINO_IN3, OUTPUT); // Configura os pinos como saída
  pinMode(PINO_IN4, OUTPUT); // Configura os pinos como saída

    Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {

    if (Serial.available() >= 2) {// Verifica se há dados disponíveis na serial
    int motor1Speed = Serial.read();  // Lê os valores enviados pela serial
    int motor2Speed = Serial.read();  // Lê os valores enviados pela serial

    // Mapeia os valores de -255 a 255 para 0 a 255 para PWM
    int motor1PWM = abs(motor1Speed); //módulo para definição da velocidade do motor A
    int motor2PWM = abs(motor2Speed); //módulo para definição da velocidade do motor B

//                        Até aqui BELEZA


    // Controle do Motor 1
    if (motor1Speed >= 0) { //Sentido Horario
        digitalWrite(PINO_IN1, LOW); //Direção motor 1
        digitalWrite(PINO_IN2, HIGH); //Direção motor 1
        analogWrite(PINO_ENA, motor1PWM); // Velocidade motor 1
    } else {
        digitalWrite(PINO_IN1, HIGH); //Direção motor 1
        digitalWrite(PINO_IN2, LOW); //Direção motor 1
        analogWrite(PINO_ENA, motor1PWM); // Velocidade motor 1
    }

    // Controle do Motor 2
    if (motor2Speed >= 0) {
        digitalWrite(PINO_IN3, LOW); //Direção motor 2
        digitalWrite(PINO_IN4, HIGH); //Direção motor 2
        analogWrite(PINO_ENB, motor2PWM); // Velocidade motor 2
    } else {
        digitalWrite(PINO_IN3, HIGH); //Direção motor 2
        digitalWrite(PINO_IN4, LOW); //Direção motor 2
        analogWrite(PINO_ENB, motor2PWM); // Velocidade motor 2
    }
  }
}
