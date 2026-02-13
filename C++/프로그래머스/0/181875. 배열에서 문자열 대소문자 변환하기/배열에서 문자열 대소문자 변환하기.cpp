#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(int i=0;i<strArr.size();i++){
        string tempStr = strArr[i];
        
        if(i%2==0){//짝수는 소문자
            for(char& ch:tempStr){
                ch = tolower(ch);
            }
        }else{//홀수는 대문자
            for(char& ch:tempStr){
                ch = toupper(ch);
            }
        }
        answer.push_back(tempStr);
    }
    return answer;
}