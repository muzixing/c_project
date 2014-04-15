#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "producerandconsumer.h"
#include <pthread.h>
//include <unistd.h>

int main(int argc, char const *argv[])
{
	queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
	queue_init(queue);
	printf("queue_init%d\n",queue->end );
	
	pthread_t tid_a,tid_b;
	queue = (void*)queue;
	printf("queue:%p\n", queue);
	pthread_create(&tid_b,NULL,producer,queue);
	printf("pthread_create producer\n");

	pthread_create(&tid_a,NULL,consumer,queue);
	printf("pthread_create consumer\n");

	//get(queue);
	while(1){;}




	/*
	int i;
	for (i = 0; i < 15; i++)
	{
		put(queue,i);
		printf("len:%d\n",get_len(queue));
	}
	printf("len:%d\n",get_len(queue));
	i=0;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n",get(queue));
		printf("len:%d\n",get_len(queue));
	}
	i =0;
	for (i = 0; i < 6; i++)
	{
		put(queue,i);
		printf("len:%d\n",get_len(queue));
	}
	printf("len:%d\n",get_len(queue));


*/
	return 0;

}