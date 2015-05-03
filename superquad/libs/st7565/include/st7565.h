#ifndef superquad_st7565_h
#define superquad_st7565_h

#include <stdio.h>
#include "fonts.h"

//Display buffer
#define bufferSize (128 * 64 / 8)

//Commands
#define displayOff 0xAE
#define displayOn 0xAF
#define setDispStartLine 0x40
#define setPage 0xB0
#define setColumnUpper 0x10
#define setColumnLower 0x00
#define setAdcNormal 0xA0
#define setAdcReverse 0xA1
#define setDispNormal 0xA6
#define setDispReverse 0xA7
#define setAllPtsNormal 0xA4
#define setAllPtsOn 0xA5
#define setBias9 0xA2
#define setBias7 0xA3
#define rmw 0xE0
#define rmwClear 0xEE
#define internalReset 0xE2
#define setComNormal 0xC0
#define setComReverse 0xC8
#define setPowerControl 0x28
#define setResistorRatio 0x20
#define setVolumeFirst 0x81
#define setVolumeSecond 0
#define setStaticOff 0xAC
#define setStaticOn 0xAD
#define setStaticReg 0x0
#define setBoosterFirst 0xF8
#define setBooster234 0
#define setBooster5 1
#define setBooster6 3
#define nop 0xE3
#define test 0xF0


//Methods
void lcdSendBuffer(uint8_t);
void lcdClearBuffer();
void lcdRefresh();
void lcdHardwareReset();
void lcdSendByte(uint8_t);
void lcdSendCommand(uint8_t);
void lcdSendData(uint8_t );
void lcdInit();
void lcdSetBrightness(uint8_t);
void lcdSetFont(Font);
void lcdDrawPixel(uint8_t, uint8_t);
void lcdDrawColumn(uint8_t, uint8_t);
void lcdDrawChar(uint8_t);


#endif
