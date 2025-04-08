#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "SUA_REDE_WIFI"
#define WIFI_PASSWORD "SENHA_WIFI"
#define FIREBASE_HOST "SEU_PROJETO.firebaseio.com"
#define FIREBASE_AUTH "CHAVE_SECRETA_FIREBASE"

// Pinos dos sensores PIR
#define PIR1 13
#define PIR2 12
#define PIR3 14
#define PIR4 27

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  
  // Configuração dos sensores
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  pinMode(PIR3, INPUT);
  pinMode(PIR4, INPUT);

  // Conectar ao Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado!");

  // Inicializar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  int pir1 = digitalRead(PIR1);
  int pir2 = digitalRead(PIR2);
  int pir3 = digitalRead(PIR3);
  int pir4 = digitalRead(PIR4);

  if (pir1 || pir2 || pir3 || pir4) {
    Serial.println("Movimento detectado!");

    String caminho = "/alertas/movimento";
    String mensagem = "Presença detectada!";
    
    Firebase.setString(firebaseData, caminho, mensagem);

    // Aguardar um tempo para evitar repetições
    delay(5000);
  }

  delay(200);
}
