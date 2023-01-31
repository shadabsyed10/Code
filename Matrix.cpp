#include "Practice_problem.h"

int Array[4][4] = { {1,2,3,4},
{5, 6, 7, 8},
{9, 10, 11, 12},
{13, 14, 15, 16} };

void Matrix_test(void)
{
	int i, j;
	int num = 4;
	int temp;
	for (i = 0; i < num; i++) // 
	{

		for (j = i; j < num; j++) //
		{
			if (i = j)
			{
				continue;
			}
			else

			{
				temp = Array[i][j]; //i =0 j = 1
				Array[i][j] = Array[j][i];
				Array[j][i] = temp;

			}
		}
	}
}