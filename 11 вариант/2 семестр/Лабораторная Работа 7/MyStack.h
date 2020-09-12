struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

struct CharStack
{
	char data[30];
	CharStack* head;
	CharStack* next;
};

void show(Stack* myStk);         //прототип
int pop(Stack* myStk);           //прототип
void push(int x, Stack* myStk);  //прототип
void kr3(Stack* myStk);
void clear(Stack* myStk);
void toFile(Stack* myStk);
void fromFile(Stack* myStk);
void string_length(Stack* myStk);
void halves();
int repeated(Stack* myStk);