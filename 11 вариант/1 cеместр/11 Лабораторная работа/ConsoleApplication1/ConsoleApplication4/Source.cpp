#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], B[N], t, k1 = 0, k2 = 0;
	int rmn = 0, rmx = 99;
	int *ppos1, *ppos2;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Введите t " << endl;
	cin >> t;
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
		cout << B[i] << "  " << endl;
		ppos1 = &A[i];
		ppos2 = &B[i];
	}
	for (i = 0; i < sz; i++)
	{
		if (*ppos1 == t)
			k1++;
		if (*ppos2 == t)
			k2++;
	}
	if (k1 > k2)
	{
		cout << "Массив A: " << endl;
		for (i = 0; i < sz; i++)
			cout << A[i] << " ";
		cout << "Массив B: " << endl;
		for (i = 0; i < sz; i++)
			cout << B[i] << " ";
	}
	else
		cout << "Массив B: " << endl;
	for (i = 0; i < sz; i++)
		cout << B[i] << " ";
	cout << endl;
	cout << "Массив A: " << endl;
	for (i = 0; i < sz; i++)
		cout << A[i] << " ";
	
}