#include "WiFi.h"
#define ledPin 2

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
 
}

void loop() {
 Serial.println("Scanning available networks....");
 digitalWrite(ledPin, HIGH);
 delay(100);
 digitalWrite(ledPin, LOW);
 delay(200);
 digitalWrite(ledPin, HIGH);
 delay(100);
 digitalWrite(ledPin, LOW);
 int n = WiFi.scanNetworks();
 if (n!=0){
   digitalWrite(ledPin, HIGH);
   Serial.print(n); Serial.println(" networks (s) found ! ");
   for(int i=0; i<n; i++){
     Serial.print("network "); Serial.print(i+1); Serial.print(": ");
     Serial.print(WiFi.SSID(i));
     Serial.print(" ("); Serial.print(WiFi.RSSI(i)); Serial.print(")");
     Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " open":"*****");
     delay(50);
   }
   }else{
     Serial.println("No available networks found !");
     digitalWrite(ledPin, HIGH);
     delay(200);
     digitalWrite(ledPin, LOW);
   }
   Serial.println("\n-------------------------------------------------------\n");
   delay(10000);
}
