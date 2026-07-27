#define _CRT_SECURE_NO_WARNINGS
#define SINGLE_LINKED_LIST
//#define DOUBLY_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

#if defined(SINGLE_LINKED_LIST)
typedef struct Node { //노드
	int data;
	struct Node* next;
}Node;

//리스트 중간에도 노드 추가 가능 함수
//head 포인터의 주소를 넘겨야 되서 이중 포인터를 넘겨야함
void insertNode(Node** head, int data, int position) {
	if (head == NULL || position < 0) {
		return; // 리스트 중간에 노드를 추가할 수 없는 경우 종료
	}
	Node* newNode = (Node*)malloc(sizeof(Node)); //힙 메모리 동적할당
	if (newNode == NULL) {
		return; //메모리 할당 실패 시 종료
	}
	newNode->data = data; //데이터 저장
	newNode->next = NULL; //마지막 노드는 항상 null을 가리킴

	if (position == 0) {// 맨 앞에 추가하는 경우
		newNode->next = *head;
		*head = newNode;
		return;
	}
	//중간이나 마지막에 추가하는 경우
	Node* temp = *head;
	//추가하려는 위치 바로 이전까지 이동
	for (int i = 0;i < position - 1;i++) {
		if (temp == NULL) {//리스트의 길이보다 큰 위치에 추가하려는 경우
			free(newNode);//위에서 할당한 메모리 해제. free를 안할 경우 메모리 누수 발생(힙 메모리 주소 상실)
			return;
		}
		temp = temp->next;
	}
	//빈리스트에 position 1이상으로 삽입하거나
	//리스트 범위를 초과한 경우
	if (temp == NULL) {
		free(newNode);
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return;
}

//리스트에서 원소값이 x인 노드를 탐색하는 함수
Node* searchNode(Node* headNode, int x) {
	Node* temp;
	temp = headNode;
	while (temp != NULL) {
		if (temp->data == x) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

//리스트에 검색한 값이 있을 경우 해당 노드를 삭제하는 함수
void deleteNode(Node** head, int x) {
	Node* current;
	Node* previous;
	if (head == NULL || *head == NULL) {
		return; 
	}
	current = *head;
	previous = NULL;
	while (current != NULL) {
		if (current->data == x) {
			break; 
		}
		previous = current;
		current = previous->next;
	}

	if (current == NULL) {
		return;	//삭제할 노드가 없는 경우 종료
	}
	if (previous == NULL) {		//첫 번째 노드를 삭제하는 경우(헤드가 삭제됨)
		*head = current->next;	//삭제 후 헤드를 변경해줘야 함
	}
	else {	//이전 노드가 삭제할 노드의 다음 노드를 가리키도록 변경
		previous->next = current->next; 
	}
	free(current);
	return;
}


//리스트의 마지막 노드까지 출력
void printList(Node* head) { //리스트 출력 함수
	Node* temp = head;
	while (temp != NULL) {//null을 만날때까지 
		printf("%d ", temp->data); //노드 출력
		temp = temp->next; //출력 후 다음 노드이동
	}
	printf("\n");
}



void freeList(Node** head) {
	if (head == NULL){
		return;
	}
	
	Node* current = *head;
	while (current != NULL) {
		//다음 노드를 저장하고 
		Node* nextNode = current->next;
		free(current); //현재 노드 제거
		current = nextNode; //다음 노드로 이동
	}
	
	*head = NULL;
}
#endif


int main() {
#if defined (SINGLE_LINKED_LIST)
	Node* head = NULL; //head 포인터 null초기화
	insertNode(&head, 10,0);
	insertNode(&head, 20,1);
	insertNode(&head, 30,2);
	puts("단일 연결 리스트 출력");
	printList(head);

	insertNode(&head, 5, 0);
	insertNode(&head, 15, 2);
	insertNode(&head, 35, 5);
	puts("추가한 연결 리스트 출력");
	printList(head);

	printf("노드 검색 : ");
	int x = 0;
	scanf("%d", &x);
	Node* cmp = searchNode(head, x);
	if (cmp != NULL && cmp->data == x) {
		puts("검색한 노드가 존재합니다.");
	}
	else {
		puts("검색한 노드가 존재하지 않습니다.");
	}
	
	deleteNode(&head,5);
	deleteNode(&head,15);
	deleteNode(&head,35);

	puts("삭제한 연결 리스트 출력");
	printList(head);

#endif
	freeList(&head);
	return 0;
}

