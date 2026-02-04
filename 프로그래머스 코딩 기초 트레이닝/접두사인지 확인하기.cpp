#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 1; //접두사가 짧을 때 끝까지 같으면 1 반환
    
    if(is_prefix.size()>my_string.size()){//접두사가 길면 아에 0
        answer=0;
    }
    
    for(int i=0;i<is_prefix.size();i++){
        if(my_string[i] != is_prefix[i]) {
            answer=0;
            break;
        }
    }
    return answer;
}
