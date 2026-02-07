#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    
    for(int i=0;i<strArr.size();){
        if(strArr[i].find("ad") != string::npos){
            //erase를 할 경우 원소들이 앞으로 당겨짐으로 i++가 진행되면 다음 원소를 검사하지 못하고 건너 뜀
            strArr.erase(strArr.begin()+i); 
        }else{//안 지웠을 때만 i를 증가시켜서 다음 원소 검사
            i++;
        }
    }
    return strArr;
}
