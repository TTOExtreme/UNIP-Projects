/*/
     Created by TTOExtreme in 08-09-2016
  /*/

#include <WifiConfig.h>
#include <ESP8266HTTPClient.h>
WifiConfig wc;

HTTPClient GPData;//get post client
String serv = "192.168.0.10";//14
int servport = 8080;

String OpenTest = "/esp/node/test?code=0";
String OpenJson = "/config/findall";

void setup() {
  wc.UseStatic(false);
  //wc.SetupWifi("Thom_D018906", "12457823");
  //wc.SetupWifi("RedeOculta", "12345678");
  wc.SetupWifi("XperiaZ3", "12345678");
  //wc.SetupWifi("UNIP_CAMPINAS", "1011121314");

  wc.Init();
  changeComCode();//sets the site to show

  if (!TryGetData(serv)) {
    ScanNet();
  }

}

void loop() {
  wc.Exec();
  delay(300);
  GetJsonUpdate();

}


