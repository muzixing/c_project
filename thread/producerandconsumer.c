#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include <pthread.h>
#include <unistd.h>

pthread_cond_t unempty = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

//Producer thread
void producer(void* p)
{
	//printf(p );
	queue_t* queue = (queue_t*)p;
	while(1)
	{
		printf("producer start\n");
		int num1 = pthread_mutex_lock(&lock);
		if (!num1)
		{
			printf("producer lock\n");
		}
		else
		{
			printf("producer set lock error \n");
		}
		if (get_len(queue) == queue->maxsize -1) //the queue has been full.
		{
			int flag = pthread_cond_wait(&unempty,&lock);//thread wait for the condition is OK.return cpu to others.
			printf("producer flag: %d\n",flag);
		}
		// allow to put.
		put(queue,12345);
		printf("producer_get_len:%d\n",get_len(queue));
		if (get_len(queue)!= 0)
		{
			pthread_cond_signal(&unempty);//use the signal to wake up other thread.
			printf("producer set signal\n");
		}

		int num2 = pthread_mutex_unlock(&lock);//unlock the mutex
		if (!num2)
		{
			printf("producer unlock successful\n");
		}
		else
		{
			printf("prodecer unlock successful\n");
		}
		sleep(1);//sleep and return the cpu to other thread.
	}
}


void consumer(void* p)
{
	//printf(*p);
	queue_t* queue = (queue_t*)p;
	while(1)
	{
		printf("consumer start\n");
		pthread_mutex_lock(&lock);//first of all lock the mutex.
		printf("consumer_get_len:%d\n",get_len(queue));
		if(get_len(queue) == 0)
		{
			//queue empty and wait.
			printf("flag%d",pthread_cond_wait(&unempty,&lock));
		}
		
		printf("consumer get,%d\n", get(queue));
		if (get_len(queue) <queue->maxsize-1)//queue is not full,so producer can work.but after get, how can the queue be full?
		{
			pthread_cond_signal(&unempty);
			printf("consumer set signal\n");
		}
		pthread_mutex_unlock(&lock);//release the lock.
		printf("consumer unlock\n");
		sleep(2);

	}
}