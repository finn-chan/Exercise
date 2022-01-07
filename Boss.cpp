#include"Boss.h"

//餐厅老板
void Boss(int* tablenumber, int* totalconsumption, int* foodnumber, string* FoodName, int* Price)
{
	char ch;
	while (1)
	{
		cout << "请问选择您要查询的信息：\n";
		cout << "顾客小票请输入 1，今日菜品信息请输入 2，退出请输入 0。\n";
		cin >> ch;
		if (ch == '1')
		{
			if (*tablenumber == 0)
			{
				cout << "没有顾客小票信息！\n";
			}
			else
			{
				int n;
				cout << "请输入要查询的顾客小票编号（1 ~ " << *tablenumber << " )\n";
				cin >> n;
				if (n >= 1 && n <= *tablenumber)
				{
					ReadReceipt(n);
				}
				else
				{
					cout << "输入错误！\n";
				}
			}
		}
		else if (ch == '2')
		{
			cout << "以下是今日菜品信息\n";
			Information(foodnumber, &*totalconsumption, FoodName, Price);
			cout << "继续查询请输入 1，退出请输入 0。\n";		//还未考虑使用者输入其他字符
			cin >> ch;
			if (ch == '0')
			{
				break;
			}
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