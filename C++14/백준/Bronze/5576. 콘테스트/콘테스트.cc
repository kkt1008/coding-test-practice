//5576
#include<iostream>
using namespace std;

int main()
{
	int arr1[10];
	int arr2[10];

	for (int i = 0; i < 10; i++)
	{//w대학
		cin >> arr1[i];
	}
	for (int i = 0; i < 10; i++)
	{//k대학
		cin >> arr2[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 10; j++) 
		{
			if (arr1[i] < arr1[j])
			{
				int temp;
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
			if (arr2[i] < arr2[j])
			{
				int temp;
				temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;
			}
		}
	}
	
	cout << arr1[0] + arr1[1] + arr1[2] << " " << arr2[0] + arr2[1] + arr2[2];
	
	return 0;
}
