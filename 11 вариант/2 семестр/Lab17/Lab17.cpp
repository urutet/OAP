#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
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
	int arr[4000], arr1[4000], arr2[4000], out[4000];
	
	for (int i = 0; i < 4000; i++)
	{
		arr[i] = rand() % 100;
		arr1[i] = rand() % 100;
		arr2[i] = rand() % 100;
	}
	cout << "Before sorting" << endl;
	for (int i = 0; i < 4000; i++)
	{
		cout << arr[i] << ' ';
	}
	clock_t start = clock();
	countSort(arr, out, sizeof(arr) / sizeof(int));
	clock_t end = clock();
	cout << endl;
	cout << "After Count Sorting sorting" << endl;
	for (int i = 0; i < 4000; i++)
	{
		cout << out[i] << ' ';
	}
	cout << endl;
	double seconds2 = (double)(end - start);
	cout << seconds2 << "clocks/sec" << endl;
	
}