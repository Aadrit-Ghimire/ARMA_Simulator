/*
 * IOConfig.cpp
 *
 *  Created on: May 7, 2022
 *      Author: Aadrit Ghimire
 */


#include "IOConfig.h"


void ConfigureIO(void){

    pinMode(BLUE_LED_PELTIER, OUTPUT);
    pinMode(RED_LED_HEATER, OUTPUT);
    pinMode(YELLOW_LED_SYSTEM_ON, OUTPUT);
    pinMode(GREEN_LED_IMG_CAPTURE, OUTPUT);
    pinMode(LED_UPLOADING_IMAGES, OUTPUT);
    pinMode(VIOLET_LED_HAND_COOLING, OUTPUT);
    pinMode(ORANGE_LED_HAND_WARMING, OUTPUT);
    pinMode(LED_HANDS_IN, OUTPUT);

    pinMode(RX_LEPTON_uC_Sw_PUSH, INPUT_PULLUP);
    pinMode(TOUCHSCREEN_ON_SW, INPUT_PULLUP);
    pinMode(HAND_ON_COOLING_PLATE_SW, INPUT_PULLUP);
    pinMode(COOLING_SS_SW, INPUT_PULLUP);
    pinMode(NEXT_HAND_SW, INPUT_PULLUP);
    pinMode(WARMING_SS_SW, INPUT_PULLUP);
    pinMode(HAND_IN_WARMING_CHAMBER_SW, INPUT_PULLUP);

}



/*---------OUTPUTS----------*/
void CoolerCtl(uint8_t Control){
    digitalWrite(BLUE_LED_PELTIER, Control);  //peltier and Fan
}

void HeaterCtl(uint8_t Control){
    digitalWrite(RED_LED_HEATER, Control);  //Heater
}

void ImgCapture(uint8_t Control){
    //flashes the led to indicate a single capture.
    digitalWrite(GREEN_LED_IMG_CAPTURE, Control);
}

void SystemOn(uint8_t Control){
    digitalWrite(YELLOW_LED_SYSTEM_ON, Control);
}

void UploadImages(uint8_t Control){
    digitalWrite(LED_UPLOADING_IMAGES, Control);
}

void HandCooling(uint8_t Control){
    digitalWrite(VIOLET_LED_HAND_COOLING, Control);
}

void HandHeating(uint8_t Control){
    digitalWrite(ORANGE_LED_HAND_WARMING, Control);
}

void HandsIn(uint8_t Control){
    digitalWrite(LED_HANDS_IN, Control);
}




/*---------INPUTS----------*/
uint8_t HandOnPlate(void){
    return HandOnPlate_debounced;
}

uint8_t HandInChamber(void){
    return HandInChamber_debounced;
}

uint8_t WarmingSS(void){
    return WarmingSS_debounced;
}

uint8_t CoolingSS(void){
    return CoolingSS_debounced;
}

uint8_t TouchScreenOn(void){
    return TouchScreenOn_debounced;
}

uint8_t NextHand(void){
    return NextHand_debounced;
}



/* Debounce logic to be called periodically by the main program */
/* Checks to see if the digital input is HIGH for 2 succesive periods*/

void debounceInputs(void){

    /*---------------HAND_ON_COOLING_PLATE_SW---------------*/
    uint8_t HandOnPlate = !digitalRead(HAND_ON_COOLING_PLATE_SW);
    HandOnPlate_debounced = (HandOnPlate_delay && HandOnPlate) ? 1 : 0; 
    HandOnPlate_delay = HandOnPlate;

    /*---------------HAND_IN_WARMING_CHAMBER_SW---------------*/
    uint8_t HandInChamber = !digitalRead(HAND_IN_WARMING_CHAMBER_SW);
    HandInChamber_debounced = (HandInChamber_delay && HandInChamber) ? 1 : 0;   
    HandInChamber_delay = HandInChamber;

    /*---------------WARMING_SS_SW---------------*/
    uint8_t WarmingSS = !digitalRead(WARMING_SS_SW);
    WarmingSS_debounced = (WarmingSS_delay && WarmingSS) ? 1 : 0;   
    WarmingSS_delay = WarmingSS;

    /*---------------COOLING_SS_SW---------------*/
    uint8_t CoolingSS = !digitalRead(COOLING_SS_SW);
    CoolingSS_debounced = (CoolingSS_delay && CoolingSS) ? 1 : 0;   
    CoolingSS_delay = CoolingSS;

    /*---------------TOUCHSCREEN_ON_SW---------------*/
    uint8_t TouchScreenOn = !digitalRead(TOUCHSCREEN_ON_SW);
    TouchScreenOn_debounced = (TouchScreenOn_delay && TouchScreenOn) ? 1 : 0;      
    TouchScreenOn_delay = TouchScreenOn;

    /*---------------NEXT_HAND_SW---------------*/
    uint8_t NextHand = !digitalRead(NEXT_HAND_SW);
    NextHand_debounced = (NextHand_delay && NextHand) ? 1 : 0;  
    NextHand_delay = NextHand;
}