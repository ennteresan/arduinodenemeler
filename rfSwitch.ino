int pirPin = 8;                   
int hareket;
int sonHareket=0;
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
  pinMode(pirPin, INPUT);   
}
void loop() {
  hareket = digitalRead(pirPin);
   if (hareket != sonHareket){
   if(hareket == HIGH){
mySwitch.switchOn("11111", "00010");
   }
  else if(hareket == LOW){   
mySwitch.switchOff("11111", "00010");
}
}sonHareket = hareket;
delay(10);
}
