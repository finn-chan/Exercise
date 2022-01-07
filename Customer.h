#include<iostream>
#include"Menu.h"
#include"NumberOfRecords.h"
#include"ShowReceipt.h"
#include"Pay.h"

using namespace std;

//顾客
void Customer(int* i, int* j, char(*tempfood)[16], int* foodnumber, int* ordernumber, int* tablenumber, int* peoplenumber, int* totalconsumption, string* FoodName, char* Name, int* Price);