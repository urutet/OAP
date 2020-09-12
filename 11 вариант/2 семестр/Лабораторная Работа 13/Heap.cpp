#include "Heap.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void AAA::print()
{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}

	void* Heap::extractMin()
	{
		int i = 0, minPos = 0;
		void* min = nullptr;
		if (!isEmpty())
		{
			min = storage[0];
			while (i < size)
			{
				if (isLess(storage[i], min))
				{
					min = storage[i];
					minPos = i;
				}
				i++;
			}
			storage[minPos] = storage[size - 1];
			size--;
			heapify(0);
		} return min;
	}

	void Heap::unionHeap(Heap h1, Heap h2)
	{
		while (h2.size != 0)
		{
			AAA* heap2 = new AAA;
			heap2->x = ((AAA*)h2.storage[h2.size - 1])->getPriority();
			insert(heap2);
			h2.size--;
		}
		heapify(0);
	}

	void Heap::extractI()
	{
		int i = 0;
		void* temp = nullptr;
		std::cout << "Введите i" << std::endl;
		std::cin >> i;
		if (i <= size)
		{
			temp = storage[i];
			storage[i] = storage[size - 1];
			storage[size - 1] = temp;
			size--;
		}
		else
		{
			std::cout << "i больше размера массива" << std::endl;
		}
	}

	void Heap::sum(Heap h1)
	{
		int sum = 0;
		AAA* heap2 = new AAA;
		while (h1.size != 0)
		{
			heap2->x = ((AAA*)h1.storage[h1.size - 1])->getPriority();
			sum += heap2->x;
			h1.size-=1;
		}
		std::cout << sum << std::endl;
	}

	void Heap::amp(Heap h1)
	{
		int amp = 0;
		AAA* heap2 = new AAA;
		while (h1.size != 0)
		{
			heap2->x = ((AAA*)h1.storage[h1.size - 1])->getPriority();
			amp *= heap2->x;
			h1.size -= 1;
		}
		std::cout << amp << std::endl;
	}

	void Heap::sr(Heap h1)
	{
		float sr = 0;
		int sum = 0, num = 0;
		AAA* heap2 = new AAA;
		while (h1.size != 0)
		{
			heap2->x = ((AAA*)h1.storage[h1.size - 1])->getPriority();
			sum += heap2->x;
			num += 1;
			h1.size -= 1;
		}
		sr = sum / num;
		std::cout << sr << std::endl;
	}
}