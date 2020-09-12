#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

void main()
{
	char str[50];
	int i;
	setlocale(LC_CTYPE, "Russian");
	cout << "Input string:";
	gets_s(str);
	for (i = 0; i < (strlen(str)-1); i++)
		if (str[i] != ' ' && str[i + 1] == ' ')
		{
			cout << str[i];
		}
		if (str[i] != ' ' && str[i + 1] == '\0')
		{
			cout << str[i];
		}
}