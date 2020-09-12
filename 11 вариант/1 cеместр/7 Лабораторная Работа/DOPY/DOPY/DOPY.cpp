// DOPY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

////////#include <iostream>
////////#include <stdio.h>
////////#include <math.h>
////////void main()
////////{
////////	setlocale(LC_CTYPE, "Russian");
////////	int n, i = 0, sum;
////////	for (n = 1; n <= 5; n++){
////////		printf("Введите целое число ");
////////		scanf_s("%d", i);
////////		if (i % 2 == 0){
////////			sum = sum + i;
////////		}
////////	}
////////}

#include <iostream>
#include <math.h>
using namespace std;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int maxsequence, n, counter;
//	float summ = 0;
//	cout << "Введите кол-во чисел в последовательности"<< endl;
//	cin >> maxsequence;
//	for (counter = 1; counter <= maxsequence; counter++)
//	{
//		cout << "Введите " << counter << " элемент последовательности" << endl;
//		cin >> n;
//		if (n % 2 == 0)
//		{
//			summ += n;
//		}
//	}
//	cout << "Сумма четных элементов последовательности равна " << summ << endl;
//}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int maxsequence, n, counter;
	float summ = 0, summ1 = 1;
	cout << "Введите кол-во чисел в последовательности"<< endl;
	cin >> maxsequence;
	for (counter = 1; counter <= maxsequence; counter++)
	{
		cout << "Введите " << counter << " элемент последовательности" << endl;
		cin >> n;
		if (n % 2 == 0)
		{
			summ += n;
		}
		else summ1 = summ1*n;
	}
	cout << "Сумма четных элементов последовательности равна " << summ << endl;
	cout << "Произведение нечетных элементов последовательности равна " << summ1 << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int maxsequence, n, counter;
	float summ = 0, summ1 = 1;
	cout << "Введите кол-во чисел в последовательности" << endl;
	cin >> maxsequence;
	for (counter = 1; counter <= maxsequence; counter++)
	{
		cout << "Введите " << counter << " элемент последовательности" << endl;
		cin >> n;
		if (n % 2 == 1)
		{
			summ += n;
		}
		summ = summ / n;
		cout << "Среднее арифметическое равно " << summ << endl;
	}