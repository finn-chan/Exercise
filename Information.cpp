#include"Information.h"

//今日菜品信息
void Information(int* foodnumber, int* totalconsumption, string* FoodName, int* Price)
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