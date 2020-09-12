#define MYQUEUE1_EQE  0x0000  // ������� � ������ ������� ������� 

struct Queue               // ���� ���������� �������� 
{
	int Head;           // ������ �������
	int Tail;           // ����� �������
	int Size;           // ������ ������� (����. �����.+1)
	void** Data;        // ��������� ������ ������� 
	Queue(int size)     // ���������� ������ �������  
	{
		Head = Tail = 0;
		Data = new void* [Size = size + 1];
	}
	bool isFull() const;       // ������� ��������a ?
	bool isEmpty()const;       // ������� ����a ? 
};

Queue createQueue(int n);            // n � ����. ���������� 
Queue createQueue(const Queue& pq);  // ������� ������� �� ������� 
bool  enQueue(Queue& q, void* x);    // �������� x 
void* delQueue(Queue& q);            // ������� ������� 
void* peekQueue(const Queue& q);     // �������� ������ �������
int clearQueue(Queue& q);            // �������� �������
void releaseQueue(Queue& q);         // ���������� ������� 
