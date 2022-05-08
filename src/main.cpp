#include <Arduino.h>
#include "SPI.h"

#include "FSM.h"
#include "IOConfig.h"

#define SCHEDULE_INTERVAL 50      //Scheduling interval in ms
unsigned long prevTime = 0;


void setup() {
  ConfigureIO();
}

void loop() {

  unsigned long currentTime = millis();

  if(currentTime - prevTime >= SCHEDULE_INTERVAL){      // Create a scheduler to execute the following tasks periodically at scheduled interval
    
    debounceInputs();

    HandsIn(HandInChamber());

    state_machine();

    prevTime = currentTime;

  }
}