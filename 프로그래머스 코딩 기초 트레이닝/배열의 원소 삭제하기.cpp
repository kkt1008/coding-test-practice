#include <unordered_set> //unordered_set 자료형 사용
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    //unordered_set은 해시테이블 구조로 인해 insert, erase, find모두 O(1)으로 수행됨
    unordered_set<int> temp(delete_list.begin(),delete_list.end());
    
    for(int x:arr){
        if(temp.find(x)==temp.end()){//find(x)로 찾으면 해당 원소 위치의 반복자 반환. 못찾으면 v.end()반환
            answer.push_back(x);
        }
    }
    
    return answer;
}
