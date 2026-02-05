//11721
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string arr;
	getline(cin, arr);
		
	for (int i = 0; i <arr.size(); i++)
	{
		cout << arr[i];
		if ((i + 1) % 10 == 0) cout << '\n';
	}
	cout << "\n";
	return 0;
}