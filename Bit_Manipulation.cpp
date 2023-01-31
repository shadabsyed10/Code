#include "Practice_problem.h"
typedef unsigned char uint8_t;
#define SET_BIT_LOC(num, loc)      (num | (1<<(loc-1)))
#define CLEAR_BIT_LOC(num, loc)    (num & ~(1<< (loc-1)))
#define TOGGLE_BIT_LOC(num, loc)   (num ^ (1<<(loc-1)))
#define CHECK_BIT_LOC(num, loc)    (num >>(loc-1) & 0x1)

void check_no_ones(void)
{
	unsigned int num = 0xFEFE0000; // 14
	unsigned int count = 0;
	while (num)
	{
		if (num & 0x1)
		{
			count++;
		}
		num = num >> 1;
	}
	printf("Number of ones are %d\n", count);
}

#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)

// Lookup table to store the total number of bits set for each index
// in the table. The macro `COUNT_BITS` generates the table.
unsigned int lookUpTable[256] = { COUNT_BITS };
void check_no_ones_lookuptable(void)
{
	unsigned int num = 0xFE00FE00; // 14
	unsigned int temp;
	unsigned int res = 0;
	temp = (num >> 24) & 0xFF;
	res += lookUpTable[temp];

	temp = (num >> 16) & 0xFF;
	res += lookUpTable[temp];

	temp = (num >> 8) & 0xFF;
	res += lookUpTable[temp];

	temp = (num  & 0xFF);
	res += lookUpTable[temp];


	printf("Look up table number of bits are %d\n",res);
}

void swap_nibble(void)
{
	int num = 0xF4;
	int res = 0;
	res = (num & 0xF0) >> 4;
	res |= (num & 0x0F) << 4;

	printf("swap nibble is %X\n",res);
}

void swap_Bits_at_loc(void)
{
	int num1 = 0x27; // 0010 0111
	int num2 = 0x35; // 0011 0101

	int loc = 5;
	int temp1 = (num1 >> (loc - 1)) & 0x1;
	int temp2 = (num2 >> (loc - 1)) & 0x1;

	if (temp1 != temp2)
	{
		num1 = num1 ^ (1 << (loc - 1)); //0011 0111 : 0x37
		num2 = num2 ^ (1 << (loc - 1)); // 0010 0101 : 0x25
	}
	printf("Swaped numbers are %X and %X \n", num1, num2);
}

