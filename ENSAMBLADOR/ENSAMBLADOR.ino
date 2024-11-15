// Configuración de pines del display de 7 segmentos
const int segmentA = 10;
const int segmentB = 11;
const int segmentC = 12;
const int segmentD = 13;
const int segmentE = A0;
const int segmentF = A1;
const int segmentG = A2;
const int segmentDP = A3;

void setup() {
  // Configuración de salidas para el display
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  
  // Inicio de la comunicación serial
  Serial.begin(9600);  
  Serial.println("En línea, esperando instrucciones...");
}

void loop() {
  // Leer la entrada serial
  if (Serial.available()) {
    char data[20];
    int number_of_bytes_received = Serial.readBytesUntil(13, data, 20);  // Lee hasta retorno de carro (13)
    data[number_of_bytes_received] = 0;  // Asegura que la cadena termine en 0

    // Imprime el comando recibido
    Serial.print("Comando recibido: ");
    Serial.println(data);

    // Llama a la función adecuada dependiendo del comando
    if (strcmp(data, "sum") == 0) {
      Serial.println("Suma realizada");
      mostrarNumero(9);  // Muestra 9
    }
    else if (strcmp(data, "di") == 0) {
      Serial.println("Resta realizada");
      mostrarNumero(1);  
    }
    else if (strcmp(data, "mul") == 0) {
      Serial.println("Multiplicación realizada");
      mostrarNumero(2); 
    }
    else if (strcmp(data, "div") == 0) {
      Serial.println("División realizada");
      mostrarNumero(3); 
    }
    else if (strcmp(data, "and") == 0) {
      Serial.println("Operación AND realizada");
      mostrarNumero(4); 
    }
    else if (strcmp(data, "or") == 0) {
      Serial.println("Operación OR realizada");
      mostrarNumero(5);  
    }
    else if (strcmp(data, "xor") == 0) {
      Serial.println("Operación XOR realizada");
      mostrarNumero(6);  
    }
    else if (strcmp(data, "error_div") == 0) {
      Serial.println("Error en división");
      mostrarNumero(8); 
    }
    else if (strcmp(data, "error_sub") == 0) {
      Serial.println("Error en resta negativa");
      mostrarNumero(9);  
    }
  }
}

// Función para mostrar el número en el display de 7 segmentos
void mostrarNumero(int numero) {
  // Apagar todos los segmentos
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDP, LOW);
  
  // Mostrar el número correspondiente en el display
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
