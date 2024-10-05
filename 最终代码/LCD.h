#include	"delay.h"

sbit	LCD_RS = P4^0;     //��������
sbit	LCD_RW = P4^1;
sbit	LCD_E  = P4^2;
sbit	PSB    = P4^3;		//PSB��Ϊ12864-12ϵ�еĴ�����ͨѶ�����л�������ʹ��8λ���нӿڣ�PSB=1
sbit	LCD_RESET	=	P4^4;	//	17---RESET	L-->Enable
#define	LCD_Data P6
#define Busy    0x80 //���ڼ��LCD״̬���е�Busy��ʶ
void WriteDataLCD(u8 WDLCD);
void WriteCommandLCD(u8 WCLCD,BuysC);
u8 ReadDataLCD(void);
u8 ReadStatusLCD(void);
void LCDInit(void);
void LCDClear(void);
void LCDFlash(void);
void DisplayOneChar(u8 X, u8 Y, u8 DData);
void DisplayListChar(u8 X, u8 Y, u8 code *DData);
//void DisplayImage (u8 code *DData);
void lcd_mainUI(int selected);
void lcd_single(void);
void lcd_double(void);
void lcd_flu(void);
void lcd_settingUI(int selected);
void lcd_setting(int *_switch,u16 *freq);
void lcd_func(int selected,int *_switch,u16 *freq);