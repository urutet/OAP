#include <iostream>
using namespace std;
void main()
{
	int A, i, maskA;
	char str1[33], str2[33];
	cout << "Vvedite chislo A " << endl;
	cin >> A;
	_itoa_s(A, str1, 2);
	cout << "Old " << str1 << endl;
	maskA = (1 << 5) - 1 << (4 - 1);
	_itoa_s(A ^= maskA, str2, 2);
	cout << "New " << str2 << endl;
}