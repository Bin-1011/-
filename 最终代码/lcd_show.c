#include "global.h"

u8 code _sin[] = {"�������"};
u8 code _dou[] = {"˫�����"};
u8 code _flu[] = {"�������"};
u8 code _set[] = {"��������"};
u8 code _sch[] = {"���⴫�п���"};
u8 code _frq[] = {"����Ƶ�ʵ���"};
//u8 code _sen[] = {"�������������"};
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
	DisplayListChar(2,1,_sin);	//�������
	DisplayListChar(2,2,_dou);	//˫�����
	DisplayListChar(2,3,_flu);	//�������
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

