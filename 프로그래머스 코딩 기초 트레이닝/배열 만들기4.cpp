#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i = 0;
    
    while(i<arr.size()){// i가 arr의 길이보다 작으면 다음 작업을 반복
        if(stk.empty()){// stk가 빈 배열이면 arr[i]를 stk에 추가하고 i++
            stk.push_back(arr[i]);
            i++;
        }else if(stk.back() < arr[i]){//stk에 원소가 있고, stk의 마지막 원소가 arr[i]보다 작으면 arr[i]를 stk의 뒤에 추가하고 i++
            stk.push_back(arr[i]);
            i++;
        }else if(stk.back() >= arr[i]){//stk에 원소가 있는데 stk의 마지막 원소가 arr[i]보다 크거나 같으면 stk의 마지막 원소를 stk에서 제거
            stk.pop_back();
        }
    }
    return stk;
}
