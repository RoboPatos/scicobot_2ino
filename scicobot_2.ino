// Definição dos pinos para os motores
const int motor1Pin1 = 3; // Pino PWM para o motor 1
const int motor1Pin2 = 4; // Pino de direção para o motor 1
const int motor2Pin1 = 5; // Pino PWM para o motor 2
const int motor2Pin2 = 6; // Pino de direção para o motor 2

void setup() {
  // Configura os pinos como saída
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Verifica se há dados disponíveis na serial
  if (Serial.available() >= 2) {
    // Lê os valores enviados pela serial
    int motor1Speed = Serial.read();
    int motor2Speed = Serial.read();

    // Mapeia os valores de -255 a 255 para 0 a 255 para PWM
    int motor1PWM = abs(motor1Speed);
    int motor2PWM = abs(motor2Speed);

    // Controle do Motor 1
    if (motor1Speed >= 0) {
      digitalWrite(motor1Pin2, LOW);  // Direção
      analogWrite(motor1Pin1, motor1PWM); // Velocidade
    } else {
      digitalWrite(motor1Pin2, HIGH); // Direção
      analogWrite(motor1Pin1, motor1PWM); // Velocidade
    }

    // Controle do Motor 2
    if (motor2Speed >= 0) {
      digitalWrite(motor2Pin2, LOW);  // Direção
      analogWrite(motor2Pin1, motor2PWM); // Velocidade
    } else {
      digitalWrite(motor2Pin2, HIGH); // Direção
      analogWrite(motor2Pin1, motor2PWM); // Velocidade
    }
  }
}
