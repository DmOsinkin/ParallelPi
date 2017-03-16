#include <iostream>
#include <time.h>

using namespace std;

int main() {
	double truePI = 4.*atan(1.);	//истинное число ПИ
	
	double pi = 1;	//инициализируем переменную, в которой будем хранить число ПИ, полученное параллельным алгоритмом.
	clock_t t1 = clock();	//отмеряем время начала
	
#pragma omp parallel for reduction(+:pi)	//вычисляем ПИ через распараллеливание
	for (int i = 1; i < 100000000; i++) {	//взяли 10 миллионов итераций
		pi += pow(-1, i) / (pow(3, i)*(2 * i + 1));	//используем ряды для вычисления ПИ
	}
	pi = pi * 2 * sqrt(3);
	clock_t t2 = clock();	//отмеряем время окончания вычислений
	printf("%.50f", pi);
	cout << endl << "Time: " << (double)(t2 - t1) / (double)CLOCKS_PER_SEC << '\n';	//время, затрченное на вычисление ПИ
	cout << endl;

	/*
	Вычисление без распараллеливания.
	*/

	double pi1 = 1;	//инициализируем переменную, в которой будем хранить число ПИ, полученное обычным алгоритмом.
	t1 = clock();
	for (int i = 1; i < 10000000; i++) {
		pi1 += pow(-1, i) / (pow(3, i)*(2 * i + 1));
	}
	pi1 = pi1 * 2 * sqrt(3);

	t2 = clock();
	printf("%.50f", pi1);
	cout << endl;
	cout << "Time: " << (double)(t2 - t1) / (double)CLOCKS_PER_SEC << '\n';
	cout << endl;
	printf("true PI = \n%.50f\n", truePI);
	system("pause");
}