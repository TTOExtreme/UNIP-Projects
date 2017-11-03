/*/
     Created by TTOExtreme in 30/09/2017
  /*/

#include <WifiConfig.h>//Extrenal lib to create/connect wifi networks and communicate over it 
#include <ESP8266HTTPClient.h>//esp8266 lib to configure
WifiConfig wc;

bool Debug = false;//debug do not enable it

HTTPClient GPData;//get post client
String serv = "192.168.0.10";//default ip of server
int servport = 8080;//port to server

String OpenTest = "/esp/node/test?code=0"; //html host to get io from server
String SendJson = "/report/"; //html host to send json to sever
String ConfigJson = "/configuration/findall"; //html host to get config
int Delay = 1;//delay to report (DO NOT TOUCH)
double MinHum = 1.0;//min humity to turn on (DO NOT TOUCH)
double MaxHum = 2.5;//max humity to turn off (DO NOT TOUCH)

void setup() {
  wc.SetDebug(Debug);
  wc.UseStatic(false);
  wc.SetupWifi("Thom_D018906", "12457823");
  //wc.SetupWifi("RedeOculta", "12345678");
  //wc.SetupWifi("XperiaZ3", "12345678");
  //wc.SetupWifi("UNIP_CAMPINAS", "1011121314");

  wc.Init();//initiates the external lib
  initArrays();//initiates internal buffer of data

  if (!TryGetData(serv)) {
    ScanNet();//scans the entire network to find server
  }

}

unsigned long tim = millis();//WDT to create asinc task
unsigned long ltim = millis();//WDT
unsigned long ltimcfg = millis();//WDT

void loop() {
  tim = millis();
  wc.Exec();
  changeComCode();//sets the site to show
  if (tim >= ltim + (Delay * 1000)) {
    SendJsonUpdate();//sends info to server
    ltim += (Delay * 1000);
  }
  if(tim >= ltimcfg + (1000)){
    GetConfig();//get the config info from server
    ltimcfg+=1000;
  }
  delay(50);

}


