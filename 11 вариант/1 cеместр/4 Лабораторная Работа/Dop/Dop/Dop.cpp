// Dop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
int _tmain(int argc, _TCHAR* argv[])

//
//void main()
{
	float r, p, q;

	printf("������� r "); scanf_s("%f", &r);
	printf("������� p "); scanf_s("%f", &p);
	printf("������� q "); scanf_s("%f", &q);
	if (r <= p*q / 2*(sqrt(pow(p, 2) + pow(q, 2)))) {
		printf("��, ��� ������� ����� ������������� ���������");
	}
	else {
		printf("���, ��� �� �������");
	}
}