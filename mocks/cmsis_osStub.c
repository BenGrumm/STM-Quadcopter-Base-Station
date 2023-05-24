#include "cmsis_osStub.h"

static uint32_t lastDelay = 0;

osStatus osDelay (uint32_t millisec){
    lastDelay = millisec;

    return osOK;
}

uint32_t CMSISDelayStub_getLastDelay(void){
    return lastDelay;
}