#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void queue_init(queue_t* queue)
{
	queue->maxsize =10;
	memset(queue->buffer,'\0',queue->maxsize);
	queue->begin = 0; //DO not wirte it down by OO. 
	queue->end = 0;

}
int get_len(queue_t* queue)
{
	if ( queue->end == queue->begin)
	{
		printf("> queue empty\n");
		return 0;
	}
	else
		printf("get end:%d\n", queue->end);
		printf("get begin:%d\n", queue->begin);
		return (queue->maxsize+queue->end - queue->begin)%queue->maxsize;
}
void put(queue_t* queue,int num)
{
	if ((queue->end+1)%(queue->maxsize) != queue->begin) // 
	{
		
		*(queue->buffer+queue->end) = num;		
		printf("> put seccessful:%d\n", queue->buffer[queue->end]);
		queue->end = (queue->end+1)%(queue->maxsize); //next available one 
	}
	else
		printf("> queue full.\n");
}
int get(queue_t* queue)
{
	if (queue->begin != queue->end)
	{
		int num = queue->buffer[queue->begin];
		queue->begin =(queue->begin+1)%(queue->maxsize);
		return num; //may have a problem.
	}
	else
	{
		printf("> queue empty.\n");
		return -1;
	}
}