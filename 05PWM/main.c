#include "test.h"
#include "key.h"

u8 pwm_v=10;
bit ds1;
u16 pwm_c;

void Timer0Init(void);
void main(void)
{	
	u8 key_v;
	
	Fuck_Init(0,0);//关闭蜂鸣器继电器
	Timer0Init();
	while(1)
	{
		if(ds1)
		{
			ds1 = 0;
			Ds_Init(pwm_v);
			
		}
		key_v = Key_Init();
		switch(key_v)
		{
			case 7:pwm_v += 10;break;
			case 6:pwm_v -= 10;break;
		}
		if((pwm_v>=100)||(pwm_v<=0))
			pwm_v = 10;
	}
}
/*************************************************
函数功能：定时器0
*************************************************/
void Timer0Init(void)		//1毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x91;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
}

void Timer0() interrupt 1
{
	u16 ds_c;
	TL0 = 0x91;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	pwm_c++;
	if(pwm_c >= 100)pwm_c = 0;
	if(pwm_c >= pwm_v)pwm = 0;
	else pwm = 1;
	
	if(ds_c++ >= 100)
	{
		ds_c = 0;
		ds1 = 1;
	}
	
}
