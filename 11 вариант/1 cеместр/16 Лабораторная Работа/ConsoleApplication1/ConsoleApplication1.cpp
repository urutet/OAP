#include <iostream>
#include <ctime>
#include <locale.h>
using namespace std;
int summaElementov(int**, int); // Прототип функции
int minElement(int**, int,  ...);



int main()
{
	setlocale(LC_ALL, "Russian");
	int size, i = 0, k = 0;
	int** A;

	cout << "Enter size ";
	cin >> size;
	A = new int* [size];	// Создание указателя на начало динамического массива
	for (int i = 0; i < size; i++) // Заполнение динамического массива
	{
		A[i] = new int[size];
		for (int j = 0; j < size; j++)
			cin >> A[i][j];
	}
	cout << "Выберите действие " << endl;
	cout << "1 - Сумма элементов массива " << endl;
	cout << "2 - Минимальный элемент в массиве " << endl;
	cin >> k;
			switch (k)
			{
			case 1: summaElementov(A, size); // Использование функции
				cout << summaElementov(A, size) << endl; // Вывод значения, которое вернула функция
			case 2: minElement(A, size);
				cout << minElement(A, size) << endl;
			}
	
	delete[] A; // Освобождение памяти/Удаление массива
}

int summaElementov(int** A, int size) // Тело функции
{
	setlocale(LC_ALL, "Russian");
	int sum = 0, sum1 = 0;
	bool plus = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i][j] < 0)	// Проверка числа массива на знак
			{
				plus = false;
				sum1 = 0;
				break;
			}
			else
			{
				plus = true;
				sum1 += A[i][j];	// Sum1 - буфер, который очищается, если plus==false
			}
		}
		if (plus == true)
		{
			sum += sum1;
			sum1 = 0;
		}
	}
	return (sum);	// Возврат значения суммы
}


int minElement(int** A, int size, ...)
{
	setlocale(LC_ALL, "Russian");
	int minEl = 999999;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i][j] < minEl)
			{
				minEl = A[i][j];
			}
		}
	}
	return (minEl);	// Возврат минимального элемента
}