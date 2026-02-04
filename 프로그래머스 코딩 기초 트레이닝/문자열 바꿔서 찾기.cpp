#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for(int i=0;i<myString.size();i++){
        if(myString[i] == 'A'){
            myString[i]='B';
        }else{
            myString[i]='A';
        }
    }
   //find() 같은 함수는 찾으면 위치(인덱스) 를 반환. 찾으면 특별한 값으로 string::npos를 반환
   if(myString.find(pat) != string::npos){//std::string에서 쓰는 “못 찾았다” 표시값
       answer=1;
   }else{
       answer=0;
   }
    
    return answer;
}
