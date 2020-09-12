#include <iostream>  
#include <time.h>
# define str_len 30                               
# define size 30  
using namespace std;
void enter_new();
void del();
void out();
void birthday();

struct Contacts
{
	char name[str_len];
	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
	char address[str_len];
	int phoneNumber;
	char placeOfWorkStudy[str_len];
	char position[str_len];
};
struct Contacts listOfContacts[size];
struct Contacts bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для вывода поздравления " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
		case 4:	 birthday(); break;
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
		cout << endl << "ФИО " << endl;
		cin >> listOfContacts[current_size].name;
		cout << "Год рождения " << endl;
		cin >> listOfContacts[current_size].yearOfBirth;
		cout << "Месяц рождения " << endl;
		cin >> listOfContacts[current_size].monthOfBirth;
		cout << "День рождения " << endl;
		cin >> listOfContacts[current_size].dayOfBirth;
		cout << "Адрес " << endl;
		cin >> listOfContacts[current_size].address;
		cout << "Телефон " << endl;
		cin >> listOfContacts[current_size].phoneNumber;
		cout << "Место работы " << endl;
		cin >> listOfContacts[current_size].placeOfWorkStudy;
		cout << "Должность " << endl;
		cin >> listOfContacts[current_size].position;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			listOfContacts[de1] = listOfContacts[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			listOfContacts[i] = bad;
	cout << "Что дальше?" << endl;
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
		cout << "Фамилия ";
		cout << listOfContacts[n - 1].name << endl;
		cout << "Год рождения ";
		cout << listOfContacts[n - 1].yearOfBirth << endl;
		cout << "Месяц рождения ";
		cout << listOfContacts[n - 1].monthOfBirth << endl;
		cout << "Год рождения ";
		cout << listOfContacts[n - 1].dayOfBirth << endl;
		cout << "Адрес ";
		cout << listOfContacts[n - 1].address << endl;
		cout << "Телефон " << endl;
		cout << listOfContacts[n - 1].phoneNumber << endl;
		cout << "Место работы " << endl;
		cout << listOfContacts[n - 1].placeOfWorkStudy << endl;
		cout << "Должность " << endl;
		cout << listOfContacts[n - 1].position << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Фамилия ";
			cout << listOfContacts[i].name << endl;
			cout << "Год рождения ";
			cout << listOfContacts[i].yearOfBirth << endl;
			cout << "Месяц рождения ";
			cout << listOfContacts[i].monthOfBirth << endl;
			cout << "День рождения ";
			cout << listOfContacts[i].dayOfBirth << endl;
			cout << "Адрес ";
			cout << listOfContacts[i].address << endl;
			cout << "Телефон " << endl;
			cout << listOfContacts[i].phoneNumber << endl;
			cout << "Место работы " << endl;
			cout << listOfContacts[i].placeOfWorkStudy << endl;
			cout << "Должность " << endl;
			cout << listOfContacts[i].position << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void birthday()
{
	int year, month, day;
	cout << "Введите год " << endl;
	cin >> year;
	cout << "Введите месяц " << endl;
	cin >> month;
	cout << "Введите день " << endl;
	cin >> day;
	for (int i = 0; i < current_size; i++)
	{
		if (year == listOfContacts[i].yearOfBirth && month == listOfContacts[i].monthOfBirth && day == listOfContacts[i].dayOfBirth)
		{
			cout << "С днем рождения, " << listOfContacts[i].name << endl;
		}
		else continue;
	}
}