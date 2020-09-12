#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод первой кучи на экран" << endl;
		cout << "2 - добавить элемент в первую кучу" << endl;
		cout << "3 - удалить максимальный элемент первой кучи" << endl;
		cout << "4 - вывод второй кучи на экран" << endl;
		cout << "5 - добавить элемент во вторую кучу" << endl;
		cout << "6 - удалить максимальный элемент второй кучи" << endl;
		cout << "7- удалить минимальный элемент первой кучи " << endl;
		cout << "8- удалить минимальный элемент второй кучи " << endl;
		cout << "9 - объединить кучи" << endl;
		cout << "10 - удаление i-того элемента" << endl;
		cout << "11 - сумма 1 кучи" << endl;
		cout << "12 - произведение элементов кучи" << endl;
		cout << "13 - среднее значение элементов кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "Сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:  h2.scan(0);
			break;
		case 5: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h2.insert(a);
		}
			  break;
		case 6:   h2.extractMax();
			break;
		case 7: h1.extractMin(); break;
		case 8: h2.extractMin(); break;
		case 9: h1.unionHeap(h1, h2); break;
		case 10: h1.extractI(); break;
		case 11: h1.sum(h1); break;
		case 12: h1.amp(h1); break;
		case 13: h1.sr(h1); break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
