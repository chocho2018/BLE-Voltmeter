#include "BlunoAccessory.h"
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
BlunoAccessory myAccessory;
char buf[5]={'0','.','0','\0'};

void setup() {
  u8g.setColorIndex(1);
  myAccessory.begin();
  Serial.begin(115200);
}

void loop() {
  u8g.firstPage();
  do
  {
    draw();
  }
  while(u8g.nextPage());
}

//Display function 
//also see https://code.google.com/p/u8glib/wiki/tpictureloop

void draw (void)
{
  u8g.setFont(u8g_font_fur49n);
  u8g.drawStr(0,58,buf);
}

void serialEvent()
{
  unsigned char i=0;
  while(Serial.available())
  {
    char inChar=(char)Serial.read();
    buf[i]=inChar;
    i++;
    }
  }
