#include <iostream>
#include <stdlib.h>
using namespace std;

void main()
{
	int ch, *ch1, n, i = 1, sz, m, A[50];
	char posled[50];
	char *ppos;
	cout << "Vvedite chislo ";
	cin >> ch;
	cout << "Vvedite m ";
	cin >> m;
	ch1 = &ch;
	for (*ch1; *ch1 >= 1;)
	{
		n = *ch1 % 10;
		*ch1 = *ch1 / 10; 
		if (n % m == 0)
		{
			cout << n << endl;
		}
		else continue;
	}

}