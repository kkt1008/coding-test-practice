#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string tempString;
    for(char ch:my_string){
        if(ch !=' '){//공백문자가 아니면 글자를 계속 합침
            tempString+=ch;
        }else{//공백분자이면 합친 글자를 벡터의 요소로 저장한다
            if(!tempString.empty()){//공백이 존재하면 문자를 추가하면 안됨. 비어있을 때는 연속공백/앞/뒤 공백이 존재한다는 의미 
                answer.push_back(tempString);//하나의 벡터 요소로 저장
                tempString.clear();//string변수 초기화. 다시 여기에 문자를 합친다.
            }
        }
    }
    if(!tempString.empty()){//마지막 남아 있는 문자열을 벡터 요소로 저장
        answer.push_back(tempString);
    }
    return answer;
}
