#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (9, 10);
byte addresses[][6] = {"0"};

struct package
{
  int id=1;
  int switchState_1 = 0;
};

typedef struct package Package;
Package data;


void setup()
{
  pinMode(3, INPUT_PULLUP);
  
  Serial.begin(57600);
  delay(1000);
  
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe(addresses[0]);
  delay(1000);
}

void loop()
{
  myRadio.write(&data, sizeof(data)); 

  Serial.print("\nPackage:");
  Serial.print(data.id);
  Serial.print("\n");
  data.id = data.id + 1;
  
  data.switchState_1 = digitalRead(3);
  Serial.print(data.switchState_1);
  
  delay(250);

}
