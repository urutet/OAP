#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], p, k = 0;
	int rmn = 0, rmx = 99;
	int *ppos1, *ppos2;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А: " << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << "  ";
	}
	for (i = 0; i < sz; i++)
	{
		ppos1 = &A[i];
		for (p = i + 1; p < sz; p++)
		{
			ppos2 = &A[p];
			if (*ppos1 == *ppos2)
				k++;
		}
	}
	cout << "Kolichestvo par " << k << endl;
}