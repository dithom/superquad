#include "include/st7565.h"
#include <string.h>

//Display buffer with 1024 bytes (1 byte is one column in a page)
uint8_t buffer[bufferSize];

//Holds current active font
Font activeFont;


void lcdSendBuffer(uint8_t *buffer) {
    
    //Iterate through pages
    for (uint8_t page = 0; page < 8; ++page) {
        
        lcdSendCommand(setPage | (7 - page));
        lcdSendCommand(setColumnLower | (0x0 & 0xF));
        lcdSendCommand(setColumnUpper | ((0x0 >> 4) & 0xF));
        lcdSendCommand(rmw);
        
        //Iterate through columns per page
        for (uint8_t column = 0; column < 128; ++column) {
            
            lcdSendData(buffer[(128 * page) + column]);
        }
    }
}


void lcdClearBuffer() {
    
    memset(buffer, 0, bufferSize);
}


void lcdRefresh() {
    
    lcdSendBuffer(buffer);
}


void lcdHardwareReset() {
    
    //Hardware reset
    st7565_cs = 0;
    st7565_rst = 0;
    _delay_ms(500);
    st7565_rst = 1;
}


void lcdSendByte(uint8_t byte) {
    
    //Make sure clock starts high
    st7565_scl = 1;
    
    //Send byte from MSB to LSB
    for (int8_t i = 7; i >= 0; --i) {
        
        st7565_scl = 0;
        st7565_sda = (byte & (1 << i) ? 1 : 0); //noch nicht gecheckt...
        st7565_scl = 1;
    }
}


void lcdSendCommand(uint8_t command) {
    
    //Set lcd to command mode
    st7565_a0 = 0;
    
    lcdSendByte(command);
}


void lcdSendData(uint8_t data) {
    
    //Set lcd to data mode
    st7565_a0 = 1;
    
    lcdSendByte(data);
}


void lcdInit() {
    
    //Set lcd pins as outputs
    st7565_cs_ddr = output;
    st7565_rst_ddr = output;
    st7565_a0_ddr = output;
    st7565_scl_ddr = output;
    st7565_sda_ddr = output;
    
    st7565_cs = 1;
    st7565_rst = 1;
    st7565_a0 = 1;
    st7565_scl = 1;
    st7565_sda = 1;
    
    //Reset lcd
    lcdHardwareReset();
    
    //Configure lcd
    lcdSendCommand(setBias9);
    lcdSendCommand(setAdcNormal);
    lcdSendCommand(setComNormal);
    lcdSendCommand(setDispStartLine);
    lcdSendCommand(setPowerControl | 0x04);
    _delay_ms(50);
    lcdSendCommand(setPowerControl | 0x06);
    _delay_ms(50);
    lcdSendCommand(setPowerControl | 0x07);
    _delay_ms(10);
    lcdSendCommand(setResistorRatio | 0x6);
    
    //Turn on lcd
    lcdSendCommand(displayOn);
    lcdSendCommand(setAllPtsNormal);
}


void lcdSetBrightness(uint8_t value) {
    
    lcdSendCommand(setVolumeFirst);
    lcdSendCommand(setVolumeSecond | (value & 0x3f));
}


void lcdSetFont(Font font) {
    
    activeFont = font;
}


void lcdDrawPixel(uint8_t x, uint8_t y) {
    
    if (x >= 128 || y >= 64) {
        
        return;
    } else {
        
        buffer[x + (y / 8) * 128] = (1 << (7 - (y % 8))); //noch nicht gecheckt...
    }
}


void lcdDrawColumn(uint8_t page, uint8_t column) {
    
    if (page >= 8 || column >= 128) {
        
        return;
    } else {
        
        buffer[page * 128 + column] = 0xFF; //wenn probleme vll |=
    }
}


void lcdDrawChar(uint8_t character) {
    
    
}