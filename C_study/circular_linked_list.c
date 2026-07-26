#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//원형 연결 리스트 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

//리스트 시작을 나타내는 head 노드 구조체
typedef struct {
	listNode* head;
}linkedList_h;

//공백 원형 연결 리스트를 생성하는 함수
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL;
	return CL;
}

//연결리스트를 순서대로 출력하는 함수
void printList(linkedList_h* CL) {
	listNode* p;
	printf("CL=(");
	p = CL->head;
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) {//헤더가 아니면
			printf(", ");
		}
	} while (p != CL->head);//헤더를 만나면 반복 종료
	printf(") \n");
}

//첫 번째 노드 생성 함수
void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode;
	listNode* temp;

	newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당
	strcpy(newNode->data, x);
	if (CL->head == NULL) {//원형 연결리스트가 공백인 경우
		CL->head = newNode;//새 노드를 리스트의 시작으로 설정
		newNode->link = newNode; //원형 연결리스트이므로 할당한 새 노드 스스로를 link로 연결
	}
	else {//공백 상태가 아닐때
		temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode; //마지막 노드를 첫번째 노드인 new와 원형 연결
		CL->head = newNode;
	}
}

//pre뒤에 노드를 삽입하는 함수
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL) {//원형리스트가 비어 있으면 new가 첫번째 노드
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {//원형리스트가 존재하면 
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

//pre뒤에 노드를 삭제하는 함수
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;
	if (CL->head == NULL) {//공백 리스트는 삭제 연산 중단
		return;
	}
	if (CL->head->link == NULL) {//노드가 1개만 있는 경우
		free(CL->head); //1개 노드만 해제 
		CL->head = NULL; //리스트 시작 포인터 NULL로 설정
		return;
	}
	else if (old == NULL) {//삭제할 노드가 없는 경우 삭제 연산 중단
		return;
	}
	else {
		pre = CL->head; //리스트 시작 노드에 pre포인터 연결
		while (pre->link != old) {//old노드 전까지 탐색
			pre = pre->link;
		}
		pre->link = old->link;
		if (old == CL->head) {
			CL->head = old->link;
		}
		free(old);
	}
}

//원형 연결 리스트에서 x노드를 찾는 함수
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp;
	temp = CL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) {
			return temp;//같을 경우 해당 노드 반환
		}
		else {//다를 경우 다음 노드로 이동
			temp = temp->link;
		}
	}
	return temp;
}

int main(void) {
	linkedList_h* CL;
	listNode* p;
	CL = createLinkedList_h();
	printf("원형 연결 리스트 생성\n");
	
	printf("원형 연결리스트에 [월] 노드 삽입\n");
	insertFirstNode(CL, "월");
	printList(CL);
	
	printf("원형 연결리스트 [월]노드 뒤에 [수]노드 삽입\n");
	p = searchNode(CL, "월");
	insertMiddleNode(CL, p, "수");
	printList(CL);
	
	printf("원형 연결리스트 [수]노드 뒤에 [금]노드 삽입\n");
	p = searchNode(CL, "수");
	insertMiddleNode(CL, p, "금");
	printList(CL);
	
	printf("원형 연결리스트에서 [수]노드 삭제\n");
	p = searchNode(CL, "수");
	deleteNode(CL,p);
	printList(CL);
		
	return 0;
}
