#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <iostream>
using namespace std;
void prog11_1();
void prog11_2();
void prog15_1();
void prog15_2();
void prog14_1();
void prog14_2();
void prog9_1();
void prog9_2();

void main()
{
	int k;
	cout << "Input prog number " << endl;
	cin >> k;
	switch (k)
	{
	case 1: prog11_1(); break;
	case 2: prog11_2(); break;
	case 3: prog15_1(); break;
	case 4: prog15_2(); break;
	case 5: prog14_1(); break;
	case 6: prog14_2(); break;
	case 7:	prog9_1(); break;
	case 8:	prog9_2(); break;
	}
}

void prog11_1()
{
	int strA[20], maxNumOfInts = 0, numOfRepeats = 0;
	FILE* pfileA, * pfileB;
	int fsize;
	errno_t err;
	int strB[20];
	err = fopen_s(&pfileA, "fileA11.txt", "r");
	err = fopen_s(&pfileB, "fileB11.txt", "w");
	if (err != 0)
	{
		cout << "Unable to open the file" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
	}
	fseek(pfileA, 0L, SEEK_END);
	fsize = ftell(pfileA);
	fseek(pfileA, 0L, SEEK_SET);
	for (int i = 0; i < fsize; i++)
	{
		fscanf_s(pfileA, "%d", &strA[i]);
	}
	for (int i = 0; i < fsize; i++)
	{

		for (int n = i + 1; n < (fsize - i); n++)
		{
			if (strA[i] == strA[n])
			{
				numOfRepeats++;
			}
	
		}
		if (numOfRepeats == 1)
		{
			fprintf_s(pfileB, "%d", strA[i]);
			numOfRepeats = 0;
		}
	}

	for (int i = 0; i < fsize; i++)
	{

	}
	fclose(pfileA);
	fclose(pfileB);
}

void prog11_2() 
	{
		char strF[255];
		int fsize;
		FILE* F1, * F2;
		errno_t err;
		err = fopen_s(&F1, "F1.txt", "r");
		err = fopen_s(&F2, "F2.txt", "w");
		if (fopen_s(&F1, "F1.txt", "r") != 0)
		{
			cout << "Unable to open the file" << endl;
		}
		else
		{
			cout << "File is opened" << endl;
		}
		fseek(F1, 0L, SEEK_END);
		fsize = ftell(F1);
		fseek(F1, 0L, SEEK_SET);
		do
		{
			fgets(strF, fsize, F1);
			cout << strF << endl;
			if ((strF[strlen(strF) - 2] == 'A') || (strF[strlen(strF) - 2] == 'a'))
			{
				fputs(strF, F2);
				fputs("\n", F2);
			}
		} while (feof(F1) == 0);
		fclose(F1);
		fclose(F2);
	}

void prog15_1()
{
	FILE* file15_1, * file15_12;
	file15_1 = fopen("file15_1.txt", "r");
	file15_12 = fopen("file15_12.txt", "w");
	if (file15_1 && file15_12) {
		int k, dim;
		puts("Enter k");
		scanf("%d", &k);
		fscanf(file15_1, "%d ", &dim); //считываем размер матрицы
		if (dim >= k) {
			for (int i = 0; i < dim; i++)  //считываем и записываем число, если оно из нужного столбца. в противном случае игнорируем
				for (int j = 0; j < dim; j++) {
					if (j == (k - 1)) {
						float el;
						fscanf(file15_1, "%f%*c", &el);
						fprintf(file15_12, "%.1f\n", el);
					}
					else fscanf(file15_1, "%*f%*c");
				}

		}
		else puts("Нет такой колонки");
	}
	else puts("Ошибка открытия/создания файла");
	fclose(file15_1);
	fclose(file15_12);

}

void prog15_2()
{

	FILE* F1, * F2;
	int k; char str[50];
	errno_t err;
	err = fopen_s(&F1, "File1.txt", "w");
	if (err != 0) {
		cout << "Cannot create the file";
	}
	fputs("Somebody\n", F1);
	fputs("Once\n", F1);
	fputs("Told\n", F1);
	fputs("Me\n", F1);
	fputs("The\n", F1);
	fputs("World\n", F1);
	fputs("Is\n", F1);
	fputs("Gonna\n", F1);
	fclose(F1);
	err = fopen_s(&F1, "File1.txt", "r");
	if (err != 0) {
		cout << "Error opening F1.txt";
	}
	cout << "Enter k";
	cin >> k;
	err = fopen_s(&F2, "File2.txt", "w");
	if (err != 0) {
		cout << "Cannot create the file";
	}

	int newLineCount = 0;
	while (newLineCount != (k - 1) ) {
		if (fgetc(F1) == '\n') 
			newLineCount++;
	}//ищем символ перехода на новую строку, чтобы определить, где начинается нужная нам строка 
	for (int i = 0; i < 3; i++) {
		fgets(str, 50, F1);
		fputs(str, F2);
		//копируем 3 строки в новый файл
	}

	fclose(F2);
	fclose(F1);
}

