//4344
#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int stu_num, sum = 0, count=0;
		int arr[1000];
		double avg;
		cin >> stu_num;
		for (int i = 0; i < stu_num; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		avg = sum / stu_num;
		for (int i = 0; i < stu_num; i++)
		{
			if (avg < arr[i]) count++;
		}
		cout.precision(5);
		cout << (float)count / stu_num * 100<<"%" << endl;
	}
	   
	return 0;
}
