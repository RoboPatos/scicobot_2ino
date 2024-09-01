// Pinos utilizados para controlar a velocidade de rotação dos motores
const int PINO_ENA = 6;  // Pino PWM para controle da velocidade do motor A
const int PINO_ENB = 5;  // Pino PWM para controle da velocidade do motor B

// Pinos utilizados para controlar o sentido de rotação dos motores
const int PINO_IN1 = 4;  // Pino digital para controle do sentido do motor A
const int PINO_IN2 = 3;  // Pino digital para controle do sentido do motor A
const int PINO_IN3 = 8;  // Pino digital para controle do sentido do motor B
const int PINO_IN4 = 7;  // Pino digital para controle do sentido do motor B

int speed1;     // Velocidade do motor A recebida via comunicação serial
int speed2;     // Velocidade do motor B recebida via comunicação serial
int motor1PWM;  // Valor PWM calculado para o motor A (baseado em speed1)
int motor2PWM;  // Valor PWM calculado para o motor B (baseado em speed2)

char rdata;     // Caractere recebido via comunicação serial
String rStr = ""; // String para armazenar os caracteres recebidos

void run_motors(); // Declaração da função para rodar os motores

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps

  // Configura os pinos como saída
  pinMode(PINO_ENA, OUTPUT);
  pinMode(PINO_ENB, OUTPUT);
  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);

  // Inicia o código com os motores parados
  digitalWrite(PINO_IN1, LOW); // Motor A parado
  digitalWrite(PINO_IN2, LOW); // Motor A parado
  digitalWrite(PINO_IN3, LOW); // Motor B parado
  digitalWrite(PINO_IN4, LOW); // Motor B parado
  digitalWrite(PINO_ENA, LOW); // PWM do motor A desligado
  digitalWrite(PINO_ENB, LOW); // PWM do motor B desligado
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available()) {
    rdata = Serial.read(); // Lê um caractere da porta serial
    rStr = rStr + rdata;   // Concatena o caractere na string rStr

    // Verifica se o caractere recebido é uma nova linha ('\n')
    if(rdata == '\n') {
      // Verifica se a string recebida começa com "o "
      if(rStr.substring(0, 2).equals("o ")) {
        int sepIndex = rStr.indexOf(" ", 2); // Encontra o índice do espaço após "o "

        // Extrai o primeiro valor de velocidade (speed1)
        speed1 = rStr.substring(2, sepIndex).toInt(); 
        Serial.print("speed1 ");
        Serial.println(speed1);

        // Extrai o segundo valor de velocidade (speed2)
        speed2 = rStr.substring(sepIndex+1).toInt();
        Serial.print("speed2 ");
        Serial.println(speed2);

        // Calcula o valor absoluto das velocidades para o PWM dos motores
        motor1PWM = abs(speed1); // Módulo para definição da velocidade do motor A
        motor2PWM = abs(speed2); // Módulo para definição da velocidade do motor B

        Serial.print("motor1PWM ");
        Serial.println(motor1PWM);
        Serial.print("motor2PWM ");
        Serial.println(motor2PWM);

        run_motors(); // Chama a função para executar os motores com as novas velocidades
      }

      rStr = ""; // Limpa a string após processar o comando
    }
  }
}

void run_motors() {
  // Controle do Motor A
  if (speed1 >= 0) { // Se a velocidade é positiva, gira no sentido horário
    digitalWrite(PINO_IN1, LOW);  // Configura o sentido do motor A
    digitalWrite(PINO_IN2, HIGH); // Configura o sentido do motor A
    analogWrite(PINO_ENA, motor1PWM); // Ajusta a velocidade do motor A
  } else { // Se a velocidade é negativa, gira no sentido anti-horário
    digitalWrite(PINO_IN1, HIGH); // Configura o sentido do motor A
    digitalWrite(PINO_IN2, LOW);  // Configura o sentido do motor A
    analogWrite(PINO_ENA, motor1PWM); // Ajusta a velocidade do motor A
  }

  // Controle do Motor B
  if (speed2 >= 0) { // Se a velocidade é positiva, gira no sentido horário
    digitalWrite(PINO_IN3, LOW);  // Configura o sentido do motor B
    digitalWrite(PINO_IN4, HIGH); // Configura o sentido do motor B
    analogWrite(PINO_ENB, motor2PWM); // Ajusta a velocidade do motor B
  } else { // Se a velocidade é negativa, gira no sentido anti-horário
    digitalWrite(PINO_IN3, HIGH); // Configura o sentido do motor B
    digitalWrite(PINO_IN4, LOW);  // Configura o sentido do motor B
    analogWrite(PINO_ENB, motor2PWM); // Ajusta a velocidade do motor B
  }
}
