#include"Practice_problem.h"

#define MAX_ITEMS (4U)

struct stack
{
	int TOP;
	int items[MAX_ITEMS];
};

void create_empty_stack(struct stack* st)
{
	st->TOP = -1;
}
bool stack_full(struct stack* st)
{
	if (st->TOP == (MAX_ITEMS - 1))
		return true;
	else
		return false;
}
void Push_on_stack(struct stack* st, int data)
{
	//check if stack is full
	bool full = stack_full(st);
	if (full)
	{
		printf("Stack is full\n");
	}
	else
	{
		st->TOP++;
		st->items[st->TOP] = data;
	}
}

bool stack_empty(struct stack* st)
{
	if (st->TOP == -1)
		return true;
	else
		return false;
}
int Pop_data_stack(struct stack* st)
{
	int res = 0;
	//check if stack is empty
	bool empty = stack_empty(st);
	if (empty)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		res = st->items[st->TOP];
		st->TOP--;
	}
	return res;
}
void print_Stack(struct stack* st)
{
	int i;
	printf("stack is \n");
	for (i = 0; i < MAX_ITEMS; i++)
	{
		printf("%d ", st->items[i]);
	}
}
void Stack(void)
{
	int res = 0;
	//creat a stack
	struct stack* st = (struct stack*)malloc(sizeof(struct stack));
	create_empty_stack(st);
	Push_on_stack(st, 10);
	Push_on_stack(st, 20);
	Push_on_stack(st, 30);
	Push_on_stack(st, 40);
	Push_on_stack(st, 50);
	print_Stack(st);

	res = Pop_data_stack(st);
	printf("\nPopped data is %d \n", res);

	res = Pop_data_stack(st);
	printf("Popped data is %d \n", res);

	res = Pop_data_stack(st);
	printf("Popped data is %d \n", res);

	res = Pop_data_stack(st);
	printf("Popped data is %d \n", res);

	res = Pop_data_stack(st);
	printf("Popped data is %d \n", res);


}