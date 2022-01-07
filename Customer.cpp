#include"Customer.h"

//顾客
void Customer(int* i, int* j, char(*tempfood)[16], int* foodnumber, int* ordernumber, int* tablenumber, int* peoplenumber, int* totalconsumption, string* FoodName, char* Name, int* Price)
{
	//重置各项数据
	*i = 0;
	*j = 0;
	for (int n = 0; n < 16; n++)
	{
		tempfood[1][n] = '0';
	}
	(*ordernumber)++;
	(*tablenumber)++;
	if (*tablenumber == 21)
	{
		*tablenumber = 1;
	}

	cout << "请问一共是几位？\n";
	cin >> *peoplenumber;
	cout << "好的\n";

	//顾客点菜
	while (1)		//顾客加菜再次循环
	{
		cout << "这是菜单，请看。\n\n";
		Menu();
		char chfood, ch;

		//将菜品
		for (*i;; (*i)++)
		{
			cin >> chfood;
			chfood = toupper(chfood);		//小写字母转换为大写字母
			ch = getchar();

			if (chfood >= 'A' && chfood <= 'P')		//防止误输入其他数组
			{
				NumberOfRecords(chfood, &*foodnumber);

				//第一道菜直接录入数组
				if (*i == 0)
				{
					tempfood[0][*i] = chfood;
					tempfood[1][*i]++;
					(*j)++;
				}
				else
				{
					int k;
					for (k = 0; k < *j; k++)
					{
						//判断是否为新的菜品
						if (chfood == tempfood[0][k])
						{
							tempfood[1][k]++;
							k = -1;
							break;
						}
					}
					//新建一项菜品									
					if (k != -1)
					{
						tempfood[0][*j] = chfood;
						tempfood[1][*j]++;
						(*j)++;
					}
				}

				if (ch == '\n')
				{
					break;
				}
			}
			else
			{
				(*i)--;
				if (ch == '\n')
				{
					break;
				}
			}
		}

		cout << "请稍等\n......\n......\n......\n";
		cout << "以上是您点的全部菜品，慢慢享用。\n";
	a:;
		cout << "\n还需要菜单吗？\n还需点菜请输入 Y/y，即刻享用请输入 N/n。\n";
		char choose;
		cin >> choose;
		choose = toupper(choose);
		if (choose == 'Y')
		{
			continue;
		}
		else if (choose == 'N')
		{
			break;
		}
		else	//用户输入了其他的字符
		{
			cout << "嗯...?";
			goto a;
		}
	}

	cout << "祝您享用愉快。\n\n结账请输入 C/c。\n";
	char choose;
	while (1)
	{
		cin >> choose;
		choose = toupper(choose);
		if (choose == 'C')
		{
			break;
		}
		else if (choose != 'C')
		{
			cout << "请您慢慢享用。\n\n结账请输入 C/c。\n";
			continue;
		}
	}

	//出示小票
	cout << "这是您的小票，请看：\n\n";
	int money;
	money = ShowReceipt(tempfood, &*j, &*ordernumber, &*tablenumber, &*peoplenumber, FoodName, Name, Price);
	*totalconsumption += money;

	//支付金额
	Pay(&money);
}