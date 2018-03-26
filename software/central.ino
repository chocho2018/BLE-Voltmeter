#define AREF 5.0
void setup() {
Serial.begin(115200);
}

void loop() {
char buf[5];
int vaule=analogRead(A0);
double vol=(double)vaule/1024*AREF*5;
vol=vol-0.2;
if(vol<0.0)
{
  vol=0.0;
  }
dtostrf(vol,2,1,buf);
buf[4]='\0';
Serial.write(buf);
delay(500);
}
