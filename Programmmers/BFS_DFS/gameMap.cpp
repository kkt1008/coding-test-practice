#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;

    int n = (int)maps.size(); // 행
    int m = (int)maps[0].size(); //열

    //시작과 도착이 벽이면 바로 -1 반환
    if(maps[0][0] == 0 || maps[n-1][m-1]==0) return -1;


    //dist[r][c] = 시작에서 (r,c)까지 이동한 거리
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;

    dist[0][0] = 1;
    q.push({0,0});

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!q.empty()){
        auto[r,c]=q.front();
        q.pop();
        //처음 목표에 도달한 순간이 최단거리
        if(r == n-1 && c == m-1) return dist[r][c];

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue; //범위 확인. 벽일 때 못감
            if(maps[nr][nc]==0) continue; // 이미 방문한 곳 스킵
            if(dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c]+1;
            q.push({nr,nc});

        }
    }
    answer = dist[n-1][m-1];
    return answer;
}
