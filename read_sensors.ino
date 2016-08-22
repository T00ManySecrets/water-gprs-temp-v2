// updates temp1, temp2, hum, batt1
void readSensors(){
  delay(2000);
  hum = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp1 = dht.readTemperature();

  if (isnan(hum) || isnan(temp1)) {
    Serial.println("Failed to read from DHT sensor!"); 
    //return;
  }


{
  String str = "";
  A6board.println("AT+CBC?");
  delay(100);
  while(A6board.available()){
    str += (char)A6board.read();
  }
  Serial.println(str);
  if(str.indexOf("+CBC") >= 0){
    batt1 = str.substring(str.indexOf("+CBC:")+6).toInt();
    batt2 = str.substring(str.indexOf("+CBC:")+8).toInt();
   
  }
}

  tempSensor.requestTemperatures();
  temp2 = tempSensor.getTempCByIndex(0);
  Serial.println("Water Temp:"); //debuging
  Serial.println(temp2); //debuging
  Serial.println("Air Temp:"); //debuging
  Serial.println(temp1); //debuging
  Serial.println("Humidity:"); //debuging
  Serial.println(hum); //debuging
  Serial.println("Battery:"); //debuging
  Serial.println(batt2); //debuging
  }
