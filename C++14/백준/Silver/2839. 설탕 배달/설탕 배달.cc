//2839
#include<iostream>
using namespace std;

int main()
{
	int num,count=0;
	cin >> num;

	while (1)
	{
		if (num % 5 == 0)
		{
			count += num / 5;
			cout << count;
			break;
		}
		num = num - 3;
		count++;
		if (num < 0)
		{
			cout<<"-1";
			break;
		}
	}
	return 0;
}
