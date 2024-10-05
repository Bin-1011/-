#include "delay.h"
#ifndef __OLED_H
#define __OLED_H			  	 



#define  u8 unsigned char 
#define  u32 unsigned int
	
#define  OLED_CMD  0	//д����
#define  OLED_DATA 1	//д����

sbit OLED_SCL=P1^4;//ʱ��CLK 
sbit OLED_SDIN=P1^3;//����MOSI

#define OLED_SCLK_Clr() OLED_SCL=0
#define OLED_SCLK_Set() OLED_SCL=1

#define OLED_SDIN_Clr() OLED_SDIN=0
#define OLED_SDIN_Set() OLED_SDIN=1


//OLED�����ú���
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size2);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 size2);	 
void OLED_Set_Pos(u8 x, u8 y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
//void OLED_DrawBMP(u8 x0, u8 y0,u8 x1, u8 y1,u8 BMP[]);
void OLED_Show(int count);
//void OLED_Setting(int *_switch,u16 *freq);
void OLED_Sensor(int *_switch);
void OLED_Freq(u16 *freq);
void OLED_Main(int _switch,u16 freq);
#endif  
	 



