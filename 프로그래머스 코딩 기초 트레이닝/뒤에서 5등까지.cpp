#include <vector>
#include <set> //multiset 자료형 사용
#include <iterator> //advance 함수 사용

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    multiset<int> temp(num_list.begin(), num_list.end());
    auto it = temp.begin();
    advance(it, 5); //반복자를 5칸 옮김
    
    answer.insert(answer.end(), temp.begin(), it);
    
    return answer;
}
