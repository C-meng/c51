#include "test.h"

u8 code wei[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
u8 code dua[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0xff};
						 //   0    1    2    3    4    5    6    7    8    9   全灭

/*************************************************
函数功能：1ms延时
*************************************************/
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}


/*************************************************
函数功能：
				定义蜂鸣器继电器工作状态
				i = 0蜂鸣器关闭
				j = 0继电器关闭
*************************************************/
void Fuck_Init(bit i,bit j)
{
	buzz = i;
	realy = j;
	P2 = Y5;
	P2 = Yc;
}
/*************************************************
函数功能：数码管显示
*************************************************/
void Ds_Init(u8 a)
{
	u8 i;
	
	P0 = 0xff;
	P2 = Y7;
	P2 = Yc;
	
	P0 = wei[i];
	P2 = Y6;
	P2 = Yc;
	
	P0 = ds[i];
	P2 = Y7;
	P2 = Yc;
	
	ds[0] = ~dua[a/10];
	ds[1] = ~dua[a%10];
	ds[2] = ~dua[10];
	ds[3] = ~dua[10];
	ds[4] = ~dua[10];
	ds[5] = ~dua[10];
	ds[6] = ~dua[10];
	ds[7] = ~dua[10];
	i++;
	if(i >= 8)
		i = 0;
	Delay1ms();
}
