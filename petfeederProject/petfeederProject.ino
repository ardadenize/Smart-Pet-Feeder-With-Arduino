void setup() {
  // put your setup code here, to run once:

}#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPLyiKUF7lC"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "zS3M2bNwZU9oxIpfLWxfJW0CsdCN22Kb"

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(6, 7); // RX, TX
// Comment this out to disable prints and save space
#include "NewPing.h"
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400
float duration, distance;
int IN1 = 2, IN2 = 3, IN3 = 4, IN4 = 5; //Step motor pinlerini tanımlıyoruz.
int sure = 3;
int feedcount=0;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ardad";
char pass[] = "e9Feh77N9sEU";
#define ESP8266_BAUD 115200
ESP8266 wifi(&EspSerial);
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1


void setup()
{
  Serial.begin(115200);
  delay(10);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  pinMode(IN1, OUTPUT);                                   //Motor pinleri OUTPUT olarak ayarlanır.
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  

  Blynk.begin(auth,wifi, ssid, pass, "blynk.cloud", 80);
 
}
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
   if(pinValue == 1){  
  if (distance >= 400 || distance <= 2){
        Serial.print(distance);
        Serial.println(" cm");
        delay(500);
        stepIleri(512);
        feedcount++;
        Blynk.virtualWrite(V0,feedcount);
         
    }
  }
  
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}

void loop()
{
  Blynk.run();
}
void stepIleri(int adimSayisi){                               //Step motora ileri hareketi yaptırır.
 for (int i = 0; i < adimSayisi; i++) {
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
