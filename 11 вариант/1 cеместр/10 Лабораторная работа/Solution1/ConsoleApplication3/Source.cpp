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
	cout << "Vvedite p ";
	cin >> p;
	cout << "Vvedite n ";
	cin >> n;
	maskA = (1 << n) - 1 << (p - 1);
	_itoa_s(A & ~maskA, str1, 2);
	cout << "A " << str1 << endl;
	cout << "Vvedite q" << endl; cin >> q;
	cout << "Vvedite m" << endl; cin >> m;
	maskB = (1 << m) - 1 << (q - 1);
	_itoa_s(B & maskB, str2, 2);
	cout << "Mask B " << str2 << endl;
	_itoa_s((A & maskA) | (B & ~maskB), str2, 2);
	cout << "New B " << str2 << endl;

}