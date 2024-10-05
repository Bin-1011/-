#include "global.h"

void main(void)
{
	int led_count = 0;
	int count = 50;
	int selected = 0;
	int sensor_switch = 0;
	u16 frequency = 100;
	P0M1 = 0;	P0M0 = 0;	//设置为准双向口
	P1M1 = 0;	P1M0 = 0;	//设置为准双向口
	P2M1 = 0;	P2M0 = 0;	//设置为准双向口
	P3M1 = 0;	P3M0 = 0;	//设置为准双向口
	P4M1 = 0;	P4M0 = 0;	//设置为准双向口
	P5M1 = 0;	P5M0 = 0;	//设置为准双向口
	P6M1 = 0;	P6M0 = 0;	//设置为准双向口 
	P7M1 = 0;	P7M0 = 0;	//设置为准双向口
	delay_ms(100);
	LCDInit(); //LCM初始化
	OLED_Init();			//初始化OLED  
	OLED_Clear();
	LCDClear();
	while(1){
		sensor(sensor_switch,&led_count,frequency,&count);
		OLED_Main(sensor_switch,frequency);
		choose(&selected);
		lcd_mainUI(selected);
		if(confirm == 0){
			LCDClear();
			OLED_Clear();
			if(selected != 3)
				OLED_Show(count);
			delay_ms(100);	
			while(cancel == 1){
				lcd_func(selected,&sensor_switch,&frequency);
				if(confirm == 0){
					led_func(selected,&led_count,&count,frequency);
				}
			}
			OLED_Clear();
		}
	}
}


void choose(int *sel){
	if(up == 0 && (*sel) != 0){
			(*sel)--;
			LCDClear();
		}
		else if(down == 0 && (*sel) != 3){
			(*sel)++;	
			LCDClear();
		}
}