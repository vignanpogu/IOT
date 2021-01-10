 #include <LGSM.h>
void setup() {
 Serial.begin(9600);
 Serial.println("SIM ready for work?");
 while(!LSMS.ready())
 {
 delay(1000);
}
 Serial.println("SIM ready for work!");
 LSMS.beginSMS("9952099290");
 LSMS.print("Hello...ASHOK, from LinkIt");
 if(LSMS.endSMS())
 {
 Serial.println("SMS is sent");
 }
 else
 {
 Serial.println("SMS is not sent");
 }
}
void loop()
{
 // do nothing
 }
