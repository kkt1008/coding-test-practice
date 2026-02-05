//2422
#include<iostream>
using namespace std;

int main()
{
	int n, m;//n:종류, m:조합개수
	cin >> n >> m;
	
	int arr[201][201] = { 0, };
	for (int i = 0; i < m; i++)
	{//2차원 배열로 해당되는 조합은 1로 표시
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	int count = 0;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i][j] == 1) continue;
			for (int k = j + 1; k < n+1; k++)
			{
				if (arr[i][k] == 1) continue;
				if (arr[j][k] == 1) continue;
				count++;
			}
		}
	}
	cout << count;
	return 0;
}
