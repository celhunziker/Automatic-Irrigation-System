// Sensor de Humedad    
           
    // Conectamos el sensor de la siguiente forma:       
    // GND    -> GND       
    // VCC    -> 5V       
    // DAT    -> A0           
     
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
int T_Sensor = 7;
int Valor; 
int M_Sensor = A0;

LiquidCrystal_I2C lcd(0x20,16,2); 
dht DHT;

void setup()
{
  pinMode(3, OUTPUT);         //Set Pin3 as output
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Proyecto");
  lcd.setCursor(0,1);
  lcd.print("Tropfen");
  delay(5000);
} 
void loop(){  
  lcd.clear();
  int chk = DHT.read11(T_Sensor);
  int Moisture = analogRead(M_Sensor);
  lcd.print(Moisture);
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  Serial.println();
  Serial.print("Humedad Suelo=");
  Serial.print(Moisture);
  Serial.println();
  Serial.print("Temperatura Ambiente=");
  Serial.print(DHT.temperature);
  Serial.print("°C");
  Serial.println();
  Serial.print("Humedad Ambiente=");
  Serial.print(DHT.humidity);
  Serial.print("%");
   
  if (Moisture > 700 && 25>=DHT.temperature && DHT.temperature>= 10)  //Suelo seco
  {
    digitalWrite(3, HIGH);//Turn off relay
    lcd.setCursor(8,0);
    lcd.print("Regando,");
    lcd.setCursor(2,1);
    lcd.print("C   Suelo Seco");
  }
  else
  {
    digitalWrite(3,LOW);
  }
  if (Moisture >= 300 && Moisture <=700)  //Suelo humedo
  {
     digitalWrite(3, LOW);
     lcd.setCursor(7,0);
     lcd.print("No Regar,");
     lcd.setCursor(2,1);
     lcd.print("C Suelo Humedo");
  }
  if (Moisture < 300)  //Suelo mojado
  {
    digitalWrite(3, LOW);
    lcd.setCursor(7,0);
    lcd.print("No Regar,");
    lcd.setCursor(2,1);
    lcd.print("C Suelo Mojado");
  }

  delay(1000); 
} 
