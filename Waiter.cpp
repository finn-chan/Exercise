#include"Waiter.h"

//服务员
void Waiter(int* tablenumber)
{
	if (*tablenumber == 0)
	{
		cout << "没有需要服务的客户。\n";
		system("pause");
	}
	else
	{
		while (1)
		{
			int n;
			cout << "请选择要服务的客户的编号（1 ~ " << *tablenumber << "），退出请输入 0。\n";
			cin >> n;
			if (n >= 1 && n <= *tablenumber)
			{
				ReadReceipt(n);
				char ch;
				cout << "我们正在准备您的菜肴，需要我去问问主厨吗？\n";
				cout << "去催一下请输入 Y/y，不用谢谢请输入 N/n\n";
				cin >> ch;
				ch = toupper(ch);
				if (ch == 'Y')
				{
					cout << "好的，我这就去后厨，请稍等\n";
					break;
				}
				else if (ch == 'N')
				{
					cout << "好的，祝您用餐愉快！\n\n";
				}
			}
			else if (n == 0)
			{
				break;
			}
			else
			{
				cout << "输入错误！\n";
			}
		}
	}
}