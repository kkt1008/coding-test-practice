#include <string>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    
    if((n>m) && ineq==">" && eq=="!"){
        answer =1;
    }else if((n<m) && ineq=="<" && eq=="!"){
        answer =1;
    }else if((n>=m) && ineq==">" && eq=="="){
        answer =1;
    }else if((n<=m) && ineq=="<" && eq=="="){
        answer =1;
    }else {
        answer=0;
    }
    
    return answer;
}
