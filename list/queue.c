
#include "queue.h"
#include <stdlib.h>

queue_t * queue_create()
{
	queue_t * queue = (queue_t *)malloc(sizeof(queue_t));
	queue->in = stack_create();
	queue->out = stack_create();
	return queue;
}
void queue_destroy(queue_t * queue)
{
	stack_destroy(queue->in);
	stack_destroy(queue->out);
}

void * queue_push(queue_t * queue, void * data)
{
	return stack_push(queue->in, data);
}

void * queue_pop(queue_t * queue)
{
	if(queue->out->top == 0)
	{
		while(queue->in->top > 0)
		{
			stack_push(queue->out,stack_pop(queue->in));
		}
	}
	return stack_pop(queue->out);
}
