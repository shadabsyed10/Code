#include <iostream>
#if 0
int calculateDeterminant_2x2(int a, int b, int c, int d)
{
	return ((a*d) - (b*c));
}

unsigned int getIndex(unsigned int row)
{
	unsigned int index = 0;

	index = magical formula;

	return index;
}

int calculateDeterminant(int *matrix, int size)
{
	int determinant = 0;
	for (unsigned int r = 0; r < size; r++)
	{
		determinant = calculateDeterminant_2x2(*(matrix + getIndex(r)), *(matrix + getIndex(r)), *(matrix + getIndex(r)), *(matrix + getIndex(r)));
	}

	return determinant;
}

// [0], [1], [2],  
int main(void)
{
	// Given 2x2 Matrix:
	// a b
	// c d

	// 2x2 Determinant:
	// det = (ad - bc)

	// Given 3x3 Matrix:
	// A b c R->
	// D e f 
	// G h i 
	// C 

	// 3x3 Determinant:
	// det = 
	// A | e f | - b | D f |  + c | D e |
	//   | h i |     | G i |      | G h |


	int testMat2x2[2 * 2] = {
	  1, 2,
	  3, 4,
	};

	int testMat3x3[3 * 3] = {
	  1, 2, 3,
	  5, 7, 8,
	  1, 2, 4,
	};

	int testMat4x4[4 * 4] = {
	  1, 2, 3, 4,
	  5, 7, 8, 9,
	  4, 3, 2, 1,
	  5, 7, 8, 19,
	};


	// Test Cases
	printf("Determinant of 2x2 matrix = %d\n", calculateDeterminant(testMat2x2, 2)); // -2
	printf("Determinant of 3x3 matrix = %d\n", calculateDeterminant(testMat3x3, 3)); // -3
	printf("Determinant of 4x4 matrix = %d\n", calculateDeterminant(testMat4x4, 4)); // -50

	return 0;
}

#endif