#include <iostream>
using namespace std;
void main()
{
	int A, i, B, p, q, m, n, maskA, maskB, s;
	char str1[33], str2[33];
	cout << "Vvedite chislo A ";
	cin >> A;
	_itoa_s(A, str1, 2);
	cout << "chislo A " << str1 << endl;
	cout << "Vvedite chislo B ";
	cin >> B;
	_itoa_s(B, str2, 2);
	cout << "chislo B " << str2 << endl;
	maskA = (1 << 2) - 1 << (5 - 1);
	_itoa_s(A & ~maskA, str1, 2);
	maskB = (1 << 2) - 1 << (5 - 1);
	_itoa_s((A & maskA) | (B & ~maskB), str2, 2);
	cout << "New B " << str2 << endl;
}