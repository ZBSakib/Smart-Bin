//welcome to learning snippets Kindly share & subscribe the channel https://www.youtube.com/channel/UCQ2ZDvPfGLbWDgLTorrklGA
//copy blynk_template_id, blynk_device_name from blynk website template info section
#define BLYNK_TEMPLATE_ID "TMPLKZh2INz6"
#define BLYNK_DEVICE_NAME "Wastebin"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#define trig D5
#define echo D6
#include "BlynkEdgent.h"
BlynkTimer timer;
long binDepth=22;

void garbageLevel(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  double level= binDepth-cm;
  if(level>0){
    long percentage=((level/binDepth))*100;
    Blynk.virtualWrite(V0,percentage);
  }
  else{
    Blynk.virtualWrite(V0,0);
  }

}

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
  timer.setInterval(10L, garbageLevel);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
} 
