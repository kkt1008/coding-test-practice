//1018
#include<iostream>
#include<algorithm>
using namespace std;
char board[50][50];
int case_white_first(int x, int y)
{
	int count = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
			{
				if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
				{
					if (board[i][j] != 'W') count++;
				}
				else
				{
					if (board[i][j] != 'B') count++;
				}
			}
			else
			{
				if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
				{
					if (board[i][j] != 'B')count++;
				}
				else
				{
					if (board[i][j] != 'W') count++;
				}
			}
		}
	}
	return count;
}
int case_black_first(int x, int y)
{
	int count = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
			{
				if(j==y||j==y+2||j==y+4||j==y+6) 
				{
					if (board[i][j] != 'B') count++;
				}
				else
				{
					if (board[i][j] != 'W') count++;
				}
			}
			else
			{
				if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
				{
					if (board[i][j] != 'W') count++;
				}
				else
				{
					if (board[i][j] != 'B') count++;
				}
			}
		}
	}
	return count;
}
int min_test_func(int a, int b)
{//a,b중 작은수 반환 
	return (a < b ? a : b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int count_black = 0, count_white = 0;
	int white_first, black_first;
	int total_min=10000;//비교를 위해 아무거나 큰 수 할당
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{//색깔 입력받음
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{//체스판 순회하면서 탐색
		if (i + 8 > n) break;//8개가 안되면 그 행은 판단안하고 다음 행 판단
		for (int j = 0; j < m; j++)
		{//처음이 흰색인 경우, 검정색인 경우 나눠서 판단
			if (j + 8 > m) break;
			white_first = case_white_first(i, j);
			black_first = case_black_first(i, j);
			total_min = min_test_func(total_min, min_test_func(white_first, black_first));
		}
	}
	cout << total_min << endl;
	return 0;
}