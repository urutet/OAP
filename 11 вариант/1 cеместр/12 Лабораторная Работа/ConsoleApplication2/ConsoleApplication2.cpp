#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

void main()
{
	char str[50];
	char *pstr;
	int i;
	setlocale(LC_CTYPE, "Russian");
	cout << "Input string:";
	gets_s(str);
	for (pstr = str; *pstr < (strlen(str) - 1); pstr++)
		if (*pstr != ' ' && *pstr == ' ')
		{
			cout << pstr;
		}
	if (*pstr != ' ' && *pstr == '\0')
	{
		cout << pstr;
	}
}