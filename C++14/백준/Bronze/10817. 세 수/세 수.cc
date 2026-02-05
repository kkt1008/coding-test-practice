//2309
#include<iostream>
using namespace std;

int main()
{
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	for (int i = 0; i < 2; i++)
	{
		int temp;
		for (int j = i + 1; j < 3; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	cout << arr[1];
	return 0;
}