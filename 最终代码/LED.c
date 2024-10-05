#include "global.h"

/******************** µ¥·¢µã»ð **************************/
void led_single(int *led_count,u16 freq){
	unsigned char led_state = 0X01;
	led_state <<= (*led_count);
	LED = ~led_state;
	if(((*led_count)++) == 7){
		(*led_count) = 0;
	}
	delay_ms(freq);
	LED = 0XFF;
}

void led_func(int selected,int *led_count,int *count,u16 freq){
	int i;
	OLED_Clear();
	switch(selected){
		case 0:				
			OLED_Show(*count);	
			if(*count>0){
				led_single(led_count,freq);
				(*count)--;
			}
			break;
		case 1:				
			for(i = 0;i < 2;i++){
				OLED_Show(*count);
				if(*count>0){
					led_single(led_count,freq);
					(*count)--;
				}
			}
			break;
		case 2:				
			while(*count>0 && cancel == 1){
				OLED_Show(*count);
				led_single(led_count,freq);
				(*count)--;
			}
			delay_ms(100);
			break;
		case 3:
			break;
	}
}