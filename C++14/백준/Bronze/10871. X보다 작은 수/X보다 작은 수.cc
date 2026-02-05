#include<iostream>
using namespace std;

int main()
{
	int A, x;
	cin >> A >> x;
	int arr[10000];

	for (int i = 0; i < A; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < A; i++)
	{
		if (arr[i] < x)
		{
			cout << arr[i] << " ";
		}
	}
	
	return 0;
}