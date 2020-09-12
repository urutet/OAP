#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], B[N], k1 = 0, k2 = 0, k3 = 0;
	int rmn = 0, rmx = 99;
	int *ppos1, *ppos2;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А: ";
	cout << "Массив B: " << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << "  ";
		B[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << B[i] << endl;
		ppos1 = &A[i];
		ppos2 = &B[i];
		if (*ppos1 == *ppos2)
			k1++;
		if (*ppos1 > *ppos2)
			k2++;
		if (*ppos1 < *ppos2)
			k3++;
	}
	cout << "Количество пар равных элементов " << k1 << endl;
	cout << "Количество пар элементов, где A > B " << k2 << endl;
	cout << "Количество пар элементов, где A < B " << k3 << endl;
}