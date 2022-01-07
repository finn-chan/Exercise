#include<iostream>
#include<iomanip>
#include"Amount.h"
#include"DispalyOrderNumber.h"
#include"RecordReceipt.h"

using namespace std;

//出示小票
int ShowReceipt(char(*tempfood)[16], int* j, int* ordernumber, int* tablenumber, int* peoplenumber, string* FoodName, char* Name, int* Price);