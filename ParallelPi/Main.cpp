#include <iostream>
#include <time.h>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main() {
	double truePI = 4.*atan(1.);	//�������� ����� ��
	
	double pi = 1;	//�������������� ����������, � ������� ����� ������� ����� ��, ���������� ������������ ����������.
	clock_t t1 = clock();	//�������� ����� ������
	
#pragma omp parallel for reduction(+:pi)	//��������� �� ����� �����������������
	for (int i = 1; i < 10000000; i++) {	//����� 10 ��������� ��������
		pi += pow(-1, i) / (pow(3, i)*(2 * i + 1));	//���������� ���� ��� ���������� ��
	}
	pi = pi * 2 * sqrt(3);
	clock_t t2 = clock();	//�������� ����� ��������� ����������
	printf("%.60f", pi);
	cout << endl << pi - truePI;
	cout << endl << "Time: " << (double)(t2 - t1) / (double)CLOCKS_PER_SEC << '\n';	//�����, ���������� �� ���������� ��
	cout << endl;

	/*
	���������� ��� �����������������.
	*/

	double pi1 = 1;	//�������������� ����������, � ������� ����� ������� ����� ��, ���������� ������� ����������.
	t1 = clock();
	for (int i = 1; i < 10000000; i++) {
		pi1 += pow(-1, i) / (pow(3, i)*(2 * i + 1));
	}
	pi1 = pi1 * 2 * sqrt(3);

	t2 = clock();
	printf("%.60f", pi1);
	cout << endl << pi1 - truePI;
	cout << endl;
	cout << "Time: " << (double)(t2 - t1) / (double)CLOCKS_PER_SEC << '\n';
	cout << endl;
	printf("true PI = \n%.60f\n", truePI);
	system("pause");
}