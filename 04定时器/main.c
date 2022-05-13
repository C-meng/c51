#include "test.h"

u8 num;

void Timer0Init(void);
void main(void)
{
	Fuck_Init(0,0);//关闭蜂鸣器继电器
	Timer0Init();
	while(1)
	{
		Ds_Init(num);
	}
}
/*************************************************
函数功能：定时器0
*************************************************/
void Timer0Init(void)		//1毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
}

void Timer0() interrupt 1
{
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
}
