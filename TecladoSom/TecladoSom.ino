#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço I2C identificado: 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);  // (endereço, colunas, linhas)
int linha = 0;
int buzzer = 2;
void setup() {
  lcd.init();  // Inicializa o LCD
  lcd.backlight();
  pinMode(buzzer, OUTPUT);



  lcd.setCursor(0, 0);  // Coluna 0, Linha 0
  lcd.print("Esperando");
  lcd.setCursor(0, 1);
  lcd.print("Digitacao");
  pinMode(3, OUTPUT);  //linha 1
  pinMode(4, OUTPUT);  //linha 2
  pinMode(5, OUTPUT);  //linha 3
  pinMode(6, OUTPUT);
  //linha 4

  pinMode(8, INPUT);   //coluna  1
  pinMode(9, INPUT);   //coluna  2
  pinMode(10, INPUT);  //coluna 3
  pinMode(11, INPUT);  //coluna 4

  Serial.begin(9600);

  Serial.println("Esperando D");
}


void loop() {
  for (linha = 3; linha <= 6; linha++) {
    //verifica a coluna 1
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(linha, HIGH);
    if (digitalRead(8) == HIGH) {
      if (linha == 3) {
        lcd.clear();
        lcd.print("Tecla 1 ");
        tone(buzzer, 400);
        ;  // Liga o buzzer
        delay(200);
        noTone(buzzer);
      }
      delay(200);
    }

    if (digitalRead(8) == HIGH) {
      if (linha == 6) {
        lcd.clear();
        lcd.print("Tecla *");
        tone(buzzer, 400);
        ;
        // Liga o buzzer
        delay(200);
        noTone(buzzer);
      }
      delay(200);
    }


    if (digitalRead(8) == HIGH) {
      if (linha == 5) {
        lcd.clear();
        lcd.print("Tecla 7");
        tone(buzzer, 400);
        ;  // Liga o buzzer
        delay(200);
        noTone(buzzer);
      }
      delay(200);
    }


    if (digitalRead(8) == HIGH) {
      if (linha == 4) {
        lcd.clear();
        lcd.print("Tecla 4 ");
        tone(buzzer, 400);
        delay(200);
        noTone(buzzer);
      }


      delay(200);
    }

    if (digitalRead(9) == HIGH) {
      if (linha == 3) {
        lcd.clear();
        lcd.print("Tecla 2 ");
        tone(buzzer, 400);
        delay(200);
        noTone(buzzer);
      }
      delay(200);
    }
    if (digitalRead(9) == HIGH) {
      if (linha == 6) {
        lcd.clear();
        lcd.print("Tecla 0");
        tone(buzzer, 400);
        delay(200);
        noTone(buzzer);
      }
      delay(200);
    }

    if (digitalRead(9) == HIGH) {
      if (linha == 5) {
        lcd.clear();
        lcd.print("Tecla 8");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
      delay(200);
    }

    if (digitalRead(9) == HIGH) {
      if (linha == 4) {
        lcd.clear();
        lcd.print("Tecla 5 ");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }

      delay(200);
    }




    if (digitalRead(10) == HIGH) {
      if (linha == 3) {
        lcd.clear();
        lcd.print("Tecla 3");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
    }
    if (digitalRead(9) == HIGH) {
      if (linha == 6) {
        lcd.clear();
        lcd.print("Tecla #");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
    }
    if (digitalRead(10) == HIGH) {
      if (linha == 5) {
        lcd.clear();
        lcd.print("Tecla 9");
        tone(buzzer, 400);
        delay(200);
        noTone(buzzer);
      }
    }

    if (digitalRead(10) == HIGH) {
      if (linha == 4) {
        lcd.clear();
        lcd.print("Tecla 6 ");
        tone(buzzer, 400);
        delay(200);
        noTone(buzzer);
      }
    }

    if (digitalRead(11) == HIGH) {
      if (linha == 3) {
        lcd.clear();
        lcd.print("Tecla A ");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
    }
    if (digitalRead(11) == HIGH) {
      if (linha == 4) {
        lcd.clear();
        lcd.print("Tecla B");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
    }

    if (digitalRead(11) == HIGH) {
      if (linha == 5) {
        lcd.clear();
        lcd.print("Tecla C");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
    }
    if (digitalRead(11) == HIGH) {
      if (linha == 6) {
        lcd.clear();
        lcd.print("Tecla D");
        tone(buzzer, 400);

        delay(200);
        noTone(buzzer);
      }
    }
    Serial.println(digitalRead(9));
  }
}
