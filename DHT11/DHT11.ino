/*
 * 
*/

#include <SimpleDHT.h>
int pinDHT11 = 8;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1500);
    return;
  }
  Serial.print("Lecture OK: ");
  Serial.print(" TEMPERATURE "); Serial.print((int)temperature); Serial.print(" °C, ");
  Serial.print(" HUMIDITE "); Serial.print((int)humidity); Serial.println("%");
  delay(1500);
  }
