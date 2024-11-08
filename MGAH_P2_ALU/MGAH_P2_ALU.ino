// Configuración de pines del display de 7 segmentos
const int segmentA = 10;
const int segmentB = 11;
const int segmentC = 12;
const int segmentD = 13;
const int segmentE = A0; // Pines analógicos para segmentos adicionales
const int segmentF = A1;
const int segmentG = A2;
const int segmentDP = A3;

void setup() {
  // Configuración de entradas para los botones
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
  // Entradas de bus de control
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  
  // Configuración de salidas para el display y LEDs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  
  pinMode(7, OUTPUT);  // Salida para acarreo en suma
  pinMode(8, OUTPUT);  // Error en división
  pinMode(9, OUTPUT);  // Error en resta negativa
  pinMode(13, OUTPUT); // Resultado de operaciones
}

// Función para controlar los segmentos del display
void mostrarNumero(int numero) {
  // Apaga todos los segmentos
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDP, LOW);
  
  // Control de segmentos para mostrar el número deseado
  switch (numero) {
    case 0:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      break;
    case 1:
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 4:
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 5:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 6:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 7:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      break;
    case 8:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 9:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
  }
}

void loop() {
  // Operación de suma (muestra 0)
  if ((!digitalRead(2) && !digitalRead(3) && digitalRead(4)) && (digitalRead(5) ^ digitalRead(6))) {
    mostrarNumero(0); // Muestra el número 0 para suma en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Operación de resta (muestra 1)
  if ((!digitalRead(2) && digitalRead(3) && !digitalRead(4)) && (digitalRead(5) ^ digitalRead(6))) {
    mostrarNumero(1); // Muestra el número 1 para resta en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Operación de multiplicación (muestra 2)
  if ((!digitalRead(2) && digitalRead(3) && digitalRead(4)) && (digitalRead(5) && digitalRead(6))) {
    mostrarNumero(2); // Muestra el número 2 para multiplicación en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Operación de división (muestra 3)
  if ((digitalRead(2) && !digitalRead(3) && !digitalRead(4)) && (!digitalRead(5) ^ digitalRead(6))) {
    mostrarNumero(3); // Muestra el número 3 para división en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Operación AND (muestra 4)
  if ((digitalRead(2) && !digitalRead(3) && digitalRead(4)) && (digitalRead(5) && digitalRead(6))) {
    mostrarNumero(4); // Muestra el número 4 para AND en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Operación OR (muestra 5)
  if ((digitalRead(2) && digitalRead(3) && !digitalRead(4)) && (digitalRead(5) || digitalRead(6))) {
    mostrarNumero(5); // Muestra el número 5 para OR en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Operación XOR (muestra 6)
  if ((digitalRead(2) && digitalRead(3) && digitalRead(4)) && (digitalRead(5) ^ digitalRead(6))) {
    mostrarNumero(6); // Muestra el número 6 para XOR en display
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  // Error en división (muestra 8 en el display y enciende LED en pin 8)
  if ((digitalRead(2) && !digitalRead(3) && !digitalRead(4)) && (!digitalRead(5) && digitalRead(6))) {
    mostrarNumero(8); // Muestra el número 8 para error en display
    digitalWrite(8, HIGH); // Error de división
  } else {
    digitalWrite(8, LOW);
  }

  // Error en resta negativa (muestra 9 en el display y enciende LED en pin 9)
  if ((!digitalRead(2) && digitalRead(3) && !digitalRead(4)) && (digitalRead(5) && !digitalRead(6))) {
    mostrarNumero(9); // Muestra el número 9 para error en display
    digitalWrite(9, HIGH); // Error en resta negativa
  } else {
    digitalWrite(9, LOW);
  }
}
