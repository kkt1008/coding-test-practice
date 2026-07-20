#include<stdio.h>

#define MAX(a,b) ((a>b) ? a:b)
#define MAX_DEGREE 50

typedef struct {			//구조체 polynomial 정의
	int degree;				//다항식 차수
	float coef[MAX_DEGREE];	//다항식 각 항의 계수
}polynomial;

//함수 선언
polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

int main() {
	//다항식 초기화
	polynomial A = { 3, {4,3,5,0} }; 
	polynomial B = { 4, {3,1,0,2,1} };

	polynomial C;

	C = addPoly(A, B);// 다항식 A,B에 대한 덧셈 진행을 위한 함수 호출

	//다항식 출력
	printf("\nA(x) = "); printPoly(A);
	printf("\nB(x) = "); printPoly(B);
	printf("\nC(x) = "); printPoly(C);
	
	return 0;
}

polynomial addPoly(polynomial A, polynomial B) { //다항식 2개를 더한 다항식을 반환하는 함수
	polynomial C;

	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);
	
	//각 항의 차수는 A>B , A=B, A<B 3가지 존재
	while (A_index <= A.degree && B_index <= B.degree) {//A와 B의 모든 다항식의 차수 이내일 때까지 연산 수행
		if (A_degree > B.degree) {// A>B 일 때, A의 계수를 먼저 저장
			C.coef[C_index++] = A.coef[A_index++];// A의차수를 저장 후, C 인덱스 증가
			A_degree--;// 처리한 A의 차수 -1 감소
		}
		else if (A_degree == B_degree) {// A=B 일 때, A,B 두 항의 덧셈 결과를 저장
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			//두 다항식 모두 차수가 같은 항을 처리했으므로 A,B 둘다 차수를 -1 감소시켜줘야함
			A_degree--; 
			B_degree--;
		}
		else {// A<B 일 때, B의 계수를 먼저 저장
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C; //덧셈 결과 반환
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i < P.degree+1; i++) { //P.degree 만큼의 항을 출력
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" + ");
	}
	printf("\n");
}
