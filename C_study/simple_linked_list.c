#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode { //헤더가 아닌 일반 노드
	char data[4];
	struct ListNode* link;
}listNode;

//head 노드 구조체로 정의
typedef struct {
	listNode* head;
}linkedList_h;

//함수 미리 선언
linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
void freeLinkedList_h(linkedList_h* L);

int main() {
	linkedList_h* L;
	L = createLinkedList_h(); //노드 생성
	printf("(1) 공백 리스트 생성하기 \n");
	printList(L);
	
	printf("(2) 리스트에 [수] 노드 삽입하기\n");
	insertFirstNode(L, "수"); //노드 추가
	printList(L);
	
	printf("(3) 리스트 마지막에 [금] 노드 삽입하기\n");
	insertFirstNode(L, "금");
	printList(L);

	printf("(4) 리스트 첫 번째에 [월] 노드 삽입하기\n");
	insertFirstNode(L, "월");
	printList(L);

	printf("(5) 리스트 공간을 해제하여 공백 리스트로 만들기\n");
	freeLinkedList_h(L); //노드 해제
	printList(L);

	return 0;
}


linkedList_h* createLinkedList_h(void) {//노드 생성 함수
	linkedList_h* L; //노드 변수 
	L = (linkedList_h*)malloc(sizeof(linkedList_h)); //노드를 실제 linkedList_h구조체만큼 메모리 할당
	L->head = NULL; //노드 L의 메모리 할당 후, L내부 head는 null로 초기화 
	return L; //메모리 할당된 노드 반환
}

void freeLinkedList_h(linkedList_h* L) {
	listNode* p; //노드를 가리키는 포인터 
	while (L->head != NULL) {//헤더가 NULL일 때까지 반복
		p = L->head;
		L->head = L->head->link;
		free(p); //할당한 메모리 해제
		p = NULL;
	}
}

void printList(linkedList_h* L) {//연결리스트를 순서대로 출력하는 함수
	listNode* p;
	printf("L=(");
	p = L->head;// 매개변수 L 노드의 내부 head 포인터의 자료형도 listNode라서 대입 가능
	while (p != NULL) { // 마지막 노드의 헤더가 NULL로 초기화되어 있으므로, 마지막 노드를 만나기 전까지 출력 
		printf("%s", p->data);
		p = p->link; //노드의 링크가 가리키는 노드를 새롭게 노드 포인터로 할당
		if (p != NULL) printf(", "); //노드의 값 출력 후, 쉼표출력
	}
	printf(")\n");
}

void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode)); //listNode구조체 만큼 메모리 할당
	strcpy(newNode->data, x); //새로운 노드 내부 data에 문자열 저장
	newNode->link = L->head;// 할당된 노드 내부 요소 link에 새로 추가한 노드의 헤더 저장
	L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산 
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode; //노드를 가리키는 포인터
	newNode = (listNode*)malloc(sizeof(listNode)); //새로운 노드 공간 메모리에 할당
	strcpy(newNode->data, x);

	if (L == NULL) { //리스트를 새로 만들어야 하는 공백 리스트인 경우
		newNode->link = NULL; //헤더가 첫 노드이자 마지막 노드
		L->head = newNode;
	}
	else if (pre == NULL) { //삽입 위치를 지정하는 포인터 pre가 NULL인 경우---?? 무슨 말이지?
		L->head = newNode;
	}
	else {  //포인터 pre 노드 뒤에 새 노드 연결
		newNode->link = pre->link;
		pre->link = newNode;
	}
}
//마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h*L, char *x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode)); //마지막 노드에 해당하는 노드 메모리 할당
	strcpy(newNode->data, x); 
	newNode->link = NULL;
	if (L->head == NULL) {//현재 리스트가 공백인 경우
		L->head = newNode; //새 노드를 리스트의 시작 노드로 연결
		return;
	}
	//리스트가 공백이 아닌 경우
	temp = L->head;// 임시로 헤더의 주소를 저장
	while (temp->link != NULL) {//리스트의 마지막 노드까지 순회
		temp = temp->link; //현재 리스트의 마지막 노드를 찾은 후 temp에 할당
	}
	temp->link = newNode;//temp에 할당된 현재 리스트에서 찾은 마지막 노드의 다음 노드로 추가한 노드 연결 
		
}


