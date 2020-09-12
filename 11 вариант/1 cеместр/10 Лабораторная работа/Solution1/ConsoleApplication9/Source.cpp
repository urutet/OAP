#include <iostream>
using namespace std;
void main()
{
	int A, i, maskA, n,p;
	char str1[33], str2[33];
	cout << "Vvedite chislo A " << endl;
	cin >> A;
	cout >> "Vvedite n i p " << endl; cin >> n; cin >> p;
	_itoa_s(A, str1, 2);
	cout << "Old " << str1 << endl;
	maskA = (1 << n) - 1 << (p - 1);
	_itoa_s(A ^= maskA, str2, 2);
	cout << "New " << str2 << endl;
}