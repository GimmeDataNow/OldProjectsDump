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

void setup() 
{
  pinMode(8, INPUT_PULLUP);
  
  Serial.begin(57600);
  delay(1000);
}


void loop()  
{
  int fromPin8 = digitalRead(8);
  Serial.print(fromPin8);
  if (fromPin8 == 0){
    motor1.drive(255,1000);
  }
  else {

      motor1.brake();
  }
  
   delay(1000);
}
