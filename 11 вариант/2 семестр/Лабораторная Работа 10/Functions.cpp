#include <iostream>
#include <fstream>
#include "Header.h"
#include <ctime>
#include <cmath>
using namespace std;


void prog1()
{
	int m, n, num;
	cout << "Enter m" << endl;
	cin >> m;
	cout << "Enter n" << endl;
	cin >> n;
	num = func(m, n);
	cout << num << endl;;
	system("pause");
}



int func(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return n + 1;
	}
	else
	{
		return func(m - 1, func(m, n - 1));
	}
}

void prog2()
{
	int n, x, num;
	cout << "Enter n" << endl;
	cin >> n;
	cout << "Enter x" << endl;
	cin >> x;
	num = del(n, x);
	cout << num << endl;
}

int del(int n, int x)
{
	if (x == 1)
	{
		return 1;
	}
	else if (n % x == 0 && x > 1)
	{
		return (del(n, x - 1) + 1);
	}
	else if (n % x != 0 && x > 1)
	{
		return (del(n, x - 1));
	}
}



void swap(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool NextSet(int* a, int n)
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false; // больше перестановок нет
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	swap(a, j, k);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r)
		swap(a, l++, r--);
	return true;
}
void Print(int* a, int n)  // вывод перестановки
{
	static int num = 1; // номер перестановки
	cout.width(3); // ширина поля вывода номера перестановки
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void dop3()
{
	int n, * a;
	cout << "N = ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	Print(a, n);
	while (NextSet(a, n))
		Print(a, n);
	cin.get(); cin.get();
}