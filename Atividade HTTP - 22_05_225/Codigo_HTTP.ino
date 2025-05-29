#include <ESP8266WiFi.h> // Conecta o ESP8266 na rede Wi-Fi
#include <ESP8266WebServer.h> //Gerencia o servidor HTTP

#define LED_PIN D6 //Define o pino da LED

const char *ssid = "Rede Wi-Fi"; //Colocar a rede wifi
const char *password = "123456"; //Colocar a senha do wifi

ESP8266WebServer server (80); //Cria o servidor que funcionará na porta 80, padrão HTTP

int LED_state = LOW; //Começa com o LED apagado

String getHTML() {
  String html = "<!DOCTYPE HTML>";
  html += "<html>";
  html += "<head>";
  html += "<link rel='icon' href='data:,'>";
  html += "</head>";
  html += "<p>LED state: <span style='color: red;'>";

  if (LED_state == LOW)
    html += "OFF";
  else
    html += "ON";

  html += "</span></p>";
  html += "<a href='/led1/on'>Turn ON</a>";
  html += "<br><br>";
  html += "<a href='/led1/off'>Turn OFF</a>";
  html += "</html>";

  return html;
}// Retorna toda a página HTML

void setup() {

  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LED_state);

  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print("Conectando ao Wi-Fi inserido");
  }
  Serial.print("Conectado")

  //Informa o IP da página para acessar no navegador
  Serial.print("Endereço de IP da página Web:");
  Serial.print(WiFi.localIP());

  //Quando acessa a página liga o LED
  server.on("/", HTTP_GET,[](){
    Serial.println("ESP8266 Web Server: Solicitação recebida");
    Serial.println("GET /led1/on");

    LED_state = HIGH;
    digitalWrite(LED_PIN,LED_state);
    server.send(200,"text/html",getHTML());
  });

  //Quando fecha a página desliga o LED
  server.on("/led1/off", HTTP_GET, [](){
    Serial.println("GET/led1/off");

    LED_state = LOW;
    digitalWrite(LED_PIN, LED_state);
    server.send(200,"text/html",getHTML());
  });

  //Inicia o servidor Web
  server.begin();
}


void loop() {

  //Verifica se há alguma requisição
  server.handleClient();                      
}
