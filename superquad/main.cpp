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
    lcdSetBrightness(25);
    lcdSetFont(font5x7);
}