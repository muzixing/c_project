/*
##################
Author: muzi
Date:2014/4/10
TODO: Using the stack to complete the list function.
##################
*/
#ifndef _STACK_H_
#define _STACK_H_

typedef struct _stack
{
	void ** buttom;
	int top;
	int max_size;
}stack_t;
stack_t * stack_create();

void stack_destroy(stack_t * stack);
void * stack_push(stack_t * stack, void * data);
void * stack_pop(stack_t * stack);

#endif
