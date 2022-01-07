#include"Serving.h"

//厨师上菜
void Serving(int* foodnumber, int* donefood, string* FoodName)
{
	cout << "以下是今日顾客点菜单\n";
	while (1)
	{
		OutboundDeliveryOrderForChef(foodnumber, donefood, FoodName);
		char ch;
		cout << "更改单个菜品状态请先输入菜品代号，全部上菜请输入 1，退出请输入 0。\n";
		cin >> ch;
		ch = toupper(ch);
		if (ch >= 'A' && ch <= 'P')
		{
			int num;
			cout << "请输入改变数量：\n";
			cin >> num;
			if (num > foodnumber[ch - 'A'] - donefood[ch - 'A'])
			{
				cout << "输入数量超过未做数量！\n";
			}
			else if (num < 0)
			{
				cout << "无效操作！\n";
			}
			else
			{
				donefood[ch - 'A'] += num;
				cout << "正在更新数据\n......\n......\n......\n已更新数据。\n";
			}
		}
		else if (ch == '1')
		{
			cout << "您确定吗？确定请输入 T，取消请输入 F\n";
			cin >> ch;
			ch = toupper(ch);
			if (ch == 'T')
			{
				for (int i = 0; i < 16; i++)
				{
					donefood[i] = foodnumber[i];
				}
			}
			else if (ch == 'F')
			{
				//nothing
			}
			else
			{
				cout << "无效操作！系统已自动取消！\n";
			}
		}
		else if (ch == '0')
		{
			break;
		}
		else
		{
			cout << "无效操作！\n";
		}
	}
}