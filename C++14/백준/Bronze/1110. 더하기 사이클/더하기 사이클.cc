#include<iostream>
using namespace std;
int main()
{
	int num,temp ,new_num, result;
	int  count = 0;
	cin >> num;
	result = num;
	while (1)
	{		
		temp = (num / 10) + (num % 10);
		new_num=(num % 10)*10 + (temp % 10);
		count++;
		num = new_num;
		if (new_num == result) break;
	}
	cout << count;
	return 0;
}