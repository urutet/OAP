#include <iostream>
#include<Windows.h>
#include <iomanip>

using namespace std;

struct INFO
{
	char surname[30];
	char name[30];
	int year;
	int kurs;
	int gruppa;

	int math;
	int physics;
	int english;
};

struct students
{
	INFO info;
	students* prev;
	students* next;
};

void input(students** head, students** tail, INFO stud);
void show(students* head);
void sort_kurs(students* head);
void sort_surname(students* head);
void sred_ball_gruppa(students* head);
void old_young(students* head);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	students* head = NULL;
	students* tail = NULL;

	INFO first = { "Старик",	"Илья",		1999,	3,	2,	6,7,8 };
	input(&head, &tail, first);
	INFO second = { "Крылов",	"Пётр",		2001,	2,	1,	4,4,5 };
	input(&head, &tail, second);
	INFO third = { "Булгаков",	"Никита",		2002,	1,	1,	8,7,9 };
	input(&head, &tail, third);
	INFO fourth = { "Пушкин",	"Александр",	2002,	1,	1,	7,7,8 };
	input(&head, &tail, fourth);
	INFO fifth = { "Иванов",	"Евгений",		2000,	3,	2,	5,6,4 };
	input(&head, &tail, fifth);
	INFO sixth = { "Мозгов",		"Евгений",		2002,	1,	2,	9,8,9 };
	input(&head, &tail, sixth);

	sort_kurs(head);
	sort_surname(head);
	sred_ball_gruppa(head);
	old_young(head);

	system("pause");
}

void input(students** head, students** tail, INFO stud)
{
	students* temp = new students;
	temp->next = NULL;

	temp->info = stud;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = *tail = temp;
	}
	else
	{
		temp->prev = *tail;
		(*tail)->next = temp;
		*tail = temp;
	}
}

void show(students* head)
{
	students* temp = new students;
	if (head == NULL) cout << "Список пуст!" << endl;
	else
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->info.surname << '\t' << temp->info.kurs /*<< '\t' << temp->info.gruppa*/ << endl;
			temp = temp->next;
		}
		cout << endl;
	}
}

