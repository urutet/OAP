#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

char Func(int, char*);

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int i = 0, j = 0;
    char arr[40];
    char need = Func(i, arr);
    cout << endl << arr << endl;
    cout << endl << "Символ, получившийся после шага номер 26: " << need << endl;
}

char Func(int i, char* arr)
{

    int rmn = 67, rmx = 90;
    arr[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
    cout << (int)arr[i] << endl;
    if (i < 39)
    {
        return Func(i + 1, arr);
    }
    else
    {
        return arr[i];
    }
}