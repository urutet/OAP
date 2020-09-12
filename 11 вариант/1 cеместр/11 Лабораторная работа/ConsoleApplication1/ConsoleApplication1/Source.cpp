#include <iostream>
using namespace std;

void main()
{
	const int N = 50;
	int i, sz;
	int posled[N];
	int *ppos;
	cout << "Vvedite kolichestvo chisel " << endl;
	cin >> sz;
	for (i = 1; i < sz; i++)
	{
		posled[0] = 0;
		cout << "Vvedite chislo" << endl;
		cin >> posled[i];
		if (posled[i] - posled[i - 1] > 1)
		{
			ppos = &posled[i];
			break;
		}
		else continue;
	}
	cout << "Nedostajushee chislo " << *ppos - 1 << endl;

}