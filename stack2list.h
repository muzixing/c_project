#ifndef _STACK_2_LIST_
#define _STACK_2_LIST_

#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack2list{
	stack_t * a;
	stack_t * b;
	bool flag;

}stack2list_t;

stack2list_t* stack2list_create();
void *stack2list_convert(stack_t* _using,stack_t* empty);
void stack2list_destroy(stack2list_t * stack2list);
void * stack2list_push(stack2list_t * stack2list, void * data);
void * stack2list_pop(stack2list_t * stack2list);

#endif
