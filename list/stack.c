#include <stdlib.h>
#include "stack.h"

stack_t* stack_create(){
	stack_t * p = (stack_t *)malloc(sizeof(stack_t));
	p->max_size = 10;
	p->buttom = (void **)malloc(sizeof(void *) * p->max_size);
	p->top = 0;
	return p;
}

void stack_destroy(stack_t * stack){
	free(stack->buttom);
	free(stack);
}

void * stack_push(stack_t * stack, void * data)
{
	if(stack->top >= stack->max_size)
	{
		return NULL;
	}
	stack->buttom[stack->top] = data;
	stack->top++;
	return data;
}

void * stack_pop(stack_t * stack)
{
	if (stack->top > 0)
	{
		stack->top--;
		return (stack->buttom[stack->top]);
	}
	return NULL;
}
