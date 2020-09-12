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
	cout << "Vvedite p ";
	cin >> p;
	cout << "Vvedite n ";
	cin >> n;
	maskA = (1 << n) - 1 << (p - n);
	_itoa_s(maskA, str2, 2);
	cout << str2 << endl;
	_itoa_s(A | maskA, str1, 2);
	cout << "A " << str1 << endl;
}