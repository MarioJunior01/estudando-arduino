#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Define os pinos de controle e dados
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Cria uma variável do tipo display
int i=1;
int potPin = A0; //Cria uma variável potPin associada ao pino analógico A0;
int ledPin = 10; // Cria uma variável ledPin associada ao pino 10 (PWM)
float valorPot = 0; // Cria uma variável para guardar a leitura do potenciômetro 
float valorFinal = 0; // Cria uma variável para guardar o valor final convertido


void setup() {
  pinMode(potPin,INPUT); // define o potenciômetro como entrada
  pinMode(ledPin,OUTPUT); // define o led como saída
  lcd.begin(16, 2); // Inicializa o display LCD
  lcd.cursor(); // Liga o LCD
}

void loop() {

 
  lcd.print("  Ola Mundo ");
  

}