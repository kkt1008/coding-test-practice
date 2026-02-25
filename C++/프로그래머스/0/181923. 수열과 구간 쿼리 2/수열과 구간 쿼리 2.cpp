#include <string>
#include <vector>
#include <climits> // INT_MAX 사용하기 위해 추가
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i=0;i<queries.size();i++){//쿼리의 갯수만큼 반복
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2]; 
        int temp = INT_MAX;
            
        for(int i=s;i<=e;i++){
            if(arr[i] > k){
                temp = min(temp,arr[i]);
            }
        }
        
        if(temp == INT_MAX){
            answer.push_back(-1);
        }else{
            answer.push_back(temp);
        }
        
    }
    
    
    return answer;
}