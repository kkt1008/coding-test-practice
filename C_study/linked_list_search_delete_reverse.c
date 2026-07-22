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

//리스트에서 노드를 삭제하는 연산
void deleteNode(linkedList_h* L, listNode* p) { // L: 리스트 시작 주소(헤더 노드), p:삭제할 노드의 바로 앞 노드
	listNode* pre; //pre가 가리키는 다음 노드를 삭제함
	if (L->head == NULL) {//공백리스트라 삭제할 노드 없음
		return;//연산 중지
	}
	if (L->head->link = NULL) {//리스트에 노드가 한개(헤더 노드가 유일)
		free(L->head); //헤더 노드를 메모리 해제
		L->head = NULL; //리스트 시작 포인터 NULL로 초기화 
		return;
	}
	else if (p = NULL) return; //삭제할 노드가 없으면 연산 중단
	else {//리스트에 노드가 존재하는 경우
		pre = L->head; //삭제할 노드의 선행자 노드를 포인터 pre를 이용해 찾기
		while (pre->link != p) {//삭제 노드의 선행 노드를 찾을때까지 탐색 
			pre = pre->link;
		}
		pre->link = p->link; //선행자 노드와 삭제할 노드의 다음 노드를 연결
		free(p); //삭제 노드의 메모리 해제
	}
}

//리스트에서 원소값이x 노드를 탐색하는 함수
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp; //리스트 노드 순회 포인터
	temp = L->head;//리스트의 시작 주소로 temp 초기화
	while(temp!=NULL){ //노드의 마지막이 null을 반환할 때까지 탐색
		if (strcmp(temp->data, x) == 0) {//노드의data와 원소값 비교. 같으면 0반환
			return temp; //참일 경우 노드를 가리키는 포인터 반환
		}
		else {
			temp = temp->link; //아닐경우 temp에 다음 노드를 할당한 뒤 다시 비교
		}
	}
	return temp;
}

//리스트의 노드 순서를 역순으로 바꾸는 연산====> 가장 어려움!!!
void reverse(linkedList_h* L) {
	listNode* p; //
	listNode* q; //p
	listNode* r; //q

	p = L->head; //p를 첫 번째 노드에 설정
	q = NULL; 
	r = NULL; 

	//리스트의 첫 번째 노드부터 링크를 따라 다음 노드를 이동하면서 노드 간의 연결을 바꿈
	while (p != NULL) {
		r = q; //둘다 NULL로 초기화된 상태. 
		q = p; //q와 p가 같은 노드를 바라봄
		p = p->link; //헤더가 가리키는 다음 노드를 p에 할당. q는 처음 노드 그대로 가리키는 중.
		q->link = r; //q가 가리키는 노드의 링크가 null이 되면서 노드 연결이 끊김. 
	}
	L->head = q;
}
