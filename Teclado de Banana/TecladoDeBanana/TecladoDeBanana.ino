
const int pinosBananas[6] = {A0, A1, A2, A3, A4, A5};
const int notas[6] = {262, 294, 330, 349, 392, 440}; 
const int buzzer = 10;
const int botao = 2; 

const int limiar = 400;

bool modoMenu = false;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT_PULLUP); 
}

void loop() {
  
  if (digitalRead(botao) == LOW) {
    delay(200); 
    if (digitalRead(botao) == LOW) {
      modoMenu = true;
      Serial.println("Modo MENU ativado. Toque uma banana para escolher uma música.");
      esperarSelecaoDeMusica();
      modoMenu = false;
    }
  }

 
  if (!modoMenu) {
    bool algumaTocada = false;

    for (int i = 0; i < 6; i++) {
      int leitura = analogRead(pinosBananas[i]);
      Serial.print(leitura);
      Serial.print("\t");

      if (leitura < limiar) {
        tocarNota(notas[i], 300);
        algumaTocada = true;
        break;
      }
    }

    if (!algumaTocada) {
      noTone(buzzer);
    }
    
    Serial.println();
    delay(100);
  }
}


void esperarSelecaoDeMusica() {
  bool selecionado = false;

  while (!selecionado) {
    for (int i = 0; i < 6; i++) {
      int leitura = analogRead(pinosBananas[i]);

      if (leitura < limiar) {
        tocarMusica(i); 
        selecionado = true;
        break;
      }
    }
    delay(100);
  }
}


void tocarNota(int frequencia, int duracao) {
  tone(buzzer, frequencia);
  delay(duracao);
  noTone(buzzer);
}

void tocarMusica(int indice) {
  Serial.print("Tocando música da banana ");
  Serial.println(indice + 1);

  switch (indice) {
    case 0: 
      tocarSequencia(new int[4]{262, 294, 330, 349}, 4);
      break;
    case 1: 
      tocarSequencia(new int[4]{330, 349, 392, 440}, 4);
      break;
    case 2: 
      tocarSequencia(new int[6]{262, 262, 392, 392, 440, 440}, 6); // Twinkle Twinkle trecho
      break;
    case 3: 
      tocarSequencia(new int[6]{392, 349, 330, 294, 262, 262}, 6); // Ode à Alegria final
      break;
    case 4: 
      tocarSequencia(new int[8]{330, 330, 349, 392, 392, 349, 330, 294}, 8); // Ode à Alegria início
      break;
    case 5: 
      tocarSequencia(new int[5]{262, 330, 262, 330, 440}, 5); // Batida divertida
      break;
    default:
      Serial.println("Música inválida.");
      break;
  }
}


void tocarSequencia(int* sequencia, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    tocarNota(sequencia[i], 300);
    delay(100);
  }
  delete[] sequencia; 
