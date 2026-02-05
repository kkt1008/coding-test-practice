//2920
#include<iostream>
using namespace std;

int main()
{
	int arr[8];
	int num;
	int asc=0,desc=0;
	for (int i = 0; i < 8; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	for(int i=0;i<4;i++)
	{
		if (arr[i] == i + 1 && arr[i] + arr[7 - i] == 9)asc++;
		if (arr[7 - i] == i + 1 && arr[i] + arr[7 - i] == 9) desc++;
	}
	if (asc == 4) cout << "ascending";
	else if (desc == 4) cout << "descending";
	else cout << "mixed";
	
	return 0;
}