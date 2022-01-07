#include"Cashier.h"

//收银员
void Cashier(int* totalconsumption, int* foodnumber, int* donefood, string* FoodName, int* Price)
{
	char ch;
	while (1)
	{
		cout << "查询今日流水请输入 1，查询今日顾客点菜单请输入 2，退出请输入 0。\n";
		cin >> ch;
		if (ch == '1')
		{
			cout << "今日顾客点餐总金额为：" << setw(4) << *totalconsumption << " 元。" << endl;
		}
		else if (ch == '2')
		{
			OutboundDeliveryOrderForCashier(foodnumber, donefood, FoodName, Price);
		}
		else if (ch == '0')
		{
			break;
		}
		else
		{
			cout << "输入错误，请重新输入！\n";
		}
	}

}