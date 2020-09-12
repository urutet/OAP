#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], k = 0;
	cout << "Введите количество чисел в массиве " << endl;
	cin >> sz;
	cout << "Введите числа массива " << endl;
	for (i = 0; i < sz; i++)
	{		cin >> A[i];
		if (A[i] == A[i - 1])
		{
			k++;
		}
	}
	cout << "Количество пар " << k << endl;
}