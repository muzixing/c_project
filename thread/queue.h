#ifndef _QUEUE_
#define _QUEUE_


typedef struct _QUEUE_
{
	int maxsize;
	int buffer[10];  //bad design
	int end;
	int begin;
	
}queue_t;

void queue_init(queue_t* queue);
int get_len(queue_t* queue);
void put(queue_t* queue,int num);
int get(queue_t* queue);

#endif