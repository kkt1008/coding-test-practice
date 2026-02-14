#include <string>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int a, b;
    char op;
    int answer=0;

    stringstream ss(binomial);
    ss >> a >> op >> b;   // "a op b" 형태 파싱

    if (op == '+') answer = a + b;
    else if (op == '-') answer = a - b;
    else if (op == '*') answer = a * b;

    return answer; 
}
