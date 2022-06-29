#include <ESP8266WiFi.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int counter = 0;
int currentState = 0;
int previousState = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ssid     = "Wifi"; //Red local
const char* password = "Zanahoria1"; //Contraseña
const char* host = "192.168.1.69"; // Tu equipo
/*const char* ssid     = "TP-Link_80DD"; //Red local
const char* password = "88984643"; //Contraseña
const char* host = "192.168.1.101"; // Tu equipo*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int trigPin = D5;   
const int echoPin = D6;   
long duration;  
int distance; 
int distancec; 
///////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void setup(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////

 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output  
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
 Serial.begin(9600); // Starts the serial communication 

    Serial.begin(9600);
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
}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int value = 0;

void loop(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Clears the trigPin  
 digitalWrite(trigPin, LOW);  
 delayMicroseconds(2);  
 // Sets the trigPin on HIGH state for 10 micro seconds  
 digitalWrite(trigPin, HIGH);  
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds  
 duration = pulseIn(echoPin, HIGH);  
 // Calculating the distance  
 distance= duration*0.034/2; 
 Serial.print("La distancia normal es de 5, la actual a sido de:");  
Serial.println(distance);   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 distancec = (duration/2)/29.1;
 if (distancec <= 10){ 
 currentState = 0;
 Serial.print("La puerta esta cerrada");
 }
 else {
 currentState = 1;
 }
 delay(100);
 if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
Serial.print("Segundos que a estado separada de la puerta: ");
Serial.println(counter);
    }
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    String url = "/arduino";
   url += "?distance=";
   url += distance;
   url += "&counter=";
   url += counter;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    while(client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }

    Serial.println();
    Serial.println("closing connection");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////






 
