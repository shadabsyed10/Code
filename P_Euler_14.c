#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
The following iterative sequence is defined for the set of positive integers:

 n - > n/2 (n is even)
 n -> 3n +1 (n is odd)
Using the rule above and starting with 
, we generate the following sequence:

It can be seen that this sequence (starting at 
 and finishing at 
) contains 
 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 
.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#define RANGE 1000000
int main()
{
    int seq_max = 0;
    int seq_local = 0;
    int max_num = 0;
    for(unsigned int i = RANGE-1; i >= 1; i--)
    {
        unsigned int num = i;
        seq_local = 0;
        while(num != 1)
        {
            if((num & 1) == 1)
            {
                num = 3*num + 1;
            }
            else
            {
                num = num / 2;
            }
            seq_local++;
        }
        if(seq_local > seq_max)
        {
            seq_max = seq_local;
            max_num = i;
            printf("Cur max seq len : %d, Cur start num : %d\n", seq_max, max_num);
        }
    }
    printf("Max seq len : %d, start num : %d", seq_max, max_num);

}
