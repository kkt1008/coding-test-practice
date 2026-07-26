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
	if (CL == NULL) {//malloc 실패 검사
		return;
	}
	CL->head = NULL;
	return CL;
}

//연결리스트를 순서대로 출력하는 함수
void printList(linkedList_h* CL) {
	listNode* p;
	printf("CL=(");

	if (CL == NULL || CL->head == NULL) {//공백 리스트이면 빈 상태 출력
		printf(")\n");
		return;
	}

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
	if (CL == NULL || pre == NULL|| x==NULL) {//pre가 있는 노드인지 검색
		return;
	}

	newNode = (listNode*)malloc(sizeof(listNode));
	if (newNode == NULL) {//malloc 실패 여부 검사 습관화!!
		return;
	}

	strcpy(newNode->data, x);
	newNode->link = pre->link;
	pre->link = newNode;
	return;
}

//pre뒤에 노드를 삭제하는 함수
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;
	if (CL==NULL||CL->head == NULL||old==NULL) {//공백 리스트는 삭제 연산 중단
		return;
	}
	if (CL->head->link == CL->head) {//노드가 1개만 있는 경우
		free(CL->head); //1개 노드만 해제 
		CL->head = NULL; //리스트 시작 포인터 NULL로 설정
		return;
	}

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

//원형 연결 리스트에서 x노드를 찾는 함수
//리스트에 없는 노드를 요청해도 항상 노드 전체를 한 바퀴 탐색한 뒤 결과 반환
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp;
	
	if (CL == NULL || CL->head == NULL) {
		return NULL;
	}
	temp = CL->head;

	do {
		if (strcmp(temp->data, x) == 0) {
			return temp;//같을 경우 해당 노드 반환
		}
		temp = temp->link; //다를 경우 다음 노드로 이동
	} while (temp != CL->head); //다시 시작노드로 돌아올 때까지 
	return NULL;
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
