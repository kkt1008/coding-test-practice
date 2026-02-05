#include<iostream>
using namespace std;

int main()
{
	int trial; //시도횟수
	int result[100];
	cin >> trial;
	for (int i = 0; i < trial; i++)
	{
		int a, b;
		cin >> a >> b;
		result[i] = a + b;
	}

	for (int i = 0; i < trial; i++)
	{
		cout << result[i] << endl;
	}
	   	
	return 0;
}