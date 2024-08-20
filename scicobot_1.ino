//motor A
const byte A_IA = 9; // Motor A Input A --> MOTOR A (+) (PWM)
const byte A_IB = 6; // Motor A Input B --> MOTOR A (-) (PWM)

//motor B
const byte B_IA = 11; // Motor B Input A --> MOTOR B (+) (PWM)
const byte B_IB = 10; // Motor B Input B --> MOTOR B (-) (PWM)

//variáveis
int motorSpeed = 0; // armazenar o valor de velocidade atual
boolean stateTurn = 0; // armazenar rotação (0 ou 1) - 0: horário / 1: anti-horário

//Inicializa Pinos e Comunicação Serial (setup)
void setup(){
 Serial.begin(9600); // inicia a comunicação serial
 // define pinos como saída do Arduino
 pinMode(A_IA,OUTPUT); // motor A
 pinMode(A_IB,OUTPUT); // motor A
 pinMode(B_IA,OUTPUT); // motor B
 pinMode(B_IB,OUTPUT); // motor B
 // inicia com os motores desligados
 motorBreak();
}

// loop infinito 
void loop() {  
  menu(); // inicia menu no monitor serial  
}

// inicia menu no monitor serial
void menu() {
  boolean isValidOption;
  // desenho do menu
  Serial.println( "-----------------------------" );
  Serial.println( "MENU:" );
  Serial.println( "1) Velocidade 1 (75%)" );
  Serial.println( "2) Velocidade 2 (50%)" );
  Serial.println( "3) Velocidade 3 (25%)" );
  Serial.println( "4) Freiar" );
  Serial.println( "5) Velocidade 4 (100%)" );
  Serial.println( "6) Para trás (anti-horário)" );
  Serial.println( "7) Para frente (horário)" );
  Serial.println( "-----------------------------" );
  // ações do menu
  do {
    byte caractere;
    // aguarde o próximo caractere
    Serial.println("...");
    Serial.print("Digite a opção: ");    
    while ( !Serial.available() ) {}
    caractere = Serial.parseInt();
    if (caractere > 0 && caractere <8) {
      Serial.println(caractere);    
    } else {
      Serial.println("Opção Inválida");
    }
    //caractere = Serial.read();    
    // executa as opções do menu
    switch (caractere) {
    case 1: // velocidade 25%
      Serial.println("Velocidade 1 (25%)");
      motorSpeed = (255 * 0.75);
      motorRun(motorSpeed);
      isValidOption = true; 
      break;
    case 2: // velocidade 50%
      Serial.println("Velocidade 2 (50%)");
      motorSpeed = (255 * 0.5);
      motorRun(motorSpeed);
      isValidOption = true; 
      break; 
    case 3: // velocidade 75%
      Serial.println("Velocidade 3 (75%)");
      motorSpeed = (255 * 0.25);
      motorRun(motorSpeed);
      isValidOption = true; 
      break;
    case 4: // velocidade 100%
      Serial.println("Velocidade 4 (100%)");
      motorSpeed = 0;
      motorRun(motorSpeed);
      isValidOption = true; 
      break;     
    case 5: // frear bruscamente o motor
      Serial.println("Freiar motor");
      motorSpeed = 255;
      motorRun(motorSpeed);
      isValidOption = true; 
      break;
   case 6: //sentido horário (para frente)
      Serial.println("Rodar para frente");
      if (stateTurn) {
        stateTurn = 0; // muda para sentido horário (false)
        motorBreak(); // para o motor 
      }
      motorRun(motorSpeed); // roda o motor (frente) com a última velocidade
      break;  
   case 7: //sentido horário (para frente)
      Serial.println("Rodar para trás");
      if (!stateTurn) {
        stateTurn = 1; // muda para sentido horário (true)
        motorBreak(); // para o motor
      }
      motorRun(motorSpeed); // roda o motor (frente) com a última velocidade
      break;     
    default:
      isValidOption = false; // caractere inválido   
      break;   
    }

  } while( isValidOption == true );
}

// função para rodar o motor na velocidade e sentido de rotação definidos
void motorRun(int velocidade) {
  if (!stateTurn) { // sentido horário (frente)
    digitalWrite(A_IB,LOW);
    digitalWrite(B_IB, LOW);
    analogWrite(A_IA, velocidade); // velocidade em função do sinal PWM
    analogWrite(B_IA, velocidade); // velocidade em função do sinal PWM
  } else {
    digitalWrite(A_IA,LOW);
    digitalWrite(B_IA, LOW);
    analogWrite(A_IB, velocidade); // velocidade em função do sinal PWM
    analogWrite(B_IB, velocidade); // velocidade em função do sinal PWM
  }
}

// freio do motor
void motorBreak() {
   digitalWrite(A_IA,LOW);
   digitalWrite(A_IB,LOW);
   digitalWrite(B_IA, LOW);
   digitalWrite(B_IB,LOW); 
}
