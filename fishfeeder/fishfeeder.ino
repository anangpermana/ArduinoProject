#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* wifiName = "Redmi144";
const char* wifiPass = "N@nau143";
const int Motor = 5;
const char *host = "http://echarging.duckdns.org/welcome?id_bat=1";
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;

void setup() {
  // Initialize Serial Monitor
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Motor, OUTPUT);
  Serial.begin(115200);
  delay(10);
  Serial.println();
  
  Serial.print("Connecting to ");
  Serial.println(wifiName);

  WiFi.begin(wifiName, wifiPass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 

// Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT +7 = 25200
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(25200);
}
void loop() {
  
//  while(!timeClient.update()) {
//    timeClient.forceUpdate();
//  }
//  // The formattedDate comes with the following format:
//  // 2018-05-28T16:00:13Z
//  // We need to extract date and time
//  formattedDate = timeClient.getFormattedTime();
//  Serial.println(formattedDate);
//  // Extract date
//  int splitT = formattedDate.indexOf("T");
//  dayStamp = formattedDate.substring(0, splitT);
//  Serial.print("DATE: ");
//  Serial.println(dayStamp);
//  if(dayStamp == "17:22:30" ||dayStamp == "17:22:32" ||dayStamp == "17:22:34" ||dayStamp == "17:22:36" ||dayStamp == "17:22:38" || dayStamp == "07:00:32" ||dayStamp == "07:00:34" ||dayStamp == "07:00:36" ||dayStamp == "07:00:38" ||dayStamp == "07:00:38"){
//    Serial.print("Motor on");
//    digitalWrite(Motor, LOW);
//   }else{
//    digitalWrite(Motor, HIGH);
//   }
//  
//  delay(1000);
// get status from server
//  HTTPClient http;
//  Serial.print("Request Link:");
//  Serial.println(host);
//  
//  http.begin(host);     //Specify request destination
//  
//  int httpCode = http.GET();            //Send the request
//  String payload = http.getString();    //Get the response payload from server
//
//  Serial.print("Response Code:"); //200 is OK
//  Serial.println(httpCode);   //Print HTTP return code
//
//  Serial.print("Returned data from Server:");
//  Serial.println(payload);    //Print request response payload
//
//  if(httpCode == 200){
//        // Allocate JsonBuffer
//    // Use arduinojson.org/assistant to compute the capacity.
//    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//    DynamicJsonBuffer jsonBuffer(capacity);
//  
//   // Parse JSON object
//    JsonObject& root = jsonBuffer.parseObject(payload);
//    if (!root.success()) {
//      Serial.println(F("Parsing failed!"));
//      return;
//    }
//  
//    // Decode JSON/Extract values
//    Serial.println(F("Response:"));
////    Serial.println(root["capacity"].as<char*>());
////    Serial.println(root["time"].as<char*>());
////    Serial.println(root["data"][0].as<char*>());
////    Serial.println(root["data"][1].as<char*>());
//
//    float capacity_status = root["capacity"].as<float>();
//    Serial.println(capacity_status);
//  }
  
digitalWrite(Motor, HIGH);
delay(1000);
digitalWrite(Motor, LOW);
delay(2000);
}
