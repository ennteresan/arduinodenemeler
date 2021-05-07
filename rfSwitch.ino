// **** INCLUDES *****
#include "LowPower.h"
#include <RCSwitch.h>
// Use pin 2 as wake up pin
const int wakeUpPin = 2;
int hareket;
int sonHareket=0;
RCSwitch mySwitch = RCSwitch();
void wakeUp()
{
  
    // Just a handler for the pin interrupt.
}

void setup()
{
    // Configure wake up pin as input.
    // This will consumes few uA of current.
    pinMode(wakeUpPin, INPUT); 
    mySwitch.enableTransmit(10);
  
}

void loop() 
{
    // Allow wake up pin to trigger interrupt on low.
    attachInterrupt(0, wakeUp, CHANGE);
    
    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    
    // Disable external pin interrupt on wake up pin.
    detachInterrupt(0); 
    
    // Do something here
    // Example: Read sensor, data logging, data transmission.
      hareket = digitalRead(wakeUpPin);
      if (hareket != sonHareket){
        if(hareket == HIGH){
          mySwitch.switchOn("11111", "00010");
          }
        else if(hareket == LOW){   
          mySwitch.switchOff("11111", "00010");
          }
      }
      sonHareket = hareket;
      delay(100);
    
}
