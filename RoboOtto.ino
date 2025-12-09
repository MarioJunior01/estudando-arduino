

#include <Servo.h>

Servo pe1;
Servo pe2;
Servo perna1;
Servo perna2;

#define TRIG 8
#define ECHO 9
#define BUZZER 7

int pos = 0;    

void setup() {
 pe1.attach(2);
 pe2.attach(5);
 perna1.attach(3);
 perna2.attach(5);
 pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
 
}

void loop() {
  long duracao, distancia;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duracao = pulseIn(ECHO, HIGH, 25000UL);
  if (duracao == 0) {
    distancia = -1;
  } else {
    distancia = duracao * 0.0343 / 2;
  }

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
   if (distancia > 0 && distancia <= 5) {
    tone(BUZZER, 400);
    delay(3000);
    for (pos = 0; pos <= 90; pos += 1) { 
    pe1.write(pos);             
    delay(15); 
    
   for (pos = 0; pos <= 90; pos += 1) { 
    pe1.write(pos);             
    delay(15);                       
    }
   } 
  }
  else {
    noTone(BUZZER);
  for (pos = 0; pos <= 90; pos += 1) { 
    pe1.write(pos);             
    delay(15);                       
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    pe1.write(pos);              
    delay(15);                      
  }
 for (pos = 180; pos >= 0; pos -= 1) { 
    perna1.write(pos);              
    delay(15);                      
  }
   for (pos = 180; pos >= 0; pos -= 1) { 
    perna2.write(pos);              
    delay(15);                      
  }

  }
}
