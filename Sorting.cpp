#include "Practice_problem.h"

void AscendingOrder(void)
{
	int arr[] = { 5, 7, 1, 2 };// 1 7 5 2 //1572
	int i, j, temp = 0;
	int arr_len;
	arr_len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < arr_len; i++)
	{
		for (j = i + 1; j < arr_len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Ascending order is\n");
	for (i = 0; i < arr_len; i++)
	{
		printf("%d \n", arr[i]);
	}
}

void DescendingOrder(void)
{
	int arr[] = { 1,2,3,4,5 };
	int arr_length = sizeof(arr) / sizeof(arr[0]);
	int i, j, temp;

	for (i = 0; i < arr_length; i++)
	{
		for (j = i + 1; j < arr_length; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	printf("Descending order is\n");
	for (i = 0; i < arr_length; i++)
	{
		printf("%d \n", arr[i]);
	}

}
void sorting(void)
{
	AscendingOrder();
	DescendingOrder();
}