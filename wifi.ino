#include <LWiFi.h>
#include <LWiFiClient.h> 

#define WIFI_AP "Name_of_your_AP" 
#define WIFI_PWD "Password_of_your_AP" 
 
LWiFi.begin(); LWiFi.connect(WIFI_AP);  // if the AP is not encrypted 
LWiFi.connect WEP(WIFI_AP, WIFI_PWD);  // if the AP uses WEP encryption 
LWiFi.connect WPA(WIFI_AP, WIFI_PWD);  // if the AP uses WPA encryption

/* Connect to a web site */
#define SITE_URL "www.mediatek.com" 
LWiFiClient c; 
c.connect(SITE_URL, 80); //HTTP uses PORT 80

/* Send HTTP request */
c.println("GET / HTTP/1.1"); 
c.println("Host: " SITE_URL);
c.println("Connection: close"); 
c.println(); 
 
/* Get the web content */
int v; 
while(c.available()) 
{  
  v = c.read();      // return one byte at a time   
  if(v < 0)     
  break;           // no more data 
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
