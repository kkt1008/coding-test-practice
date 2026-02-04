#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int lenOfVector = num_list.size(); //벡터 크기.  
    
    if(num_list.back() > num_list[lenOfVector-2]){
        int temp = num_list.back() - num_list[lenOfVector-2];
        num_list.push_back(temp);
        answer.insert(answer.end(),num_list.begin(),num_list.end());
    }else{
        int temp = 2*num_list.back();
        num_list.push_back(temp);
        answer.insert(answer.end(),num_list.begin(),num_list.end());
    }   
      
    return answer;
}


