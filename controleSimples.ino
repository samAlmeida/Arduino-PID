#include <Ultrasonic.h>
#define TRIGGER_PIN  12
#define ECHO_PIN     13
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
double erro, nivelAnterior, kP, kI, kD, P, I, D, pid, setPoint;
long processoAnterior;
bool manual;
void setup() {
  Serial.begin(9600);
  setPoint = 10;
  kP = 1.0;
  kI = 1.0;
  kD = 1.0;
}


void loop() {
  if (Serial.available() > 0) {
    char constante = Serial.read();
    double valor = Serial.parseFloat();
    if (constante == 'p') {
      kP = valor;
    }
    if (constante == 'i') {
      kI = valor;
    }
    if (constante == 'd') {
      kD = valor;
    }
    if (constante == 's') {
      setPoint = valor;
    }
    if (constante == 'a') {
      manual = true;
    }
    if (constante == 'e') {
      manual = false;
    }
    if (constante == 'm') {
      pid = valor;
    }
  }
  if (manual == false){
     long microsec = ultrasonic.timing();
  double rawnivel = ultrasonic.convert(microsec, Ultrasonic::CM);
  //double nivel = map(rawnivel, 0.0, 25.0, 25.0, 0.0);
  double nivel =  (rawnivel - 0.0) * (0.0 - 25.0) / (25.0 - 0.0) + 25.0;

  erro = setPoint - nivel;
  if ( nivel > 25)
  {
    nivel = 25;
  }
  if (nivel < 0) {
    nivel = 0;
  }
  float tempoDeProcesso = (millis() - processoAnterior) / 1000.0;
  processoAnterior = millis();
  //P
  P = erro * kP;
  //I
  I = I + (erro * kI) * tempoDeProcesso;

  if (I > 255)
  {
    I = 255;
  }
  if ( I < 0)
  {
    I = 0;
  }
  //D
  D = (nivelAnterior - nivel) * kD / tempoDeProcesso;
  nivelAnterior = nivel;
  // Soma tudo
  pid = P + I + D;

  if ( pid > 255)
  {
    pid = 255;
  }
  if (pid < 0) {
    pid = 0;
  }
  analogWrite(3, pid);
  }
  long microsec = ultrasonic.timing();
  double rawnivel = ultrasonic.convert(microsec, Ultrasonic::CM);
  //double nivel = map(rawnivel, 0.0, 25.0, 25.0, 0.0);
  double nivel =  (rawnivel - 0.0) * (0.0 - 25.0) / (25.0 - 0.0) + 25.0;
  
  for (int i = 0; i <= 5; i++) {
    String str;
    str += String(nivel);
    str += "n";
    Serial.print(str);
    Serial.flush();
  }
  for (int j = 0; j <= 5; j++) {
    String str;
    str += String(pid);
    str += "p";
    Serial.print(str);
    Serial.flush();
  }
  delay(50);
}

