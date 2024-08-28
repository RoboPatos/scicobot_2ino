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

int i = 0; //declaracao da variavel para as rampas

const int TEMPO_ESPERA = 1000; //declaracao do intervalo de 1 segundo entre os sentidos de rotacao do motor

const int TEMPO_RAMPA = 30; //declaracao do intervalo de 30 ms para as rampas de aceleracao e desaceleracao

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
    //Serial.println(rStr);
    if( rdata == '\n')
    { // o -240 -56
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
//    if(rStr.substring(0, 1).toInt() == "P")
//    {
//    }
      rStr = "";
    }
  }


    
  // //configura os motores para o sentido horario
  // digitalWrite(PINO_IN1, LOW); 
  // digitalWrite(PINO_IN2, HIGH);
  // digitalWrite(PINO_IN3, LOW);
  // digitalWrite(PINO_IN4, HIGH);

  // //rampa de aceleracao
  // for (i = 0; i < 256; i=i+10){ 
  //   analogWrite(PINO_ENA, i);
  //   analogWrite(PINO_ENB, i);
  //   delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  // }

  // //rampa de desaceleracao
  // for (i = 255; i >= 0; i=i-10){ 
  //   analogWrite(PINO_ENA, i);
  //   analogWrite(PINO_ENB, i);
  //   delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  // }

  // delay(TEMPO_ESPERA); //intervalo de um segundo

  // //configura os motores para o sentido anti-horario
  // digitalWrite(PINO_IN1, HIGH); 
  // digitalWrite(PINO_IN2, LOW);
  // digitalWrite(PINO_IN3, HIGH);
  // digitalWrite(PINO_IN4, LOW);

  // //rampa de aceleracao
  // for (i = 0; i < 256; i=i+10){ 
  //   analogWrite(PINO_ENA, i);
  //   analogWrite(PINO_ENB, i);
  //   delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  // }

  // //rampa de desaceleracao
  // for (i = 255; i >= 0; i=i-10){ 
  //   analogWrite(PINO_ENA, i); 
  //   analogWrite(PINO_ENB, i);
  //   delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  // }

  // delay(TEMPO_ESPERA); //intervalo de um segundo
  
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