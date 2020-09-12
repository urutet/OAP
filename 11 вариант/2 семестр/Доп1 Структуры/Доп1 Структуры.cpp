#include <iostream>  
#include <time.h>
# define str_len 30                               
# define size 30  
# define exams 5

using namespace std;
void enter_new();
void del();
void out();
void progress();

struct Students
{
	char name[str_len];
	int numOfExams;
	int examMark[exams];
};
struct Students listOfStudents[size];
struct Students bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для отображения упеваемости" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
		case 4: progress(); break;
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
		cin >> listOfStudents[current_size].name;
		cout << "Количество экзаменов " << endl;
		cin >> listOfStudents[current_size].numOfExams;
		for (int i = 0; i < listOfStudents[current_size].numOfExams; i++)
		{
			cout << "Введите оценку за " << i + 1 << " экзамен" << endl;
			cin >> listOfStudents[current_size].examMark[i];
		}
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
			listOfStudents[de1] = listOfStudents[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			listOfStudents[i] = bad;
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
		cout << listOfStudents[n - 1].name << endl;
		cout << "Количество экзаменов " << endl;
		cout << listOfStudents[current_size].numOfExams << endl;
		for (int i = 0; i < listOfStudents[current_size].numOfExams; i++)
		{
			cout << "Оценка за " << i + 1 << " экзамен" << endl;
			cout << listOfStudents[current_size].examMark[i] << endl;;
		}
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Фамилия ";
			cout << listOfStudents[i].name << endl;
			cout << "Количество экзаменов " << endl;
			cout << listOfStudents[i].numOfExams << endl;
			for (int n = 0; n < listOfStudents[i].numOfExams; i++)
			{
				cout << "Оценка за " << n + 1 << " экзамен" << endl;
				cout << listOfStudents[current_size].examMark[n] << endl;;
			}
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void progress()
{
	bool success = true;
	float greatMarks = 0.0;
	for (int i = 0; i < current_size; i++)
	{
		for (int n = 0; n < exams; n++)
		{
			if (listOfStudents[i].examMark[n] == 4 || listOfStudents[i].examMark[n] == 5)
			{
				continue;
			}
			else
			{
				success = false;
				break;
			}
		}
		if (success == true)
		{
			greatMarks += 1;
			continue;
		}
		else
		{
			success = true;
			continue;
		}
	}
	cout << "Процент отличников " << (greatMarks / current_size) * 100.0 << "%" << endl;
	cout << "Что дальше?" << endl;
	cin >> choice;
}