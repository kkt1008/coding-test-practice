#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    string tempMyString;
    string tempPat;
    
    for(char &ch:myString){
        tempMyString+=tolower(ch);
    }
    for(char &ch:pat){
        tempPat+=tolower(ch);
    }
    
    if(myString.size() < pat.size()){//pat이 길면 무조건 0
        answer=0;
    }else{//pat이 같거나 짧을때 문자열 비교
        if(tempMyString.find(tempPat) != string::npos){
            answer=1;
        }else{
            answer=0;
        }    
    }
    
    return answer;
}