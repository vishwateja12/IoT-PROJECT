#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include<HCSR04.h>
const int trig = 18;
const int echo = 5;
HCSR04 hc(trig, echo);
char auth[] = "X4-Lti57mCzcTp4exHsfU0fC0ZHMb5XY";
char ssid[] = "Redmi Note 8 Pro";
char pass[] = "12345678";

float c = 0;
float cf = 0;
float KE,PE,TE=0;
float v = 0;
float t=0;
float m = 100; 
float g=9.8;


BlynkTimer timer;

void setup()
{
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
 
  Blynk.run();
  c = hc.dist();
  delay(100);
  cf = hc.dist();
  v = cf-c;
  PE = m*c*g/100;
  KE = m*v*v/2;
  TE = KE + PE;
 Blynk.virtualWrite(V0, KE);
 Blynk.virtualWrite(V1,PE);
 Blynk.virtualWrite(V2,TE);
 Serial.print(c);
 Serial.println("\n");
 Serial.print(cf);
 Serial.println("\n");
 Serial.print(KE);
 Serial.println("\n");
 Serial.println("----------------------------------------------------------------");
}
