#include <string>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    my_string.replace(my_string.begin()+s,my_string.begin()+s+overwrite_string.size(),overwrite_string);
    return my_string;
}
