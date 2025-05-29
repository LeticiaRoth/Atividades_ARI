//Dupla: Letícia Roth e Layslla Oreti 
//LED_BUILDIN
//LD = 2

const byte LED = 2; //const afirma que a variável não mudará durante o código
//octeto de bit.


void setup(){ //serve para configurar os pinos
  pinMode(LED, OUTPUT); //serve para definir o tipo do pino  
}

void loop(){
  digitalWrite(LED, HIGH); //liga a led, o ESP comandará
  delay(1000);
  
  digitalWrite(LED, LOW); //desliga a led
  delay (1000);
}