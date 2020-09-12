#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;
#define size 9

void enterNew();
void menu();
void sort();
void out();

int currentSize = 0, choice;
struct Sanatoria
{
    char name[20];
    char place[10];
    char heal[20];
    int amount;
};

struct Sanatoria listOfSanatoria[size];


void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "CАНАТОРИИ" << endl << endl;
    menu();
    cout << "Выберите пункт: ";
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 1:
        {
            enterNew();
            break;
        }
        case 2:
        {
            out();
            break;
        }
        }
    } while (choice != 4);
    cout << "~~Выход~~" << endl;
}

void menu()
{
    cout << "1.Ввод данных про санатории" << endl;
    cout << "2.Вывод данных" << endl;
    cout << "3.Поиск информации" << endl;
    cout << "4.Выход" << endl;
}

void enterNew()
{
    cout << endl << "Ввод информации" << endl << endl;
    if (currentSize < size)
    {
        cout << "Санаторий номер: " << currentSize + 1 << endl;
        cout << "Название санатория: "; cin >> listOfSanatoria[currentSize].name; cout << endl;
        cout << "Место расположения: "; cin >> listOfSanatoria[currentSize].place; cout << endl;
        cout << "Профиль лечение: "; cin >> listOfSanatoria[currentSize].heal; cout << endl;
        cout << "Количество путёвок: "; cin >> listOfSanatoria[currentSize].amount; cout << endl;
        cout << endl;
        currentSize++;
    }
    else
    {
        cout << "Введено максимальнон количество строк" << endl;
    }
    cout << "Запись добавлена" << endl << endl;
    menu();
    cout << "Что дальше? (выберите пункт)" << endl;
    cin >> choice;
}

void out()
{
    sort();
    cout << "Вывод данных в виде таблицы" << endl;
    for (int i = 0; i < 155; i++)
    {
        cout << "_";
    }
    cout << endl;
    for (int i = 0; i < 155; i++)
    {
        if (i != 0 && i != 5 && i != 25 && i != 30 && i != 55 && i != 60 && i != 80 && i != 85 && i != 157)
            cout << " ";
        if (i == 0)
            cout << "|";
        if (i == 5)
            cout << "Название санатория";
        if (i == 25)
            cout << "|";
        if (i == 30)
            cout << "Место расположения";
        if (i == 55)
            cout << "|";
        if (i == 60)
            cout << "Профиль лечения";
        if (i == 80)
            cout << "|";
        if (i == 85)
            cout << "Количество путёвок";
        if (i == 90)
            cout << "|";
    }
    cout << endl;
    for (int i = 0; i < 155; i++)
    {
        cout << "_";
    }
    cout << endl;
    for (int j = 0; j < currentSize; j++)
    {
        for (int i = 0; i < 155; i++)
        {
            if (i != 0 && i != 5 && i != 25 && i != 30 && i != 55 && i != 60 && i != 80 && i != 85 && i != 90)
                cout << " ";
            if (i == 0)
                cout << "|";
            if (i == 5)
                cout << listOfSanatoria[j].name;
            if (i == 25)
                cout << "|";
            if (i == 30)
                cout << listOfSanatoria[j].place;
            if (i == 35)
                cout << "|";
            if (i == 40)
                cout << listOfSanatoria[j].heal;
            if (i == 65)
                cout << "|";
            if (i == 85)
                cout << listOfSanatoria[j].amount;
            if (i == 90)
                cout << "|";
        }
        cout << endl;
        for (int i = 0; i < 155; i++)
        {
            cout << "_";
        }
        cout << endl;
    }
    cout << "Вывод завершен" << endl << endl;
    menu();
    cout << "Что дальше? (выберите пункт)" << endl;
    cin >> choice;
}


void sort()
{
    struct Sanatoria empty;
    for (int i = 0; i < currentSize; i++)
    {
        for (int j = i; j < currentSize; j++)
        {
            if (strcmp(listOfSanatoria[i].name, listOfSanatoria[j].name) > 0)
            {
                empty = listOfSanatoria[i];
                listOfSanatoria[i] = listOfSanatoria[j];
                listOfSanatoria[j] = empty;
            }
        }
    }
    for (int i = 0; i < currentSize; i++)
    {
        for (int j = i; j < currentSize; j++)
        {
            if (strcmp(listOfSanatoria[i].heal, listOfSanatoria[j].heal) > 0)
            {
                empty = listOfSanatoria[i];
                listOfSanatoria[i] = listOfSanatoria[j];
                listOfSanatoria[j] = empty;
            }
        }
    }
}