#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;// l과 r이하 정수 중에서 0과 5로만 이루어진 모든 정수를 오름차순으로 저장한 배열
    //숫자를 문자로 변환시키고 해당 숫자에 5,0이라는 문자로만 이루어졌는지 확인
    for(int i=l;i<=r;i++){
        string temp = to_string(i);
        bool ok=true;
        for(char ch:temp){
            if(ch != '0' && ch != '5'){
                ok=false;
                break;
            }
        }
        if(ok==true){
            answer.push_back(i);
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    
    return answer;
}