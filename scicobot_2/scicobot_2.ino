//pinos utilizados para controlar a velocidade de rotação
const int PINO_ENA = 6; 
const int PINO_ENB = 5;

//pinos utilizados para controlar o sentido do motor
const int PINO_IN1 = 4; 
const int PINO_IN2 = 3;
const int PINO_IN3 = 8;
const int PINO_IN4 = 7;

int speed1;
int speed2;
int motor1PWM;
int motor2PWM;

char rdata; // received charactors
String rStr = "";

int params[4];

void run_motors();

void setup() {
  Serial.begin(9600);

  //configuração dos pinos como saida
  pinMode(PINO_ENA, OUTPUT); 
  pinMode(PINO_ENB, OUTPUT);
  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);

  //inicia o codigo com os motores parados
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, LOW);
  digitalWrite(PINO_ENA, LOW);
  digitalWrite(PINO_ENB, LOW);
}

void loop() {
   if (Serial.available()) {
    rdata = Serial.read();
    rStr = rStr + rdata;
    if( rdata == '\n')
    { 
      if(rStr.substring(0, 2).equals("o ")) 
      {
        int sepIndex = rStr.indexOf(" ", 2); // começando em 2 pq "o " ocupam 0 e 1
        speed1 = rStr.substring(2, sepIndex).toInt();
        Serial.print("speed1 ");
        Serial.println(speed1);
        speed2 = rStr.substring(sepIndex+1).toInt();
        Serial.print("speed2 ");
        Serial.println(speed2);
        
        motor1PWM = abs(speed1); //módulo para definição da velocidade do motor A
        motor2PWM = abs(speed2); //módulo para definição da velocidade do motor B

        Serial.print("motor1PWM ");
        Serial.println(motor1PWM);
        Serial.print("motor2PWM ");
        Serial.println(motor2PWM);
        
        run_motors();
      }

      rStr = "";

    }
  }
}

void run_motors(){
  if (speed1 >= 0) { //Sentido Horario
        digitalWrite(PINO_IN1, LOW); //Direção motor 1
        digitalWrite(PINO_IN2, HIGH); //Direção motor 1
        analogWrite(PINO_ENA, motor1PWM); // Velocidade motor 1
    } else {
        digitalWrite(PINO_IN1, HIGH); //Direção motor 1
        digitalWrite(PINO_IN2, LOW); //Direção motor 1
        analogWrite(PINO_ENA, motor1PWM); // Velocidade motor 1
    }

    // Controle do Motor 2
    if (speed2 >= 0) {
        digitalWrite(PINO_IN3, LOW); //Direção motor 2
        digitalWrite(PINO_IN4, HIGH); //Direção motor 2
        analogWrite(PINO_ENB, motor2PWM); // Velocidade motor 2
    } else {
        digitalWrite(PINO_IN3, HIGH); //Direção motor 2
        digitalWrite(PINO_IN4, LOW); //Direção motor 2
        analogWrite(PINO_ENB, motor2PWM); // Velocidade motor 2
    }
}