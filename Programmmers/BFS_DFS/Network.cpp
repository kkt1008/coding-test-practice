#include <string>
#include <vector>
#include <stack>
using namespace std;
//컴퓨터 개수 n, 연결정보 2차원 vector
//연결된 노드가 총 몇개?? ===> DFS로 접근
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n,0); //총 노드의 크기만큼 방문여부 확인용 벡터
    
    for(int i=0;i<n;i++){
        if(visited[i]) continue; //이미 네트워크에 연결되어 있을 경우
        
        answer++;
        stack<int> st; //DFS용 스택. 나중에 방문할 정점이 들어감
        st.push(i); //시작점부터 스택에 넣고 DFS 준비 
        visited[i]=1; //방문한 노드 1로 처리
        
        while(!st.empty()){
            int current = st.top(); //스택의 맨 위 정점 저장
            st.pop(); // 방금 꺼낸 정점을 스택에서 제거
            
            //현재 노드 current와 인접한 모든 노드 스캔
            for(int next=0;next<n;next++){// 총 노드수 만큼 순회
                if(computers[current][next] ==0) continue;
                if(visited[next]==1) continue;
                
                visited[next]=1;
                st.push(next);
            }
        }
    }
    return answer;
}
