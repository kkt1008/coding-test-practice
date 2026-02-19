#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    //answer+=a; // 초항을 더해줌
    
    for(int i=0;i<included.size();i++){
        if(included[i]==true){
            answer+=a + (d*i);
        }
    }
    
    return answer;
}