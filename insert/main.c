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

	insert(first,10,3);
	printf("%s\n", "insert done");
	link_t* pointer = link_create();
	printf("%s\n", "insert done");
	pointer = first;
	do
	{
		printf("%d\n", pointer->data);
		pointer = pointer->next;
	} while (pointer->next!=NULL);
	printf("%d\n", pointer->data);



	return 0;
}