#include "test.h"
#include "key.h"

void main(void)
{
	u8 key_v;
	
	Fuck_Init(0,0);//�رշ������̵���
	while(1)
	{
		key_v = Key_Init();
		Ds_Init(key_v);
	}
}