void prog14_1()
{
	FILE* file15_1, * file15_12;
	file15_1 = fopen("file15_1.txt", "r");
	file15_12 = fopen("file15_12.txt", "w");
	if (file15_1 && file15_12) {
		int k, dim;
		puts("Enter k");
		scanf("%d", &k);
		fscanf(file15_1, "%d ", &dim); //считываем размер матрицы
		if (dim >= k) {
			for (int i = 0; i < dim; i++)  //считываем и записываем число, если оно из нужного столбца. в противном случае игнорируем
				for (int j = 0; j < dim; j++) {
					if (j == (k - 1)) {
						float el;
						fscanf(file15_1, "%f%*c", &el);
						fprintf(file15_12, "%.1f\n", el);
					}
					else fscanf(file15_1, "%*f%*c");
				}

		}
		else puts("Нет такой колонки");
	}
	else puts("Ошибка открытия/создания файла");
	fclose(file15_1);
	fclose(file15_12);

}

void prog14_2()
{
	FILE* F1_14, * F2_14;
	int num; char str[50];
	errno_t err;
	err = fopen_s(&F1_14, "F14_1.txt", "w");
	if (err != 0) {
		cout << "Cannot open the file";
	}
	fputs("1. Nothing Special\n", F1_14);
	fputs("smth\n", F1_14);
	fputs("3. else\n", F1_14);
	fputs("4. true\n", F1_14);
	fputs("ffs\n", F1_14);
	fputs("oke\n", F1_14);
	fclose(F1_14);
	err = fopen_s(&F1_14, "F14_1.txt", "r");
	if (err != 0) {
		cout << "Cannot open the file";
	}
	err = fopen_s(&F2_14, "F14_2.txt", "w");
	if (err != 0) {
		cout << "Cannot open the file";
	}
	while (!feof(F1_14)) {
		fgets(str, 50, F1_14);
		if (isdigit(str[0])) {

			fputs(str, F2_14);

		}

	}


	fclose(F2_14);
	fclose(F1_14);
}

void prog9_1()
{
	int strA[20], maxNumOfInts = 0, numOfRepeats = 0;
	FILE* pfileA, * pfileB;
	int fsize;
	errno_t err;
	int strB[20];
	err = fopen_s(&pfileA, "fileA9.txt", "r");
	err = fopen_s(&pfileB, "fileB9.txt", "w");
	if (err != 0)
	{
		cout << "Unable to open the file" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
	}
	fseek(pfileA, 0L, SEEK_END);
	fsize = ftell(pfileA);
	fseek(pfileA, 0L, SEEK_SET);
	for (int i = 0; i < fsize; i++)
	{
		fscanf_s(pfileA, "%d", &strA[i]);
	}
	for (int i = 0; i < fsize; i++)
	{

		for (int n = i + 1; n < (fsize - i); n++)
		{
			if (strA[i] == strA[n])
			{
				numOfRepeats++;
			}

		}
		if (numOfRepeats == 0)
		{
			fprintf_s(pfileB, "%d", strA[i]);
			numOfRepeats = 0;
		}
	}

	for (int i = 0; i < fsize; i++)
	{

	}
	fclose(pfileA);
}

void prog9_2()
{
	char strF[255];
	int fsize, k;
	FILE* F1, * F2;
	errno_t err;
	err = fopen_s(&F1, "F1_9.txt", "r");
	err = fopen_s(&F2, "F2_9.txt", "w");
	if (fopen_s(&F1, "F1_9.txt", "r") != 0)
	{
		cout << "Unable to open the file" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
	}
	cout << "Enter k " << endl;
	cin >> k;
	fseek(F1, 0L, SEEK_END);
	fsize = ftell(F1);
	fseek(F1, 0L, SEEK_SET);
	do
	{
		fgets(strF, fsize, F1);
		if (strlen(strF) > k)
		{
			fputs(strF, F2);
			fputs("\n", F2);
		}
	} while (feof(F1) == 0);
	fclose(F1);
	fclose(F2);
}