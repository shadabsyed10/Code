#include "Practice_problem.h"

typedef unsigned char uint8_t;
#if 0
struct circular_buffer
{
	uint8_t* pbuffer;
	uint8_t head;
	uint8_t tail;
	uint8_t max_size;
};

#define MAX_BUFFER_SIZE (5u)
uint8_t Buffer[MAX_BUFFER_SIZE];

struct circular_buffer my_CB;
void print_cb(struct circular_buffer* cb)
{
	uint8_t i;
	
	if (cb->tail < cb->head)
	{
		for (i = cb->tail; i < cb->head; i++)
		{
			printf("%d : ",cb->pbuffer[i]);
		}
	}
	else
	{
		for (i = cb->tail; i < cb->max_size; i++)
		{
			printf("%d : ", cb->pbuffer[i]);
		}
		for (i = 0; i < cb->head; i++)
		{
			printf("%d : ", cb->pbuffer[i]);
		}
	}
}
void Push_data_buffer(struct circular_buffer* cb, uint8_t data)
{
	uint8_t next = cb->head + 1;

	//check overflow
	if (next >= cb->max_size)
	{
		next = 0;
	}

	//check full
	if (cb->tail == next)
	{
		printf("buffer is full\n");
		return;
	}
	cb->pbuffer[cb->head] = data;
	cb->head = next;
}
uint8_t Pop_data_buffer(struct circular_buffer* cb)
{
	uint8_t data = 0;
	uint8_t next = cb->tail + 1;

	//check if empty
	if (cb->tail == cb->head)
	{
		printf("Buffer is empty\n");
		return 0;
	}

	//check overflow
	if (next >= cb->max_size)
		next = 0;

	data = cb->pbuffer[cb->tail];
	cb->tail = next;
	return data;
}
void Circular_buffer(void)
{
	uint8_t data = 0;
	my_CB.pbuffer = &Buffer[0];
	my_CB.head = 0;
	my_CB.tail = 0;
	my_CB.max_size = MAX_BUFFER_SIZE;
	Push_data_buffer(&my_CB, 50);
	Push_data_buffer(&my_CB, 60);
	Push_data_buffer(&my_CB, 70);
	Push_data_buffer(&my_CB, 80);
	Push_data_buffer(&my_CB, 90);
	print_cb(&my_CB);

	data = Pop_data_buffer(&my_CB);
	printf("data is %d \n", data);
	print_cb(&my_CB);


}
#endif

#define BUFFER_SIZE (4u)
int circular_buffer[BUFFER_SIZE] = { 0 };
int rd_indx = 0;
int wr_index = 0;
int buffer_len = 0;

void cb_write(int data)
{
	if (buffer_len == BUFFER_SIZE)
	{
		printf("Buffer is full\n");
	}
	circular_buffer[wr_index] = data;
	buffer_len++;
	wr_index++;
	if (wr_index == BUFFER_SIZE)
	{
		wr_index = 0;
	}
}

void cb_read(int* data)
{
	if (buffer_len == 0)
	{
		printf("Buffer is empty\n");
		return;
	}
	*data = circular_buffer[rd_indx];
	buffer_len--;
	rd_indx++;
	if (rd_indx == BUFFER_SIZE)
		rd_indx = 0;

}
void Circular_buffer(void)
{

	int rd_data = 0;
	cb_read(&rd_data);
	cb_write(10);
	cb_write(20);
	cb_write(30);
	cb_write(40);
	cb_write(50);
	cb_write(60);
	cb_write(70);
	cb_write(80);
	cb_write(90);

	cb_read(&rd_data);
	printf("Read data is %d\n", rd_data);
	cb_read(&rd_data);
	printf("Read data is %d\n", rd_data);
	cb_read(&rd_data);
	printf("Read data is %d\n", rd_data);
	cb_read(&rd_data);
	printf("Read data is %d\n", rd_data);
	cb_read(&rd_data);
	printf("Read data is %d\n", rd_data);
	cb_read(&rd_data);
	printf("Read data is %d\n", rd_data);
}

