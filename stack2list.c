#include "stack2list.h"
#include <stdlib.h>
//#include "stack.h"

stack2list_t* stack2list_create()
{	
	stack2list_t* stack2list = (stack2list_t*)malloc(sizeof(stack2list_t));
	stack2list->a = stack_create();
	stack2list->b = stack_create();
	stack2list->flag = false;

	return stack2list;

}
void *stack2list_convert(stack_t* _using , stack_t* empty)
{
	//reverse the number by pop and push.
	int i;
	for(i = 0; i< _using->top;i++)
	{
		int* tmp = stack_pop(_using);
		//int t = *tmp;
		//printf("tmp is %d:\n",t);
		stack_push(empty,(void*)tmp);
	}
	return NULL;
}

void stack2list_destroy(stack2list_t * stack2list)
{
	stack_destroy(stack2list->a);
	stack_destroy(stack2list->b);
}
void * stack2list_push(stack2list_t * stack2list, void * data)
{	
	//TODO:reverse and reset the flag	
	if (stack2list->a->top > stack2list->b->top) //find the stack in use.
	{	
		if(stack2list->flag)//if need to reverse.
		{
			stack2list_convert(stack2list->a,stack2list->b);
			stack_push(stack2list->b,data);
			stack2list->flag = false;
			return NULL;
		}
		//no need to reverse, and push directly.
		stack_push(stack2list->a,data);
		return NULL;
	}
	else
	{
		if(stack2list->flag)
		{
			stack2list_convert(stack2list->b,stack2list->a);
			stack_push(stack2list->a,data);
			stack2list->flag = false;
			return NULL;
		}
		stack_push(stack2list->b,data);
		return NULL;
	}
	return data;
}

void * stack2list_pop(stack2list_t * stack2list)
{
	//TODO:set the flag ,reverse the flag and pop.

	if (stack2list->flag == true)
	{
		//last action is pop ,so we have no need to reverse.
		if (stack2list->a->top > stack2list->b->top)
		{
			return stack_pop(stack2list->a);
		}
		return stack_pop(stack2list->b);
	}
	else  // last action is push.so we have to reverse the number.
	{	
		stack2list->flag = true; //change the flag.
		if (stack2list->a->top > stack2list->b->top)
		{	
		stack2list_convert(stack2list->a,stack2list->b);
		return stack_pop(stack2list->b);
		}
		stack2list_convert(stack2list->b,stack2list->a);
		return stack_pop(stack2list->a);
	}
	
}