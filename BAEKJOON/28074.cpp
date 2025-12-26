#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	//bool 형 변수로 
	bool M = false;
	bool O = false;
	bool B = false;
	bool I = false;
	bool S = false;

	for (char c : str) {
		if (c == 'M') M = true;
		else if (c == 'O') O = true;
		else if (c == 'B')B = true;
		else if (c == 'I')I = true;
		else if (c == 'S')S = true;
	}

	if (M && O && B && I && S) cout << "YES";
	else cout << "NO";


	return 0;
}
