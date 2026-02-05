#include<iostream>
using namespace std;

int main()
{
	int hour, min;

	cin >> hour >> min;

	if (hour == 0)
	{
		if (min >= 45)
		{
			cout << hour << " " << min-45;
		}
		else
		{
			hour = 23;
			cout << hour << " " << min + 15;
		}
	}
	else
	{
		if (min >= 45)
		{
			cout << hour << " " << min - 45;
		}
		else
		{
			cout << hour - 1 << " " << min + 15;
		}
	}
	
	return 0;
}