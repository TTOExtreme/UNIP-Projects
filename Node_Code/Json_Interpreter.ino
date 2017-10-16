#include <ArduinoJson.h>

long id;
int timeToGenerateReport;


void GetJsonUpdate() {
  GPData.begin("http://" + serv + ":" + String(servport) + OpenJson);
  int ReqCode = GPData.GET();
  Serial.println("Try Get Data from: " + String(ReqCode) + " " + serv + ":" + String(servport) + OpenJson);
  if (ReqCode > 0) {
    String c = GPData.getString();
    Serial.println(c);
    ConvertToInternData(c);
  }
  GPData.end();
}

bool ConvertToInternData(String input){
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(input);
  
  id=input["id"];
  timeToGenerateReport=input["timeToGenerateReport"];
}

