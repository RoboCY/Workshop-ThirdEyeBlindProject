// https://github.com/gamegine/HCSR04-ultrasonic-sensor-lib
// Choose Arduino Leonardo
#include "./HCSR04.h"

#define LED_PIN 14
#define BUZZ_PIN A3
#define TRIG_PIN 15
#define ECHO_PIN 16

HCSR04 distanceSensor(ECHO_PIN, TRIG_PIN);
int distance;
int toneValue;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("THIRD EYE PROJECT START!");
}

void loop() {
  distance = distanceSensor.dist();
  Serial.print(distance);
  Serial.print(" ");

  if(distance > 200) distance = 0;

  toneValue = 200 - distance;
  Serial.print(distance);
  Serial.print(" ");
  Serial.println(toneValue);
  

  if(distance == 0){
    noTone(BUZZ_PIN);
    digitalWrite(LED_PIN, LOW);  
  }
  else{
    digitalWrite(LED_PIN, HIGH); 
    tone(BUZZ_PIN,1000,toneValue);
  }
 
  delay(500); 
}
