#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
#define size 3

void enterNew();
void menu();
void sort();
void afterTime();
void out();

int currentSize = 0, choice;
struct Trains
{
    char destination[20];
    char number[10];
    char depTime[10];
};

struct Trains listOfTrains[size];




void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "ПОЕЗДА" << endl << endl;
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
        case 3:
        {
            afterTime();
            break;
        }
        }
    } while (choice != 4);
    cout << "Выход" << endl;
}

void menu()
{
    cout << "1.Ввод данных про поезда" << endl;
    cout << "2.Вывод данных" << endl;
    cout << "3.Проверка наличия поездов после введенного времени" << endl;
    cout << "4.Выход" << endl;
}

void enterNew()
{
    cout << endl << "Ввод информации " << endl << endl;
    if (currentSize < size)
    {
        cout << "Поезд номер: " << currentSize + 1 << endl;
        cout << "Место назначения: "; cin >> listOfTrains[currentSize].destination; cout << endl;
        cout << "Номер поезда: "; cin >> listOfTrains[currentSize].number; cout << endl;
        cout << "Время отправления: "; cin >> listOfTrains[currentSize].depTime; cout << endl;
        cout << endl;
        currentSize++;
    }
    else
    {
        cout << "Введено максимальное количество строк" << endl;
    }
    cout << "Запись добавлена" << endl << endl;
    menu();
    cout << "Что дальше? (выберите пункт)" << endl;
    cin >> choice;
}

void out()
{
    sort();
    cout << endl << "Вывод информации о поездах " << endl << endl;
    for (int j = 0; j < currentSize; j++)
    {
        cout << "Поезд номер: " << j + 1 << endl;
        cout << "Место назначения: " << listOfTrains[j].destination << endl;
        cout << "Номер поезда: " << listOfTrains[j].number << endl;
        cout << "Время отправления: " << listOfTrains[j].depTime << endl;
    }
    cout << "Вывод завершён" << endl << endl;
    menu();
    cout << "Что дальше? (выберите пункт)" << endl;
    cin >> choice;
}

void sort()
{
    struct Trains empty;
    for (int i = 0; i < currentSize; i++)
    {
        for (int j = i; j < currentSize; j++)
        {
            if (strcmp(listOfTrains[i].destination, listOfTrains[j].destination) > 0)
            {
                empty = listOfTrains[i];
                listOfTrains[i] = listOfTrains[j];
                listOfTrains[j] = empty;
            }
        }
    }
}

void afterTime()
{
    cout << "Поиск поездов после определенного времени" << endl;
    char enteredTime[10];
    cout << "Введите нужное вам время: "; cin >> enteredTime;
    cout << "Результат поиска: " << endl;
    bool isTime = false;
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(listOfTrains[i].depTime, enteredTime) > 0)
        {
            isTime = !isTime;
            cout << "Поезд номер: " << i + 1 << endl;
            cout << "Место назначения: " << listOfTrains[i].destination << endl;
            cout << "Номер поезда: " << listOfTrains[i].number << endl;
            cout << "Время отправления: " << listOfTrains[i].depTime << endl;
        }
        if (!isTime)
        {
            cout << "Информация не найдена" << endl;
        }
    }
    menu();
    cout << "Что дальше? (выберите пункт)" << endl;
    cin >> choice;
}