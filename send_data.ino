///thingspeak()///

bool sendthingspeakGSM(byte thingspeakType, float value1, float value2, float value3, float value4) {
  String host = "api.thingspeak.com";
  String apikey   = "YOUR API KEY";
  
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  A6command("AT+CGATT?", "OK", "yy", 20000, 2);
  
  
  A6command("AT+CGATT=1", "OK", "yy", 20000, 2);
  
  
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  A6command("AT+CGDCONT=1,\"IP\",\"internet.tele2.hr\"", "OK", "yy", 20000, 2); //bring up wireless connection
  
  
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  A6command("AT+CGACT=1,1", "OK", "yy", 10000, 2);
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  
  
  // A6command("AT+CIICR", "OK", "yy", 20000, 2); //bring up wireless connection
  // A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  A6command("AT+CIFSR", "OK", "yy", 20000, 2); //get local IP adress
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  
  
  A6command("AT+CIPSTART=\"TCP\",\"" + host + "\",80", "CONNECT OK", "yy", 25000, 2); //start up the connection
  
  
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  A6command("AT+CIPSEND", ">", "yy", 10000, 1); //begin send data to remote server
  
  
  delay(500);
  A6board.print("GET /update?api_key=");
  A6board.print(apikey);
  A6board.print("&field1=");
  A6board.print(value1);
  A6board.print("&&field2=");
  A6board.print(value2);
  A6board.print("&&field3=");
  A6board.print(value3);
  A6board.print("&&field4=");
  A6board.print(value4);
  A6board.print(" HTTP/1.1");
  A6board.print("\r\n");
  A6board.print("HOST: ");
  A6board.print(host);
  A6board.print("\r\n");
  A6board.print("\r\n");

  Serial.print("GET /update?api_key=");
  Serial.print(apikey);
  Serial.print("&field1=");
  Serial.print(value1);
  Serial.print("&&field2=");
  Serial.print(value2);
  Serial.print("&&field3=");
  Serial.print(value3);
  Serial.print("&&field4=");
  Serial.print(value4);
  Serial.print(" HTTP/1.1");
  Serial.print("\r\n");
  Serial.print("HOST: ");
  Serial.print(host);
  Serial.print("\r\n");
  Serial.print("\r\n");
  
  
  A6command(end_c, "HTTP/1.1", "yy", 30000, 1); //begin send data to remote server
  //A6board.println(end_c); //sending ctrlZ
  unsigned long   entry = millis();
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  A6command("AT+CIPCLOSE", "OK", "yy", 15000, 1); //sending
  A6command("AT+CIPSTATUS", "OK", "yy", 10000, 2);
  delay(100);
  Serial.println("-------------------------End------------------------------");
  
}
