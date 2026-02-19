#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(auto &q :queries){
        int i=q[0];
        int j=q[1];
        swap(arr[i],arr[j]);
    }   
    return arr;
}