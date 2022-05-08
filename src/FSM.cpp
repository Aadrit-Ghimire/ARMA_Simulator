/*
 * FSM.cpp
 *
 *  Created on: May 7, 2022
 *      Author: Aadrit Ghimire
 */


#include "FSM.h"


static state_t FSM_State = IDLE;

void state_machine(void){
    
    switch(FSM_State){
        
        case IDLE:
            /*ACTION*/
            SystemOn(ON);
            CoolerCtl(OFF);
            HeaterCtl(OFF);   
            HandHeating(OFF);    

            idleTimer++;

            /*TRANSITION*/
            if(idleTimer >= 100){
                FSM_State = PRECONDITIONING;
                idleTimer = 0;
            }
            break;


        case PRECONDITIONING:
            /*ACTION*/
            CoolerCtl(ON);
            HeaterCtl(ON);
            PreConTimer++;

            /*TRANSITION*/  
            if(PreConTimer >= 200){
                FSM_State = READY;
                PreConTimer = 0;
            }
            break;


        case READY:
            /*ACTION*/
            readyTimeOut++;
            CoolerCtl(ON);
            HeaterCtl(ON);

            /*TRASNSITION*/   
            if(HandInChamber()){
                FSM_State = WARMING_HAND;
                readyTimeOut = 0;
            }
            else if(readyTimeOut >= 400){
                FSM_State = IDLE;
                readyTimeOut = 0;
            }
            break;


        case WARMING_HAND:
            /*ACTION*/
            HandHeating(ON);

            /*TRASNSITION*/   
            if(WarmingSS() && HandOnPlate()){
                FSM_State = FIRST_IMAGES;
                HandHeating(OFF);
            }
            else if(!HandInChamber()){
                FSM_State = READY;
                HandHeating(OFF);
            }
            break;


        case FIRST_IMAGES:
            /*ACTION*/
            ImgCapture(ON);
            HandCooling(ON);
            firstImgTimer++;

            /*TRASNSITION*/   
            if(firstImgTimer >= 60){
                FSM_State = RECURRING_IMAGES;
                ImgCapture(OFF);
                firstImgTimer = 0;
            }
            if(!HandOnPlate()){
                FSM_State = READY;
                ImgCapture(OFF);
                firstImgTimer = 0;                
            }     
            break;            
        

        case RECURRING_IMAGES:
            /*ACTION*/
            recImgTimer++;

            if(recImgTimer >= 200 && recImgTimer < 400){
                ImgCapture(ON);
            }
            else if(recImgTimer >= 400){
                ImgCapture(OFF);
                recImgTimer = 0;
                recImgCounter++;
            }

            /*TRASNSITION*/  
            if(recImgCounter==10 || CoolingSS()){
                FSM_State = UPLOAD_DATA;
                ImgCapture(OFF);
                recImgTimer = 0;
                recImgCounter = 0;                
            }
            if(!HandOnPlate()){
                FSM_State = READY;
                ImgCapture(OFF);
                recImgTimer = 0;
                recImgCounter = 0;               
            }             
            break;        


        case UPLOAD_DATA:
            /*ACTION*/
            UploadImages(ON);
            CoolerCtl(OFF); 
            HandCooling(OFF); 
            upImgTimer++;

            /*TRASNSITION*/  
              if(NextHand()){
                  FSM_State = WARMING_HAND;
                  UploadImages(OFF);
                  upImgTimer = 0;
              }
              else if(upImgTimer >= 200  && !NextHand()){
                  FSM_State = READY;
                  UploadImages(OFF);
                  upImgTimer = 0;
              }    
            break;       


        case ERROR:
            /*ACTION*/
            /*TRASNSITION*/        
            break;     
                        
    }
}

