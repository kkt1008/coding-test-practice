#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n%2 !=0){ //n이 홀수이면
        for(int i=0;i<n+1;i++){
            if(i%2 !=0 ){//홀수인 모든 양의 정수들
                answer+=i;
            }
        }
    }else{//n이 짝수이면
        for(int j=0;j<n+1;j++){
            if(j%2 ==0){
                answer+=j*j;
            }
        }
    }
    
    return answer;
}
