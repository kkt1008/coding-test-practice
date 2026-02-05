//2386
#include<iostream>
#include<string>
using namespace std;

int main()
{
	while (1)
	{
		char a;
		string str;
		int count = 0;
		cin >> a;
		if (a == '#') break;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (a == str[i]) count++;
			if(a+32==str[i]) count++;
			if (a - 32 == str[i]) count++;
		}
		cout << a<<" "<<count << endl;
	}

	return 0;
}