//1181
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string a, string b)
{//길이 비교 함수-짧은거 순서대로
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}
int main()
{
	int n;//단어의 개수
	cin >> n;
	vector<string> s;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		//cin >> s[i];
		s.push_back(word);
	}//길이 짧은거 부터,길이 같으면 사전순으로,중복x
	sort(s.begin(), s.end(),cmp);//직접 비교함수 이용해서 정렬
	string temp;
	for (int i = 0; i < n; i++)
	{
		if (temp == s[i]) continue;
		cout << s[i] << endl;
		temp = s[i];
	}
	return 0;
}
