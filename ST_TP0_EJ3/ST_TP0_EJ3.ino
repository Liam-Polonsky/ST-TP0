#include <Wire.h>     // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  // crea objeto


#include "DHT.h"
#include <DHT.h>
#include <DHT_U.h>
float t;

#define DHTPIN 23     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

#define LedPin 25

void setup() {
  Wire.begin();         // inicializa bus I2C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  dht.begin();
  pinMode(LedPin, OUTPUT);
}

void loop() {
  dhtFunc();
  oledFunc();
  LedOn();
}

void dhtFunc() {

  t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
}
void oledFunc()
{
  display.clearDisplay();      // limpia pantalla
  display.setCursor(0, 20);     // ubica cursor en inicio de coordenadas 0,0
  display.setTextSize(1);
  display.print("la temeperatura es: ");  // escribe en pantalla el texto

  display.setTextColor(WHITE);
  display.setCursor(0, 40);     // ubica cursor en inicio de coordenadas 0,0
  display.setTextSize(2);
  display.print(t);  // escribe en pantalla el texto
  display.display();     // muestra en pantalla todo lo establecido anteriormente
}

void LedOn()
{
  if (t >= 29)
  {
    digitalWrite(LedPin, HIGH);
  }
  else
  {
    digitalWrite(LedPin, LOW);
  }
}
