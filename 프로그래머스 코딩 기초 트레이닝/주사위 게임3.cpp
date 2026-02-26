#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    // p,p,q,r이면 q x r
    //제일 먼저 정렬을 통해 어떤 수가 같은지 판별====>핵심 아이디어!!
    vector<int> v={a,b,c,d};
    sort(v.begin(), v.end());
    int x0=v[0], x1=v[1], x2=v[2], x3=v[3];
    
    if(x0 == x3){//4개 전부 같은 경우
        answer = 1111 * x0;
    }else if(x0 == x2 && x0 != x3){// 3개가 p, 1개 q (10 x p + q)^2
    //x3이 다른 수 일 때
        answer = (10*x0 + x3) * (10*x0 + x3);
    }else if(x0 != x1 && x1 == x3){
    //x0이 다른 수 일 때    
        answer = (10*x1 + x0) * (10*x1 + x0);
    }else if(x0 == x1 && x2 == x3){//2개씩 같을 경우
        answer = (x0 + x2) * abs(x0 - x2);
    }else if(x0 == x1){// p,p,q,r이면 q x r
    //x0 = x1
        answer = x2 * x3;
    }else if(x1 == x2){
    //x1 = x2
        answer = x0 * x3;
    }else if(x2 == x3){
    //x2 = x3
        answer = x0 * x1;
    }else{//모두 다를때는 가장 작은 숫자
        answer = x0;
    }   
    return answer;
}
