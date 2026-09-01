#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element; //스택 원소의 자료형 int로 정의

//스택 노드 구조체
typedef struct stackNode{ 
    element data;
    struct stackNode*link;
}stackNode;

stackNode*top; //스택의 top 노드를 지정하는 포인터

int isEmpty(){//스택이 공백인지 확인하는 함수
    if(top==NULL){//top이 null이면 공백임
        return 1;
    }else{
        return 0;
    }
}

void push(element item){//스택의 top에 원소 추가 함수
    stackNode*temp=(stackNode*)malloc(sizeof(stackNode));
    temp->data=item;//스택 top에 원소 연결
    temp->link=top; //스택에 원소를 새롭게 추가하면 top포인터 갱신
    top=temp;
}

element pop(){//스택의 top에서 원소 제거 함수
    element item;
    stackNode*temp=top;

    if(top==NULL){//스택이 공백일 때
        printf("\n\n stack is empty\n");
        return 0;
    }else{
        item=temp->data; //제거할 원소를 옮김
        top=temp->link; //top포인터를 이전 노드로 옮김
        free(temp); //top노드 메모리 반환
        return item; //제거한 원소 반환
    }
}

element peek(){//스택의 top원소 탐색 함수
    if(top==NULL){//스택이 공백인 경우
        printf("\n\n stack is empty\n");
        return 0;
    }else{//공백이 아닐 때
        return (top->data); //현재 top 원소 반환
    }
}

void printStack(){
    stackNode*p=top;
    printf("\n stack[ ");
    while(p){
        printf("%d",p->data);
        p=p->link;
    }
    printf("] ");
}

int main(){
    element item;
    top=NULL;
    printStack();
    push(1); printStack();
    push(2); printStack();
    push(3); printStack();

    item=peek();
    printStack();

    printf("peek=> %d",item); //현재 top출력
    
    item=pop();//top원소 삭제
    printStack();
    printf("pop => %d",item);
    
    item=pop();
    printStack();
    printf("pop =>%d",item);

    return 0;
}
