// Definición de pines de los botones
const int boton1 = 9;
const int boton2 = 10;
const int boton3 = 11;
const int boton4 = 12;
const int boton5 = 13;

// Definición de pines del display de 7 segmentos
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;

// Tabla de patrones para los números del 0 al 9 en display de 7 segmentos
byte numeros[10] = {
  0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00000111,  // 7
  0b01111111,  // 8
  0b01101111   // 9
};

void setup() {
  // Configuración de los pines de los botones
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  pinMode(boton5, INPUT);
  
  // Configuración de los pines de los segmentos del display
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  
  // Inicializa el anodo común a 5V
  digitalWrite(5, HIGH); 
}

void loop() {
  // Comprobamos el estado de los botones 
  
  if (digitalRead(boton1)) {
    mostrarNumero(0);  // Muestra el número 0 cuando se presiona el botón1
  } 
  else if (digitalRead(boton2)) {
    mostrarNumero(1);  // Muestra el número 1 cuando se presiona el botón2
  }
  else if (digitalRead(boton3)) {
    mostrarNumero(2);  // Muestra el número 2 cuando se presiona el botón3
  }
  else if (digitalRead(boton4)) {
    mostrarNumero(3);  // Muestra el número 3 cuando se presiona el botón4
  }
  else if (digitalRead(boton5)) {
    mostrarNumero(4);  // Muestra el número 4 cuando se presiona el botón5
  }

  delay(200);  // Retraso para evitar lecturas erróneas
}

// Función para mostrar un número en el display de 7 segmentos
void mostrarNumero(int num) {
  byte patron = numeros[num];  // Obtenemos el patrón binario para el número

  // Controlar los segmentos de acuerdo al patrón binario
  digitalWrite(segA, bitRead(patron, 0));
  digitalWrite(segB, bitRead(patron, 1));
  digitalWrite(segC, bitRead(patron, 2));
  digitalWrite(segD, bitRead(patron, 3));
  digitalWrite(segE, bitRead(patron, 4));
  digitalWrite(segF, bitRead(patron, 5));
  digitalWrite(segG, bitRead(patron, 6));
}

