#include"Amount.h"

//显示小票上每道菜的金额
int Amount(char food, char quantity, char* Name, int* Price)
{
	for (int i = 0; i < 16; i++)
	{
		if (food == Name[i])
		{
			return Price[i] * (quantity - '0');
		}
	}
	return 0;
}