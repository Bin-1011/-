#ifndef GLOBAL_H
#define GLOBAL_H
#include "LED.h"
#include "LCD.h"
#include "oled.h"
#define button P2	
sbit up = P2^4;
sbit down = P2^5;
sbit confirm = P2^6;
sbit cancel = P2^7;
void sensor(int _switch,int *led_count,u16 freq,int *count);
void choose(int *sel);
#endif