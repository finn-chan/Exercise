#include"OutboundDeliveryOrderForCashier.h"

//菜品待做表（For Cashier）
void OutboundDeliveryOrderForCashier(int* foodnumber, int* donefood, string* FoodName, int* Price)
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