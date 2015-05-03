#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "include/ioConfig.h"
#include "libs/st7565/include/st7565.h"
#include "libs/st7565/st7565.cpp" //???
#include "libs/st7565/include/fonts.h"


int main() {
    
    lcdInit();
    lcdClearBuffer();
    lcdRefresh();
    lcdSetBrightness(20);
    lcdSetFont(font5x7);
    lcdDrawString(38, 20, "Button Test");
    lcdDrawString(3, 55, "0");
    lcdDrawString(42, 55, "0");
    lcdDrawString(82, 55, "0");
    lcdDrawString(120, 55, "0");
    lcdRefresh();
    
    //Set buttons as inputs
    button1_ddr = input;
    button2_ddr = input;
    button3_ddr = input;
    button4_ddr = input;
    
    //Set led as output
    led_ddr = output;
    
    //Enable internal pullups
    PORTB = 0xFF;
    
    //Turn off led
    led = 0;
    
    //Check buttons
    while (1) {
        
        if (!button1) {
            
            lcdDrawString(3, 55, "1");
            lcdRefresh();
        } else {
            
            lcdDrawString(3, 55, "0");
            lcdRefresh();
        }
        
        if (!button2) {
            
            lcdDrawString(42, 55, "1");
            lcdRefresh();
        } else {
            
            lcdDrawString(42, 55, "0");
            lcdRefresh();
        }
        
        if (!button3) {
            
            lcdDrawString(82, 55, "1");
            lcdRefresh();
        } else {
            
            lcdDrawString(82, 55, "0");
            lcdRefresh();
        }
        
        if (!button4) {
            
            lcdDrawString(120, 55, "1");
            lcdRefresh();
        } else {
            
            lcdDrawString(120, 55, "0");
            lcdRefresh();
        }
        
        if (!button1 || !button2 || !button3 || !button4) {
            
            led = 1;
        } else {
            
            led = 0;
        }
    }
}