#include <DFRobot_DHT11.h>

#include <DHT11.h>



#define DHTIN 
#define DHTTYPE DHT11

DHT11 dht(DHTIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  float temperature =dht.readTemperature();
  float temperature =dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
 delay(2000);

}