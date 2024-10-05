#include "global.h"

u8 code _sin[] = {"单发点火"};
u8 code _dou[] = {"双发点火"};
u8 code _flu[] = {"连发点火"};
u8 code _set[] = {"其他设置"};
u8 code _sch[] = {"红外传感开关"};
u8 code _frq[] = {"发射频率调节"};
//u8 code _sen[] = {"传感器触发射击"};
u8 code select_l[] = {0XA1,0XFA};
//u8 code select_r[] = {0XA1,0XFB};

void lcd_func(int selected,int *_switch,u16 *freq){
	switch(selected){
		case 0:
			lcd_single();
			break;
		case 1:
			lcd_double();
			break;
		case 2:				
			lcd_flu();
			break;
		case 3:
			lcd_setting(_switch,freq);
			LCDClear();
			break;
	}

}


void lcd_mainUI(int selected){
	DisplayListChar(1,selected+1,select_l);
	DisplayListChar(2,1,_sin);	//单发点火
	DisplayListChar(2,2,_dou);	//双发点火
	DisplayListChar(2,3,_flu);	//连发点火
	DisplayListChar(2,4,_set);	//
	delay_ms(50);
}

void lcd_single(void){
	DisplayListChar(2,1,_sin);	
	delay_ms(50);
}

void lcd_double(void){
	DisplayListChar(2,1,_dou);
	delay_ms(50);
}
void lcd_flu(void){
	DisplayListChar(2,1,_flu);
	delay_ms(50);
}


void lcd_settingUI(int selected){
	DisplayListChar(1,selected+3,select_l);
	DisplayListChar(2,1,_set);
	DisplayListChar(2,3,_sch);
	DisplayListChar(2,4,_frq);
	delay_ms(50);
}

void lcd_setting(int *_switch,u16 *freq){
	int sel = 0;
	while(cancel == 1){
		OLED_Main(*_switch,*freq);
		if(up == 0 && sel!= 0){
			sel--;
			LCDClear();
		}
		else if(down == 0 && sel != 1){
			sel++;	
			LCDClear();
		}
		lcd_settingUI(sel);
		if(confirm == 0){
			delay_ms(50);
			LCDClear();
			switch(sel){
				case 0:
					DisplayListChar(1,1,_sch);
					OLED_Sensor(_switch);
					OLED_Clear();
					LCDClear();
					break;
				case 1:
					DisplayListChar(1,1,_frq);
					OLED_Freq(freq);
					OLED_Clear();
					LCDClear();
					break;
			}
		}
	}
}

