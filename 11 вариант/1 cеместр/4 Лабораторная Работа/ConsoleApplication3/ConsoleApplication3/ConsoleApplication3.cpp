// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int d;
	puts("��� ����? (1-�������, 2-�� �����)");
	cin >> d;
	switch (d)
	{
	case 1: { puts("���� ����� ���������? (1 - ����� ������, 2 - ����� ����, 3 - ������� ���������");
		cin >> d;
		switch (d)
		{
		case 1: puts("�������!"); break;
		case 2: puts("�������! ������� ���� �� ����"); break;
		case 3: puts("�������! ���� � ������� �� ���� ����");
			break;
		}
		break;
	}
	case 2: puts("��� ���������?");
		cin >> d;
		switch (d)
		{
		case 1: puts("������ ������"); break;
		case 2: puts("������� � ������"); break;
		case 3: puts("�������� ��������� �� ���� ����"); break;
		}
		break;
	default: puts("�������� ���� �� ������������ ���������"); break;
	}
	return 0;
}
