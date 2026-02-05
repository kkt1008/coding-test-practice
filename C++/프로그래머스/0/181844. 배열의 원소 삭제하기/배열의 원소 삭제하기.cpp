#include <unordered_set> //unordered_set 자료형 사용
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    unordered_set<int> temp(delete_list.begin(),delete_list.end());
    
    for(int x:arr){
        if(temp.find(x)==temp.end()){
            answer.push_back(x);
        }
    }
    
    return answer;
}