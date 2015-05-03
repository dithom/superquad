#ifndef superquad_ioConfig_h
#define superquad_ioConfig_h

#include "registerBit.h"

//General
#define input 0
#define output 1

//ST7565 LCD
#define st7565_cs_ddr registerBit(DDRD, 5)
#define st7565_rst_ddr registerBit(DDRD, 6)
#define st7565_a0_ddr registerBit(DDRD, 7)
#define st7565_scl_ddr registerBit(DDRD, 4)
#define st7565_sda_ddr registerBit(DDRD, 1)

#define st7565_cs registerBit(PORTD, 5)
#define st7565_rst registerBit(PORTD, 6)
#define st7565_a0 registerBit(PORTD, 7)
#define st7565_scl registerBit(PORTD, 4)
#define st7565_sda registerBit(PORTD, 1)

#endif
