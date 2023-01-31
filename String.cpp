#include"Practice_problem.h"



void pallindrome_String(void)
{
	const char* string = "fahim";
	int len = strlen(string);
	int half_len = len >> 1;
	int i;
	int j = len-1;
	for (i = 0; i < half_len; i++)
	{
		if (string[i] == string[j])
		{
			j--;
			continue;
		}
		else
		{
			printf("Not Palindrome \n");
			return ;
		}
	}
	printf("Palindrome \n");
}

#define MAX_ASCII (256U)
void Max_repeated_char_without_repeat(void)
{
	const char* string = "faaaah";
	int counter[MAX_ASCII] = { 0 };
	int i, j;
	int len = strlen(string);
	int max_index = 0;
	int max_char = 0;
	for (i = 0; i < len; i++)
	{
		if (counter[string[i]] == 0)
		{
			for (j = i; j < len; j++)
			{
				if (string[i] == string[j])
				{
					counter[string[i]]++;
				}
			}
		}
	}
	max_index = counter[0];
	for (i = 0; i < MAX_ASCII; i++)
	{
		if (max_index <= counter[i])
		{
			max_char = i;
			max_index = counter[i];
		}
	}
	printf("Max repeated char is %C and repeated %d times \n", max_char, max_index);

}



void reverse_string(void)
{
	const char* string = "fahim";
	char temp[256] = { 0 };
	int len = strlen(string);
	int i;
	int j = len - 1;
	for (i = 0; i < len; i++)
	{
		temp[i] = string[j];
		j--;
	}
	puts(temp);


}

void String_example(void)
{
	pallindrome_String();
	Max_repeated_char_without_repeat();
	reverse_string();
}