#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string s_a=to_string(a);
    string s_b=to_string(b);
    
    string comboNum = s_a+s_b; 
    int num1 = stoi(comboNum);
    int num2 = 2*a*b;
    
    if(num1>num2){
        answer = num1;
    }else{
        answer = num2;
    }
        
    return answer;
}
