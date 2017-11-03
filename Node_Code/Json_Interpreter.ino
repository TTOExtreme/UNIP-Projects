void GetConfig() {//get the config json with data from server
  String url="http://" + serv + ":" + String(servport) + ConfigJson;
  GPData.begin(url);
  int ReqCode = GPData.GET();
  if(Debug){Serial.println("Try Get Data from: " + url);}
  if (ReqCode > 0) {
    String c = GPData.getString();
    if(Debug){Serial.println(c);}
    ConvertToInternData(c);//pass json to process for overide values
  }
  GPData.end();
}
void SendJsonUpdate() {
  Proc();//process data
  double temp=Temp();//get last temp
  double humi=Humi();//get last humity
  String url= "http://" + serv + ":" + String(servport) + SendJson + String(temp) + "/" + String(humi) + "/insert";
  GPData.begin(url);
  int ReqCode = GPData.GET();
  if(Debug){Serial.println(url);}
  if (ReqCode > 0) {
    String c = GPData.getString();
    if(Debug){Serial.println(c);}
  }
  GPData.end();
}

void ConvertToInternData(String input){//pass json to process for overide values
  String aux=input;
  int pos=input.indexOf("}");
  while(pos>0){
    pos=aux.indexOf("}");
    String aux2=aux.substring(0,pos);
    String value = aux2.substring(aux2.lastIndexOf("value\":")+7,aux2.lastIndexOf("}"));
    if(aux2.indexOf("TIME_TO_GENERATE_REPORT")>0){
      if(Debug){Serial.println("TIME_TO_GENERATE_REPORT " + value);}
      Delay = value.toInt();
    }
    if(aux2.indexOf("MIN_HUMIDITY")>0){
      if(Debug){Serial.println("MIN_HUMIDITY " + value);}
      MinHum = value.toInt();
    }
    if(aux2.indexOf("MAX_HUMIDITY")>0){
      if(Debug){Serial.println("MAX_HUMIDITY " + value);}
      MaxHum = value.toInt();
    }
    aux=aux.substring(pos+1);
  }
}

