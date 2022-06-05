#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include  <ESP8266WiFi.h>




//D6 = Rx & D5 = Tx

SoftwareSerial nodemcu(D5, D6);


void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  nodemcu.begin(9600);

}
void loop() {
  

 StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();
   //Assign collected data to JSON Object
  data["distance"] = 100;
  data["statusSensor"] = 300; 
  data["statusSensor2"] = 200; 
  data["statusSensor3"] = 400; 

  //Send data to NodeMCU
  data.printTo(nodemcu);
  jsonBuffer.clear();


  delay(2000);
 
}
