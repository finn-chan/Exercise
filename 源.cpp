//餐厅点餐结算系统
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Amount.h"
#include"Boss.h"
#include"Cashier.h"
#include"Customer.h"
#include"DispalyOrderNumber.h"
#include"Information.h"
#include"Menu.h"
#include"NumberOfRecords.h"
#include"OutboundDeliveryOrderForCashier.h"
#include"OutboundDeliveryOrderForChef.h"
#include"Pay.h"
#include"ReadReceipt.h"
#include"RecordReceipt.h"
#include"Serving.h"
#include"ShowReceipt.h"
#include"Waiter.h"

using namespace std;

//定义菜单以及价格
string FoodName[16] = { "雪花牛扒(A)      " ,"西冷(B)          ","海菇双拼(C)      " ,"泡菜披萨(D)      " ,"海风鲜果披萨(E)  " ,"俄式罗宋汤(F)    " ,"新虾仁法式鲜汤(G)" ,"黑椒牛柳炒意面(H)","韩式海鲜烩意面(I)","王老吉(J)        " ,"果粒橙(K)        ","大椰汁(L)        " ,"大可乐(M)        " ,"劲酒(N)          ","青岛啤酒(O)      ", "江小白(P)        " };
char Name[16] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' };
int Price[16] = { 128,128,98,89,58,40,52,57,48,8,15,20,24,48,12,25 };

int main()
{
	char people1, people2;
	int i, j;		//i 记录每次顾客点菜的数量,j 记录菜品的数量
	int foodnumber[16];		//顾客点菜的菜品总数
	int donefood[16];		//定义已完成的餐品数
	for (int n = 0; n < 16; n++)
	{
		foodnumber[n] = 0;
		donefood[n] = 0;
	}
	char tempfood[2][16];		//顾客点菜时的零时数组，记录菜品以及数量，tempfood[1][x] 为每个菜品的数量
	int ordernumber = 0, tablenumber = 0;		//定义订单号和餐桌号
	int totalconsumption = 0;		//定义今日流水
	int peoplenumber;		//定义单次用餐人数

	while (1)
	{
		cout << "您是？\n顾客点餐请输入 1，工作人员请输入 2，退出请输入 0。\n";
		cin >> people1;
		if (people1 == '1')	//顾客
		{
			Customer(&i, &j, tempfood, foodnumber, &ordernumber, &tablenumber, &peoplenumber, &totalconsumption, FoodName, Name, Price);

			system("pause");
			system("cls");
		}

		else if (people1 == '2')
		{
			cout << "您是？\n收银员请输入 1，厨师请输入 2，服务员请输入 3，餐厅老板请输入 4，系统管理员请输入 5，退出请输入 0。\n";
			cin >> people2;

			if (people2 == '1')		//收银员
			{
				Cashier(&totalconsumption, foodnumber, donefood, FoodName, Price);

				system("cls");
			}

			else if (people2 == '2')		//厨师
			{
				Serving(foodnumber, donefood, FoodName);
				system("cls");
			}

			else if (people2 == '3')		//服务员
			{
				Waiter(&tablenumber);

				system("cls");
			}

			else if (people2 == '4')		//餐厅老板
			{
				Boss(&tablenumber, &totalconsumption, foodnumber, FoodName, Price);

				system("cls");
			}

			else if (people2 == '5')		//系统管理员
			{
				Boss(&tablenumber, &totalconsumption, foodnumber, FoodName, Price);

				system("pause");
				system("cls");
			}

			else if (people2 == '0')
			{
				break;
			}
		}

		else if (people1 == '0')
		{
			break;
		}
	}
	return 0;
}