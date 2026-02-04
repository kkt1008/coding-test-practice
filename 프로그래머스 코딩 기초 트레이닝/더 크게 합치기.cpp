#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string s_a = to_string(a); //숫자를 문자열로 변환
    string s_b = to_string(b);
    
    string ab= s_a + s_b;
    string ba= s_b + s_a;
    
    int numAB = stoi(ab); //문자열을 숫자로 변환
    int numBA = stoi(ba);
    
    if(numAB > numBA){
        answer = numAB;
    }else if(numAB == numBA){
        answer = numAB;
    }else{
        answer = numBA;
    }
    
    return answer;
}
