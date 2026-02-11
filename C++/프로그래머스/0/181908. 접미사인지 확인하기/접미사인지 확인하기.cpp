#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    string cmp;
    
    if (is_suffix.size() > my_string.size()) return 0;   
    cmp = my_string.substr(my_string.size()-is_suffix.size());
    if(cmp==is_suffix){
        answer =1;
    }else{
        answer=0;
    }
    return answer;
}