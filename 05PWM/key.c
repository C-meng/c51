#include "key.h"

/*************************************************
函数功能：10ms延时
*************************************************/
void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}


/*************************************************
函数功能：独立按键
*************************************************/
u8 Key_Init(void)
{
	u8 key_num;
	
	key_num = 0;
	
	S7 = 1;S6 = 1;S5 = 1;S4 = 1;
	
	if(S7 != 1){Delay10ms();if(S7 != 1){key_num = 7;while(S7 != 1);}}
	if(S6 != 1){Delay10ms();if(S6 != 1){key_num = 6;while(S6 != 1);}}
	if(S5 != 1){Delay10ms();if(S5 != 1){key_num = 5;while(S5 != 1);}}
	if(S4 != 1){Delay10ms();if(S4 != 1){key_num = 4;while(S4 != 1);}}
	
	return key_num;
}

//u8 Key_Init(void)
//{
//	u8 key_num;
//	
//	ha1 = 1;ha2 = 1;ha3 = 1;ha4 = 1;
//	li1 = 0;li2 = 0;li3 = 0;li4 = 0;
//	
//	if((ha1 != 1)||(ha2 != 1)||(ha3 != 1)||(ha4 != 1))
//	{
//		Delay10ms();
//		if(ha1 != 1)key_num = 7;
//		else if(ha2 != 1)key_num = 6;
//		else if(ha3 != 1)key_num = 5;
//		else if(ha4 != 1)key_num = 4;
//		
//		ha1 = 0;ha2 = 0;ha3 = 0;ha4 = 0;
//		li1 = 1;li2 = 1;li3 = 1;li4 = 1;
//		
//		if(li1 != 1)key_num += 0;
//		else if(li2 != 1)key_num += 4;
//		else if(li3 != 1)key_num += 8;
//		else if(li4 != 1)key_num += 12;
//		
//		while((li1 != 1)||(li2 != 1)||(li3 != 1)||(li4 != 1));
//	}
//	return key_num;
//}