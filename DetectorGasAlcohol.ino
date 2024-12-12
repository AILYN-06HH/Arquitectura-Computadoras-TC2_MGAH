int alcohol;

void setup() {

  Serial.begin (9600);
  pinMode (A0,INPUT);
  pinMode (2,OUTPUT);
  pinMode (3,OUTPUT);
  pinMode (7,OUTPUT);

}

void loop() {
  alcohol =analogRead (A0);

  if(alcohol>285){
    digitalWrite (2,LOW); //Apaga el led verde
    digitalWrite (3,HIGH); //Enciende el led rojo "Hay Alcohol"
    digitalWrite (7,HIGH); //Enciende buzzer
    delay (1000);
    digitalWrite (7, LOW); //Apaga buzzer
    delay (1000);
  }
  else {
    digitalWrite (2,HIGH); //Enciende led verde
    digitalWrite (3, LOW); //Apaga led rojo "Hay alcohol"
  }
  Serial.println (alcohol);

}