#include <vector>
#include <set>
#include <iterator>
using namespace std;

vector<int> solution(vector<int> num_list) {
    multiset<int> temp(num_list.begin(), num_list.end()); //중복을 유지한 정렬된 컨테이너
    
    auto it = temp.begin();
    advance(it, 5);
    temp.erase(temp.begin(), it);
    
    return vector<int>(temp.begin(), temp.end());    
}
