#include <string>
#include <vector>
#include <queue>
using namespace std;
// +나 -를 붙이는 상태로 보고 진행. 이진트리 형성
// DFS로 접근. 모든 깊이의 n까지 가야 경우의 수를 세기 때문에 BFS도 가능
int solution(vector<int> numbers, int target) {
    // ex = numbers:[1,1,1,1,1], target:3
    int answer = 0; int sum=0;
    queue<pair<int,int>> q; // idx, sum
    q.push({0,0});

    
    while(!q.empty()){
        auto[idx, sum]=q.front(); q.pop();
        
        if(idx==(int)numbers.size()){
            if(sum==target) answer++;
            continue;
        }
        
        q.push({idx+1, sum+numbers[idx]});
        q.push({idx+1, sum-numbers[idx]});
    }
    
    
    return answer;
}
