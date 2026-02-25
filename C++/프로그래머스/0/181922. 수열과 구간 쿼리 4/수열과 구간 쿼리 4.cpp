#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i=0;i<queries.size();i++){
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2]; 
        
        for(int i = s;i <= e;i++){
            if(i % k == 0){//i가 k의 배수이면 arr[i]+1
                arr[i]+=1;
            }
        }
    }
    answer=arr;
    return answer;
}