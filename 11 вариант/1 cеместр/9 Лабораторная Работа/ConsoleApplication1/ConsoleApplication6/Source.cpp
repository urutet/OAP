#include <iostream>
#include <ctime>
#include <vector>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], k = 0;
	cout << "������� ���������� ����� � ������� " << endl;
	cin >> sz;
	cout << "������� ����� ������� " << endl;
	for (i = 0; i < sz; i++)
	{
		cin >> A[i];
	}
	for (i = 0; i < sz; i++)
	{
		if (A[i] == A[i + 1])
		{
			continue;
		}
		else k++;
		if (A[i] == A[i - 1])
		{
			continue;
		}
		else k++;
	}
	cout << k-1 << endl;
}