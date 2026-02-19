#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
   
    for(int i=1;i<numLog.size();i++){
        int diff=numLog[i] - numLog[i-1];
        
        if(diff == 1){
            answer.push_back('w');
        }else if(diff == -1){
            answer.push_back('s');
        }else if(diff == 10){
            answer.push_back('d');
        }else if(diff == -10){
            answer.push_back('a');
        }
    }    
    return answer;
}
