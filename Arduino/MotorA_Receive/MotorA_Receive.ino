#include <SPI.h>  
#include "RF24.h" 
#include <SparkFun_TB6612.h>


#define AIN1 2
#define AIN2 4
#define PWMA 5
//#define BIN1 7
//#define BIN2 8
//#define PWMB 6
#define STBY 3

const int offsetA = 1;
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);


RF24 myRadio (9, 10); 
byte addresses[][6] = {"0"}; 


struct package
{
  int id=0;
  int switchState_1 = 1;
};

typedef struct package Package;
Package data;


void setup() 
{
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
 
  if (myRadio.available()){
    Serial.print(">");
 
    while (myRadio.available()){
      myRadio.read( &data, sizeof(data) );
    }
    
    Serial.print("\nPackage:");
    Serial.print(data.id);
    Serial.print("\n");
    Serial.println(data.switchState_1);

    if (data.switchState_1 == 0){
      motor1.drive(255, 250);
      Serial.print("m");
    }
  }
  else {
    motor1.brake();
    Serial.print("#");
    delay(250);
  }
}
