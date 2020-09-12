#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

void main()
{
	char maxword[50], str[50], minword[50];
	int i, mx = 0, mn = 0, buf = 0, k = 0, s = 0, firstcharpos = 0, k1 = 0, g, j = 0, j1 = 99, firstpos1 = 0;
	setlocale(LC_CTYPE, "Russian");
	cout << "Input string:";
	gets_s(str);
	for (i = 0; i < (strlen(str) - 1); i++)
		if (str[i] != ' ' && str[i] != '\0')
		{
			k++;
			firstcharpos = i - s;
			s++;
			cout << firstcharpos << endl;
		}
		else
		{
			if (k > k1)
			{
				for (g = firstcharpos; g < (firstcharpos + k); g++)
				{
					maxword[g] = str[g];
				}
				k1 = k;
				firstpos1 = firstcharpos;
				k = 0;
				s = 0;
				cout << "k1 "<< k1 << endl;
			}
			cout << maxword << endl;
		}
	cout << maxword << endl;
	for (g = firstpos1; g < (firstpos1 + k1); g++)
	{
		cout << maxword[g];
	}
	//cout << endl;


	//for (i = 0; i < (strlen(str) - 1); i++)
	//	if (str[i] != ' ' && str[i] != '\0')
	//	{
	//		k++;
	//		firstcharpos = i - s;
	//		s++;
	//		cout << firstcharpos << endl;
	//	}
	//	else
	//	{
	//		if (j < j1)
	//		{
	//			for (g = firstcharpos; g < (firstcharpos + k); g++)
	//			{
	//				maxword[g] = str[g];
	//			}
	//			j1 = j;
	//			j = 0;
	//			s = 0;
	//			cout << "j1 " << j1 << endl;
	//		}
	//		else {
	//			continue;
	//		}
	//	}
	//for (g = firstcharpos; g < (firstcharpos + k1); g++)
	//{
	//	cout << maxword[g];
	//}
}