void sort_kurs(students* head)
{
	if (head == NULL) cout << "Список пуст!" << endl;
	else
	{
		students* temp = head;
		students* temp2 = head->next;
		INFO buf;

		while (temp->next)
		{
			while (temp2)
			{
				if (temp2->info.kurs < temp->info.kurs)
				{
					buf = temp2->info;
					temp2->info = temp->info;
					temp->info = buf;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
			temp2 = temp->next;
		}
		cout << "Сортировка по курсам : " << endl;
		show(head);
	}
}

void sort_surname(students* head)
{
	if (head == NULL) cout << "Список пуст!" << endl;
	else
	{
		students* temp = head;
		students* temp2 = head->next;
		INFO buf;

		while (temp->next)
		{
			while ((temp2) && temp2->info.kurs == temp->info.kurs)
			{
				if (temp2->info.surname[0] < temp->info.surname[0] || (temp2->info.surname[0] == temp->info.surname[0] && temp2->info.surname[1] < temp->info.surname[1]))
				{
					buf = temp2->info;
					temp2->info = temp->info;
					temp->info = buf;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
			temp2 = temp->next;
		}
		cout << "Сортировка по фамилии среди каждого курса " << endl;
		show(head);
	}
}

void sred_ball_gruppa(students* head)
{
	if (head == NULL) cout << "Список пуст!" << endl;
	else
	{
		students* temp = head;
		int k = 1;
		struct gruppa
		{
			int kurs;
			int gruppa;
			int quant = 0;
			double math = 0;
			double physics = 0;
			double english = 0;
		};
		gruppa gr1_1, gr1_2, gr2_1, gr2_2, gr3_1, gr3_2;

		while ((temp) && temp->info.kurs == 1)
		{
			gr1_1.kurs = 1; gr1_1.gruppa = 1;
			gr1_2.kurs = 1; gr1_2.gruppa = 2;
			switch (temp->info.gruppa)
			{
			case 1: gr1_1.quant++; gr1_1.english += temp->info.english; gr1_1.physics += temp->info.physics; gr1_1.math += temp->info.math; break;
			case 2: gr1_2.quant++; gr1_2.english += temp->info.english; gr1_2.physics += temp->info.physics; gr1_2.math += temp->info.math; break;
			}
			temp = temp->next;
		}

		while ((temp) && temp->info.kurs == 2)
		{
			gr2_1.kurs = 1; gr2_1.gruppa = 1;
			gr2_2.kurs = 1; gr2_2.gruppa = 2;
			switch (temp->info.gruppa)
			{
			case 1: gr2_1.quant++; gr2_1.english += temp->info.english; gr2_1.physics += temp->info.physics; gr2_1.math += temp->info.math; break;
			case 2: gr2_2.quant++; gr2_2.english += temp->info.english; gr2_2.physics += temp->info.physics; gr2_2.math += temp->info.math; break;
			}
			temp = temp->next;
		}

		while ((temp) && temp->info.kurs == 3)
		{
			gr3_1.kurs = 1; gr3_1.gruppa = 1;
			gr3_2.kurs = 1; gr3_2.gruppa = 2;
			switch (temp->info.gruppa)
			{
			case 1: gr3_1.quant++; gr3_1.english += temp->info.english; gr3_1.physics += temp->info.physics; gr3_1.math += temp->info.math; break;
			case 2: gr3_2.quant++; gr3_2.english += temp->info.english; gr3_2.physics += temp->info.physics; gr3_2.math += temp->info.math; break;
			}
			temp = temp->next;
		}

		gr1_1.english = gr1_1.english / gr1_1.quant;
		gr1_1.physics = gr1_1.physics / gr1_1.quant;
		gr1_1.math = gr1_1.math / gr1_1.quant;

		gr1_2.english = gr1_2.english / gr1_2.quant;
		gr1_2.physics = gr1_2.physics / gr1_2.quant;
		gr1_2.math = gr1_2.math / gr1_2.quant;

		gr2_1.english = gr2_1.english / gr2_1.quant;
		gr2_1.physics = gr2_1.physics / gr2_1.quant;
		gr2_1.math = gr2_1.math / gr2_1.quant;

		gr2_2.english = gr2_2.english / gr2_2.quant;
		gr2_2.physics = gr2_2.physics / gr2_2.quant;
		gr2_2.math = gr2_2.math / gr2_2.quant;

		gr3_1.english = gr3_1.english / gr3_1.quant;
		gr3_1.physics = gr3_1.physics / gr3_1.quant;
		gr3_1.math = gr3_1.math / gr3_1.quant;

		gr3_2.english = gr3_2.english / gr3_2.quant;
		gr3_2.physics = gr3_2.physics / gr3_2.quant;
		gr3_2.math = gr3_2.math / gr3_2.quant;

		cout << "Средние баллы групп 1 курса : " << endl;
		if (gr1_1.english > 0)
		{
			cout << "1 группа : " << endl;
			cout << "Английский : " << gr1_1.english << endl;
			cout << "Физика : " << gr1_1.physics << endl;
			cout << "Математика : " << gr1_1.math << endl;
		}
		if (gr1_2.english > 0)
		{
			cout << "2 группа : " << endl;
			cout << "Английский : " << gr1_2.english << endl;
			cout << "Физика : " << gr1_2.physics << endl;
			cout << "Математика : " << gr1_2.math << endl;
		}
		cout << endl;
		cout << "Средние баллы групп 2 курса : " << endl;
		if (gr2_1.english > 0)
		{
			cout << "1 группа : " << endl;
			cout << "Английский : " << gr2_1.english << endl;
			cout << "Физика : " << gr2_1.physics << endl;
			cout << "Математика : " << gr2_1.math << endl;
		}
		if (gr2_2.english > 0)
		{
			cout << "2 группа : " << endl;
			cout << "Английский : " << gr2_2.english << endl;
			cout << "Физика : " << gr2_2.physics << endl;
			cout << "Математика : " << gr2_2.math << endl;
		}
		cout << endl;
		cout << "Средние баллы групп 3 курса : " << endl;
		if (gr3_1.english > 0)
		{
			cout << "1 группа : " << endl;
			cout << "Английский : " << gr3_1.english << endl;
			cout << "Физика : " << gr3_1.physics << endl;
			cout << "Математика : " << gr3_1.math << endl;
		}
		if (gr3_2.english > 0)
		{
			cout << "2 группа : " << endl;
			cout << "Английский : " << gr3_2.english << endl;
			cout << "Физика : " << gr3_2.physics << endl;
			cout << "Математика : " << gr3_2.math << endl;
		}
		cout << endl;
	}
}

void old_young(students* head)
{
	if (head == NULL) cout << "Список пуст!" << endl;
	else
	{
		students* temp = head;
		INFO young = temp->info, old = temp->info;
		while (temp->next)
		{
			if (temp->info.year > young.year) young = temp->info;
			if (temp->info.year < old.year) old = temp->info;
			temp = temp->next;
		}
		cout << "Самый старший студент : " << old.surname << '\t' << old.year << endl;
		cout << "Самый младший студент : " << young.surname << '\t' << young.year << endl;
	}
}