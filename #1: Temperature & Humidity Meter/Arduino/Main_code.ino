#include <DHT.h>
#include <DHT_U.h>

#include <SD.h>
#include <SPI.h>


int pin11 = 2; // delcaring the pin of the DHT 11
#define Type DHT11 // declaring what type of DHT sensor is being used
DHT dht(pin11, Type); // declaring the dht object
float temperature_11; // declaring the temperature variable
float humidity_11; // delcaring the humidity variable



int pin22 = 2; // delcaring the pin of the DHT 11
#define Type DHT22 // declaring what type of DHT sensor is being used
DHT dht(pin22, Type); // declaring the dht object
float temperature_22; // declaring the temperature variable
float humidity_22; // delcaring the humidity variable


int cs = 5; // declarig the chip select to pin 5
File myfile; // delcaring the file object

void setup() {
  Serial.begin(9600); // starting the serial monitor 
  dht.begin(); // starting the dht 11
  SD.begin(cs); // starting the sd file
}

void loop() {
  temperature_11 = dht.readTemperature(); // reading the temperature of dht 11
  humidity_11 = dht.readHumidity(); // reading the humidity of dht 11
  temperature_22 = dht.readTemperature();
  humidity_22 = dht.readHumidity();
/*
Printing the values on the serial monitor
*/ 
  Serial.print("DHT 11's Temp: ");
  Serial.print(temperature_11);
  Serial.print("°C  ");
  Serial.print("DHT 11's Humidity: ");
  Serial.print(humidity_11);
  Serial.println("% ");


  Serial.print("DHT 22's Temp: ");
  Serial.print(temperature_22);
  Serial.print("°C  ");
  Serial.print("DHT 22's Humidity: ");
  Serial.print(humidity_22);
  Serial.println("% ");

/*
Printing the values on the sd card
 */
 
  myfile = SD.open("dht2.txt",FILE_WRITE);
    if(myfile){
      myfile.print("Dht 22 Temp: ");
      myfile.print(temperature_22);
      myfile.print(" C");
      myfile.print("  Dht 22 Humidity: ");
      myfile.print(humidity_22);
      myfile.println(" %");
      delay(300000);
      myfile.close();
    }
    else{
      Serial.println("error");
    }

}
