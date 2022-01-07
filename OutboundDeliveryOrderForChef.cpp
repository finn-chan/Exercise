#include"OutboundDeliveryOrderForChef.h"

//菜品待做表（For Chef）
void OutboundDeliveryOrderForChef(int* foodnumber, int* donefood, string* FoodName)
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