
void changeComCode() {//update the log site
  wc.SetComSite(Grapher());
}

bool TryGetData(String sv) {//try to ge return from server
  GPData.begin("http://" + sv + ":" + String(servport) + OpenTest);
  int ReqCode = GPData.GET();
  if(Debug){Serial.println("Try Get Data from: " + String(ReqCode) + " " + sv + ":" + String(servport) + OpenTest);}
  if (ReqCode > 0) {
    String c = GPData.getString();
    if(Debug){Serial.println(c);}
    if (c == "Success") {
      serv = sv;
      return true;
    }
  }
  GPData.end();
  return false;
}

void ScanNet() {//scan the entire network to find the server
  for (int i = 13; i < 256; i++) {
    String ip = GetMyIp(i);
    if (TryGetData(ip)) {
      break;
    }
    wc.Exec();
  }
}

String GetMyIp(int ipend) {//return the actual ip
  String ipget = WiFi.localIP().toString();
  int ip1 = ipget.substring(0, ipget.indexOf(".")).toInt();
  ipget = ipget.substring(ipget.indexOf(".") + 1);
  int ip2 = ipget.substring(0, ipget.indexOf(".")).toInt();
  ipget = ipget.substring(ipget.indexOf(".") + 1);
  int ip3 = ipget.substring(0, ipget.indexOf(".")).toInt();
  //Serial.println(String(ip1) + "." + String(ip2) + "." + String(ip3) + "." + String(ipend));
  return String(ip1) + "." + String(ip2) + "." + String(ip3) + "." + String(ipend);
}


