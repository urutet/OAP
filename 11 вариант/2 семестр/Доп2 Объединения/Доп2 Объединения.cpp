//Ломбард-2

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
void dateOfEnter();

struct date
{
	int year : 7;
	int month : 5;
	int day : 5;
};

struct PawnShop
{
	char clientName[str_len];
	union
	{
		char longName[str_len];
		char shortName[10];
	} listOfItems[size];
	int price;
	int credit;
	int storageDays;
	struct date enter_date;
	bool isShort;
};
struct PawnShop pawnShopList[size];
struct PawnShop bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска просроченных товаров " << endl;
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
		cin >> pawnShopList[current_size].clientName;
		cout << "Предмет в залоге " << endl;
		cin >> varArray;
		if (strlen(varArray) <= 10)
		{
			pawnShopList[current_size].isShort = true;
			strcpy_s(pawnShopList[current_size].listOfItems->shortName, varArray);
		}
		else
		{
			pawnShopList[current_size].isShort = false;
			strcpy_s(pawnShopList[current_size].listOfItems->longName, varArray);
		}
		cout << "Оценочная стоимость " << endl;
		cin >> pawnShopList[current_size].price;
		cout << "Сумма залога " << endl;
		cin >> pawnShopList[current_size].credit;
		dateOfEnter();
		cout << "Время хранения " << endl;
		cin >> pawnShopList[current_size].storageDays;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска просроченных товаров " << endl;
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
			pawnShopList[de1] = pawnShopList[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			pawnShopList[i] = bad;
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска просроченных товаров " << endl;
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
		cout << pawnShopList[n].clientName << endl;
		cout << "Предмет в залоге " << endl;
		if (pawnShopList[n].isShort == true)
		{
			cout << pawnShopList[n].listOfItems->shortName << endl;
		}
		else
		{
			cout << pawnShopList[n].listOfItems->longName << endl;
		}
		cout << "Оценочная стоимость " << endl;
		cout << pawnShopList[n].price << endl;
		cout << "Сумма залога " << endl;
		cout << pawnShopList[n].credit << endl;
		cout << "Время хранения " << endl;
		cout << pawnShopList[n].storageDays << endl;
		cout << "Дата поступления " << endl;
		cout << pawnShopList[n].enter_date.day << '.' << pawnShopList[n].enter_date.month << '.' << pawnShopList[n].enter_date.year << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Имя клиента " << endl;
			cout << pawnShopList[i].clientName << endl;
			cout << "Предмет в залоге " << endl;
			if (pawnShopList[i].isShort == true)
			{
				cout << pawnShopList[i].listOfItems->shortName << endl;
			}
			else
			{
				cout << pawnShopList[i].listOfItems->longName << endl;
			}
			cout << "Оценочная стоимость " << endl;
			cout << pawnShopList[i].price << endl;
			cout << "Сумма залога " << endl;
			cout << pawnShopList[i].credit << endl;
			cout << "Время хранения " << endl;
			cout << pawnShopList[i].storageDays << endl;
			cout << "Дата поступления " << endl;
			cout << pawnShopList[i].enter_date.day << '.' << pawnShopList[i].enter_date.month << '.' << pawnShopList[i].enter_date.year << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска просроченных товаров " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}

void dateOfEnter()
{
	int var;
	cout << "Введите год поступления 20(__) " << endl;
	cin >> var;
	pawnShopList[current_size].enter_date.year = var;
	cout << "Введите месяц поступления " << endl;
	cin >> var;
	pawnShopList[current_size].enter_date.month = var;
	cout << "Введите день поступления " << endl;
	cin >> var;
	pawnShopList[current_size].enter_date.day = var;
}

void search()
{
	char varArray[30];
	cout << "Введите срок хранения " << endl;
	cin >> varArray;
	for (int i = 0; i < current_size; i++)
		if ((_stricmp(pawnShopList[i].listOfItems->longName, varArray) == 0) || (_stricmp(pawnShopList[i].listOfItems->shortName, varArray) == 0))
		{
			cout << "Информация о просроченных товарах " << endl;
			cout << endl << "Имя клиента " << endl;
			cout << pawnShopList[i].clientName << endl;
			cout << "Предмет в залоге " << endl;
			if (pawnShopList[i].isShort == true)
			{
				cout << pawnShopList[i].listOfItems->shortName << endl;
			}
			else
			{
				cout << pawnShopList[i].listOfItems->longName << endl;
			}
			cout << "Оценочная стоимость " << endl;
			cout << pawnShopList[i].price << endl;
			cout << "Сумма залога " << endl;
			cout << pawnShopList[i].credit << endl;
			cout << "Время хранения " << endl;
			cout << pawnShopList[i].storageDays << endl;
			cout << "Дата поступления " << endl;
			cout << pawnShopList[i].enter_date.day << '.' << pawnShopList[i].enter_date.month << '.' << pawnShopList[i].enter_date.year << endl;
		}
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска просроченных товаров " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}