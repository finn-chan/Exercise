#include"ShowReceipt.h"

//出示小票
int ShowReceipt(char(*tempfood)[16], int* j, int* ordernumber, int* tablenumber, int* peoplenumber, string* FoodName, char* Name, int* Price)
{
	int sumamount = 0;
	cout << "------------------------------------------------\n";
	cout << "|                   小票                       |\n";

	cout << "| 订单号：                    ";
	DispalyOrderNumber(&*ordernumber);
	cout << "     |\n";

	cout << "| 餐桌号：                            ";
	printf("%04d", *tablenumber);
	cout << "     |\n";

	cout << "|                                              |\n";
	cout << "| 菜名                数量（份）  金额（元）   |\n";

	for (int i = 0; i < *j; i++)
	{
		cout << "|    " << FoodName[tempfood[0][i] - 'A'] << "      " << setw(2) << tempfood[1][i] << "        " << setw(4) << Amount(tempfood[0][i], tempfood[1][i], Name, Price) << "     |\n";
		sumamount += Amount(tempfood[0][i], tempfood[1][i], Name, Price);
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
	RecordReceipt(tempfood, &*j, &*ordernumber, &*tablenumber, &*peoplenumber, FoodName, Name, Price);
	cout << "本次消费 " << sumamount << " 元，请输入金额以支付\n";
	return sumamount;
}