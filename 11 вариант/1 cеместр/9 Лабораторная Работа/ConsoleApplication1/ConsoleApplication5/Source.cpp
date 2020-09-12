#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], k = 0;
	float s = 0;
	cout << "¬ведите четное количество чисел в массиве " << endl;
	cin >> sz;
	cout << "¬ведите числа массива " << endl;
	for (i = 0; i < sz; i++)
	{
		cin >> A[i];
		s = s + A[i];
	}
	s = s / sz;
	for (i = 0; i < (sz/2); i++)
	if (A[i] > s)
	{
		continue;
	}
	else
	{
		A[(sz / 2) + i] = A[i];
	}
	for (i = 0; i < sz; i++);
	{
		cout << A[i] << endl;
	}
}