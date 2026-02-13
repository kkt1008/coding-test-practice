#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(char &ch:str){
        if('a'<=ch && ch<='z'){
            ch= toupper(ch);
        }else{
            ch=tolower(ch);
        }
    }
    
    cout<<str;
    return 0;
}
