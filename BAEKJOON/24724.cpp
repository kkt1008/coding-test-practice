#include <iostream>
using namespace std;

int main() {
	int T = 0; //부품 관리 횟수
	int N = 0; //부품의 개수
	int A = 0; // 각 그룹의 크기 제한
	int B = 0; // 각 그룹의 무게 제한

	cin >> T; // 최초에 부품 관리 횟수 입력받음
	for (int numT = 0; numT < T; numT++) {
		cin >> N; // 각 관리횟수 별로 부품 갯수 새롭게 입력받음
		cin >> A >> B; // 크기제한, 무게 제한 입력 받음
		for (int numN = 0; numN < N; numN++) { //부품 종류들 입력
			int num1 = 0; int num2 = 0;
			cin >> num1 >> num2;
		}

	}

	for (int i = 0; i < T; i++) {
		cout << "Material Management "<<i+1 << endl;
		cout << "Classification ---- End!" << endl;
	}

	return 0;
}
