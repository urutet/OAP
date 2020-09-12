# include <iostream>
#include <ctime>
using namespace std;
void massiv();
void matrix();

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	do
	{
		cout << endl;
		cout << "Введите" << endl;
		cout << "1-одномерный массив" << endl;
		cout << "2-работа с матрицей" << endl;
		cout << "3-выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1: massiv(); break;
		case 2: matrix(); break;
		case 3: break;
		}
	} while (c != 3);
}

void massiv()
{
	setlocale(LC_CTYPE, "Russian");
	int* pStr; // указатель для адреса массива
	int *pc;
	int i, length, count = 0, rmx = 99, rmn = 0;

	cout << "Введите размер массива ";
	cin >> length;
	pStr = new int[length + 1];
	//выделение динам.памяти
	srand((unsigned)time(NULL));
	for (i = 0; i < length; i++)
	{
		pStr[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		// или A[i] = rand() % rmx; - для [0, rmx) 
		cout << pStr[i] << endl;
	}
	cout << endl;
	for (i = 0; i < length; i++)
	{
		if (pStr[i] == 0)
		{
			cout << i << endl;
			break;
		}
	}


	delete[] pStr; // освобождение динам. памяти
}



void matrix()
{
	int size, n, i = 0, k = 0;
	int** A;
	cout << "Enter size ";
	cin >> size;
	srand(time(0));
	A = new int* [size];
	for (int i = 0; i < size; i++)
	{
		A[i] = new int[size];
		for (int j = 0; j < size; j++)
			cin >> A[i][j];
	}
	cout << endl;
	for (int j = 0; j < size; j++)
	{
		k = 0;
		for (int i = 0; i < size; i++)
		{
			if (A[i][j] == A[j][i])
			{
				k++;
			}
		}
		if (k == size)
		{
			cout << "Номер одинаковых столбца и строчки " << j + 1 << endl;
		}
	}
	delete[] A;
}
