/*
 * FSM.h
 *
 *  Created on: May 7, 2022
 *      Author: Aadrit Ghimire
 */


#ifndef FSM_H
#define FSM_H

#include <Arduino.h>
#include "IOConfig.h"

#define ON  1
#define OFF 0

static uint32_t idleTimer = 0;
static uint32_t PreConTimer = 0;
static uint32_t readyTimeOut = 0;
static uint32_t firstImgTimer = 0;
static uint32_t recImgTimer = 0;
static uint32_t recImgCounter = 0; 
static uint32_t upImgTimer = 0;

typedef enum{
    IDLE,
    PRECONDITIONING,
    READY,
    WARMING_HAND,
    FIRST_IMAGES,
    RECURRING_IMAGES,
    UPLOAD_DATA,
    ERROR,
}state_t;

void state_machine(void);

#endif