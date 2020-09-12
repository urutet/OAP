//Список авто-2

#include <iostream>
using namespace std;

# define str_len 30                            
# define size 30  

char varArray[str_len];

using namespace std;
void enter_new();
void del();
void out();
void search();
void productionDate();
void techVis();

struct date
{
	int year : 7;
	int month : 5;
	int day : 5;
};

struct Cars
{
	char clientName[str_len];
	union
	{
		char longName[str_len];
		char shortName[10];
	} listOfCarsManufact[size];
	char color[10];
	char VIN[10];
	char bodyType[10];
	struct date productionDate;
	struct date techVision;
	bool isShort;
};
struct Cars carsList[size];
struct Cars bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
		case 4: search(); break;
		}
	} while (choice != 5);
}


void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Имя клиента " << endl;
		cin >> carsList[current_size].clientName;
		cout << "Марка автомобиля " << endl;
		cin >> varArray;
		if (strlen(varArray) <= 10)
		{
			carsList[current_size].isShort = true;
			strcpy_s(carsList[current_size].listOfCarsManufact->shortName, varArray);
		}
		else
		{
			carsList[current_size].isShort = false;
			strcpy_s(carsList[current_size].listOfCarsManufact->longName, varArray);
		}
		cout << "Цвет автомобиля " << endl;
		cin >> carsList[current_size].color;
		cout << "VIN автомобиля " << endl;
		cin >> carsList[current_size].VIN;
		cout << "Тип кузова " << endl;
		cin >> carsList[current_size].bodyType;
		cout << "Дата выпуска " << endl;
		productionDate();
		cout << "Дата последнего ТО " << endl;
		techVis();
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
		cout << "Что дальше?" << endl;
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для вывода записи(ей)" << endl;
		cout << "4-для поиска по владельцам " << endl;
		cout << "5-для выхода" << endl;
		cin >> choice;
}


void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			carsList[de1] = carsList[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			carsList[i] = bad;
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}


void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << endl << "Имя клиента " << endl;
		cout << carsList[n].clientName << endl;
		cout << "Марка автомобиля " << endl;
		if (carsList[n].isShort == true)
		{
			cout << carsList[n].listOfCarsManufact->shortName << endl;
		}
		else
		{
			cout << carsList[n].listOfCarsManufact->longName << endl;
		}
		cout << "Цвет " << endl;
		cout << carsList[n].color << endl;
		cout << "VIN автомобиля " << endl;
		cout << carsList[n].VIN << endl;
		cout << "Тип кузова " << endl;
		cout << carsList[n].bodyType << endl;
		cout << "Дата производства " << endl;
		cout << carsList[n].productionDate.day << '.' << carsList[n].productionDate.month << '.' << carsList[n].productionDate.year << endl;
		cout << "Дата последнего ТО " << endl;
		cout << carsList[n].techVision.day << '.' << carsList[n].techVision.month << '.' << carsList[n].techVision.year << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Имя клиента " << endl;
			cout << carsList[i].clientName << endl;
			cout << "Марка автомобиля " << endl;
			if (carsList[i].isShort == true)
			{
				cout << carsList[i].listOfCarsManufact->shortName << endl;
			}
			else
			{
				cout << carsList[i].listOfCarsManufact->longName << endl;
			}
			cout << "Цвет " << endl;
			cout << carsList[i].color << endl;
			cout << "VIN автомобиля " << endl;
			cout << carsList[i].VIN << endl;
			cout << "Тип кузова " << endl;
			cout << carsList[i].bodyType << endl;
			cout << "Дата производства " << endl;
			cout << carsList[i].productionDate.day << '.' << carsList[i].productionDate.month << '.' << carsList[i].productionDate.year << endl;
			cout << "Дата последнего ТО " << endl;
			cout << carsList[i].techVision.day << '.' << carsList[i].techVision.month << '.' << carsList[i].techVision.year << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}

void productionDate()
{
	int var;
	cout << "Введите год выпуска 20(__) " << endl;
	cin >> var;
	carsList[current_size].productionDate.year = var;
	cout << "Введите месяц выпуска " << endl;
	cin >> var;
	carsList[current_size].productionDate.month = var;
	cout << "Введите день выпуска " << endl;
	cin >> var;
	carsList[current_size].productionDate.day = var;
}
void techVis()
{
	int var;
	cout << "Введите год ТО 20(__) " << endl;
	cin >> var;
	carsList[current_size].techVision.year = var;
	cout << "Введите месяц ТО " << endl;
	cin >> var;
	carsList[current_size].techVision.month = var;
	cout << "Введите день ТО " << endl;
	cin >> var;
	carsList[current_size].techVision.day = var;
}

void search()
{
	char varArray[str_len];
	cout << "Введите фамилию владельца " << endl;
	cin >> varArray;
	for (int i = 0; i < current_size; i++)
		if (_stricmp(carsList[i].clientName, varArray) == 0)
		{
			cout << endl << "Имя клиента " << endl;
			cout << carsList[i].clientName << endl;
			cout << "Марка автомобиля " << endl;
			if (carsList[i].isShort == true)
			{
				cout << carsList[i].listOfCarsManufact->shortName << endl;
			}
			else
			{
				cout << carsList[i].listOfCarsManufact->longName << endl;
			}
			cout << "Цвет " << endl;
			cout << carsList[i].color << endl;
			cout << "VIN автомобиля " << endl;
			cout << carsList[i].VIN << endl;
			cout << "Тип кузова " << endl;
			cout << carsList[i].bodyType << endl;
			cout << "Дата производства " << endl;
			cout << carsList[i].productionDate.day << '.' << carsList[i].productionDate.month << '.' << carsList[i].productionDate.year << endl;
			cout << "Дата последнего ТО " << endl;
			cout << carsList[i].techVision.day << '.' << carsList[i].techVision.month << '.' << carsList[i].techVision.year << endl;
		}
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}