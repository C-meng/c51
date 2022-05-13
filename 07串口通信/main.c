#include "test.h"

void UartInit(void);

void main(void)
{
	Fuck_Init(0,0);//关闭蜂鸣器继电器
	UartInit();//串口初始化
	Led_Init(0x7f);
}

void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0xE0;		//设定定时初值
	TH1 = 0xFE;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA = 1;
}

void Uart(void) interrupt 4
{
	u8 a;
	a = SBUF;
	Led_Init(a);
	RI = 0;
	SBUF =01;
	while(!TI);			 
	TI=0;
}