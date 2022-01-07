#include"RecordReceipt.h"

//记录小票
void RecordReceipt(char (*tempfood)[16], int* j, int* ordernumber, int* tablenumber, int* peoplenumber, string* FoodName, char* Name, int* Price)
{
	string str;
	str = *ordernumber + 48;
	int sumamount = 0;
	ofstream ofs(str + ".txt");

	ofs << "------------------------------------------------\n";
	ofs << "|                   小票                       |\n";

	ofs << "| 订单号：                    " << "20220109000" << *ordernumber << "     |\n";
	ofs << "| 餐桌号：                            " << "000" << *tablenumber << "     |\n";

	ofs << "|                                              |\n";
	ofs << "| 菜名                数量（份）  金额（元）   |\n";

	for (int i = 0; i < *j; i++)
	{
		ofs << "|    " << FoodName[tempfood[0][i] - 'A'] << "      " << setw(2) << tempfood[1][i] << "        " << setw(4) << Amount(tempfood[0][i], tempfood[1][i], Name, Price) << "     |\n";
		sumamount += Amount(tempfood[0][i], tempfood[1][i], Name, Price);
	}

	if (sumamount < 500)
	{
		ofs << "|                                              |\n";
		ofs << "| 餐位费                    " << setw(2) << *peoplenumber << "         " << setw(3) << *peoplenumber * 10 << "     |\n";		//餐位费每人 10 元
		sumamount += (*peoplenumber * 10);
	}
	ofs << "|                                              |\n";
	ofs << "| 总额                                ";
	ofs << setw(4) << sumamount;
	ofs << "     |" << endl;
	ofs << "------------------------------------------------\n\n";
	ofs.close();
}