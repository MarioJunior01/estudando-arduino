#include <Servo.h>

Servo quadrilE;
Servo peE;
Servo quadrilD;
Servo peD;
#define TRIG 7
#define ECHO 8
#define BUZZER 6



void setup() {
  peD.attach(9);
  peE.attach(11);
  quadrilE.attach(10);
  quadrilD.attach(12);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {


  if (objetoFrente() < 10) {
    tone(BUZZER, 400);
    delay(3000);
  } else {
    andarFrente();
    noTone(BUZZER);
  }
}

void andarFrente() {

  // 1. joga o peso para direita
  peD.write(70);
  peE.write(110);
  delay(250);

  // 2. quadril esquerdo vira para frente → passo
  quadrilE.write(60);
  delay(350);

  // 3. volta pé ao normal
  peD.write(90);
  peE.write(90);
  delay(200);


  // ───────────────── PASSO DIREITO ─────────────────

  // 1. joga o peso para esquerda
  peD.write(110);
  peE.write(70);
  delay(250);

  // 2. quadril direito vira para frente → passo
  quadrilD.write(120);
  delay(350);

  // 3. volta pé ao normal
  peD.write(90);
  peE.write(90);
  delay(200);
}

void dancar() {
}

long objetoFrente() {
  long duracao, distancia;

  // Gera um pulso de 10us no TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Lê o tempo do pulso no ECHO
  duracao = pulseIn(ECHO, HIGH);

  // Converte o tempo em distância (cm)
  distancia = duracao * 0.0343 / 2;

  return distancia;
}
