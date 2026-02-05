#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    //컨테이너에 따라 반복자 타입이 다르기 때문에 컴파일러가 알아서 타입을 추론하도록 auto로 반복자 타입 설정
    //find는 찾으면 해당 원소를 가리키는 반복자 반환. 못 찾으면 v.end()반환
    auto it = find(num_list.begin(),num_list.end(),n);
    
    if(it !=num_list.end()){
        answer=1;
    }else{
     answer=0;   
    }
    
    return answer;
}
