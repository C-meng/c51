#include "test.h"
#include "key.h"

u8 pwm_v=10;
bit ds1;
u16 pwm_c;

void Timer0Init(void);
void main(void)
{	
	u8 key_v;
	
	Fuck_Init(0,0);//�رշ������̵���
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
�������ܣ���ʱ��0
*************************************************/
void Timer0Init(void)		//1����@11.0592MHz
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x91;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
}

void Timer0() interrupt 1
{
	u16 ds_c;
	TL0 = 0x91;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
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
