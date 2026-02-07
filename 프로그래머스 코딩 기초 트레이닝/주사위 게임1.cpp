#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    if(a%2 ==0 && b%2==0){//모두 짝수인 경우
        answer = abs(a-b);
    }else if(a%2 !=0 && b%2 !=0){//모두 홀수인 경우 
        answer = a*a + b*b;
    }else{
        answer = (a+b)*2;
    }
    
    return answer;
}
