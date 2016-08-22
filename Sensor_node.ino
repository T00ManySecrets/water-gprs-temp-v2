#include <Sleep_n0m1.h>
#include <avr/wdt.h>
#include <String.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define OK 1
#define NOTOK 2
#define TIMEOUT 3
#define RST 4          // Reset Pin 
#define DHTPIN 7      // Digital pin where DHT sensor is connected
#define ONE_WIRE_BUS 6 // Digital pin where DS18B20 is connected

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM232
DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature tempSensor(&oneWire);
Sleep sleep;
unsigned long sleepTime;

float temp1;
float temp2;
float batt1;
float batt2;
float hum;

#define A6board Serial1


#define A6baud 115200
#define SERIALTIMEOUT 3000

char end_c[2];

void setup() {
  sleepTime = 900000;
  pinMode(RST, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(5, HIGH); 
  digitalWrite(RST, LOW);
  //digitalWrite(8, LOW);
  digitalWrite(8, HIGH); 
  delay(3000);       
  digitalWrite(8, LOW);
  dht.begin();
  tempSensor.begin();
  A6board.begin(A6baud);   // the GPRS baud rate
  Serial.begin(115200);    // the GPRS baud rate
  // ctrlZ String definition
  end_c[0] = 0x1a;
  end_c[1] = '\0';
  Serial.println("Start");

  
  
  delay(500);
  
  
  if (A6begin() != OK) {
    Serial.println("Error");
    while (1 == 1);
  }
}

void loop()
{
  
    {
      
        
        
        Serial.println("----------------------Post value to Thingspeak-------------------------------");
        readSensors();
        sendthingspeakGSM(1, temp1, temp2, hum, batt2);
        
        (A6command("AT+CPOF", "OK", "yy", 5000, 2) == OK);   // Reset to factory settings
        sleep.pwrDownMode(); //set sleep mode
        sleep.sleepDelay(sleepTime); //sleep for: sleepTime
        
        wdt_enable(WDTO_120MS);
        while(1) {}
    }
  if ( A6board.available())
    Serial.write( A6board.read());

  delay(2000);
   
}

