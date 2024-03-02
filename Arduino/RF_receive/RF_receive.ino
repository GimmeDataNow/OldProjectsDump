#include <SPI.h>  
#include "RF24.h" 

RF24 myRadio (9, 10); 
byte addresses[][6] = {"0"}; 

struct package
{
  int id=0;
  int switchState_1 = 0;
};

typedef struct package Package;
Package data;


void setup() {
  Serial.begin(57600);
  delay(1000);

  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
}


void loop() {
  myRadio.isChipConnected();
  if (myRadio.available()) {
    Serial.print(">");

    while (myRadio.available()) {
      myRadio.read( &data, sizeof(data) );
    }
    
    Serial.print("\nPackage:");
    Serial.print(data.id);
    Serial.print("\n");
    Serial.println(data.switchState_1);
  }
  else {
    Serial.print("#");
  }

  delay(125);
}
