#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    int zero_cnt=0;
    
    while(zero_cnt < n_str.size() && n_str[zero_cnt]=='0'){
        zero_cnt++;
    }
    n_str.erase(0,zero_cnt);
    
    
    return n_str;
}
