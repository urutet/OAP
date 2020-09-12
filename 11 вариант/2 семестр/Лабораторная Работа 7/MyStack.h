struct Stack
{
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

struct CharStack
{
	char data[30];
	CharStack* head;
	CharStack* next;
};

void show(Stack* myStk);         //��������
int pop(Stack* myStk);           //��������
void push(int x, Stack* myStk);  //��������
void kr3(Stack* myStk);
void clear(Stack* myStk);
void toFile(Stack* myStk);
void fromFile(Stack* myStk);
void string_length(Stack* myStk);
void halves();
int repeated(Stack* myStk);