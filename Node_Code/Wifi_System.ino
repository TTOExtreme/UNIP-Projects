
void changeComCode() {
  String str = "Starting";

  wc.SetComSite(str);
}

bool TryGetData(String sv) {
  GPData.begin("http://" + sv + ":" + String(servport) + OpenTest);
  int ReqCode = GPData.GET();
  Serial.println("Try Get Data from: " + String(ReqCode) + " " + sv + ":" + String(servport) + OpenTest);
  if (ReqCode > 0) {
    String c = GPData.getString();
    Serial.println(c);
    if (c == "Success") {
      serv = sv;
      return true;
    }
  }
  GPData.end();
  return false;
}

void ScanNet() {
  for (int i = 243; i < 256; i++) {
    String ip = GetMyIp(i);
    if (TryGetData(ip)) {
      break;
    }
    wc.Exec();
  }
}

String GetMyIp(int ipend) {
  String ipget = WiFi.localIP().toString();
  int ip1 = ipget.substring(0, ipget.indexOf(".")).toInt();
  ipget = ipget.substring(ipget.indexOf(".") + 1);
  int ip2 = ipget.substring(0, ipget.indexOf(".")).toInt();
  ipget = ipget.substring(ipget.indexOf(".") + 1);
  int ip3 = ipget.substring(0, ipget.indexOf(".")).toInt();
  //Serial.println(String(ip1) + "." + String(ip2) + "." + String(ip3) + "." + String(ipend));
  return String(ip1) + "." + String(ip2) + "." + String(ip3) + "." + String(ipend);
}


