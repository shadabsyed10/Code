#include<stdio.h>

#include"Practice_problem.h"

void memcpy_example(void)
{
	char string1[100] = "fahimbandali";
	int len = strlen(string1);
	char string2[100] = { 0 };
	memcpy_code(string2, string1, len);
	printf("\nstring1 is %s", string1);
	printf("\nstring2 is %s", string2);

}

void* memcpy_code(void* dest, void* src, int size)
{
	int i;
	char* source = (char*)src;
	char* destination = (char*)dest;

	for (i = 0; i < size; i++)
	{
		destination[i] = source[i];
	}
	return 0;
}

int main(void) 
{
	printf("Hello world\n");
	int i = 0;
	Linked_List();
	Stack();
	String_example();
	sorting();
	Circular_buffer();
	Bit_Manipulation();
	for (i = 0; i < 4; i++)
	{
		state_machine_example();

	}
	Matrix_test();

	return 0;
}