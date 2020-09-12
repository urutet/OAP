#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N];
	int rmn = 0, rmx = 99;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А:" << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << endl;
	}
	for (i = 0; i < sz; i++)
	{
		if (A[i] % 2 == 1)
		{
			for (int k = i; k < sz; k++){
				A[i] = A[i + 1];
			}	
			sz--; i--;

		}
	}
	cout << endl;
	sz += 3;
	for (i = sz - 3; i < sz; i++)
		A[i] = 0;
	for (i = 1; i < sz; i++)
		cout << A[i] << endl;
}