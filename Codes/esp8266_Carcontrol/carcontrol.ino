#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
//define Motor PINs
#define ENA D5
#define IN1 D8
#define IN2 D7

// Define variables
bool dir1 = 0; 
bool dir2 = 0;
int Speed;

// Setting up Blynk and wifi details
char auth[] = "ovCPpShzmWz0xLssNjPqb5TLnUZ85_K0"; 
char ssid[] = "vivo 1920";
char pass[] = "nanditha"; 

// Define Motor pins as output pins
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

 // Setup connection details and connect to Blynk server
 Blynk.begin(auth, ssid, pass);
}
 // Define Virtual pins; using param.asInt to read inputs
BLYNK_WRITE(V0) {
  dir1 = param.asInt();
}
 
BLYNK_WRITE(V1) {
  dir2 = param.asInt();
}
 
BLYNK_WRITE(V2) {
  Speed = param.asInt();
}

 // Function smartpulley to control the H-bridge and motors
void smartpulley() {
  if (dir1 == 1) {
    turnDir1();
    Serial.println("forward");
  } else if (dir2 == 1) {
    turnDir2();
    Serial.println("backward");
  }else if (dir1 == 0 && dir2 == 0) {
    Stop();
    Serial.println("stop");
  }
}

// Calling the function smartpulley()
void loop() {
  Blynk.run();
  smartpulley();
}

 // Function to rotate motors in one direction (forward)
void turnDir1() {
  analogWrite(ENA, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
// Function to rotate motors in opposite direction (backward)
void turnDir2() {
  analogWrite(ENA, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

}
// Stops the rotation of motor
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

}
