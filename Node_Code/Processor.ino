//ports from sensors
const byte HumPort = D0;
const byte TempPort = D1;
const byte DataPort = A0;

const byte BombPort = D2;

//buffer arrays 
double TempArray[50];
double HumArray[50];

double SensorHum(){//get stable Humity value from sensor
  digitalWrite(HumPort,HIGH);
  delay(100);
  double ret = analogRead(DataPort);
  for(int i=0;i<30;i++){ret = (ret+analogRead(DataPort))/2;}
  digitalWrite(HumPort,LOW);
  return ret/10;
}

double SensorTemp(){//get stable temp value from sensor
  double v=3.3/1023;
  digitalWrite(TempPort,HIGH);
  delay(100);
  double ret = analogRead(DataPort);
  for(int i=0;i<30;i++){ret = (ret+analogRead(DataPort))/2;}
  ret=(ret*v)/0.01;
  digitalWrite(TempPort,LOW);
  return ret;
}

void Proc(){//process the data puting into buffer and turn on or off the bomb 
  arrAdd(SensorTemp(),TempArray);
  arrAdd(SensorHum(),HumArray);
  if(Humi()<MinHum){
    digitalWrite(BombPort,HIGH);
  }
  if(Humi()<MaxHum){
    digitalWrite(BombPort,LOW);
  }
}

void initArrays(){//initiates the buffer
  for(int i=0;i<50;i++){TempArray[i]=0; HumArray[i]=0;}
  pinMode(TempPort,OUTPUT);
  pinMode(HumPort,OUTPUT);
  pinMode(BombPort,OUTPUT);
}

String GetTempArr(){//ger the temp buffer
  String ret="[";
  for(int i=0;i<50;i++){ret+=String(TempArray[i]) + ",";}
  ret+=String(TempArray[49])+"]";
  return ret;
}

String GetHumArr(){//get the humity buffer
  String ret="[";
  for(int i=0;i<50;i++){ret+=String(HumArray[i]) + ",";}
  ret+=String(HumArray[49])+"]";
  return ret;
}

double Temp(){//get the last temp readed
  return TempArray[49]; 
}

double Humi(){//get the last humity readed
  return HumArray[49]; 
}