void swap_adj_bits(void)
{
	unsigned int num = 0xAB; // 1010 1011
	unsigned int res = 0; // 0x57 : 0101 0111
	res = ((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1);
	printf("swapped number is %X\n", res);
}

void adj_bits_are_set(void)
{
	int num = 0x45; // 0100 0101
	int res = num & (num << 1);
	if (res)
	{
		printf("adj bits are found\n");
	}
	else
	{
		printf("No adj bits are found\n");
	}
}
void Reverse_bit_order(void)
{
	uint8_t num = 0x2;
	uint8_t num_bits = sizeof(num) * 8;
	uint8_t i;
	uint8_t reverse_num = 0;

	for (i = 0; i < num_bits; i++)
	{
		if (num & (1 << i))
		{
			reverse_num |= 1 << ((num_bits - 1) - i);
		}
	}
	printf("\nReversed number is %X \n", reverse_num);
}
#define R2(n) n, n + 2*64, n + 1*64, n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
#define REVERSE_BITS R6(0), R6(2), R6(1), R6(3)

// lookup table to store the reverse of each index of the table.
// The macro `REVERSE_BITS` generates the table
unsigned int lookup_reverse[256] = { REVERSE_BITS };
void Reverse_bit_order_lookup(void)
{
	unsigned int num = 0x2;
	unsigned int reverse = 0;

	reverse = lookup_reverse[num & 0xff] << 24 | lookup_reverse[(num >> 8) & 0xff] << 16 | lookup_reverse[(num >> 16) & 0xff] << 8 | lookup_reverse[num >> 24 & 0xff];
	printf("Lookup Reversed number is %X \n", reverse);
}

void xor_without_Xoroperator(void)
{
	int x = 65; // 0x41
	int y = 80; // 0x50

	int result = (x | y) - (x&y);
	printf("XOR with out XOR is %x\n",result);
}
void check_sign_of_numbers(void)
{
	int a = 90;
	int b = 100;

	if ((a ^ b) < 0)
	{
		printf("Opposite signs\n");
	}
	else
	{
		printf("same signs\n");
	}
}

void swap(int &x, int &y)
{
	if (x != y)
	{
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
	}
}

void clear_rightmost_bit(void)
{
	int num = 0x07; // 0000 0111
	int res = 0; // 0000 0110
	res = num & (~(0x1));
	printf("after clearing rightmost bit, answer is %X\n",res);
}

void Power_of_2(void)
{
	int num = 15;
	int res = num & (num - 1);
	if (res)
	{
		printf("It's not a power of 2\n");
	}
	else
	{
		
		printf("It's a power of 2\n");
	}
}

void Power_of_4(void)
{
	// return true if `n` is a power of 2, and its only
	// set bit is present at even position
	unsigned int n = 16;
	unsigned int temp = 0;
	temp = n && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
	if (temp)
	{
		printf("It's a power of 4\n");
	}
	else
	{
		printf("It's not a power of 4\n");
	}
}

void Power_of_8(void)
{
	// return true if `n` is a power of 2, and its only
	// set bit is present at even position
	unsigned int n = 64;
	unsigned int temp = 0;
	temp = n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
	if (temp)
	{
		printf("It's a power of 8\n");
	}
	else
	{
		printf("It's not a power of 8\n");
	}
}
void rightmost_bit_position(void)
{
	int num = 0x10;// 0001 0000
	int count = 1;
	while (num)
	{
		if (num & 0x1)
		{
			printf("Right most bit is at postion %d\n", count);
			return;
		}
		count++;
		num = num >> 1;
	}

}

void abs_of_number(void)
{
	int num = -15;// 1111 1010
	int mask = num >> (sizeof(num) * 8 - 1);
	int res = (num + mask) ^ mask;
	printf("size of num is %d\n", sizeof(num));
	printf("mask value is %d\n", mask);
	printf("abs value is %d\n", res);
}

void num_bits_flipped(void)
{
	int a = 65; //0100 0001 : 0x41
	int b = 80; //0101 0000 : 0x50
	int count = 0;
	int res = a ^ b;
	while (res)
	{
		if (res & 0x1)
		{
			count++;
		}
		res = res >> 1;
	}
	printf("Number of bits required to be flipped are %d\n", count);
}

void find_next_power_of_two(void)
{
	int num = 10;

	num = num - 1;
	while (num & num - 1)
	{
		num = num & num - 1;
	}
	num <<= 1;
	printf("Next power of two is %d\n", num);
}


void find_prev_power_of_two(void)
{
	int num = 1;

	while (num & num - 1)
	{
		num = num &  num - 1;
	}
	
	printf("Prev power of two is %d\n", num);
}

void find_parity(void)
{
	uint8_t num = 0x07;
	uint8_t count = 0;
	bool parity = false; // 0= even; 1= odd
	while (num)
	{
		if (num & 0x1)
		{
			count++;
			parity ^= 1;
		}
		num = num >> 1;
	}
	if (count % 2)
	{
		printf("Odd parity\n");
	}
	else
	{
		printf("Even parity\n");
	}
	//printf("Pairy is %d\n", parity);
}

#define P2(n) n, n^1, n^1, n
#define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
#define FIND_PARITY P6(0), P6(1), P6(1), P6(0)

// lookup table to store the parity of each index of the table.
// The macro `FIND_PARITY` generates the table
unsigned int lookup[256] = { FIND_PARITY };
void find_parity_lookuptable(void)
{
	unsigned int num = 0xFE00FE00; // no og bits are 14
	bool parity = false; // 0: even ; 1: odd
	num = num ^ (num >> 16);
	num = num ^ (num >> 8);
	parity = lookup[num & 0xff];
	printf("Look up table parity is %d\n", parity);

}

void multiply_16bit_using_8bit_multiplier(void)
{
	int m = 23472;
	int n = 2600;
	int result = 0;
	uint8_t mlow = m & 0x00ff;
	uint8_t mhigh = (m & 0xff00) >> 8;

	uint8_t nlow = n & 0x00ff;
	uint8_t nhigh = (n & 0xff00) >> 8;

	unsigned short mlow_nlow = (unsigned short)(mlow * nlow);
	unsigned short mhigh_nlow = (unsigned short)(mhigh * nlow);

	unsigned short mlow_nhigh = (unsigned short)(mlow * nhigh);
	unsigned short mhigh_nhigh = (unsigned short)(mhigh * nhigh);

	result = mlow_nlow + ((mhigh_nlow + mlow_nhigh) << 8) + (mhigh_nhigh << 16);
	printf("Multiplication result is %d\n",result);


}

void find_missing_number(void)
{
	
	int arr[] = { 1,2,3,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*
	int m = len + 1;
	int total = m * (m + 1) / 2;
	int i, sum;
	sum = 0;
	for (i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	int missing_num = total - sum;
	printf("Missing number is %d\n", missing_num);
	*/

	int XOR = 0;
	//compute XOR of all the elements in array
	for (int i = 0; i < len; i++)
	{
		XOR = XOR ^ arr[i];
	}

	//compute XOR of all elements from 1 to len+1
	for (int i = 1; i <= len + 1; i++)
	{
		XOR = XOR ^ i;
	}
	printf("Missing number is %d\n", XOR);
}

void circular_shit_by_k_pos(void)
{
	unsigned char num = 127;
	unsigned char size = sizeof(num) * 8;
	uint8_t shift = 3;

	unsigned char leftshift = 0;
	unsigned char rightshift = 0;

	leftshift = (num << shift) | (num >> (size - 3));
	rightshift = (num >> shift) | (num << (size - 3));
	printf("Leftshift number is %X\n", leftshift);
	printf("Rightshift number is %X\n", rightshift);

}
void find_odd_occuring_number(void)
{
	int arr[] = { 4,3,6,6,3,2,2,4,4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int XOR = 0;
	for (int i = 0; i < n; i++) {
		XOR = XOR ^ arr[i];
		printf("XOR is %x\n", XOR);
	}

	printf("Odd occuring element is %x\n", XOR);
}
void Bit_Manipulation(void)
{
	int num = 0xF0;// 1111 0000
	int bit;
	num = SET_BIT_LOC(num, 3); //F4
	printf("\nSET bit = %X\n", num);

	num = CLEAR_BIT_LOC(num, 3); //F0
	printf("CLEAR bit = %X\n", num);

	num = TOGGLE_BIT_LOC(num, 3); //F4 1111 0100
	printf("CLEAR bit = %X\n", num);

	bit = CHECK_BIT_LOC(num, 2);
	printf("CHECK bit = %X\n", bit);



	check_no_ones();
	check_no_ones_lookuptable();

	swap_nibble();
	swap_Bits_at_loc();
	swap_adj_bits();

	adj_bits_are_set();
	Reverse_bit_order();
	Reverse_bit_order_lookup();

	check_sign_of_numbers();

	clear_rightmost_bit();

	Power_of_2();
	Power_of_4();
	Power_of_8();

	rightmost_bit_position();

	abs_of_number();

	num_bits_flipped();

	find_next_power_of_two();

	find_prev_power_of_two();

	find_parity();
	find_parity_lookuptable();

	multiply_16bit_using_8bit_multiplier();

	xor_without_Xoroperator();

	find_missing_number();
	circular_shit_by_k_pos();

	find_odd_occuring_number();


}