#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
	//백준 3003번
	//흰색 킹, 퀸, 룩, 비숍, 나이트, 폰의 개수가 첫줄에 주어짐
	//총 16개 킹-1 퀸-1 룩-2 비숍-2 나이트-2 폰-8
	int initKing = 1;
	int initQueen = 1;
	int initLook = 2;
	int initBishop = 2;
	int initKnight = 2;
	int initPawn = 8;

	int inputKing = 0;
	int inputQueen = 0;
	int inputLook = 0;
	int inputBishop = 0;
	int inputKnight = 0;
	int inputPawn = 0;

	int resultKing = 0;
	int resultQueen = 0;
	int resultLook = 0;
	int resultBishop = 0;
	int resultKnight = 0;
	int resultPawn = 0;

	cin >> inputKing >> inputQueen >> inputLook >> inputBishop >> inputKnight >> inputPawn;

	resultKing = initKing - inputKing;
	resultQueen = initQueen - inputQueen;
	resultLook = initLook - inputLook;
	resultBishop = initBishop - inputBishop;
	resultKnight = initKnight - inputKnight;
	resultPawn = initPawn - inputPawn;

	cout << resultKing << " " << resultQueen << " " << resultLook << " "<<  resultBishop << " " << resultKnight << " " << resultPawn << endl;

	return 0;
}