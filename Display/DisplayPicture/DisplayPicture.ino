#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
static const uint8_t image_data_icon[1024] = {
    0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x3f, 0x80, 0x1f, 
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x3f, 0x80, 0x03, 
    0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x3f, 0x00, 0x00, 
    0x00, 0x00, 0x05, 0x55, 0x55, 0x57, 0xf0, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 
    0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 
    0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x07, 0xff, 0xff, 0xff, 0x80, 0x00, 
    0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0xfc, 0x00, 0x00, 0x10, 0x0f, 0xf8, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
    0x00, 0x01, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x03, 0xfe, 0x22, 0x10, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0xfc, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xfc, 0x00, 0xfe, 0x00, 0xff, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xf8, 0x01, 0xfc, 0x00, 0x3f, 0x80, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xe0, 0x03, 0xf8, 0x00, 0x3f, 0x80, 0x07, 0xf8, 0x00, 0x01, 0x7d, 0x00, 0x00, 0x00, 
    0x04, 0x40, 0x00, 0x01, 0xf8, 0x00, 0x1f, 0x80, 0x0f, 0xe0, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x3f, 0x80, 0x1f, 0xc0, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0xff, 0x00, 0x1f, 0xc0, 0x00, 0xff, 0xd7, 0xfe, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xff, 0xef, 0xfe, 0x00, 0x1f, 0xc0, 0x01, 0xfe, 0x00, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x0f, 0xc0, 0x03, 0xf8, 0x00, 0x3f, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x1f, 0xc0, 0x03, 0xf8, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0x7a, 0x00, 0x00, 0x3f, 0xc0, 0x03, 0xf8, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x01, 0xf8, 0x00, 0x7f, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x01, 0xfe, 0x00, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0xff, 0xf7, 0xfe, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x7f, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0x12, 0x49, 0x24, 0x92, 0x44, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x7e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x2f, 0xf8, 0x00, 0x3f, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x1f, 0xe0, 0x03, 0xf8, 0x00, 0x1f, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xfc, 0x00, 0x07, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xfc, 0x00, 0x01, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xfc, 0x00, 0x00, 0x7f, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x07, 0xff, 0x10, 0x04, 0x9f, 0xe0, 0x03, 0xf8, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x07, 0xfa, 0x2f, 0xf0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0x00, 0x00, 
    0x24, 0x89, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x03, 
    0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x0f
};
void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.drawBitmap(0,0,image_data_icon  ,128,64,1);
  display.display(); 
}

void loop() {
  
}
