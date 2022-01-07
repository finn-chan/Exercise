#include"Pay.h"

//支付金额
void Pay(int* money)
{
	int m;
	while (1)
	{
		cin >> m;
		if (m > *money)
		{
			cout << "感谢用餐，这是您的找零，一共是 " << m - *money << " 元，请收好。\n\n";
			break;
		}
		else if (m == *money)
		{
			cout << "感谢用餐，祝您生活愉快！\n\n";
			break;
		}
		else if (m > 0 && m < *money)
		{
			cout << "还有 " << *money - m << " 元未支付，请继续输入。\n";
			*money -= m;
		}
		else if (m <= 0)
		{
			cout << "先生不要开玩笑，请您输入。\n";
		}
	}
}