//餐厅点餐结算系统
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include<iomanip>
using namespace std;

//定义菜单以及价格
string FoodName[16] = { "雪花牛扒(A)      " ,"西冷(B)          ","海菇双拼(C)      " ,"泡菜披萨(D)      " ,"海风鲜果披萨(E)  " ,"俄式罗宋汤(F)    " ,"新虾仁法式鲜汤(G)" ,"黑椒牛柳炒意面(H)","韩式海鲜烩意面(I)","王老吉(J)        " ,"果粒橙(K)        ","大椰汁(L)        " ,"大可乐(M)        " ,"劲酒(N)          ","青岛啤酒(O)      ", "江小白(P)        " };
char Name[16] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' };
int Price[16] = { 128,128,98,89,58,40,52,57,48,8,15,20,24,48,12,25 };

//定义菜单
void Menu();

//显示订单号
void DispalyOrderNumber(int* ordernumber);

//显示小票上每道菜的金额
int Amount(char food, char quantity);

//出示小票
int Receipt(char tempfood[][16], int j, int* ordernumber, int* tablenumber, int* peoplenumber);

//支付金额
void Pay(int money);

//记录菜品数量(For Boss)
void NumberOfRecords(char chfood, int* foodnumber);

//今日菜品信息
void Information(int* foodnumber, int* totalconsumption);

//厨师上菜
void Serving(int* foodnumber, int* donefood);

//菜品待做表(For Chef)
void OutboundDeliveryOrderForChef(int* foodnumber, int* donefood);

//菜品待做表（For Cashier）
void OutboundDeliveryOrderForCashier(int* foodnumber, int* donefood);

