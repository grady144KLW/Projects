#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Wire.h>
#include <Adafruit_BMP280.h>

#define reset 4 // declaring a reset pin
Adafruit_SSD1306 display(reset); // declaring an object to represent the display

Adafruit_BMP280 bmp; // declaring the bmp 280 object
float temp_; // declaring the temperature variable
float altitude_; // declaring the altitude variable 

void setup() {
Serial.begin(9600);
Wire.begin(); // starting the i2c library
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initializing the display with the address 
bmp.begin(0x76); // initializing the bmp 280 with the address

}

void loop() {
temp_ = bmp.readTemperature(); // setting the temperature variable to read the value
altitude_ = bmp.readAltitude(); // setting the altitude variable to read the value
  
display.clearDisplay();
display.setTextColor(WHITE); // setting the text colour
display.setTextSize(1); // setting the size of the text
display.setCursor(0,0); // setting the cursor at the top left
display.print("GTK Temp meter V2.0"); // printing this on the top left
display.setCursor(0,10); // setting the cursor at the middle left on the screen
display.print("Temp: "); // printing this on the middle left 
display.print(temp_); // printing the temperature value in the same cursor (middle left)
display.print("°C"); // printing the symbol for the temperature 
display.setCursor(0,20); // setting the cursor at the bottom left of the screen
display.print("Altitude: "); // printing this on the bottom left
display.print(altitude_); // printing the altitude on the same cursor (bottom left)
display.print("α"); // printing the symbol for the altitude
display.display(); // displaying what was written in the screen
}
