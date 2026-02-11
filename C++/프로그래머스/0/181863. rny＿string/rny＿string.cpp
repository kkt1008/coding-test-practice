#include <string>
using namespace std;

string solution(string rny_string) {
    string ans;
    //메모리 크기를 미리 확보해서 문자를 붙일 때마다 발생하는 재할당 감소
    ans.reserve(rny_string.size() * 2); //전부m인 경우에 최대 2배 길이까지 늘어남. 

    for (char c : rny_string) {
        if (c == 'm') ans += "rn";
        else ans += c;
    }
    return ans;
}
