
#include <ESP8266WiFi.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//const char* ssid     = "Wifi"; //Red local
//const char* password = "Zanahoria1"; //Contraseña
//const char* host = "192.168.1.254"; // Tu equipo

const char* ssid     = "TP-Link_80DD"; //Red local
const char* password = "88984643"; //Contraseña
const char* host = "192.168.1.105"; // Tu equipo
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
    Serial.begin(115200);
    delay(10);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int value = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop(){
    delay(5000);
    ++value;

    Serial.print("connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
    }

    // Se utilizara la tabla de con tu nombre para realizar la pruebas
    String url = "/agregar";
    url += "?name=";
    url += "Prueba";

    Serial.print("Requesting URL: ");
    Serial.println(url);

    // This will send the request to the server
    client.print(String("POST ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 5000) {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server and print them to Serial
    while(client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }

    Serial.println();
    Serial.println("closing connection");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
