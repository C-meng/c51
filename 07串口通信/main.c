#include "test.h"

void UartInit(void);

void main(void)
{
	Fuck_Init(0,0);//�رշ������̵���
	UartInit();//���ڳ�ʼ��
	Led_Init(0x7f);
}

void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��1ʱ��ΪFosc,��1T
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ
	TL1 = 0xE0;		//�趨��ʱ��ֵ
	TH1 = 0xFE;		//�趨��ʱ��ֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
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