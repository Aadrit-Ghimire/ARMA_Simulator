/*
 * IOConfig.h
 *
 *  Created on: May 7, 2022
 *      Author: Aadrit Ghimire
 */

#ifndef IOCONFIG_H
#define IOCONFIG_H

#include <Arduino.h>
#include "SPI.h"


/*Below definitions correspind to the intital specifications*/
#define TEMP1_CS      2
#define TEMP2_CS      3
#define PELTIER_CTRL  5
#define HEATER_CTRL   6
#define SPI_MOSI      13
#define SPI_MISO      14
#define LED           13


/*Simulator Specific OUTPUT definitions*/
#define BLUE_LED_PELTIER        5
#define RED_LED_HEATER          6
#define YELLOW_LED_SYSTEM_ON    11
#define GREEN_LED_IMG_CAPTURE   1
#define LED_UPLOADING_IMAGES    A13
#define VIOLET_LED_HAND_COOLING A17
#define ORANGE_LED_HAND_WARMING A16
#define LED_HANDS_IN            A10

/*Simulator specific INPUT definitions*/
#define RX_LEPTON_uC_Sw_PUSH        0
#define TOUCHSCREEN_ON_SW           12
#define HAND_ON_COOLING_PLATE_SW    33
#define COOLING_SS_SW               32
#define NEXT_HAND_SW                25
#define WARMING_SS_SW               24
#define HAND_IN_WARMING_CHAMBER_SW  A11




/*static variables to debounce the input switches*/
static uint8_t HandOnPlate_delay = 0;
static uint8_t HandInChamber_delay = 0;
static uint8_t WarmingSS_delay = 0;
static uint8_t CoolingSS_delay = 0;
static uint8_t TouchScreenOn_delay = 0;
static uint8_t NextHand_delay = 0;

static uint8_t HandOnPlate_debounced = 0;
static uint8_t HandInChamber_debounced = 0;
static uint8_t WarmingSS_debounced = 0;
static uint8_t CoolingSS_debounced = 0;
static uint8_t TouchScreenOn_debounced = 0;
static uint8_t NextHand_debounced = 0;



/*---------Function declarations-------------*/

/*-----Config IO Pins-----*/
/*To be called in the setup*/
void ConfigureIO(void);

/*---------DEBOUNCE----------*/
/*to be called periodically in loop*/
void debounceInputs(void);

/*---------OUTPUTS----------*/
void CoolerCtl(uint8_t Control);
void HeaterCtl(uint8_t Control);
void ImgCapture(uint8_t Control);
void SystemOn(uint8_t Control);
void UploadImages(uint8_t Control);
void HandCooling(uint8_t Control);
void HandHeating(uint8_t Control);
void HandsIn(uint8_t Control);

/*---------INPUTS----------*/
/*returns the debounced input values*/
uint8_t HandOnPlate(void);
uint8_t HandInChamber(void);
uint8_t WarmingSS(void);
uint8_t CoolingSS(void);
uint8_t TouchScreenOn(void);
uint8_t NextHand(void);



#endif