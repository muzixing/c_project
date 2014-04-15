#include "link.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	link_t * first = link_create();
	first->data = 1;
	first->next = NULL;
	printf("first->data:%d\n", first->data);

	link_t * Second = link_create();
	Second->data = 2;
	Second->next = NULL;
	first->next = Second;
	printf("Second->data:%d\n", Second->data);

	link_t * third = link_create();
	third->data = 3;
	third->next = NULL;
	Second->next = third;
	printf("third->data:%d\n", third->data);

	link_t * four = link_create();
	four->data = 4;
	four->next = NULL;
	third->next = four;
	printf("four->data:%d\n", four->data);

	link_t * tail = link_create();
	tail->data = 5;
	tail->next = first;
	four->next = tail;

	printf("tail->data:%d\n", tail->data);



	insert(first,10,3);
	printf("%s\n", "insert done");
	link_t* pointer = link_create();
	
	pointer = first;
	do
	{
		printf("%d\n", pointer->data);
		pointer = pointer->next;
	} while (pointer->next!=first);
	printf("%d\n", pointer->data);



	return 0;
}