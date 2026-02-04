#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
   
    int prod=1; //모든 원소들의 곱
    int sum=0; //모든 원소들의 합의 제곱
    
    for(int i:num_list){
        prod*=i;
        sum+=i;
    }
    
    return prod< sum*sum ? 1:0; 
}
