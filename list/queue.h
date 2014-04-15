#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "stack.h"

typedef struct _QUEUE_H_
{
	stack_t * in;
	stack_t * out;
}queue_t;

queue_t * queue_create();
void queue_destroy(queue_t * queue);
void * queue_push(queue_t * queue, void * data);
void * queue_pop(queue_t * queue);


#endif