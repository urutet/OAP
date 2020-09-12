#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;


void v11_1();
void v11_2();
void v4_1();
void v4_2();
void v2_1();
void v2_2();
void v9_1();
void v9_2();

int main()
{
    SetConsoleOutputCP(1251);
	int k;
	cout << "Enter the program number " << endl;
	cin >> k;
	switch (k)
	{
	case 1: v11_1(); break;
	case 2: v11_2(); break;
	case 3: v4_1(); break;
	case 4: v4_2(); break;
	case 5: v2_1(); break;
	case 6: v2_2(); break;
	case 7: v9_1(); break;
	case 8: v9_2(); break;
	}
	return 0;
}


void v11_1()
{
	char buff[50];
	char minWord[50];
	int numOfWords = 0, numOfSym = 0, minNum = 50;
	ofstream fout;
	ifstream fin;
	fin.open("FILE1.txt");
	fout.open("FILE2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	else
	{
		do
		{
			fin.getline(buff, 50);	// Чтение строки из файла
			for (int i = 0; i < strlen(buff); i++)	// Цикл проверки символов буфера
			{
				if (buff[i] == ' ')
				{

					buff[0] = '\0';	// Если в строке есть пробел, то буфер пустой и строка не выводится во второй файл
					break;
				}
			}
			if (buff[0] == '\0')	// Если буфер стодержит перенос строки, то он не выводится
			{
				continue;
			}
			else
			{
				fout << buff << endl; // Вывод строки в файл
				numOfWords++;
			}
		} while (!fin.eof());
	}
	fin.close();
	fout.close();
	fin.open("FILE2.txt");
		do
		{
			fin.getline(buff, 50);
			numOfSym = strlen(buff);
			if (buff[0] == '\0')
			{
				continue;
			}
			if (numOfSym < minNum)
			{
				minNum = numOfSym;
				fin.getline(minWord, 50);
			}
		} while (!fin.eof());
		cout << minWord << endl;
		fin.close();
}
void v11_2()
{
	char buff[50];
	char minWord[50], maxWord[50];
	int numOfWords = 0, numOfSym = 0, vowels = 0, minNum = 99, maxNum = 0, startIndex = 0, endIndex = 0;
	ofstream fout;
	ifstream fin;
	fin.open("FILE11_1.txt");
	fout.open("FILE11_2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	else
	{
		getchar();
		cout << "Enter the first line " << endl; // Ввод первой строки
		cin.getline(buff, 50);
		fout << buff << endl; // Вывод в файл
		cout << "Enter the second line " << endl; // Ввод второй строки
		cin.getline(buff, 50);
		fout << buff << endl;// Вывод в файл

	}
	fin.close(); // Закрытие потока ввода
	fout.close(); // Закрытие потока вывода
	fin.open("FILE11_2.txt");
	fin.getline(buff, 50);
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u' || buff[i] == 'A' || buff[i] == 'E' || buff[i] == 'I' || buff[i] == 'O' || buff[i] == 'U')
		{
			vowels += 1; // Проверка на количество гласных
		}
		if (buff[i] == ' ' || buff[i] == '\0')
		{
			if (numOfSym < minNum)
			{
				minNum = numOfSym;
				endIndex = i;
				startIndex = i - (minNum);
				numOfSym = 0;
			}
		}													// Подсчет самого короткого слова
		else
		{
			numOfSym++;
			continue;
		}
	}
	cout << "minWord" << endl;
	for (int i = startIndex; i <= endIndex; i++)
	{
		cout << buff[i];			// Вывод слова
	}
	cout << endl;

	numOfSym = 0;
	startIndex = 0;
	endIndex = 0;
	fin.getline(buff, 50);
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u' || buff[i] == 'A' || buff[i] == 'E' || buff[i] == 'I' || buff[i] == 'O' || buff[i] == 'U')
		{
			vowels += 1;
		}
		if (buff[i] == ' ' || buff[i] == '\0')
		{
			if (numOfSym > maxNum)
			{
				maxNum = numOfSym;
				endIndex = i;
				startIndex = i - (maxNum);
				numOfSym = 0;
			}
		}															// Подсчет самого длинного слова
		else
		{
			numOfSym++;
			continue;
		}
	}
	cout << "maxWord" << endl;
	for (int i = startIndex; i <= endIndex; i++)
	{
		cout << buff[i];				// Вывод слова
	}
	cout << endl;
	cout << "Vowels " << vowels << endl;		// Вывод количества гласных
	fin.close();
}
void v4_1()
{
	char buff[50];
	char minWord[50];
	int numOfAWords = 0;
	ofstream fout;
	ifstream fin;
	fin.open("FILE4_1.txt");
	fout.open("FILE4_2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	else
	{
		do
		{
			fin.getline(buff, 50);
			for (int i = 0; i < strlen(buff); i++)
			{
				if (buff[i] == '0' || buff[i]=='1' || buff[i]=='2' || buff[i]=='3' || buff[i] =='4' || buff[i]=='5' || buff[i]=='6' || buff[i]=='7' || buff[i]=='8' || buff[i]=='9')
				{

					buff[0] = '\0';
					break;
				}
			}
			if (buff[0] == '\0')
			{
				continue;
			}
			else
			{
				fout << buff << endl;
				if (buff[0] == 'A' || buff[0] == 'a')
				{
					numOfAWords++;
				}
			}
		} while (!fin.eof());
	}
	fin.close();
	fout.close();
	cout << "Number of strings starting with A " << numOfAWords << endl;
}
void v4_2()
{
	char buff[50];
	char maxWord[50];
	int numOfWords = 0, numOfSym = 0, maxNum = 0, startIndex = 0, endIndex = 0;
	ofstream fout;
	ifstream fin;
	fin.open("FILE42_1.txt");
	fout.open("FILE42_2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	else
	{
		getchar();
		cout << "Enter the first line " << endl; // Ввод первой строки
		cin.getline(buff, 50);
		fout << buff << endl; // Вывод в файл
	}
	fin.close(); // Закрытие потока ввода
	fout.close(); // Закрытие потока вывода
	fin.open("FILE42_2.txt");
	fin.getline(buff, 50);
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == ' ' || buff[i] == '\0')
		{
			if (numOfSym > maxNum)
			{
				maxNum = numOfSym;
				endIndex = i;
				startIndex = i - (maxNum);
				numOfSym = 0;
			}
		}															// Подсчет самого длинного слова
		else
		{
			numOfSym++;
			continue;
		}
	}
	cout << "maxWord" << endl;
	for (int i = startIndex; i <= endIndex; i++)
	{
		cout << buff[i];				// Вывод слова
	}
	cout << endl;
	cout << "Chars count " << maxNum << endl;
}
void v2_1()
{
	char buff[50];
	char minWord[50];
	int numOfWords = 0;
	ofstream fout;
	ifstream fin;
	fin.open("FILE2_1.txt");
	fout.open("FILE2_2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	else
	{
		do
		{
			fin.getline(buff, 50);
			if (buff[0] == 'a' || buff[0] == 'A')
				fout << buff << endl;
			else
			{
				continue;
			}
		} while (!fin.eof());
	}
	fin.close();
	fout.close();
	fin.open("FILE2_2.txt");
	do
	{
		fin.getline(buff, 50);
		for (int i = 0; i < strlen(buff); i++)
		{
			if (buff[i] == ' ' || buff[i] == '\0')
			{
				numOfWords++;
			}
		}
	} while (!fin.eof());
	cout << "Number of words " << numOfWords << endl;
	fin.close();
}
void v2_2()
{
	char buff[50];
	char maxWord[50];
	int numOfWords = 0, numOfSym = 0, minNum = 99, startIndex = 0, endIndex = 0;
	ofstream fout;
	ifstream fin;
	fin.open("FILE42_1.txt");
	fout.open("FILE42_2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened!\n";
	else
	{
		getchar();
		cout << "Enter the first line " << endl; // Ввод первой строки
		cin.getline(buff, 50);
		fout << buff << endl; // Вывод в файл
	}
	fin.close(); // Закрытие потока ввода
	fout.close(); // Закрытие потока вывода
	fin.open("FILE42_2.txt");
	fin.getline(buff, 50);
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == ' ' || buff[i] == '\0')
		{
			if (numOfSym < minNum)
			{
				minNum = numOfSym;
				endIndex = i;
				startIndex = i - (minNum);
				numOfSym = 0;
			}
		}															// Подсчет самого короткого слова
		else
		{
			numOfSym++;
			continue;
		}
	}
	cout << "minGroup" << endl;
	for (int i = startIndex; i <= endIndex; i++)
	{
		cout << buff[i];				// Вывод слова
	}
	cout << endl;
}
void v9_1()
{
	char buff[50];
	int firstStr = 0, lastStr = 0, strCount = 1, wordCount = 0;
	ifstream fin("FILE9_1.txt");
	ofstream fout("FILE9_2.txt");
	cout << "Enter the first and the last line" << endl;
	cout << "1)"; cin >> firstStr;
	cout << "2)";  cin >> lastStr;
	if (!fin.is_open())
	{
		cout << "File cannot be opened\n";
	}
	else
	{
		do
		{
			fin.getline(buff, 50);
			int sizeOfStr = strlen(buff);
			if (strCount >= firstStr && strCount <= lastStr)
			{

				if (buff[0] == 'C' || buff[0] == 'c')
				{
					fout << buff << endl;
				}
			}
			strCount++;
		} while (!fin.eof());
	}
	fin.close();
	fout.close();
	fin.open("FILE9_2.txt");
	if (!fin.is_open())
		cout << "File cannot be opened\n";
	else
	{
		do
		{
			fin.getline(buff, 50);
			int sizeOfStr = strlen(buff);
			for (int i = 0; i < sizeOfStr; i++)
			{
				if (buff[i] == ' ' || buff[i] == '\0')
				{
					wordCount++;
				}
			}
		} while (!fin.eof());
	}
	cout << "There are " << wordCount << " words in the first line" << endl;
	fin.close();
	fout.close();
}
void v9_2()
{
	char buff[50];
	char str[20];
	int wordSize = 0, wordNumber = 0, minSize, necessWord = 0;
	ifstream fin;
	ofstream fout;
	fout.open("FILE92_2.txt");
	cout << "Enter the line " << endl; getchar();
	gets_s(buff);
	fout << buff;
	int sizeOfStr = strlen(buff);
	minSize = sizeOfStr;
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == ' ' || buff[i] == '\0')
		{
			wordNumber++;
			if (wordSize < minSize)
			{
				minSize = wordSize;
				necessWord = wordNumber;
			}
			wordSize = 0;
		}
		wordSize++;
	}
	cout << "MinWord in the line is the " << necessWord << ". Size of " << minSize-1 << " symbols" << endl;
	fin.close();
	fout.close();
}