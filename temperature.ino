#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int B = 4275;
const int R0 = 100000;
void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    pinMode(A0,INPUT);
    pinMode(2,OUTPUT);
    Serial.begin(9600);
}

void loop() 
{
   int a = analogRead(A0);
  float R = 1023.0/((float)a)-1.0;
  R = 100000.0*R;
   float Temp =1.0/(log(R/100000.0)/B+1/298.15)-273.15;
   if(Temp >= 30)
   {
    digitalWrite(2,HIGH);
    Serial.println("Oops!! High temperature!!! ");
   }
   else
   {
     digitalWrite(2,LOW);
   }
   Serial.println(Temp);
   lcd.setCursor(0,1);
   lcd.println(Temp);
   lcd.print("C");
   delay(2000);
}
