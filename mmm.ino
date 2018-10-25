#include <dht.h>

dht DHT;

int T_Sensor = 7;

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(T_Sensor);
  Serial.println();
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print("C");
  Serial.println();
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%");
  delay(1000);
}
