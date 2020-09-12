#include <iomanip>
#include "time.h"
#include "iostream"
#include "conio.h"
#include "ctime"
using namespace std;
int main()
{
	int mas[50][50];
	int i, j, n, rmn = 0, rmx = 99, min = 99, maxi = 0;
	srand(time(NULL));
	cout << "Vvedite razmer massiva" << endl; cin >> n;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			mas[i][j] = (int)(((double)rand() /
				(double)RAND_MAX) * (rmx - rmn) + rmn);
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
	for (i = 0, j = 0; i < n, j < n; i++, j++)
	{
		if (mas[i][j] < min)
		{
			min = mas[i][j];
			maxi = j;
		}
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout << setw(4) << mas[i][maxi];
	}
}