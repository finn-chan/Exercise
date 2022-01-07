#include"DispalyOrderNumber.h"

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
}