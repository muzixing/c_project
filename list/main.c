#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//#include "stack2list.h"


void int_printer(void * data);
//void print_stack2list(stack2list_t * stack2list, void (*data_printer)(void * data));

int main()
{
	
	/*
	stack2list_t * stack2list = stack2list_create();

	int * data = (int *)malloc(sizeof(int));
	*data = 1;
	stack2list_push(stack2list,data);
	data = (int *)malloc(sizeof(int));
	*data = 2;
	stack2list_push(stack2list,data);
	data = (int *)malloc(sizeof(int));
	*data = 3;
	stack2list_push(stack2list,data);
	print_stack2list(stack2list,int_printer);


	printf("\n\n ");

	data = stack2list_pop(stack2list);
	print_stack2list(stack2list,int_printer);
	printf("\n  working \n");

	data = stack2list_pop(stack2list);
	print_stack2list(stack2list,int_printer);
	printf("\n  working \n");

	data = (int *)malloc(sizeof(int));
	*data = 3;
	stack2list_push(stack2list,data);
	print_stack2list(stack2list,int_printer);*/
	

	queue_t * queue = queue_create();

	int * data = (int *)malloc(sizeof(int));
	*data = 1;
	queue_push(queue,data);
	data = (int *)malloc(sizeof(int));
	*data = 2;
	queue_push(queue,data);
	data = (int *)malloc(sizeof(int));
	*data = 3;
	queue_push(queue,data);
	data = (int *)malloc(sizeof(int));
	*data = 4;
	queue_push(queue,data);
	data = (int *)malloc(sizeof(int));
	*data = 5;
	queue_push(queue,data);

	int i = 0;
	for(i = 0; i<2 ; i++)
	{
		data = (int *)queue_pop(queue);
		printf("%d,",*data);
		free(data);
	}
	data = (int *)malloc(sizeof(int));
	*data = 6;
	queue_push(queue,data);
	data = (int *)malloc(sizeof(int));
	*data = 7;
	queue_push(queue,data);
	for(i = 0; i<5 ; i++)
	{
		data = (int *)queue_pop(queue);
		printf("%d,",*data);
		free(data);
	}
	return 0;
}

void int_printer(void * data)
{
	printf("%d",*((int *)data));
}

/*void print_stack2list(stack2list_t * stack2list, void (*data_printer)(void * data))
{
	int i = 0;
	stack_t* p = (stack_t *)malloc(sizeof(stack_t));
	if (stack2list->a->top > stack2list->b->top)
	{
		p = stack2list->a;
	}
	else
	{
		p = stack2list->b;
	}
	printf("stack2list_size = %d\n",p->top);
	printf("stack2list_max_size = %d\n",p->max_size);
	printf("stack2list_data = ");
	for(i = 0; i < p->top ; i++)
	{
		data_printer(p->buttom[i]);
		printf(",");
	}
}
*/