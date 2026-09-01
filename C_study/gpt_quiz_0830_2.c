#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //c에서는 bool형을 사용하려면 추가해야됨

/* 8/31 27번 괄호 스택 검사
(, ), [, ], {, }로만 구성된 문자열이 올바르게 중첩됐는지 검사하라.

조건
- 여는 괄호는 동적으로 할당한 스택에 저장한다.
- 빈 문자열은 올바른 문자열이다.
- s == NULL은 false로 처리한다.
- 시간복잡도는 O(n)이어야 한다.

| 입력        | 출력    |
| ---------- | ------- |
| `"{[()]}"` | `true`  |
| `"([)]"`   | `false` |
| `""`       | `true`  |

*/

//문자열 길이에 맞춰서 스택을 동적으로 할당
//여는 괄호는 스택에 저장
//닫는 괄호가 나오는 경우 스택의 마지막 괄호를 확인
//매칭이 되면 true, 다르면 false
//매칭 검사가 끝나면 stack에서 제거

static bool isMatching(char str1, char str2){ //괄호 매칭 확인 함수
    if((str1=='(' && str2==')') || \
       (str1=='[' && str2==']') || \
       (str1=='{' && str2=='}')){
        return true;
       }
    else{
        return false;
    }
}

static bool brackets_valid(const char *s){
    if(s==NULL){
        return false;
    } 

    size_t str_length = strlen(s);
    char *stack=malloc((str_length+1) * sizeof(char)); //괄호로 된 문자열 저장

    if(stack==NULL){
        return false;
    }

    size_t top=0; //처음에는 0. 문자 추가되면 1증가
    bool bool_val=true; //잘못된 경우를 발견하기 전까지는 올바른 문자열로 간주

    for(size_t i=0;i<str_length;i++){
        char current=s[i];
        if(current =='(' || current =='[' || current =='{'){
            stack[top]=current; //스택에 괄호 추가
            top++; //top 인덱스 증가
        }else if(current ==')' || current ==']' || current =='}'){
            if(top==0){
                bool_val=false;
                break;
            }
            top--; //스택 top의 원소 재거
            char open = stack[top];
            if(!isMatching(open, current)){
                bool_val=false;
                break;
            }
        }else{//괄호외의 문자가 나오는 경우는 false
            bool_val = false;
            break;       
        }
    }
    if(top!= 0){
        bool_val=false;
    }
    free(stack);
    return bool_val;
}

int main(){
    printf("%s\n", brackets_valid("{[()]}") ? "true" : "false"); //true
    printf("%s\n", brackets_valid("([)]")   ? "true" : "false"); //false
    printf("%s\n", brackets_valid("")       ? "true" : "false"); //true   
    printf("%s\n", brackets_valid(NULL)     ? "true" : "false"); //false

    return 0;
}
