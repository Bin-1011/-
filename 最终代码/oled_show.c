#include "global.h"

void OLED_Main(int _switch,u16 freq){
	u8 t,p,w,h;
	t='0'+freq/1000;
	freq=freq%1000;
	p='0'+freq/100;
	freq=freq%100;
	w='0'+freq/10;
	h='0'+freq%10;
	OLED_ShowCHinese(0,2,20);//��
	OLED_ShowCHinese(18,2,21);//��
	OLED_ShowCHinese(36,2,22);//��
	OLED_ShowCHinese(54,2,23);//��
	if(_switch == 0){
		OLED_ShowCHinese(72,2,8);//��
		OLED_ShowCHinese(90,2,24);//��
	}else if(_switch == 1){
		OLED_ShowCHinese(72,2,9);//��
		OLED_ShowCHinese(90,2,25);//��
	}
	OLED_ShowCHinese(0,0,10);//��
	OLED_ShowCHinese(18,0,11);//��
	OLED_ShowCHinese(36,0,12);//Ƶ
	OLED_ShowCHinese(54,0,13);//��
	OLED_ShowChar(72,0,':',16);//:
	OLED_ShowChar(80,0,t,16);
	OLED_ShowChar(88,0,p,16);
	OLED_ShowChar(96,0,w,16);
	OLED_ShowChar(104,0,h,16);
}
	
void OLED_Show(int count){
	u8 t,p;
	t='0'+count/10;
	p='0'+count%10;
	OLED_ShowCHinese(0,0,0);//ʣ
	OLED_ShowCHinese(18,0,1);//��
	OLED_ShowCHinese(36,0,2);//��
	OLED_ShowCHinese(54,0,3);//ҩ
	OLED_ShowCHinese(72,0,4);//��
	OLED_ShowChar(90,0,':',16);//:
	OLED_ShowChar(18,2,t,16);
	OLED_ShowChar(26,2,p,16);
	OLED_ShowString(33,2,"/50",16);
}

/*void OLED_Setting(int *_switch,u16 *freq){
	int select=0;
	OLED_Clear();
	OLED_ShowChar(0,0,'>',16);
	while(cancel == 1){
		if(up == 0 && select != 0){
			select--;
			OLED_Clear();
			OLED_ShowChar(0,0,'>',16);
		}
		else if(down == 0 && select != 1){
			select++;	
			OLED_Clear();
			OLED_ShowChar(0,2,'>',16);
		}
		if(select == 0&&confirm == 0){
			delay_ms(100);
			OLED_Sensor(_switch);
			OLED_Clear();
			OLED_ShowChar(0,0,'>',16);
		}else if(select == 1&&confirm == 0){
			delay_ms(100);
			OLED_Freq(freq);
			OLED_Clear();
			OLED_ShowChar(0,0,'>',16);
		}
			
		
		OLED_ShowCHinese(10,0,5);//��
		OLED_ShowCHinese(28,0,6);//��
		OLED_ShowCHinese(46,0,7);//��
		OLED_ShowCHinese(64,0,8);//��
		OLED_ShowCHinese(82,0,9);//��
		OLED_ShowCHinese(10,2,10);//��
		OLED_ShowCHinese(28,2,11);//��
		OLED_ShowCHinese(46,2,12);//Ƶ
		OLED_ShowCHinese(64,2,13);//��
		OLED_ShowCHinese(82,2,14);//��
		OLED_ShowCHinese(100,2,15);//��
	}
}
*/
void OLED_Sensor(int *_switch){
	int select=0;
	OLED_Clear();
	OLED_ShowChar(0,0,'>',16);
	while(cancel == 1){
		if(up == 0 && select != 0){
			select--;
			OLED_Clear();
			OLED_ShowChar(0,0,'>',16);
		}
		else if(down == 0 && select != 1){
			select++;	
			OLED_Clear();
			OLED_ShowChar(0,2,'>',16);
		}
		OLED_ShowCHinese(28,0,8);//��
		OLED_ShowCHinese(46,0,24);//��
		OLED_ShowCHinese(28,2,9);//��
		OLED_ShowCHinese(46,2,25);//��
		if((*_switch) == 0){
			OLED_ShowChar(90,0,'<',16);
		}else{
			OLED_ShowChar(90,2,'<',16);
		}
		if(select == 0&&confirm==0){
			(*_switch)=0;
			delay_ms(100);
			break;
		}else if(select == 1&&confirm==0){
			(*_switch)=1;
			delay_ms(100);
			break;
		}
	}
	delay_ms(100);
}

void OLED_Freq(u16 *freq){
	u8 t,p,w,h;
	u16 temp;
	OLED_Clear();
	while(cancel == 1){
		temp=(*freq);
		t='0'+temp/1000;
		temp=temp%1000;
		p='0'+temp/100;
		temp=temp%100;
		w='0'+temp/10;
		h='0'+temp%10;
		OLED_ShowCHinese(28,0,10);//��
		OLED_ShowCHinese(46,0,11);//��
		OLED_ShowCHinese(64,0,12);//Ƶ
		OLED_ShowCHinese(82,0,13);//��
		OLED_ShowChar(43,2,t,16);
		OLED_ShowChar(51,2,p,16);
		OLED_ShowChar(59,2,w,16);
		OLED_ShowChar(67,2,h,16);
		if(up == 0){
			(*freq)+=10;
			delay_ms(100);
		}else if(down == 0){
			(*freq)-=10;
			delay_ms(100);
		}
	}
	delay_ms(100);
}