 #include <ESP8266WiFi.h>
char ssid[] = "iPhone";
char senha[] = "123456789";
 
void conectarWiFi(char SSID[], char SENHA[]){
  Serial.print("Conectando a Rede");
  Serial.println(SSID);
 
  WiFi.begin(SSID, SENHA); // Inicializa o modulo wifi
 
  while(WiFi.status () != WL_CONNECTED){
    delay(500); // Espera 0.5 segundos
    Serial.print("."); //  Imprime . no terminal
  }
 
  Serial.print("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço d IP:");
  Serial.println(WiFi.localIP()); // Função do Wifi que imprime o falor de IP do esp
}
 
void setup(){
  Serial.begin(115200);
  conectarWiFi(ssid, senha);
}
 
void loop(){ 
}
 
