/*************************************************************
 This is the code for making your own Fan Regulator that works over internet using Blynk IoT Platform

 A full tutorial video on this project is uploaded on my YouTube channel.
 Have a look over it to know more

 techiesms YouTube Channel - https://www.youtube.com/techiesms

 Code written by - Sachin Soni
 Code written on - 11.07.20
  
  Download latest Blynk library here:
  https://github.com/blynkkk/blynk-library/releases/latest

          techiesms
    explore | learn | share


 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define Speed1 21
#define Speed2 19
#define Speed4 18


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "fmjTsPbnvXbnNDyzmXik9AtI0uaQSh4n";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SmS_jiofi";
char pass[] = "sms123458956";

BLYNK_WRITE(V0)
{
  int fan_speed = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (fan_speed == 0)
  {
    //All realys Off - Fan Off
    
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
  }

  if (fan_speed == 1)
  {
    //Speed1 Relay On - Fan at speed 1
    
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
    delay(500);
    digitalWrite(Speed1, LOW);
  }

  if (fan_speed == 2)
  {
    //Speed2 Relay On - Fan at speed 2
    
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
    delay(500);
    digitalWrite(Speed2, LOW);
  }

  if (fan_speed == 3)
  {
    //Speed1 & Speed2 Relays On - Fan at speed 3
    
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
    delay(500);
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
  }

  if (fan_speed == 4)
  {
    //Speed4 Relay On - Fan at speed 4
    
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
    delay(500);
    digitalWrite(Speed4, LOW);
  }
  // process received value
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  pinMode(Speed1, OUTPUT);
  pinMode(Speed2, OUTPUT);
  pinMode(Speed4, OUTPUT);

  //Initially the fan will be in OFF state
  digitalWrite(Speed1, HIGH);
  digitalWrite(Speed2, HIGH);
  digitalWrite(Speed4, HIGH);


  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
