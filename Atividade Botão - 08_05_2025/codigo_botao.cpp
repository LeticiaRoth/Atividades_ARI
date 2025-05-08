int buzzerPin = 10; //Variável para o buzzer (saída)
int buttonPin = 7; // Variável para o botão (entrada)
int estadochave = 0; //Variável para ler o estado das chaves

void setup() //Executada no início, quando liga o Arduino
{
  pinMode(buzzerPin, OUTPUT); // Define o pino como saída
  pinMode (buttonPin, INPUT); // Por ser um botão será entrada
}

void loop() //Lógica de programação que será repetida
{
 
  estadochave = digitalRead(buttonPin); // Lê valor da entrada

   if (estadochave == HIGH){ //Estado do botão HIGH = 1 e LOW = 0
  	tone(buzzerPin,5000);
    delay(100); // 3 segundos ligados
  }else{
    noTone(buzzerPin);
    delay(100);
    
  }
}