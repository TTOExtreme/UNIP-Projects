String Grapher(){//creates an website to show the graph of temp and hum
  String ret="<html><body><p>Temperature</p><canvas id='TempC' width='1500' height='200'style='border:1px solid #d3d3d3;'></canvas><p>Humity</p><canvas id='HumC' width='1500' height='200'style='border:1px solid #d3d3d3;'></canvas><meta http-equiv='refresh' content='" + String(3) + ";'><script>";
  
  ret += "var vectTemp = " + GetTempArr() + ";";
  ret += "var vectHum = " + GetHumArr() + ";";
  
  ret += "var litem = 0;var w=1500;var h=200;var TempS = w/(vectTemp.length-1);var HumS = w/(vectHum.length-1);";
  ret += "var hmin = 15;var tm = Math.max.apply(null, vectTemp);var hm = Math.max.apply(null, vectHum);tm=(h-hmin)/(tm*1.1);hm=(h-hmin)/(hm*1.1);";

  ret += "function drawTemp(item, index){  if(index>0){var canvas = document.getElementById('TempC');var ctx = canvas.getContext('2d');ctx.font = '12px Arial';if(isOdd(index)){ctx.fillText(item,TempS*(index),h-(vectTemp[index]*tm+hmin)-5);}else{ctx.fillText(item,TempS*(index),h-(vectTemp[index]*tm-hmin)+15);}ctx.moveTo(TempS*(index-1),h-(vectTemp[index-1]*tm));ctx.lineTo(TempS*(index),h-(vectTemp[index]*tm));ctx.strokeStyle = '#ff0000';ctx.stroke();}}";

  ret += "function drawHum(item, index){if(index>0){var canvas = document.getElementById('HumC');var ctx = canvas.getContext('2d');ctx.font = '12px Arial';if(isOdd(index)==0){ctx.fillText(item,HumS*(index),h-(vectHum[index]*hm+hmin)-5);}else{ctx.fillText(item,HumS*(index),h-(vectHum[index]*hm-hmin)+15);}ctx.moveTo(HumS*(index-1),h-(vectHum[index-1]*hm));ctx.lineTo(HumS*(index),h-(vectHum[index]*hm));ctx.strokeStyle = '#00ff00';ctx.stroke();}}";
  ret += "function isOdd(num) { return num % 2;}";
  ret += "vectTemp.forEach(drawTemp);vectHum.forEach(drawHum);</script></body></html>";

  return ret;
}

