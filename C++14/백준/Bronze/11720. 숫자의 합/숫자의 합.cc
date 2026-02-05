//11720
#include<iostream>
using namespace std;
int main()
{
	int n;//숫자개수
	char arr[100];
	int sum = 0;
	cin >> n;
	cin >> arr;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i]-48;
	}
	cout << sum << endl;
	return 0;
}