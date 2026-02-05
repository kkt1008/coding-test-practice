#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    int len = arr.size();
    if(len % 2 ==0){//짝수
    //arr의 모든 홀수 인덱스 위치에 n을 더한 배열 리턴
        for(int i=0;i<len;i+=2){
            arr[i+1]+=n;    
        }
    }else{//홀수
    //arr의 모든 짝수 인덱스 위치에 n을 더한 배열 리턴
        for(int j=0;j<len;j+=2){
            arr[j]+=n;
        }
    }
    answer=arr;
    return answer;
}
