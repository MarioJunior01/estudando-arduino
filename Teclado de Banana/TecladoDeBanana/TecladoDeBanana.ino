// Piano de bananas com buzzer
const int pinosBananas[6] = {A0, A1, A2, A3, A4, A5};
const int notas[6] = {262, 294, 330, 349, 392, 440}; // Dó, Ré, Mi, Fá, Sol, Lá
const int buzzer = 10;

const int limiar = 400; // Se o valor for menor que isso, considera que foi tocado

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  bool algumaTocada = false;

  for (int i = 0; i < 6; i++) {
    int leitura = analogRead(pinosBananas[i]);
    Serial.print(leitura);
    Serial.print("\t");

    if (leitura < limiar) {
      tocarNota(notas[i], 300); // Toca a nota por 300 ms
      algumaTocada = true;
      break; // Só toca uma nota por vez
    }
  }

  if (!algumaTocada) {
    noTone(buzzer); // Para de tocar se nenhuma banana foi pressionada
  }

  Serial.println();
  delay(100); // Reduz sensibilidade
}

// Função para tocar som (para buzzers passivos)
void tocarNota(int frequencia, int duracao) {
  tone(buzzer, frequencia, duracao); // Função nativa do Arduino
}



// CODIGO COM MENU DE MUSICA

/*const int pinosBananas[6] = {A0, A1, A2, A3, A4, A5};
const int notas[6] = {262, 294, 330, 349, 392, 440}; // Dó, Ré, Mi, Fá, Sol, Lá
const int buzzer = 10;
const int botao = 2; // Botão para entrar no menu

const int limiar = 400;

bool modoMenu = false;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT_PULLUP); // Usa resistor interno
}

void loop() {
  // Verifica se botão foi pressionado
  if (digitalRead(botao) == LOW) {
    delay(200); // debounce
    if (digitalRead(botao) == LOW) {
      modoMenu = true;
      Serial.println("Modo MENU ativado. Toque uma banana para escolher uma música.");
      esperarSelecaoDeMusica();
      modoMenu = false;
    }
  }

  // Modo normal: tocar notas
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

// Função chamada no modo menu
void esperarSelecaoDeMusica() {
  bool selecionado = false;

  while (!selecionado) {
    for (int i = 0; i < 6; i++) {
      int leitura = analogRead(pinosBananas[i]);

      if (leitura < limiar) {
        tocarMusica(i); // i = índice da banana (0 a 5)
        selecionado = true;
        break;
      }
    }
    delay(100);
  }
}

// Toca uma nota simples
void tocarNota(int frequencia, int duracao) {
  tone(buzzer, frequencia);
  delay(duracao);
  noTone(buzzer);
}

// --- Músicas definidas para cada banana ---
void tocarMusica(int indice) {
  Serial.print("Tocando música da banana ");
  Serial.println(indice + 1);

  switch (indice) {
    case 0: // A0 → Música 1
      tocarSequencia(new int[4]{262, 294, 330, 349}, 4);
      break;
    case 1: // A1 → Música 2
      tocarSequencia(new int[4]{330, 349, 392, 440}, 4);
      break;
    case 2: // A2 → Música 3
      tocarSequencia(new int[6]{262, 262, 392, 392, 440, 440}, 6); // Twinkle Twinkle trecho
      break;
    case 3: // A3 → Música 4
      tocarSequencia(new int[6]{392, 349, 330, 294, 262, 262}, 6); // Ode à Alegria final
      break;
    case 4: // A4 → Música 5
      tocarSequencia(new int[8]{330, 330, 349, 392, 392, 349, 330, 294}, 8); // Ode à Alegria início
      break;
    case 5: // A5 → Música especial
      tocarSequencia(new int[5]{262, 330, 262, 330, 440}, 5); // Batida divertida
      break;
    default:
      Serial.println("Música inválida.");
      break;
  }
}

// Toca uma sequência de notas
void tocarSequencia(int* sequencia, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    tocarNota(sequencia[i], 300);
    delay(100);
  }
  delete[] sequencia; // Libera memória
}
*\