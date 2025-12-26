#include <iostream>
#include<vector>
#include<queue> 
#include <string>

using namespace std;

int main() {
	int R = 0; int C = 0;
	cin >> R >> C;
	// 잔디: # , 잔디가 아닌 그 외 공간: .
	// 총 #이 몇개인가??

	vector<string> grid(R);
	for (int i = 0; i < R; i++) { //반복문이 끝나면 행열 입력받는 것이 완료
		cin >> grid[i];
	}

	//방문여부 확인용 벡터. 동일하게 R x C 크기 아직 방문안한 곳은 0, 방문하면 1
	vector<vector<char>> visited(R, vector<char>(C, 0));
	queue<pair<int, int>> q; // BFS위한 큐. 현재 탑색할 좌표 pair로 저장

	//상하좌우 4방향만 고려하면 됨
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };

	int answer = 0; // 총 잔디 개수

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (grid[r][c] != '#') continue;
			if (visited[r][c]) continue;

			answer++;
			visited[r][c] = 1;
			q.push({ r,c });

			while (!q.empty()) {
				auto [r, c] = q.front();
				q.pop(); // 큐 맨앞 좌표를 꺼내서 r,c에 저장하고 큐에서 제거

				for (int i = 0; i < 4; i++) {//4방향 모두 검사
					int nextR = r + dr[i];
					int nextC = c + dc[i]; // 이웃칸 좌표 생성

					if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
					if (grid[nextR][nextC] != '#') continue;
					if (visited[nextR][nextC]) continue;

					visited[nextR][nextC] = 1; //방문한 좌표는 1로 처리
					q.push({ nextR, nextC }); //새로운 좌표부터 다시 BFS탐색
				}
			}


		}
	}

	cout << answer << endl;
	return 0;
}
