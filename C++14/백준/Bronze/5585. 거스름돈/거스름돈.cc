//5585
#include<iostream>
using namespace std;

int main()
{
	int num;
	int change;
	int count = 0;
	cin >> num;

	change = 1000 - num;
	if (change % 500 != 0)
	{
		int rest1;
		if (change > 500) count++;
		rest1 = change % 500;
		if (rest1 % 100 != 0)
		{
			int division1, rest2; 
			division1 = rest1 / 100;
			count += division1;
			rest2 = rest1 % 100;
			if (rest2 % 50 != 0)
			{
				int rest3, division2;
				division2 = rest2 / 50;
				count += division2;
				rest3 = rest2 % 50;
				if (rest3 % 10 != 0)
				{
					int rest4, division3;
					division3 = rest3 / 10;
					count += division3;
					rest4 = rest3 % 10;
					if (rest4 % 5 != 0)
					{
						int rest5, division4;
						division4 = rest4 / 5;
						count += division4;
						rest5 = rest4 % 5;
						count += rest5;
						cout << count << endl;
						return 0;
					}
					else
					{//635
						cout << count + (rest4 / 5) << endl;
						return 0;
					}
				}
				else
				{//630
					cout << count + (rest3 / 10) << endl;
					return 0;
				}
			}
			else
			{//650...
				cout << count + (rest2 / 50) << endl;
				return 0;
			}
		}
		else
		{//거스럼돈 600,700등인 상황
			cout << count+(rest1 / 100) << endl;
			return 0;
		}
	}
	else
	{//거스름돈 500원인 상황
		cout << count << endl;
		return 0;
	}

}
