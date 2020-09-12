#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int getHoarBorder(int* A, int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int* A, int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};
void countSort(int* in, int* out, int size)
{
	int i, j, count;
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j)
			if (in[j] < in[i] || (in[j] == in[i] && i < j))
				count++;
		out[count] = in[i];
	}
}
void bubbleSort(int* A, int size)
{
	int i, j, t;
	for (i = 1; i < size; i++)
		for (j = size - 1; j >= i; j--)
			if (A[j - 1] > A[j])
			{
				t = A[j - 1];
				A[j - 1] = A[j];
				A[j] = t;
			}
}



void ShellSort(int* A, int size)
{
	int step, i, j, tmp;

	// Выбор шага
	for (step = size / 2; step > 0; step /= 2)
		// Перечисление элементов, которые сортируются на определённом шаге
		for (i = step; i < size; i++)
			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && A[j] > A[j + step]; j -= step)
			{
				tmp = A[j];
				A[j] = A[j + step];
				A[j + step] = tmp;
			}
}


void main()
{
	static int a[10], b[10], c[20];
	int numOfElements = 0;
	srand(time(NULL));
	time_t start, end;
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
		b[i] = rand() % 100;
	}
	int* cptr = c;
	int* cptr1 = c;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] % 2 == 1)
		{
			*cptr = a[i];
			cptr += 1;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (b[i] % 2 == 0)
		{
			*cptr = b[i];
			cptr += 1;
		}
	}
	numOfElements = cptr - cptr1;
	int* c1 = new int[numOfElements];

	for (int i = 0; i < numOfElements; i++)
	{
		c1[i] = c[i];
	}
	int* c2 = new int[numOfElements];

	for (int i = 0; i < numOfElements; i++)
	{
		c2[i] = c[i];
	}

	int* in = new int[numOfElements];

	for (int i = 0; i < numOfElements; i++)
	{
		in[i] = c[i];
	}
	int* out = new int[numOfElements];

	int* bubble = new int[numOfElements];

	for (int i = 0; i < numOfElements; i++)
	{
		bubble[i] = c[i];
	}

	cout << "Before sorting" << endl;
	for (int i = 0; i < numOfElements; i++)
	{
		cout << c1[i] << ' ';
	}
	cout << endl;
	time(&start);
	sortHoar(c1, 0, numOfElements);
	time(&end);
	cout << "After Hoar's sorting" << endl;
	for (int i = 1; i < numOfElements+1; i++)
	{
		cout << c1[i] << ' ';
	}
	cout << endl;
	double seconds = difftime(end, start);
	cout << seconds << "sec" << endl;
	system("pause");
	time(&start);
	ShellSort(c2, numOfElements);
	time(&end);
	cout << "After Shell's sorting" << endl;
	for (int i = 1; i < numOfElements + 1; i++)
	{
		cout << c1[i] << ' ';
	}
	cout << endl;
	double seconds1 = difftime(end, start);
	cout << seconds1 << "sec" << endl;
	system("pause");

	time(&start);
	countSort(in, out, numOfElements);
	time(&end);
	cout << "After Count Sorting sorting" << endl;
	for (int i = 0; i < numOfElements; i++)
	{
		cout << out[i] << ' ';
	}
	cout << endl;
	double seconds2 = difftime(end, start);
	cout << seconds2 << "sec" << endl;
	system("pause");

	time(&start);
	bubbleSort(bubble, numOfElements);
	time(&end);
	cout << "After Bubble Sorting sorting" << endl;
	for (int i = 0; i < numOfElements; i++)
	{
		cout << bubble[i] << ' ';
	}
	cout << endl;
	double seconds3 = difftime(end, start);
	cout << seconds3 << "sec" << endl;
	system("pause");
}