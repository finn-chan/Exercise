#include"ReadReceipt.h"

//读取小票
void ReadReceipt(int n)
{
	string str;
	char buf[1000];
	str = n + 48;
	ifstream ifs(str + ".txt");
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	ifs.close();
}