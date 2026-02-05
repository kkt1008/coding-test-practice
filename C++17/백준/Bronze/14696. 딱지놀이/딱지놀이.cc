//14696
#include<iostream>
using namespace std;
/*
만약 두 딱지의 별의 개수가 다르다면, 별이 많은 쪽의 딱지가 이긴다.
별의 개수가 같고 동그라미의 개수가 다르다면, 동그라미가 많은 쪽의 딱지가 이긴다.
별, 동그라미의 개수가 각각 같고 네모의 개수가 다르다면, 네모가 많은 쪽의 딱지가 이긴다.
별, 동그라미, 네모의 개수가 각각 같고 세모의 개수가 다르다면, 세모가 많은 쪽의 딱지가 이긴다.
별, 동그라미, 네모, 세모의 개수가 각각 모두 같다면 무승부이다.
*/
//별:4, 동그라미:3, 네모:2, 세모:1 

int main()
{
	int round_num;
	char arr1[100];
	char arr2[100];
	int num1, num2;
	
	cin >> round_num;
	for (int i = 0; i < round_num; i++)
	{
		int star1 = 0, circle1 = 0, square1 = 0, triangle1 = 0;
		int star2 = 0, circle2 = 0, square2 = 0, triangle2 = 0;

		cin >> num1;
		for (int j = 0; j < num1; j++)
		{
			cin >> arr1[j];
			switch (arr1[j])
			{
			case '4':star1++;
				break;
			case '3':circle1++;
				break;
			case '2':square1++;
				break;
			case '1':triangle1++;
				break;
			}
			
		}
		cin >> num2;
		for (int k = 0; k < num2; k++) 
		{
			cin >> arr2[k];
			switch (arr2[k])
			{
			case '4':star2++;
				break;
			case '3':circle2++;
				break;
			case '2':square2++;
				break;
			case '1':triangle2++;
				break;
			}
	
		}
		//둘중 한명이 이기는 경우
		if (star1 > star2) cout << "A" << endl;
		if (star1 < star2) cout << "B" << endl;
		if (star1 == star2 && circle1 > circle2) cout << "A" << endl;
		if (star1 == star2 && circle1 < circle2) cout << "B" << endl;
		if (star1 == star2 && circle1 == circle2 && square1 > square2) cout << "A" << endl;
		if (star1 == star2 && circle1 == circle2 && square1 < square2) cout << "B" << endl;
		if (star1 == star2 && circle1 == circle2 && square1 == square2 && triangle1 > triangle2) cout << "A" << endl;
		if (star1 == star2 && circle1 == circle2 && square1 == square2 && triangle1 < triangle2) cout << "B" << endl;
		//무승부인 경우
		if(star1 == star2 && circle1 == circle2 && square1 == square2 && triangle1 == triangle2) cout << "D" << endl;
		
	}
	return 0;
}