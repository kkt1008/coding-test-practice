#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    int len1 = arr1.size();
    int len2 = arr2.size();
    
    int sum1=0;
    int sum2=0;
    //arr2가 크면 -1, arr1이 크면 1, 배열이 같으면 0을 리턴
    //배열의 길이가 같으면 배열의 원소의 총합으로 
    if(len1>len2){
        answer=1;
    }else if(len1<len2){
        answer=-1;
    }else{//같은 경우
        for(int i=0;i<len1;i++){
            sum1+=arr1[i];
            sum2+=arr2[i];
        }
        if(sum1>sum2){
            answer=1;
        }else if(sum1<sum2){
            answer=-1;
        }else{
            answer=0;
        }
    } 
    return answer;
}