int main()
{
	int people1 = 1, people2;
	int i, j;		//i 记录每次顾客点菜的数量,j 记录菜品的数量
	int foodnumber[16];		//顾客点菜的菜品总数
	int donefood[16];		//定义已完成的餐品数
	for (int n = 0; n < 16; n++)
	{
		foodnumber[n] = 0;
		donefood[n] = 0;
	}
	char tempfood[2][16];		//顾客点菜时的零时数组，记录菜品以及数量，a[1][x] 为每个菜品的数量
	int ordernumber = 1, tablenumber = 1;		//定义订单号和餐桌号
	int totalconsumption = 0;		//定义今日流水
	int peoplenumber;		//定义单次用餐人数

	while (1)
	{
		cout << "您是？\n顾客点餐请输入 1，工作人员请输入 2，退出请输入 0。\n";
		cin >> people1;
		if (people1 == 1)
		{
			//重置各项数据
			i = 0;
			j = 0;
			for (int n = 0; n < 16; n++)
			{
				tempfood[1][n] = '0';
			}

			cout << "请问一共是几位？\n";
			cin >> peoplenumber;
			cout << "好的\n";

			//顾客点菜
			while (1)		//顾客加菜再次循环
			{
				cout << "这是菜单，请看。\n\n";
				Menu();
				char chfood, ch;

				//将菜品
				for (i;; i++)
				{
					cin >> chfood;
					chfood = toupper(chfood);		//小写字母转换为大写字母
					ch = getchar();

					if (chfood >= 'A' && chfood <= 'P')		//防止误输入其他数组
					{
						NumberOfRecords(chfood, foodnumber);

						//第一道菜直接录入数组
						if (i == 0)
						{
							tempfood[0][i] = chfood;
							tempfood[1][i]++;
							j++;
						}
						else
						{
							int k;
							for (k = 0; k < j; k++)
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
								tempfood[0][j] = chfood;
								tempfood[1][j]++;
								j++;
							}
						}

						if (ch == '\n')
						{
							break;
						}
					}
					else
					{
						i--;
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
			money = Receipt(tempfood, j, &ordernumber, &tablenumber, &peoplenumber);
			totalconsumption += money;

			//支付金额
			Pay(money);
			system("pause");
			system("cls");
		}

		else if (people1 == 2)
		{
			cout << "您是？\n收银员请输入 1，厨师请输入 2，服务员请输入 3，餐厅老板请输入 4，系统管理员请输入 5，退出请输入 0。\n";
			cin >> people2;

			if (people2 == 1)		//收银员
			{
				char ch;
				while (1)
				{
					cout << "查询今日流水请输入 1，查询今日顾客点菜单请输入 2，退出请输入 0。\n";
					cin >> ch;
					if (ch == '1')
					{
						cout << "今日顾客点餐总金额为：" << setw(4) << totalconsumption <<" 元。" << endl;
					}
					else if (ch == '2')
					{
						OutboundDeliveryOrderForCashier(foodnumber, donefood);
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
				system("pause");
				system("cls");
			}

			else if (people2 == 2)		//厨师
			{
				Serving(foodnumber, donefood);
				system("pause");
				system("cls");
			}

			else if (people2 == 3)		//服务员
			{

				system("pause");
				system("cls");
			}

			else if (people2 == 4)		//餐厅老板
			{
				char ch;
				cout << "请问选择您要查询的信息：\n";
				while (1)
				{
					cout << "顾客小票请输入 1，今日菜品信息请输入 2，退出请输入 0。\n";
					cin >> ch;
					if (ch == '1')
					{

					}
					else if (ch == '2')
					{
						cout << "以下是今日菜品信息\n";
						Information(foodnumber, &totalconsumption);
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
				system("cls");
			}

			else if (people2 == 5)		//系统管理员
			{

				system("pause");
				system("cls");
			}

			else
			{
				break;
			}
		}

		else
		{
			break;
		}
	}
	return 0;
}

//定义菜单
void Menu()
{
	cout << "------------------------------\n";
	cout << "|            菜单            |\n";
	cout << "| *牛排类                    |\n";
	cout << "|   雪花牛扒(A)       128 元 |\n";
	cout << "|   西冷(B)           128 元 |\n";
	cout << "|   海菇双拼(C)        98 元 |\n";
	cout << "|                            |\n";
	cout << "| *披萨                      |\n";
	cout << "|   泡菜披萨(D)        89 元 |\n";
	cout << "|   海风鲜果披萨(E)    58 元 |\n";
	cout << "|                            |\n";
	cout << "| *汤类                      |\n";
	cout << "|   俄式罗宋汤(F)      40 元 |\n";
	cout << "|   新虾仁法式鲜汤(G)  52 元 |\n";
	cout << "|                            |\n";
	cout << "| *意面                      |\n";
	cout << "|   黑椒牛柳炒意面(H)  57 元 |\n";
	cout << "|   韩式海鲜烩意面(I)  48 元 |\n";
	cout << "|                            |\n";
	cout << "| *饮料/酒水                 |\n";
	cout << "|   王老吉(J)           8 元 |\n";
	cout << "|   果粒橙(K)          15 元 |\n";
	cout << "|   大椰汁(L)          20 元 |\n";
	cout << "|   大可乐(M)          24 元 |\n";
	cout << "|   劲酒(N)            48 元 |\n";
	cout << "|   青岛啤酒(O)        12 元 |\n";
	cout << "|   江小白(P)          25 元 |\n";
	cout << "|                            |\n";
	cout << "|请输入菜品后对应的字母      |\n";
	cout << "|菜品间输入空格，最后回车结束|\n";
	cout << "------------------------------\n";

}

//显示订单号
void DispalyOrderNumber(int* ordernumber)
{
	time_t tt = time(NULL);
	tm* t = localtime(&tt);
	printf("%d%02d%02d%04d",
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		*ordernumber);
	(*ordernumber)++;
}

//显示小票上每道菜的金额
int Amount(char food, char quantity)
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

//出示小票
int Receipt(char tempfood[][16], int j, int* ordernumber, int* tablenumber, int* peoplenumber)
{
	int sumamount = 0;
	cout << "------------------------------------------------\n";
	cout << "|                   小票                       |\n";

	cout << "| 订单号：                    ";
	DispalyOrderNumber(&*ordernumber);
	cout << "     |\n";

	cout << "| 餐桌号：                            ";
	printf("%04d", *tablenumber);
	(*tablenumber)++;
	if (*tablenumber == 21)
	{
		*tablenumber = 1;
	}
	cout << "     |\n";

	cout << "|                                              |\n";
	cout << "| 菜名                数量（份）  金额（元）   |\n";

	for (int i = 0; i < j; i++)
	{
		cout << "|    " << FoodName[tempfood[0][i] - 'A'] << "      " << setw(2) << tempfood[1][i] << "        " << setw(4) << Amount(tempfood[0][i], tempfood[1][i]) << "     |\n";
		sumamount += Amount(tempfood[0][i], tempfood[1][i]);
	}

	if (sumamount < 500)
	{
		cout << "|                                              |\n";
		cout << "| 餐位费                    " << setw(2) << *peoplenumber << "         " << setw(3) << *peoplenumber * 10 << "     |\n";		//餐位费每人 10 元
		sumamount += (*peoplenumber * 10);
	}
	cout << "|                                              |\n";
	cout << "| 总额                                ";
	cout << setw(4) << sumamount;
	cout << "     |" << endl;
	cout << "------------------------------------------------\n\n";
	cout << "本次消费 " << sumamount << " 元，请输入金额以支付\n";
	return sumamount;
}

//支付金额
void Pay(int money)
{
	int m;
	while (1)
	{
		cin >> m;
		if (m > money)
		{
			cout << "感谢用餐，这是您的找零，一共是 " << m - money << " 元，请收好。\n\n";
			break;
		}
		else if (m == money)
		{
			cout << "感谢用餐，祝您生活愉快！\n\n";
			break;
		}
		else if (m > 0 && m < money)
		{
			cout << "还有 " << money - m << " 元未支付，请继续输入。\n";
			money -= m;
		}
		else if (m <= 0)
		{
			cout << "先生不要开玩笑，请您输入。\n";
		}
	}
}

//记录菜品数量(For Boss)
void NumberOfRecords(char chfood, int* foodnumber)
{
	(foodnumber[chfood - 'A'])++;
}

//今日菜品信息
void Information(int* foodnumber, int* totalconsumption)
{
	int sumamount = 0;
	cout << "------------------------------------------------\n";
	cout << "|                 今日菜品信息                 |\n";
	cout << "|                                              |\n";
	cout << "| 菜名                数量（份）  金额（元）   |\n";
	for (int n = 0; n < 16; n++)
	{
		if (n == 3 || n == 5 || n == 7 || n == 9)
		{
			cout << "|                                              |\n";
		}
		cout << "|    ";
		cout << FoodName[n] << "      " << setw(2) << foodnumber[n] << "        " << setw(4) << foodnumber[n] * Price[n] << "     |\n";
		sumamount += foodnumber[n] * Price[n];
	}
	cout << "|                                              |\n";
	cout << "| 餐位费                              " << setw(4) << *totalconsumption - sumamount << "     |\n";
	cout << "|                                              |\n";
	cout << "| 总额                                ";
	cout << setw(4) << *totalconsumption;
	cout << "     |" << endl;
	cout << "------------------------------------------------\n\n";
}

//厨师出菜
void Serving(int* foodnumber, int* donefood)
{
	cout << "以下是今日顾客点菜单\n";
	while (1)
	{
		OutboundDeliveryOrderForChef(foodnumber, donefood);
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

//菜品待做表（For Chef）
void OutboundDeliveryOrderForChef(int* foodnumber, int* donefood)
{
	cout << "--------------------------------------------------------------\n";
	cout << "|                          出菜单                            |\n";
	cout << "|                                                            |\n";
	cout << "| 菜品                未做（份）  已做（份）    总共（份）   |\n";
	for (int i = 0; i < 16; i++)
	{
		if (i == 3 || i == 5 || i == 7 || i == 9)
		{
			cout << "|                                                            |\n";
		}
		cout << "|    " << FoodName[i] << "     " << setw(2) << foodnumber[i] - donefood[i] << "          " << setw(3) << donefood[i] << "           " << setw(3) << foodnumber[i] << "     |\n";
	}
	cout << "--------------------------------------------------------------\n\n";
}

//菜品待做表（For Cashier）
void OutboundDeliveryOrderForCashier(int* foodnumber, int* donefood)
{
	int sum = 0;
	cout << "--------------------------------------------------------------\n";
	cout << "|                          出菜单                            |\n";
	cout << "|                                                            |\n";
	cout << "| 菜品                单价（元）  已做（份）    总额（元）   |\n";
	for (int i = 0; i < 16; i++)
	{
		if (i == 3 || i == 5 || i == 7 || i == 9)
		{
			cout << "|                                                            |\n";
		}
		cout << "|    " << FoodName[i] << "    " << setw(3) << Price[i] << "          " << setw(3) << donefood[i] << "          " << setw(4) << Price[i] * donefood[i] << "     |\n";
		sum += Price[i] * donefood[i];
	}
	cout << "|                                                            |\n";
	cout << "| 总额                                              " << setw(4) << sum << "     |\n";
	cout << "--------------------------------------------------------------\n\n";
}