#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string temp="l";
    for(int i=0;i<myString.size();i++){
        if(myString[i]<temp[0]){
            myString[i]=temp[0];
        }
    }
    
    return myString;
}
