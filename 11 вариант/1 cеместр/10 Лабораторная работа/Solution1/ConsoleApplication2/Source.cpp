#include <iostream>
using namespace std;
void main()
{
	int A, i;
	char str[33];
	cout << "Vvedite chislo ";
	cin >> A;
	_itoa_s(A, str, 2);
	cout << str << endl;
	if ((A & 0x0F) == 0)
		cout << "Chislo kratno 16";
	else
		cout << "Chislo ne kratno 16";
}