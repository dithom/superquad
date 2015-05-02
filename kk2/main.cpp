#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ioConfig.h"
#include "libs/st7565/st7565.cpp" //header einbinden


int main() {
    
    lcdInit();
    lcdClearBuffer();
    lcdRefresh();
    lcdSetBrightness(25);

    //Column animation
    /*uint16_t i = 0;
    
    while (1) {
        
        if (i >= 1024) {
            
            i = 0;
        }
        
        lcdClearBuffer();
        lcdDrawColumn(floor(i / 128), i % 128);
        lcdRefresh();
        i++;
    }*/
}