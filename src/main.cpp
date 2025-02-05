#include <Arduino.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#define PIN_RESET 255 //
#define DC_JUMPER 0   // I2C Addres: 0 - 0x3C, 1 - 0x3D
#include <SSD1306.h>  // OLED library by Daniel Eichhorn
//SSD1306 display(0x3c, D2, D1);
uint8_t str1 = 0;
uint8_t str2 = 0;
uint8_t str3 = 0;
uint8_t str4 = 0;
uint8_t str5 = 0;
uint8_t str6 = 0;

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3d, D2, D1);
SSD1306Wire  display2(0x3c, D2, D1);
SSD1306Wire  display3(0x3d, D4, D3);//3c,3D,40 SHT
SSD1306Wire  display4(0x3c, D4, D3);//3C,3D.45 INA

void displayTemp(float temp, String scale)
{
  display.clear();
  display.setFont(ArialMT_Plain_24);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(32, 15, String(temp));
  display.setFont(ArialMT_Plain_16);
  display.drawString(32, 40, scale);
  display.display();
}

void dispTemplate_threeLineV1(String str1, String str2, String str3)
{ // 7 signs per row
  uint8_t iHorpos = 28;
  display.clear();
  display.setFont(ArialMT_Plain_16); //(ArialMT_Plain_10)
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(iHorpos, 15, str1);
  display.drawString(iHorpos, 30, str2);
  display.drawString(iHorpos, 45, str3);
  display.display();
}

void dispTemplate_threeLineV2(String str1, String str2, String str3)
{
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(32, 13, str1);
  display.setFont(ArialMT_Plain_24);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 24, str2);
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(96, 51, str3);
  display.display();
}

void dispTemplate_fourLineV1(String str1, String str2, String str3, String str4)
{
  uint8_t iHorpos = 28;
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(iHorpos, 15, str1);
  display.drawString(iHorpos, 27, str2);
  display.drawString(iHorpos, 39, str3);
  display.drawString(iHorpos, 51, str4);
  display.display();
} 

void FourOled() 
{
  uint8_t iHorOffs = 31;  
  display.clear();
  display.setFont(ArialMT_Plain_16);//(ArialMT_Plain_10)
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(iHorOffs, 15, "str2");
  display.drawString(iHorOffs, 30, "str4");
  display.drawString(iHorOffs, 45, "str6");
  display.display();

  display2.clear();
  display2.setFont(ArialMT_Plain_16);//(ArialMT_Plain_10)
  display2.setTextAlignment(TEXT_ALIGN_LEFT);
  display2.drawString(iHorOffs, 15, "str8");
  display2.drawString(iHorOffs, 30, "strX");
  display2.drawString(iHorOffs, 45, "str12");
  display2.display();

  display3.clear();
  display3.drawString(0, 0, "ABRAVINK : " + String(millis()));
  display3.display();

  display4.clear();
  display4.drawString(0, 0, "Hello world: " + String(millis()));
  display4.display();
  delay(10);
}

void setup() 
{
  Serial.begin(115200);
  Serial.println("\nTestFourOled 200706");
  Serial.println("setup ");
  display.init();
  display.setBrightness(254);
  //display.flipScreenVertically();
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(48, 35, F("Wait"));
  display.display();

  // Initialising the UI will init the display too.
  display.init();
  display2.init();
  display3.init();
  display4.init();
  // This will make sure that multiple instances of a display driver
  // running on different ports will work together transparently
  display.setI2cAutoInit(true);
  display2.setI2cAutoInit(true);
  display3.setI2cAutoInit(true);
  display4.setI2cAutoInit(true);

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  display2.flipScreenVertically();
  display2.setFont(ArialMT_Plain_16);
  display2.setTextAlignment(TEXT_ALIGN_LEFT);

  display3.flipScreenVertically();
  display3.setFont(ArialMT_Plain_16);
  display3.setTextAlignment(TEXT_ALIGN_LEFT);

  display4.flipScreenVertically();
  display4.setFont(ArialMT_Plain_16);
  display4.setTextAlignment(TEXT_ALIGN_LEFT);

} 

void loop() 
{
   FourOled();
}




